#ifndef ILI9341_H
# define ILI9341_H

# include <avr/io.h>
#include <avr/pgmspace.h>
#include "./ili9341command.h"
#include "./ili9341_font.h"

#define ILI9341_TFTWIDTH 240
#define ILI9341_TFTHEIGHT 320

#define TFT_DC 46
#define TFT_CS 53
#define TFT_RST 48
#define TFT_MOSI 51
#define TFT_CLK 52
#define TFT_MISO 50

#ifndef _BV(bit)
#define _BV(bit) (1<<(bit))
#endif

#define AVR_WRITESPI(x) for (SPDR = (x); (!(SPSR & _BV(SPIF)));)
#define abs(x) ((x) < 0 ? -(x) : (x))
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))
#define MAX(X, Y) (((X) > (Y)) ? (X) : (Y))
#define MISO_WRITE 37
#define _swap_int16_t(a, b) \
    {                       \
        int16_t t = a;      \
        a = b;              \
        b = t;              \
    }

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
volatile uint8_t *portPINL;

uint8_t spcr;
uint8_t spsr;

int16_t cursor_x;
int16_t cursor_y;
uint16_t textcolor;
uint16_t textbgcolor;
uint8_t textsize_x;   ///< Desired magnification in X-axis of text to print()
uint8_t textsize_y;
uint8_t cp437;
uint8_t wrap;

uint8_t rotation;

int16_t width;       ///< Display width as modified by current rotation
int16_t height;


void    ili9341_begin(void);
void    ili9341_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, uint8_t delay);
void    spiWrite(uint8_t b);
void    ili9341_setCursor(int16_t x, int16_t y);
void    ili9341_setTextColor(uint16_t c);
void    ili9341_setTextSize(uint8_t s);
void    write(uint8_t c, int16_t color, uint8_t size, uint8_t delay);
void    ili9341_println(char *str, int16_t color, uint8_t size, uint8_t delay);
void    ili9341_print(char *str, int16_t color, uint8_t size, uint8_t delay);
void    setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint8_t delay);
void    SPI_WRITE16(uint16_t w, uint8_t delay);
void    ili9341_setRotation(uint8_t m);
void    ili9341_fillScreen(uint16_t color);
void    writePixel(int16_t x, int16_t y, uint16_t color, uint8_t delay);
void    ili9341_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, uint8_t delay);
void    spi_begin_transaction(void);
void    spi_end_transaction(void);
void    ili9341_drawfillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color, uint8_t delay);
void    writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color, uint8_t delay);
void    ili9341_drawfillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, uint8_t delay);
void    ili9341_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color);
uint16_t color565(uint8_t red, uint8_t green, uint8_t blue);
void    graphic_test(void);
void	ili9341_putnbr(int8_t n, int16_t color, uint8_t size, uint8_t delay);
void	ili9341_putnbrln(int8_t n, int16_t color, uint8_t size, uint8_t delay);

void    ili9341_draw_256IMG(const uint16_t *bitmap, int16_t x, int16_t y, int16_t width, int16_t height, int16_t scale);
void    writeColor(uint16_t color, uint32_t len, uint8_t delay);
void    ili9341_putnbr_base(int32_t nbr, char *base, int16_t color, uint8_t size, uint8_t delay);
void    ili9341_putnbr_baseln(int32_t nbr, char *base, int16_t color, uint8_t size, uint8_t delay);
#endif