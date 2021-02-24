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
    }
	return bit
}

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
    if (RFID_RST >= 0)
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
    if (RFID_MISO >= 0)
    {
        ft_pin_mode(RFID_MISO,FT_INPUT);
    }
    if (RFID_RST >= 0)
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

int main()
{
	initSPI(1);
	PCD_Init();
	for (;;)	
	{
	}
	return (0);
}