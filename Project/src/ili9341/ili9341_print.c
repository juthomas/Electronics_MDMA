#include "ili9341.h"

#define MISO_WRITE 37

void writeCommand(uint8_t cmd)
{
    ft_digital_write(TFT_DC,FT_LOW);
    spiWrite(cmd);
    ft_digital_write(TFT_DC,FT_HIGH);
}

void SPI_WRITE16(uint16_t w)
{
    for (uint8_t bit = 0; bit < 16; bit++)
    {
        if (w & 0x8000)
            ft_digital_write(TFT_MOSI,FT_HIGH);
        else
            ft_digital_write(TFT_MOSI,FT_LOW);
        ft_digital_write(TFT_CLK,FT_HIGH);
        ft_digital_write(TFT_CLK,FT_LOW);
        w <<= 1;
    }
}

void writeColor(uint16_t color, uint32_t len)
{

    uint8_t hi = color >> 8, lo = color;
    while (len--)
    {
        for (uint8_t bit = 0, x = hi; bit < 8; bit++)
        {
            if (x & 0x80)
                *portSPI |= (1 << 2);
            else
                *portSPI &= ~(1 << 2);
            *portSPI |= (1 << 1);
            *portSPI &= ~(1 << 1);
            x <<= 1;
        }
        for (uint8_t bit = 0, x = lo; bit < 8; bit++)
        {
            if (x & 0x80)
                *portSPI |= (1 << 2);
            else
                *portSPI &= ~(1 << 2);
            *portSPI |= (1 << 1);
            *portSPI &= ~(1 << 1);
            x <<= 1;
        }
    }
}

void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h)
{
    uint16_t x2 = (x1 + w - 1), y2 = (y1 + h - 1);
    writeCommand(ILI9341_CMD_PAGE_ADDRESS_SET); // Column address set
    SPI_WRITE16(x1);
    SPI_WRITE16(x2);
    writeCommand(ILI9341_CMD_PAGE_ADDRESS_SET); // Row address set
    SPI_WRITE16(y1);
    SPI_WRITE16(y2);
    writeCommand(ILI9341_CMD_MEMORY_WRITE); // Write to RAM
}

void ili9341_fillRect(int16_t x, int16_t y, int16_t w, int16_t h, uint16_t color)
{
    if (w && h)
    {
        if (w < 0)
        {
            x += w + 1;
            w = -w;
        }
        if (x < ILI9341_TFTWIDTH)
        {
            if (h < 0)
            {
                y += h + 1;
                h = -h;
            }
            if (y < ILI9341_TFTHEIGHT)
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
                        if (x2 >= ILI9341_TFTWIDTH)
                            w = ILI9341_TFTWIDTH - x;
                        if (y2 >= ILI9341_TFTHEIGHT)
                            h = ILI9341_TFTHEIGHT - y;
                        if (TFT_CS >= 0)
                            ft_digital_write(TFT_CS,FT_LOW);
                        setAddrWindow(x, y, w, h);
                        writeColor(color, (uint32_t)w * h);
                        if (TFT_CS >= 0)
                            ft_digital_write(TFT_CS,FT_HIGH);
                    }
                }
            }
        }
    }
}