#include "../../inc/mdma.h"

void ili9341_drawLine(uint16_t x1, uint16_t y1, uint16_t x2, uint16_t y2, uint16_t color, uint8_t delay)
{
    if (x1 == x2)
    {
        if (y1 > y2)
            _swap_int16_t(y1, y2);
        writeLine(x1, y1, x1, y2, color, delay);
    }
    else if (y1 == y2)
    {
        if (x1 > x2)
            _swap_int16_t(x1, x2);
        writeLine(x1, y1, x2, y1, color, delay);
    }
    else
    {
        SPI_BEGIN_TRANSACTION();
        if (TFT_CS >= 0)
            ft_digital_write(TFT_CS, FT_LOW);
        writeLine(x1, y1, x2, y2, color, delay);
        if (TFT_CS >= 0)
            ft_digital_write(TFT_CS, FT_HIGH);
    }
}

void ili9341_drawfillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color, uint8_t delay)
{
    if (w && h)
    {
        if (w < 0)
        {
            x += w + 1;
            w = -w;
        }
        if (x < width)
        {
            if (h < 0)
            {
                y += h + 1;
                h = -h;
            }
            if (y < height)
            {
                int16_t x2 = x + w - 1;
                if (x2 >= 0)
                {
                    int16_t y2 = y + h - 1;
                    if (y2 >= 0)
                    {
                        if (x < 0)
                        {
                            x = 0;
                            w = x2 + 1;
                        }
                        if (y < 0)
                        {
                            y = 0;
                            h = y2 + 1;
                        }
                        if (x2 >= width)
                            w = width - x;
                        if (y2 >= height)
                            h = height - y;
                        if (TFT_CS >= 0)
                            *portSPI &= ~(1 << 0);
                        setAddrWindow(x, y, w, h, delay);
                        writeColor(color, (uint32_t)w * h, delay);
                        if (TFT_CS >= 0)
                            *portSPI |= (1 << 0);
                    }
                }
            }
        }
    }
}

void ili9341_drawRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    SPI_BEGIN_TRANSACTION();
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_LOW);
    drawFastHLine(x, y, w, color, 0);
    drawFastHLine(x, y + h - 1, w, color, 0);
    drawFastVLine(x, y, h, color, 0);
    drawFastVLine(x + w - 1, y, h, color, 0);
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_HIGH);
}

void ili9341_drawfillCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color, uint8_t delay)
{
    SPI_BEGIN_TRANSACTION();
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_LOW);
    drawFastVLine(x0, y0 - r, 2 * r + 1, color, delay);
    fillCircleHelper(x0, y0, r, 3, 0, color, delay);
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_HIGH);
}

void ili9341_drawCircle(int16_t x0, int16_t y0, int16_t r, uint16_t color, uint8_t delay)
{
    int16_t f = 1 - r;
    int16_t ddF_x = 1;
    int16_t ddF_y = -2 * r;
    int16_t x = 0;
    int16_t y = r;

    SPI_BEGIN_TRANSACTION();
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_LOW);
    writePixel(x0, y0 + r, color, delay);
    writePixel(x0, y0 - r, color, delay);
    writePixel(x0 + r, y0, color, delay);
    writePixel(x0 - r, y0, color, delay);

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

        writePixel(x0 + x, y0 + y, color, delay);
        writePixel(x0 - x, y0 + y, color, delay);
        writePixel(x0 + x, y0 - y, color, delay);
        writePixel(x0 - x, y0 - y, color, delay);
        writePixel(x0 + y, y0 + x, color, delay);
        writePixel(x0 - y, y0 + x, color, delay);
        writePixel(x0 + y, y0 - x, color, delay);
        writePixel(x0 - y, y0 - x, color, delay);
    }
    if (TFT_CS >= 0)
        ft_digital_write(TFT_CS, FT_HIGH);
}

void ili9341_drawTriangle(int16_t x0, int16_t y0, int16_t x1, int16_t y1, int16_t x2, int16_t y2, uint16_t color)
{
    ili9341_drawLine(x0, y0, x1, y1, color, 0);
    ili9341_drawLine(x1, y1, x2, y2, color, 0);
    ili9341_drawLine(x2, y2, x0, y0, color, 0);
}

void ili9341_fillScreen(uint16_t color)
{
    ili9341_drawfillRect(0, 0, width, height, color, 0);
}