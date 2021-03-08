#include "../../inc/mdma.h"

uint16_t color565(uint8_t red, uint8_t green, uint8_t blue)
{
    return ((red & 0xF8) << 8) | ((green & 0xFC) << 3) | (blue >> 3);
}

void writeColor(uint16_t color, uint32_t len, uint8_t delay)
{
    uint8_t hi = color >> 8, lo = color;
    while (len--)
    {
        AVR_WRITESPI(hi);
        AVR_WRITESPI(lo);
    }
}

void writePixel(int16_t x, int16_t y, uint16_t color, uint8_t delay)
{
    if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
    {
        setAddrWindow(x, y, 1, 1, delay);
        SPI_WRITE16(color, delay);
    }
}

void writeLine(int16_t x0, int16_t y0, int16_t x1, int16_t y1, uint16_t color, uint8_t delay)
{
    int16_t steep = abs(y1 - y0) > abs(x1 - x0);

    if (steep)
    {
        _swap_int16_t(x0, y0);
        _swap_int16_t(x1, y1);
    }

    if (x0 > x1)
    {
        _swap_int16_t(x0, x1);
        _swap_int16_t(y0, y1);
    }

    int16_t dx, dy;
    dx = x1 - x0;
    dy = abs(y1 - y0);

    int16_t err = dx / 2;
    int16_t ystep;

    if (y0 < y1)
        ystep = 1;
    else
        ystep = -1;
    for (; x0 <= x1; x0++)
    {
        if (steep)
            writePixel(y0, x0, color, delay);
        else
            writePixel(x0, y0, color, delay);
        err -= dy;
        if (err < 0)
        {
            y0 += ystep;
            err += dx;
        }
    }
}

void drawFastVLine(int16_t x, int16_t y, int16_t h, uint16_t color, uint8_t delay)
{
    spi_begin_transaction();
    writeLine(x, y, x, y + h - 1, color, delay);
    spi_end_transaction();
}

void drawFastHLine(int16_t x, int16_t y, int16_t w, uint16_t color, uint8_t delay)
{
    spi_begin_transaction();
    writeLine(x, y, x + w - 1, y, color, delay);
    spi_end_transaction();
}

void fillCircleHelper(int16_t x0, int16_t y0, int16_t r, uint8_t corners, int16_t delta, uint16_t color, uint8_t delay)
{

    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;
    int16_t px = x;
    int16_t py = y;

    delta++; // Avoid some +1's in the loop

    while (x < y)
    {
        if (f >= 0)
        {
            y--;
            ddF_y += 2;
            f += ddF_y;
        }
        x++;
        ddF_x += 2;
        f += ddF_x;
        // These checks avoid double-drawing certain lines, important
        // for the SSD1306 library which has an INVERT drawing mode.
        if (x < (y + 1))
        {
            if (corners & 1)
                drawFastVLine(x0 + x, y0 - y, 2 * y + delta, color, delay);
            if (corners & 2)
                drawFastVLine(x0 - x, y0 - y, 2 * y + delta, color, delay);
        }
        if (y != py)
        {
            if (corners & 1)
                drawFastVLine(x0 + py, y0 - px, 2 * px + delta, color, delay);
            if (corners & 2)
                drawFastVLine(x0 - py, y0 - px, 2 * px + delta, color, delay);
            py = y;
        }
        px = x;
    }
}