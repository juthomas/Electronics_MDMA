#include "../../inc/mdma.h"

void writeCommand(uint8_t cmd)
{
    ft_digital_write(TFT_DC, FT_LOW);
    AVR_WRITESPI(cmd);
    ft_digital_write(TFT_DC, FT_HIGH);
}

void SPI_WRITE16(uint16_t w, uint8_t delay)
{
    AVR_WRITESPI(w >> 8);
    AVR_WRITESPI(w);
}

void setAddrWindow(uint16_t x1, uint16_t y1, uint16_t w, uint16_t h, uint8_t delay)
{
    uint16_t x2 = (x1 + w - 1), y2 = (y1 + h - 1);
    writeCommand(ILI9341_CMD_COLUMN_ADDRESS_SET); // Column address set
    SPI_WRITE16(x1, delay);
    SPI_WRITE16(x2, delay);
    writeCommand(ILI9341_CMD_PAGE_ADDRESS_SET); // Row address set
    SPI_WRITE16(y1, delay);
    SPI_WRITE16(y2, delay);
    writeCommand(ILI9341_CMD_MEMORY_WRITE);
    if (delay)
        custom_delay(delay); // Write to RAM
}