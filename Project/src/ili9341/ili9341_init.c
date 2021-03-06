# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
//#  define F_CPU 16000000
# endif
#include "../../inc/ili9341.h"
#include <avr/io.h>
#include <util/delay.h>

#define SPI_MODE_MASK 0x0C
#define SPI_CLOCK_MASK 0x03
#define SPI_MODE3 0x0C
#define SPI_MODE2 0x08
#define SPI_2XCLOCK_MASK 0x01
/* 
** Okay here is all commands that we are going to feed our ILI9341 LCD Screen.
** The Datasheet is a pain in the ass to understand and even have some errors according to Adafruit itself.
** Like David said on an Arduino forum : "All the same,   a datasheet with errors is MUCH better than no datasheet at all."
** Thanks David.
** Let's trust Adafruit about that and even if there are two commands undocumented, we should follow there wisdomness.
** //https://forums.adafruit.com/viewtopic.php?f=47&t=63229
*/

// void _delay_ms(uint32_t milli);

static const uint8_t PROGMEM initcmd[] = {
	0xEF, 3, 0x03, 0x80, 0x02,                                                              //Undocumented but necessary
	ILI9341_CMD_POWER_CONTROL_B, 3, 0x00, 0xC1, 0x30,
	0xED, 4, 0x64, 0x03, 0x12, 0x81,                                                        //Undocumented but necessary
	ILI9341_CMD_DRIVER_TIMING_CONTROL_A, 3, 0x85, 0x00, 0x78,
	ILI9341_CMD_POWER_ON_SEQ_CONTROL, 5, 0x39, 0x2C, 0x00, 0x34, 0x02,
	ILI9341_CMD_PUMP_RATIO_CONTROL, 1, 0x20,                                                // Pump Radio Control
	ILI9341_CMD_DRIVER_TIMING_CONTROL_B, 2, 0x00, 0x00,                                     // Driver timing control B
	ILI9341_CMD_POWER_CONTROL_1, 1, 0x23,                                                   // Power control VRH[5:0]
	ILI9341_CMD_POWER_CONTROL_2, 1, 0x10,                                                   // Power control SAP[2:0];BT[3:0]
	ILI9341_CMD_VCOM_CONTROL_1, 2, 0x3e, 0x28,                                              // VCM control
	ILI9341_CMD_VCOM_CONTROL_2, 1, 0x86,                                                    // VCM control2
	ILI9341_CMD_MEMORY_ACCESS_CONTROL, 1, 0x48,                                             // Memory Access Control
	ILI9341_CMD_VERT_SCROLL_START_ADDRESS, 1, 0x00,                                         // Vertical scroll zero
	ILI9341_CMD_COLMOD_PIXEL_FORMAT_SET, 1, 0x55,
	ILI9341_CMD_FRAME_RATE_CONTROL_NORMAL, 2, 0x00, 0x18,
	ILI9341_CMD_DISPLAY_FUNCTION_CONTROL, 3, 0x08, 0x82, 0x27,                              // Display Function Control
	ILI9341_CMD_ENABLE_3_GAMMA_CONTROL, 1, 0x00,                                            // 3Gamma Function Disable
	ILI9341_CMD_GAMMA_SET, 1, 0x01,                                                         // Gamma curve selected
	ILI9341_CMD_POSITIVE_GAMMA_CORRECTION, 15, 0x0F, 0x31, 0x2B, 0x0C, 0x0E, 0x08, 0x4E, 0xF1, 0x37, 0x07, 0x10, 0x03, 0x0E, 0x09, 0x00,
	ILI9341_CMD_NEGATIVE_GAMMA_CORRECTION, 15, 0x00, 0x0E, 0x14, 0x03, 0x11, 0x07, 0x31, 0xC1, 0x48, 0x08, 0x0F, 0x0C, 0x31, 0x36, 0x0F,
	ILI9341_CMD_SLEEP_OUT, 0x80,                                                            // Exit Sleep
	ILI9341_CMD_DISPLAY_ON, 0x80,                                                           // Display on
	0x00                                                                                    // End of list
};

void ili9341_setCursor(int16_t x, int16_t y)
{
	cursor_x = x;
	cursor_y = y;
}

void ili9341_setTextColor(uint16_t c) 
{ 
	textcolor = textbgcolor = c; 
}

void ili9341_setTextSize(uint8_t s) {
  textsize_x = (s > 0) ? s : 1;
  textsize_y = (s > 0) ? s : 1;
}

// Begin and end transation have to be called before each data send in SPI.
// It's like saying "Hey now pay it's my turn to speak bro".

void spi_end_transaction(void)
{
    if (TFT_CS >= 0)
        *portSPI |= (1 << 0);
   // sei();
}

void spi_begin_transaction(void)
{
    //cli();
    if (TFT_CS >= 0)
        *portSPI &= ~(1 << 0);
}

/*
**  To send a command we have to:
**  1. Set the CS pin to LOW.
**  2. Between a LOW/HIGH DC send the command.
**  3. Send The parameters of the command.
**  4. Set the CS pin to HIGH.
*/

void sendCommand(uint8_t commandByte, uint8_t *dataBytes, uint8_t numDataBytes)
{
	spi_begin_transaction();
	//ft_digital_write(TFT_DC,FT_LOW);
	*((volatile uint8_t *)267) &= ~(1 << 3);
	AVR_WRITESPI(commandByte);
	*((volatile uint8_t *)267) |= (1 << 3);
	for (int i = 0; i < numDataBytes; i++)
		AVR_WRITESPI((*dataBytes)++);
	spi_end_transaction();
}

void sendCommand_init(uint8_t commandByte, const uint8_t *dataBytes, uint8_t numDataBytes)
{
	spi_begin_transaction();
	*((volatile uint8_t *)267) &= ~(1 << 3);
	AVR_WRITESPI(commandByte);
	*((volatile uint8_t *)267) |= (1 << 3);
	for (int i = 0; i < numDataBytes; i++)
		AVR_WRITESPI(pgm_read_byte(dataBytes++));
	spi_end_transaction();
}

/*      
**      It's kind of brutal to assign spcr and spsr values like that
**      spcr = _BV(SPE) | _BV(MSTR) | ((bitOrder == LSBFIRST) ? _BV(DORD) : 0) |
**      (dataMode & SPI_MODE_MASK) | ((clockDiv >> 1) & SPI_CLOCK_MASK);
**      spsr = clockDiv & SPI_2XCLOCK_MASK;
**      The only params that worked with our atmega2560 and our LCD screen on the SPI.h library returned 81 for spcr and 1 for spsr
**      The frequency is set at 3000000 for the Hardware SPI communication.
*/

/*
** Il faut que CS soit en OUTPUT avant de set SPCR, sinon il peut declarer le MCU en tant que slave.
*/

void initSPI()
{
	// ft_pin_mode(TFT_CS,FT_OUTPUT);
	DDRB |= 1 << 0;
	// ft_pin_mode(RFID_CS, FT_OUTPUT);
	DDRL |= 1 << 2;
	// ft_digital_write(TFT_CS,FT_HIGH);
	PORTB |= 1 << 0;
	// ft_digital_write(RFID_CS,FT_HIGH);
	PORTL |= 1 << 2;
	// ft_pin_mode(TFT_DC,FT_OUTPUT);
	DDRL |= 1 << 3;
	// ft_digital_write(TFT_DC,FT_HIGH);
	PORTL |= 1 << 3;
    
    uint8_t clockDiv = 3;
    
    // SPE indique qu'on veut le SPI, MSTR que 
    //SPCR = _BV(SPE) | _BV(MSTR) | 0 | (SPI_MODE3 & SPI_MODE_MASK) | ((clockDiv >> 1) & SPI_CLOCK_MASK);;
    SPCR = _BV(SPE) | _BV(MSTR) | (1 << SPR0);
	SPSR = 1;
	// ft_pin_mode(TFT_CS, FT_OUTPUT);
	DDRB |= 1 << 0;
	// ft_pin_mode(RFID_CS, FT_OUTPUT);
	DDRL |= 1 << 2;
	// ft_pin_mode(TFT_CLK, FT_OUTPUT);
	DDRB |= 1 << 1;
	// ft_pin_mode(TFT_MOSI, FT_OUTPUT);
	DDRB |= 1 << 2;
	 //sei();//?


	// ft_pin_mode(TFT_RST,FT_OUTPUT);
	DDRL |= 1 << 1;
	// ft_digital_write(TFT_RST,FT_HIGH);
	PORTL |= 1 << 1;
	_delay_ms(100);
	// ft_digital_write(TFT_RST,FT_LOW);
	PORTL &= !(1 << 1);
	_delay_ms(100);
	// ft_digital_write(TFT_RST,FT_HIGH);
	PORTL |= 1 << 1;
	_delay_ms(200);

}

// void initSPI()
// {
//     spcr = 81;
//     spsr = 1;

//     *((volatile uint8_t *)36) |= (1 << 0);
//     *((volatile uint8_t *)266) |= (1 << 2);
//     *((volatile uint8_t *)37) |= (1 << 0);
//     *((volatile uint8_t *)267) |= (1 << 2);
//     *((volatile uint8_t *)266) |= (1 << 3);
//     *((volatile uint8_t *)267) |= (1 << 3);
//     cli();
//     *((volatile uint8_t *)36) |= (1 << 0);
//     *((volatile uint8_t *)266) |= (1 << 2);
//     *((volatile uint8_t *)36) |= (1 << 1);
//     *((volatile uint8_t *)36) |= (1 << 2);
//     sei();
//     *((volatile uint8_t *)266) |= (1 << 1);

//     _delay_ms(100);
//     *((volatile uint8_t *)267) &= ~(1 << 1);
//     _delay_ms(100);
//     *((volatile uint8_t *)267) |= (1 << 1);
//     _delay_ms(200);
// }

//For vertical display it is 1 and 3.

void ili9341_setRotation(uint8_t m) {
 rotation = m % 4; // can't be higher than 3
  switch (rotation) {
  case 0:
	m = (MADCTL_MX | MADCTL_BGR);
	width = ILI9341_TFTWIDTH;
	height = ILI9341_TFTHEIGHT;
	break;
  case 1:
	m = (MADCTL_MV | MADCTL_BGR);
	width = ILI9341_TFTHEIGHT;
	height = ILI9341_TFTWIDTH;
	break;
  case 2:
	m = (MADCTL_MY | MADCTL_BGR);
	width = ILI9341_TFTWIDTH;
	height = ILI9341_TFTHEIGHT;
	break;
  case 3:
	m = (MADCTL_MX | MADCTL_MY | MADCTL_MV | MADCTL_BGR);
	width = ILI9341_TFTHEIGHT;
	height = ILI9341_TFTWIDTH;
	break;
  }
  sendCommand(0x36, &m, 1);
}

void ili9341_begin()
{
	uint8_t cmd;
	uint8_t x;
	uint8_t numArgs;
	
	wrap = 1;
	cp437 = 0;
	width = ILI9341_TFTWIDTH;
	height = ILI9341_TFTHEIGHT;
	portSPI = 37;
	portPINL = 267;
	const uint8_t *addr = initcmd;
	while ((cmd = pgm_read_byte(addr++)) > 0)
	{
		
		x = pgm_read_byte(addr++);
		numArgs = x & 0x7F;
		sendCommand_init(cmd, addr, numArgs);
		addr += numArgs;
		if (x & 0x80)
			_delay_ms(150);
	}
}