#ifndef ILI9341_H
# define ILI9341_H

# include <avr/io.h>
#include <avr/pgmspace.h>
#include "./ili9341command.h"
#include "./ili9341_font.h"

#define ILI9341_TFTWIDTH 240  ///< ILI9341 max TFT width
#define ILI9341_TFTHEIGHT 320 ///< ILI9341 max TFT height

// It's gonna change but here the port number on the MEGA 2560 PRO we connected to the LCD Screen
#define TFT_DC 46
#define TFT_CS 53
#define TFT_RST 48
#define TFT_MOSI 51
#define TFT_CLK 52
#define TFT_MISO 50

// Color definitions, stollen like most of the actual code from adafruit lol
#define ILI9341_BLACK 0x0000       ///<   0,   0,   0
#define ILI9341_NAVY 0x000F        ///<   0,   0, 123
#define ILI9341_DARKGREEN 0x03E0   ///<   0, 125,   0
#define ILI9341_DARKCYAN 0x03EF    ///<   0, 125, 123
#define ILI9341_MAROON 0x7800      ///< 123,   0,   0
#define ILI9341_PURPLE 0x780F      ///< 123,   0, 123
#define ILI9341_OLIVE 0x7BE0       ///< 123, 125,   0
#define ILI9341_LIGHTGREY 0xC618   ///< 198, 195, 198
#define ILI9341_DARKGREY 0x7BEF    ///< 123, 125, 123
#define ILI9341_BLUE 0x001F        ///<   0,   0, 255
#define ILI9341_GREEN 0x07E0       ///<   0, 255,   0
#define ILI9341_CYAN 0x07FF        ///<   0, 255, 255
#define ILI9341_RED 0xF800         ///< 255,   0,   0
#define ILI9341_MAGENTA 0xF81F     ///< 255,   0, 255
#define ILI9341_YELLOW 0xFFE0      ///< 255, 255,   0
#define ILI9341_WHITE 0xFFFF       ///< 255, 255, 255
#define ILI9341_ORANGE 0xFD20      ///< 255, 165,   0
#define ILI9341_GREENYELLOW 0xAFE5 ///< 173, 255,  41
#define ILI9341_PINK 0xFC18

#define _swap_int16_t(a, b) \
    {                       \
        int16_t t = a;      \
        a = b;              \
        b = t;              \
    }

typedef uint32_t ADAGFX_PORT_t;
typedef volatile ADAGFX_PORT_t *PORTreg_t;

volatile uint8_t *portSPI;
int16_t cursor_x;
int16_t cursor_y;
uint16_t textcolor;
uint16_t textbgcolor;
uint8_t textsize_x;   ///< Desired magnification in X-axis of text to print()
uint8_t textsize_y;
uint8_t cp437;
uint8_t wrap;

/* 
** Okay here is all commands that we are going to feed our ILI9341 LCD Screen.
** The Datasheet is a pain in the ass to understand and even have some errors according to Adafruit itself.
** Like David said on an Arduino forum : "All the same,   a datasheet with errors is MUCH better than no datasheet at all."
** Thanks David.
** Let's trust Adafruit about that and even if there are two commands undocumented, we should follow there wisdomness.
** //https://forums.adafruit.com/viewtopic.php?f=47&t=63229
*/


void ili9341_begin(void);
void ili9341_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
void spiWrite(uint8_t b);
void ili9341_setCursor(int16_t x, int16_t y);
void ili9341_setTextColor(uint16_t c);
void ili9341_setTextSize(uint8_t s);
void write(uint8_t c);
void ili9341_println(char *str);
void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h);
void SPI_WRITE16(uint16_t w);

#endif