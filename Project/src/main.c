#include "../inc/mdma.h"

#define CPU_CLOCK 2000000

static void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

static void	custom_delay(int32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int ft_spiWrite(uint8_t b)
{
    for (uint8_t bit = 0; bit < 8; bit++)
    {
        if (b & 0x80)
            ft_digital_write(RFID_MOSI,FT_HIGH);
        else
            ft_digital_write(RFID_MOSI,FT_LOW);
        ft_digital_write(CLK,FT_HIGH);
        b <<= 1;
        ft_digital_write(CLK,FT_LOW);
		return bit;
    }
	return 0;
}

/**
 * Writes a number of bytes to the specified register in the MFRC522 chip.
 * The interface is described in the datasheet section 8.1.2.
 */
void PCD_WriteRegister2(uint8_t reg, uint8_t count, uint8_t *values)
{
  ft_digital_write(RFID_SS, FT_LOW); /* Select SPI Chip MFRC522 */
 
  // MSB == 0 is for writing. LSB is not used in address. Datasheet section 8.1.2.3.
  (void) ft_spiWrite(reg & 0x7E);
  for (uint8_t index = 0; index < count; index++)
  {
    (void) ft_spiWrite(values[index]);
  }
 
  ft_digital_write(RFID_RST, FT_HIGH); /* Release SPI Chip MFRC522 */
} // End PCD_WriteRegister()

/**
 * Reads a number of bytes from the specified register in the MFRC522 chip.
 * The interface is described in the datasheet section 8.1.2.
 */
void PCD_ReadRegister2(uint8_t reg, uint8_t count, uint8_t *values, uint8_t rxAlign)
{
  if (count == 0) { return; }
 
  uint8_t address = 0x80 | reg;  // MSB == 1 is for reading. LSB is not used in address. Datasheet section 8.1.2.3.
  uint8_t index = 0;             // Index in values array.
 
  ft_digital_write(RFID_SS, FT_LOW);                      /* Select SPI Chip MFRC522 */
  count--;                       // One read is performed outside of the loop
  (void) ft_spiWrite(address);   // Tell MFRC522 which address we want to read
 
  while (index < count)
  {
    if ((index == 0) && rxAlign) // Only update bit positions rxAlign..7 in values[0]
    {
      // Create bit mask for bit positions rxAlign..7
      uint8_t mask = 0;
      for (uint8_t i = rxAlign; i <= 7; i++)
      {
        mask |= (1 << i);
      }
 
      // Read value and tell that we want to read the same address again.
      uint8_t value = ft_spiWrite(address);
 
      // Apply mask to both current value of values[0] and the new data in value.
      values[0] = (values[index] & ~mask) | (value & mask);
    }
    else
    {
      // Read value and tell that we want to read the same address again.
      values[index] = ft_spiWrite(address);
    }
 
    index++;
  }
 
  values[index] = ft_spiWrite(0); // Read the final byte. Send 0 to stop reading.
 
  ft_digital_write(RFID_RST, FT_HIGH);                       /* Release SPI Chip MFRC522 */
} // End PCD_ReadRegister()

void PCD_WriteRegister(uint8_t reg, uint8_t value)
{
  ft_digital_write(RFID_SS, FT_LOW); /* Select SPI Chip MFRC522 */
 
  // MSB == 0 is for writing. LSB is not used in address. Datasheet section 8.1.2.3.
  (void) ft_spiWrite(reg & 0x7E);
  (void) ft_spiWrite(value);
 
  ft_digital_write(RFID_RST, FT_HIGH); /* Release SPI Chip MFRC522 */
}

uint8_t PCD_ReadRegister(uint8_t reg)
{
  uint8_t value;
  ft_digital_write(RFID_SS, FT_LOW);  /* Select SPI Chip MFRC522 */
 
  // MSB == 1 is for reading. LSB is not used in address. Datasheet section 8.1.2.3.
  (void) ft_spiWrite(0x80 | reg);
 
  // Read the value back. Send 0 to stop reading.
  value = ft_spiWrite(0);
 
  ft_digital_write(RFID_RST, FT_HIGH); /* Release SPI Chip MFRC522 */
 
  return value;
}

/**
 * Turns the antenna on by enabling pins TX1 and TX2.
 * After a reset these pins disabled.
 */
void PCD_AntennaOn()
{
  uint8_t value = PCD_ReadRegister(TxControlReg);
  if ((value & 0x03) != 0x03)
  {
    PCD_WriteRegister(TxControlReg, value | 0x03);
  }
} // End PCD_AntennaOn()

void PCD_Init()
{
  /* Reset MFRC522 */
  ft_digital_write(RFID_RST, FT_LOW);
  custom_delay(10);
  ft_digital_write(RFID_RST, FT_HIGH);
  
  // Section 8.8.2 in the datasheet says the oscillator start-up time is the start up time of the crystal + 37,74us. Let us be generous: 50ms.
  custom_delay(50);
 
  // When communicating with a PICC we need a timeout if something goes wrong.
  // f_timer = 13.56 MHz / (2*TPreScaler+1) where TPreScaler = [TPrescaler_Hi:TPrescaler_Lo].
  // TPrescaler_Hi are the four low bits in TModeReg. TPrescaler_Lo is TPrescalerReg.
  PCD_WriteRegister(T_MODE_REG, 0x80);      // TAuto=1; timer starts automatically at the end of the transmission in all communication modes at all speeds
  PCD_WriteRegister(T_PRESCALER_REG, 0xA9); // TPreScaler = TModeReg[3..0]:TPrescalerReg, ie 0x0A9 = 169 => f_timer=40kHz, ie a timer period of 25us.
  PCD_WriteRegister(T_RELOADH_REG, 0x03);   // Reload timer with 0x3E8 = 1000, ie 25ms before timeout.
  PCD_WriteRegister(T_RELOADL_REG, 0xE8);
 
  PCD_WriteRegister(TX_ASK_REG, 0x40);      // Default 0x00. Force a 100 % ASK modulation independent of the ModGsPReg register setting
  PCD_WriteRegister(MODE_REG, 0x3D);       // Default 0x3F. Set the preset value for the CRC coprocessor for the CalcCRC command to 0x6363 (ISO 14443-3 part 6.2.4)
 
  PCD_WriteRegister(RFCfgReg, (0x07<<4)); // Set Rx Gain to max
 
  PCD_AntennaOn();                        // Enable the antenna driver pins TX1 and TX2 (they were disabled by the reset)
} // End PCD_Init()

void initSPI(uint32_t freq)
{
    if (ft_digital_read(RFID_RST) >= 0)
    {
        ft_pin_mode(RFID_RST,FT_OUTPUT);
        ft_digital_write(RFID_RST,FT_HIGH);
    }
    //ft_pin_mode(RFID_DC,FT_OUTPUT);
    //ft_digital_write(RFID_DC,FT_HIGH);

    ft_pin_mode(RFID_MOSI, FT_OUTPUT);
    ft_digital_write(RFID_MOSI, FT_LOW);
    ft_pin_mode(CLK,FT_OUTPUT);
    ft_digital_write(CLK,FT_LOW);
    if (ft_digital_read(RFID_MISO) >= 0)
    {
        ft_pin_mode(RFID_MISO,FT_INPUT);
    }
    if (ft_digital_read(RFID_RST) >= 0)
    {
        ft_pin_mode(RFID_RST,FT_OUTPUT);
        ft_digital_write(RFID_RST,FT_HIGH);
        custom_delay(100);
        ft_digital_write(RFID_RST,FT_LOW);
        custom_delay(100);
        ft_digital_write(RFID_RST,FT_HIGH);
        custom_delay(200);
    }
}
/*=============================================*/

/**
 * Sets the bits given in mask in register reg.
 */
void PCD_SetRegisterBits(uint8_t reg, uint8_t mask)
{
  uint8_t tmp = PCD_ReadRegister(reg);
  PCD_WriteRegister(reg, tmp | mask);     // set bit mask
} // End PCD_SetRegisterBitMask()

/**
 * Use the CRC coprocessor in the MFRC522 to calculate a CRC_A.
 */
uint8_t PCD_CalculateCRC(uint8_t *data, uint8_t length, uint8_t *result)
{
  PCD_WriteRegister(COMIEN_REG, PCD_Idle);      // Stop any active command.
  PCD_WriteRegister(DIVIRQ_REG, 0x04);           // Clear the CRCIRq interrupt request bit
  PCD_SetRegisterBits(FIFO_LVL_REG, 0x80);      // FlushBuffer = 1, FIFO initialization
  PCD_WriteRegister2(FIFO_DATA_REG, length, data); // Write data to the FIFO
  PCD_WriteRegister(COMIEN_REG, PCD_CalcCRC);   // Start the calculation
 
  // Wait for the CRC calculation to complete. Each iteration of the while-loop takes 17.73us.
  uint16_t i = 5000;
  uint8_t n;
  while (1)
  {
    n = PCD_ReadRegister(DIVIRQ_REG);  // DIVIRQ_REG[7..0] bits are: Set2 reserved reserved MfinActIRq   reserved CRCIRq reserved reserved
    if (n & 0x04)
    {
      // CRCIRq bit set - calculation done
      break;
    }
    
    if (--i == 0)
    {
      // The emergency break. We will eventually terminate on this one after 89ms.
      // Communication with the MFRC522 might be down.
      return STATUS_TIMEOUT;
    }
  }
 
  // Stop calculating CRC for new content in the FIFO.
  PCD_WriteRegister(COMIEN_REG, PCD_Idle);
 
  // Transfer the result from the registers to the result buffer
  result[0] = PCD_ReadRegister(CRCResultRegL);
  result[1] = PCD_ReadRegister(CRCResultRegH);
  return STATUS_OK;
} // End PCD_CalculateCRC()

/**
 * Transfers data to the MFRC522 FIFO, executes a commend, waits for completion and transfers data back from the FIFO.
 * CRC validation can only be done if backData and backLen are specified.
 */
uint8_t PCD_CommunicateWithPICC(uint8_t command,
                                         uint8_t waitIRq,
                                         uint8_t *sendData,
                                         uint8_t sendLen,
                                         uint8_t *backData,
                                         uint8_t *backLen,
                                         uint8_t *validBits,
                                         uint8_t rxAlign,
                                         int    checkCRC)
{
  uint8_t n, _validBits = 0;
  uint32_t i;
 
  // Prepare values for BitFramingReg
  uint8_t txLastBits = validBits ? *validBits : 0;
  uint8_t bitFraming = (rxAlign << 4) + txLastBits;   // RxAlign = BitFramingReg[6..4]. TxLastBits = BitFramingReg[2..0]
 
  PCD_WriteRegister(COMMAND_REG, 0x0);            // Stop any active command.
  PCD_WriteRegister(COMIRQ_REG, 0x7F);                 // Clear all seven interrupt request bits
  PCD_SetRegisterBits(FIFO_LVL_REG, 0x80);            // FlushBuffer = 1, FIFO initialization
  PCD_WriteRegister2(FIFO_DATA_REG, sendLen, sendData);  // Write sendData to the FIFO
  PCD_WriteRegister(BIT_FRAMING_REG, bitFraming);       // Bit adjustments
  PCD_WriteRegister(COMMAND_REG, command);             // Execute the command
  if (command == PCD_Transceive)
  {
    PCD_SetRegisterBits(BIT_FRAMING_REG, 0x80);      // StartSend=1, transmission of data starts
  }
 
  // Wait for the command to complete.
  // In PCD_Init() we set the TAuto flag in TModeReg. This means the timer automatically starts when the PCD stops transmitting.
  // Each iteration of the do-while-loop takes 17.86us.
  i = 2000;
  while (1)
  {
    n = PCD_ReadRegister(COMIRQ_REG);  // ComIrqReg[7..0] bits are: Set1 TxIRq RxIRq IdleIRq   HiAlertIRq LoAlertIRq ErrIRq TimerIRq
    if (n & waitIRq)
    {          // One of the interrupts that signal success has been set.
		serial_putstr("break\r\n");
      break;
    }
 
    if (n & 0x01)
    {           // Timer interrupt - nothing received in 25ms
      serial_putstr("timeout1\r\n");
	  return STATUS_TIMEOUT;
    }
 
    if (--i == 0)
    {           // The emergency break. If all other condions fail we will eventually terminate on this one after 35.7ms. Communication with the MFRC522 might be down.
      serial_putstr("timeout\r\n");
	  return STATUS_TIMEOUT;
    }
  }

  // Stop now if any errors except collisions were detected.
  uint8_t errorRegValue = PCD_ReadRegister(ERROR_REG); // ErrorReg[7..0] bits are: WrErr TempErr reserved BufferOvfl   CollErr CRCErr ParityErr ProtocolErr
  if (errorRegValue & 0x13)
  {  // BufferOvfl ParityErr ProtocolErr
	serial_putstr("error\r\n");
    return STATUS_ERROR;
  }
 
  // If the caller wants data back, get it from the MFRC522.
  if (backData && backLen)
  {
    n = PCD_ReadRegister(FIFO_LVL_REG);           // Number of bytes in the FIFO
    if (n > *backLen)
    {
		serial_putstr("no room\r\n");
      return STATUS_NO_ROOM;
    }
 
    *backLen = n;                       // Number of bytes returned
    PCD_ReadRegister2(FIFO_DATA_REG, n, backData, rxAlign);    // Get received data from FIFO
    _validBits = PCD_ReadRegister(ControlReg) & 0x07; // RxLastBits[2:0] indicates the number of valid bits in the last received byte. If this value is 000b, the whole byte is valid.
    if (validBits)
    {
      *validBits = _validBits;
    }
  }
 
  // Tell about collisions
  if (errorRegValue & 0x08)
  { // CollErr
	serial_putstr("collision\r\n");
    return STATUS_COLLISION;
  }
 
  // Perform CRC_A validation if requested.
  if (backData && backLen && checkCRC)
  {
    // In this case a MIFARE Classic NAK is not OK.
    if ((*backLen == 1) && (_validBits == 4))
    {
		serial_putstr("mifare\r\n");
      return STATUS_MIFARE_NACK;
    }
 
    // We need at least the CRC_A value and all 8 bits of the last byte must be received.
    if ((*backLen < 2) || (_validBits != 0))
    {
		serial_putstr("wrong");
      return STATUS_CRC_WRONG;
    }
 
    // Verify CRC_A - do our own calculation and store the control in controlBuffer.
    uint8_t controlBuffer[2];
    n = PCD_CalculateCRC(&backData[0], *backLen - 2, &controlBuffer[0]);
    if (n != STATUS_OK)
    {
		serial_putstr("not not ok\r\n");
      return n;
    }
 
    if ((backData[*backLen - 2] != controlBuffer[0]) || (backData[*backLen - 1] != controlBuffer[1]))
    {
		serial_putstr("wrong wrong\r\n");
      return STATUS_CRC_WRONG;
    }
  }
 
  return STATUS_OK;
} // End PCD_CommunicateWithPICC()

/**
 * Executes the Transceive command.
 * CRC validation can only be done if backData and backLen are specified.
 */
uint8_t PCD_TransceiveData(uint8_t *sendData,uint8_t sendLen,uint8_t *backData,uint8_t *backLen,uint8_t *validBits,uint8_t rxAlign,int    checkCRC)
{
	uint8_t waitIRq = (COMIRQ_REG >> 5) && (COMIRQ_REG >> 4);    // RxIRq and IdleIRq
															//RxIRq a received data stream ends
															//IdleIRq a command execution finishes
	serial_putnbr((int)waitIRq);
	return PCD_CommunicateWithPICC(PCD_Transceive, waitIRq, sendData, sendLen, backData, backLen, validBits, rxAlign, checkCRC);
} // End PCD_TransceiveData()

/**
 * Clears the bits given in mask from register reg.
 */
void PCD_ClrRegisterBits(uint8_t reg, uint8_t mask)
{
  uint8_t tmp = PCD_ReadRegister(reg);
  PCD_WriteRegister(reg, tmp & (~mask));    // clear bit mask
} // End PCD_ClearRegisterBitMask()

/*
 * Transmits REQA or WUPA commands.
 * Beware: When two PICCs are in the field at the same time I often get STATUS_TIMEOUT - probably due do bad antenna design.
 */
uint8_t card_request_wakeup(uint8_t command, uint8_t *bufferATQA, uint8_t *bufferSize)
{
  uint8_t validBits;
  uint8_t status;
 

  if (bufferATQA == NULL || *bufferSize < 2)
  {  // The ATQA response is 2 bytes long.
    return STATUS_NO_ROOM;
  }
 
  // ValuesAfterColl=1 => Bits received after collision are cleared.
  PCD_ClrRegisterBits(CollReg, 0x80);
 
  // For REQA and WUPA we need the short frame format
  // - transmit only 7 bits of the last (and only) byte. TxLastBits = BitFramingReg[2..0]
	validBits = 7;
 
 	status = PCD_TransceiveData(&command, 1, bufferATQA, bufferSize, &validBits, 0, 0);
	if (status != STATUS_OK)
	{
		serial_putstr("not ok\r\n");
		return status;
	}
 
	if ((*bufferSize != 2) || (validBits != 0))
	{   // ATQA must be exactly 16 bits.
		serial_putstr("error\r\n");
    	return STATUS_ERROR;
	}
	serial_putstr("cc\r\n");
	return STATUS_OK;
} // End PICC_REQA_or_WUPA(

/*
 * Transmits a REQuest command, Type A. Invites PICCs in state IDLE to go to READY and prepare for anticollision or selection. 7 bit frame.
 * Beware: When two PICCs are in the field at the same time I often get STATUS_TIMEOUT - probably due do bad antenna design.
 */
uint8_t card_id_request(uint8_t *bufferATQA, uint8_t *bufferSize)
{
  return card_request_wakeup(PICC_CMD_REQA, bufferATQA, bufferSize);
} // End PICC_RequestA()

/*
 * Returns true if a PICC responds to PICC_CMD_REQA.
 * Only "new" cards in state IDLE are invited. Sleeping cards in state HALT are ignored.
 */
int card_check(void)
{
  uint8_t bufferATQA[2];
  uint8_t bufferSize = sizeof(bufferATQA);
  uint8_t result = card_id_request(bufferATQA, &bufferSize);
  return ((result == STATUS_OK) || (result == STATUS_COLLISION));
} // End PICC_IsNewCardPresent()

int main()
{
	serial_init();
	initSPI(1);
	PCD_Init();
	serial_putstr("Init made\r\n");
	for (;;)	
	{
		if(card_check())
			serial_putstr("coucou");
	}
	return (0);
}