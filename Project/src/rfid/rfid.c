#include <mdma.h>
#include <string.h>
#include <avr/io.h>

unsigned char main_buf[9];
unsigned char DefaultKey[6] = {0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF};
unsigned char Uid[4] = {0xFF, 0xFF, 0xFF, 0xFF};

//--------------------------------------------------
/*PCD REGISTER SET*/
//--------------------------------------------------

void PCD_WriteRegister(unsigned char reg, unsigned char value)
{
  SPCR = 0b1010000;
  SPSR = 0;
  ft_digital_write(RFID_CS, FT_LOW); // Select slave
  SPDR = reg;                        // MSB == 0 is for writing. LSB is not used in address. Datasheet section 8.1.2.3.
  while (!(SPSR & (1 << SPIF)))
    ;
  SPDR = value;
  while (!(SPSR & (1 << SPIF)))
    ;
  ft_digital_write(RFID_CS, FT_HIGH); // Release slave again
}

unsigned char PCD_ReadRegister(unsigned char reg)
{
  unsigned char value;

  SPCR = 0b1010000;
  SPSR = 0;
  ft_digital_write(RFID_CS, FT_LOW); // Select slave
  SPDR = (0x80 | reg);
  while (!(SPSR & (1 << SPIF)))
    ;       // MSB == 1 is for reading. LSB is not used in address. Datasheet section 8.1.2.3.
  SPDR = 0; // Read the value back. Send 0 to stop reading.
  while (!(SPSR & (1 << SPIF)))
    ;
  value = SPDR;
  ft_digital_write(RFID_CS, FT_HIGH); // Release slave again
  return (value);
}

void PCD_ClrRegisterBits(unsigned char reg, unsigned char mask)
{
  unsigned char tmp = PCD_ReadRegister(reg);
  PCD_WriteRegister(reg, tmp & (~mask)); // clear  choosen bits
}

void PCD_SetRegisterBits(unsigned char reg, unsigned char mask)
{
  unsigned char tmp = PCD_ReadRegister(reg);
  PCD_WriteRegister(reg, tmp | mask); // set choosen bits
}

unsigned char PCD_CommunicateWithPICC(unsigned char command,
                                      unsigned char *sendData,
                                      unsigned char sendLen,
                                      unsigned char *backData,
                                      unsigned char *backLen,
                                      unsigned char *validBits,
                                      unsigned char rxAlign)
{
  unsigned char status;
  unsigned char waitFor = 0x30;
  unsigned char lastBits;
  unsigned char n;
  int i;

  if (command == PCD_MFAuthent)
    waitFor = 0x10;
  unsigned char bitFraming = (rxAlign << 4) + *validBits;
  PCD_WriteRegister(CommandReg, PCD_Idle); // Stop any active command.
  PCD_WriteRegister(CommIRqReg, 0x7F);
  PCD_WriteRegister(FIFOLevelReg, 0x80);
  for (i = 0; i < sendLen; i++)
  {
    PCD_WriteRegister(FIFODataReg, sendData[i]);
  }                                             // FlushBuffer = 1, FIFO initialization
  PCD_WriteRegister(BitFramingReg, bitFraming); // Bit adjustments
  PCD_WriteRegister(CommandReg, command);

  if (command == PCD_Transceive)
    PCD_SetRegisterBits(BitFramingReg, 0x80); // StartSend=1, transmission of data starts

  for (i = 2000; i > 0; i--)
  {
    n = PCD_ReadRegister(CommIRqReg); // ComIrqReg[7..0] bits are: Set1 TxIRq RxIRq IdleIRq HiAlertIRq LoAlertIRq ErrIRq TimerIRq
    if (n & waitFor)
    { // One of the interrupts that signal success has been set.
      break;
    }
    if (n & 0x01)
    { // Timer interrupt - nothing received in 25ms
      break;
    }
  }
  if (i == 0)
    ft_digital_write(13, FT_HIGH);

  PCD_ClrRegisterBits(BitFramingReg, 0x80);
  status = STATUS_ERROR;
  if (n & 0x01)
    status = STATUS_TIMEOUT;
  else
  {
    if (!(PCD_ReadRegister(ErrorReg) & 0x1B))
    {
      status = STATUS_OK;
      n = PCD_ReadRegister(FIFOLevelReg);
      lastBits = PCD_ReadRegister(ControlReg) & 0x07;
      if (lastBits)
        *backLen = (n - 1) * 8 + lastBits;
      else
        *backLen = n * 8;
      if (n > 18)
        n = 18;
      if (n > 0)
      {
        for (i = 0; i < n; i++)
          backData[i] = PCD_ReadRegister(FIFODataReg);
      }
    }
  }
  PCD_WriteRegister(CommandReg, PCD_Idle);
  return (status);
}

unsigned char PCD_CommunicateWithPICC2(unsigned char command,
                                       unsigned char *sendData,
                                       unsigned char sendLen,
                                       unsigned char *backData,
                                       unsigned char *backLen,
                                       unsigned char *validBits,
                                       unsigned char rxAlign)
{
  unsigned char status;
  unsigned char waitFor = 0x30;
  unsigned char lastBits;
  unsigned char n;
  int i;

  if (command == PCD_MFAuthent)
    waitFor = 0x10;
  unsigned char bitFraming = (rxAlign << 4) + *validBits;
  PCD_WriteRegister(CommandReg, PCD_Idle); // Stop any active command.
  PCD_WriteRegister(CommIRqReg, 0x7F);
  PCD_WriteRegister(FIFOLevelReg, 0x80);
  for (i = 0; i < sendLen; i++)
  {
    PCD_WriteRegister(FIFODataReg, sendData[i]);
  }                                             // FlushBuffer = 1, FIFO initialization
  PCD_WriteRegister(BitFramingReg, bitFraming); // Bit adjustments
  PCD_WriteRegister(CommandReg, command);

  if (command == PCD_Transceive)
    PCD_SetRegisterBits(BitFramingReg, 0x80); // StartSend=1, transmission of data starts

  for (i = 2000; i > 0; i--)
  {
    n = PCD_ReadRegister(CommIRqReg); // ComIrqReg[7..0] bits are: Set1 TxIRq RxIRq IdleIRq HiAlertIRq LoAlertIRq ErrIRq TimerIRq
    if (n & waitFor)
    { // One of the interrupts that signal success has been set.
      break;
    }
    if (n & 0x01)
    { // Timer interrupt - nothing received in 25ms
      break;
    }
  }
  //if(i == 0)
  //Serial.println("ERROR");

  PCD_ClrRegisterBits(BitFramingReg, 0x80);
  status = STATUS_ERROR;
  if (n & 0x01)
    status = STATUS_TIMEOUT;
  else
  {
    if (!(PCD_ReadRegister(ErrorReg) & 0x1B))
    {
      status = STATUS_OK;
      n = PCD_ReadRegister(FIFOLevelReg);
      lastBits = PCD_ReadRegister(ControlReg) & 0x07;
      if (validBits)
        *validBits = lastBits;
      if (n > 18)
        n = 18;
      *backLen = n;
      if (n > 0)
      {
        for (i = 0; i < n; i++)
          backData[i] = PCD_ReadRegister(FIFODataReg);
      }
    }
  }
  PCD_WriteRegister(CommandReg, PCD_Idle);
  return (status);
}

//--------------------------------------------------
/*INIT RFID*/
//--------------------------------------------------

void PCD_AntennaOn()
{
  unsigned char tmp;

  tmp = PCD_ReadRegister(TxControlReg);
  if (!(tmp & 0x03))
  {
    PCD_SetRegisterBits(TxControlReg, 0x03);
  }
}

void PCD_AntennaOff()
{
  PCD_ClrRegisterBits(TxControlReg, 0x03);
}

void PCD_Tinit()
{
  // When communicating with a PICC we need a timeout if something goes wrong.
  // f_timer = 13.56 MHz / (2*TPreScaler+1) where TPreScaler = [TPrescaler_Hi:TPrescaler_Lo].
  // TPrescaler_Hi are the four low bits in TModeReg. TPrescaler_Lo is TPrescalerReg.

  PCD_WriteRegister(TModeReg, 0x80);      //0x80 = 10000000 TAuto=1; timer starts automatically at the end of the transmission in all communication modes at all speeds
  PCD_WriteRegister(TPrescalerReg, 0xA9); // 0xa9 = 10101001 = 169 TPreScaler = TModeReg[3..0]:TPrescalerReg, ie 0x0A9 = 169 => f_timer=40kHz, ie a timer period of 25us.
  PCD_WriteRegister(TReloadRegH, 0x03);   // Reload timer with 0x3E8 = 1000, ie 25ms before timeout.

  PCD_WriteRegister(TReloadRegL, 0xE8);

  PCD_WriteRegister(TxASKReg, 0x40); //  Default 0x00. Force a 100 % ASK modulation independent of the ModGsPReg register setting

  PCD_WriteRegister(ModeReg, 0x3D); // Default 0x3F. Set the preset value for the CRC coprocessor for the CalcCRC command to 0x6363 (ISO 14443-3 part 6.2.4)
}

void PCD_Reset()
{
  PCD_WriteRegister(CommandReg, PCD_SoftReset);
  unsigned char count = 0;
  while ((PCD_ReadRegister(CommandReg) & 16) && (++count) < 3)
    custom_delay(50);
}

void PCD_init()
{

  int hardReset = 0;

  ft_pin_mode(RFID_CS, FT_OUTPUT);
  ft_digital_write(RFID_CS, FT_HIGH);

  ft_pin_mode(RFID_RST, FT_INPUT);

  if (ft_digital_read(RFID_RST) == FT_LOW)
  {             
    ft_digital_write(13, FT_HIGH);                         // The MFRC522 chip is in power down mode.
    ft_pin_mode(RFID_RST, FT_OUTPUT);    // Now set the resetPowerDownPin as digital output.
    ft_digital_write(RFID_RST, FT_LOW);  // Make sure we have a clean LOW state.
    custom_delay(1);                     // 8.8.1 Reset timing requirements says about 100ns. Let us be generous: 2μsl
    ft_digital_write(RFID_RST, FT_HIGH); // Exit power down mode. This triggers a hard reset.
    // Section 8.8.2 in the datasheet says the oscillator start-up time is the start up time of the crystal + 37,74μs. Let us be generous: 50ms.
    custom_delay(50);
    hardReset = 1;
  }
  if (!hardReset)
    PCD_Reset();

  // Reset baud rates
  PCD_WriteRegister(TxModeReg, 0x00);
  PCD_WriteRegister(RxModeReg, 0x00);
  // Reset ModWidthReg
  PCD_WriteRegister(ModWidthReg, 0x26);

  PCD_Tinit();
  PCD_AntennaOn();
}

void SPI_init(uint32_t freq)
{
  if (ft_digital_read(RFID_RST) >= 0)
  {
    ft_pin_mode(RFID_RST, FT_OUTPUT);
    ft_digital_write(RFID_RST, FT_HIGH);
  }
  //ft_pin_mode(RFID_DC,FT_OUTPUT);
  // ft_digital_write(RFID_DC,FT_HIGH);

  cli();
  ft_pin_mode(RFID_MOSI, FT_OUTPUT);
  ft_digital_write(RFID_MOSI, FT_LOW);
  ft_pin_mode(CLK, FT_OUTPUT);
  ft_digital_write(CLK, FT_LOW);
  sei();

  if (ft_digital_read(RFID_MISO) >= 0)
  {
    ft_pin_mode(RFID_MISO, FT_INPUT);
  }
  if (ft_digital_read(RFID_RST) >= 0)
  {
    ft_pin_mode(RFID_RST, FT_OUTPUT);
    ft_digital_write(RFID_RST, FT_HIGH);
    custom_delay(100);
    ft_digital_write(RFID_RST, FT_LOW);
    custom_delay(100);
    ft_digital_write(RFID_RST, FT_HIGH);
    custom_delay(200);
  }
}

void init_rfid()
{
  //serial_init();
  //initSPI();
  PCD_init();
  //ft_digital_write(13, FT_HIGH);
}

unsigned char PCD_CalculateCRC(unsigned char *data,  ///< In: Pointer to the data to transfer to the FIFO for CRC calculation.
                               unsigned char length, ///< In: The number of unsigned chars to transfer.
                               unsigned char *result ///< Out: Pointer to result buffer. Result is written to result[0..1], low unsigned char first.
)
{
  unsigned char i;

  PCD_WriteRegister(CommandReg, PCD_Idle); // Stop any active command.
  PCD_WriteRegister(DivIrqReg, 0x04);      // Clear the CRCIRq interrupt request bit
  PCD_WriteRegister(FIFOLevelReg, 0x80);   // FlushBuffer = 1, FIFO initialization
  for (i = 0; i < length; i++)
  {
    PCD_WriteRegister(FIFODataReg, data[i]);
  }
  PCD_WriteRegister(CommandReg, PCD_CalcCRC); // Start the calculation

  // Wait for the CRC calculation to complete. Each iteration of the while-loop takes 17.73μs.
  // TODO check/modify for other architectures than Arduino Uno 16bit

  // Wait for the CRC calculation to complete. Each iteration of the while-loop takes 17.73us.
  for (uint16_t i = 5000; i > 0; i--)
  {
    // DivIrqReg[7..0] bits are: Set2 reserved reserved MfinActIRq reserved CRCIRq reserved reserved
    unsigned char n = PCD_ReadRegister(DivIrqReg);
    if (n & 0x04)
    {                                          // CRCIRq bit set - calculation done
      PCD_WriteRegister(CommandReg, PCD_Idle); // Stop calculating CRC for new content in the FIFO.
      // Transfer the result from the registers to the result buffer
      result[0] = PCD_ReadRegister(CRCResultRegL);
      result[1] = PCD_ReadRegister(CRCResultRegH);
      return STATUS_OK;
    }
  }
  // 89ms passed and nothing happend. Communication with the MFRC522 might be down.
  return STATUS_TIMEOUT;
}

//--------------------------------------------------
/*PCD REGISTER SET*/
//--------------------------------------------------

unsigned char PcdAnticoll(unsigned char *main_buf)
{
  unsigned char status;

  //unsigned char buffer[9];					// The SELECT/ANTICOLLISION commands uses a 7 unsigned char standard frame + 2 unsigned chars CRC_A
  main_buf[0] = PICC_CMD_SEL_CL1;

  unsigned char rxAlign = 0;
  unsigned char txLastBits = 0;
  unsigned char index = 2;    // Number of whole unsigned chars: SEL + NVB + UIDs
  main_buf[1] = (index << 4); // NVB - Number of Valid Bits
  unsigned char bufferUsed = index;
  // Store response in the unused part of buffer
  unsigned char responseLen = 7;
  status = PCD_CommunicateWithPICC(PCD_Transceive, main_buf, bufferUsed, &main_buf[index], &responseLen, &txLastBits, rxAlign);

  //here maybe coll choose
  PCD_SetRegisterBits(CollReg, 0x80);
  return (status == STATUS_OK);
}

unsigned char PcdRequest(unsigned char *pTagType)
{
  unsigned char status;
  unsigned char unLen;
  unsigned char buf[18];

  PCD_ClrRegisterBits(CollReg, 0x80);
  buf[0] = PICC_CMD_REQA;

  unsigned char rxAlign = 0;
  unsigned char txLastBits = 7;

  status = PCD_CommunicateWithPICC(PCD_Transceive, buf, 1, buf, &unLen, &txLastBits, rxAlign);

  if ((status == STATUS_OK) && (unLen == 0x10))
  {
    *pTagType = buf[0];
    *(pTagType + 1) = buf[1];
    return 1;
  }
  return 0;
}

unsigned char PcdSelect(unsigned char *main_buf)
{
  unsigned char status;

  main_buf[0] = PICC_CMD_SEL_CL1;
  main_buf[1] = 0x70; // NVB - Number of Valid Bits: Seven whole unsigned chars
                      // Calculate BCC - Block Check Character
  main_buf[6] = main_buf[2] ^ main_buf[3] ^ main_buf[4] ^ main_buf[5];
  // Calculate CRC_A
  status = PCD_CalculateCRC(main_buf, 7, &main_buf[7]);
  if (status != STATUS_OK)
  {
    serial_putstr("crc not good");
    return status;
  }
  unsigned char txLastBits = 0; // 0 => All 8 bits are valid.
  unsigned char bufferUsed = 9;
  // Store response in the last 3 unsigned chars of buffer (BCC and CRC_A - not needed after tx)
  unsigned char *responseBuffer;
  responseBuffer = &main_buf[6];
  unsigned char responseLen = 3;

  //PCD_ClrRegisterBits(CollReg, 0x80);
  //PCD_WriteRegister(BitFramingReg, 0);	// RxAlign = BitFramingReg[6..4]. TxLastBits = BitFramingReg[2..0]

  unsigned char rxAlign = 0;
  status = PCD_CommunicateWithPICC(PCD_Transceive, main_buf, bufferUsed, responseBuffer, &responseLen, &txLastBits, rxAlign);
  unsigned char index = 2;

  if (status == STATUS_OK)
  {
    for (unsigned char count = 0; count < 4; count++)
      Uid[count] = main_buf[index++];
    return 1;
  }
  return 0;
}

unsigned char MifareRead(unsigned char blockAddr, unsigned char *buffer, unsigned char *bufferLen)
{
  unsigned char status;

  if (buffer == NULL || *bufferLen < 18)
    return (STATUS_NO_ROOM);

  buffer[0] = PICC_CMD_MF_READ;
  buffer[1] = blockAddr;

  status = PCD_CalculateCRC(buffer, 2, &buffer[2]);
  if (status != STATUS_OK)
    return (status);

  unsigned char rxAlign = 0;
  unsigned char txLastBits = 0;
  status = PCD_CommunicateWithPICC(PCD_Transceive, buffer, 4, buffer, bufferLen, &txLastBits, rxAlign);
  return (status);
}

unsigned char MifareTransceive(unsigned char *sendData, unsigned char sendLen)
{
  unsigned char status;

  unsigned char cmdBuffer[18];
  memcpy(cmdBuffer, sendData, sendLen);
  if (sendData == NULL || sendLen > 16)
    return (STATUS_INVALID);

  status = PCD_CalculateCRC(cmdBuffer, sendLen, &cmdBuffer[sendLen]);
  if (status != STATUS_OK)
    return (status);

  sendLen += 2;
  unsigned char validBits = 0;
  unsigned char rxAlign = 0;
  status = PCD_CommunicateWithPICC2(PCD_Transceive, cmdBuffer, sendLen, cmdBuffer, &sendLen, &validBits, rxAlign);
  if (status == STATUS_TIMEOUT)
    return (STATUS_OK);
  if (status != STATUS_OK)
    return (status);
  // The PICC must reply with a 4 bit ACK
  if (sendLen != 1 || validBits != 4)
  {
    return STATUS_ERROR;
  }
  if (cmdBuffer[0] != 0xA)
  {
    return STATUS_MIFARE_NACK;
  }
  return STATUS_OK;
}

unsigned char MifareWrite(unsigned char blockAddr, unsigned char *buffer, unsigned char bufferLen)
{
  unsigned char status;

  if (buffer == NULL || bufferLen < 16)
    return (STATUS_INVALID);

  unsigned char cmdBuffer[2];
  cmdBuffer[0] = PICC_CMD_MF_WRITE;
  cmdBuffer[1] = blockAddr;
  status = MifareTransceive(cmdBuffer, 2);
  if (status != STATUS_OK)
    return (status);
  status = MifareTransceive(buffer, bufferLen);
  return (status);
}

unsigned char PcdAuthenticate(unsigned char blockAddr)
{

  unsigned char sendData[12];
  sendData[0] = PICC_CMD_MF_AUTH_KEY_A;
  sendData[1] = blockAddr;
  for (unsigned char i = 0; i < 6; i++)
  { // 6 key unsigned chars
    sendData[2 + i] = DefaultKey[i];
  }
  // Use the last uid unsigned chars as specified in http://cache.nxp.com/documents/application_note/AN10927.pdf
  // section 3.2.5 "MIFARE Classic Authentication".
  // The only missed case is the MF1Sxxxx shortcut activation,
  // but it requires cascade tag (CT) unsigned char, that is not part of uid.
  for (unsigned char i = 0; i < 4; i++)
  { // The last 4 unsigned chars of the UID
    sendData[8 + i] = Uid[i];
  }
  unsigned char rxAlign = 0;
  unsigned char txLastBits = 0;

  unsigned char unLen = 4;
  return (PCD_CommunicateWithPICC(PCD_MFAuthent, sendData, 12, sendData, &unLen, &txLastBits, rxAlign));
}

void DumpSector(unsigned char sector)
{
  unsigned char status;
  unsigned char firstBlock;
  unsigned char nbBlocks;
  int isSectorTrailer;
  unsigned char blockIndex;

  nbBlocks = 4;
  firstBlock = sector * 4;

  unsigned char byteCount;
  unsigned char buffer[18];
  unsigned char blockAddr;
  isSectorTrailer = 1;
  blockIndex = nbBlocks - 1;



  while (blockIndex != 255)
  {
    blockAddr = firstBlock + blockIndex;
    byteCount = 18;
    ili9341_putnbrln(blockAddr, ILI9341_WHITE, 1, 0);

    if (isSectorTrailer)
    {
      status = PcdAuthenticate(firstBlock);
      if (status != STATUS_OK)
      {
        ili9341_print("Auth failed\n", ILI9341_WHITE, 1, 0);
        return;
      }

      isSectorTrailer = 0;
    }
    status = MifareRead(blockAddr, buffer, &byteCount);
    if (status != STATUS_OK)
    {
      ili9341_print("write Failed : ", ILI9341_WHITE, 1, 0);
      ili9341_putnbrln(status == STATUS_NO_ROOM, ILI9341_WHITE, 1, 0);

      return;
    }
    ili9341_print(buffer, ILI9341_WHITE, 1, 0);

    // for (unsigned char index = 0; index < 16; index++)
    // {
    //   if (buffer[index] < 0x10)
      
    //      ili9341_print(" 0", ILI9341_WHITE, 1, 0);
    //   else
    //     ili9341_print(" ", ILI9341_WHITE, 1, 0);
    //   //ili9341_putnbr_base(buffer[index],"0123456789ABCDEF", ILI9341_WHITE, 1, 0);
    //   ili9341_print(buffer[index], ILI9341_WHITE, 1, 0);

    //   if ((index % 4) == 3)
    //   {
    //     ili9341_print(" ", ILI9341_WHITE, 1, 0);
    //   }
    // }
   ili9341_putnbrln(blockIndex, ILI9341_WHITE, 1, 0);

    blockIndex--;
  }
  ili9341_print("end sector \n", ILI9341_WHITE, 1, 0);
}

void PcdDump()
{
  unsigned char nb_sectors;

  nb_sectors = 16;
  ili9341_print("UID : ", ILI9341_WHITE, 1, 0);
  char base[16] = {'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F'};
  for (int i = 0; i < 4; i++)
  {
    ili9341_putnbr_base(Uid[i], "012345689ABCDEF", ILI9341_WHITE, 1, 0);
    ili9341_print(",", ILI9341_WHITE, 1, 0);

  }
  ili9341_println("", ILI9341_WHITE, 1, 0);
  //serial_putstr("Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits\n");
  //ili9341_println("Sector Block   0  1  2  3   4  5  6  7   8  9 10 11  12 13 14 15  AccessBits\n", ILI9341_WHITE, 1, 0);
  for (int8_t i = nb_sectors - 1; i >= 0; i--)
  {
    ili9341_print("sector ", ILI9341_WHITE, 1, 0);
    ili9341_putnbr(i, ILI9341_WHITE, 1, 0);
    ili9341_putnbrln(i, ILI9341_WHITE, 1, 0);
    //ili9341_println("", ILI9341_WHITE, 1, 0);
    DumpSector(i);
  }
}

void PICC_WriteData()
{
  unsigned char block;
  unsigned char status;
  unsigned char imager[192];
  unsigned char name[10] = {'P', 'A', 'R', 'T', 'Y', ' ', 'B', 'O', 'Y'};

  int j = -1;

  while (j++ < 192)
  {
      if(j < 10)
        buffer[j] = name[j];
      else
        buffer[j] = 0;
  }
  
  int i;
  i = 0;
  block = 63;
  while (i < 192)
  {
    if ((block + 1) % 4)
    {
      status = MifareWrite(block, &image[i], 16);
      if (status != STATUS_OK)
        return;
      i += 16;
    }
    else
    {
      status = PcdAuthenticate(block);
      if (status != STATUS_OK)
        return;
    }
    block--;
  }
  //ili9341_print("WRITE MADE EHE \n\n", ILI9341_WHITE, 1, 0);
}

int test_rfid()
{

  //init_rfid();
  //ft_digital_write(13, FT_HIGH);
  if (PcdRequest(main_buf))
  {
    if (PcdAnticoll(main_buf))
    {
      if (PcdSelect(main_buf))
      {
        //ft_digital_write(13, FT_HIGH);
        //PICC_WriteData();
        PcdDump();
        return 1;
      }
    }
  }
  return 0;
}
