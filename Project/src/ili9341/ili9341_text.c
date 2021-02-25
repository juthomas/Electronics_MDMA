#include "../../inc/mdma.h"

void writePixel(int16_t x, int16_t y, uint16_t color)
{
  if ((x >= 0) && (x < width) && (y >= 0) && (y < height))
  {
    setAddrWindow(x, y, 1, 1);
    SPI_WRITE16(color);
  }
}

void drawChar(int16_t x, int16_t y, unsigned char c,
              uint16_t color, uint16_t bg, uint8_t size_x,
              uint8_t size_y)
{
  if ((x >= width) ||    // Clip right
      (y >= height) ||   // Clip bottom
      ((x + 6 * size_x - 1) < 0) || // Clip left
      ((y + 8 * size_y - 1) < 0))   // Clip top
    return;

  if (!cp437 && (c >= 176))
    c++; // Handle 'classic' charset behavior

  if (TFT_CS >= 0)
    ft_digital_write(TFT_CS,FT_LOW);
  for (int8_t i = 0; i < 5; i++)
  { // Char bitmap = 5 columns
    uint8_t line = pgm_read_byte(&font[c * 5 + i]);
    for (int8_t j = 0; j < 8; j++, line >>= 1)
    {
      if (line & 1)
      {
        if (size_x == 1 && size_y == 1)
          writePixel(x + i, y + j, color);
        else
          ili9341_fillRect(x + i * size_x, y + j * size_y, size_x, size_y,
                           color);
      }
      else if (bg != color)
      {
        if (size_x == 1 && size_y == 1)
          writePixel(x + i, y + j, bg);
        else
          ili9341_fillRect(x + i * size_x, y + j * size_y, size_x, size_y, bg);
      }
    }
  }
  if (TFT_CS >= 0)
    ft_digital_write(TFT_CS,FT_HIGH);
}

void write(uint8_t c, int16_t color, uint8_t text_size)
{
  if (c == '\n')
  {                             // Newline?
    cursor_x = 0;               // Reset x to zero,
    cursor_y += text_size * 8; // advance y one line
  }
  else if (c != '\r')
  { // Ignore carriage returns
    if (wrap && ((cursor_x + text_size * 6) > width))
    {                             // Off right?
      cursor_x = 0;               // Reset x to zero,
      cursor_y += text_size * 8; // advance y one line
    }
    drawChar(cursor_x, cursor_y, c, color, textbgcolor, text_size, text_size);
    cursor_x += text_size * 6; // Advance x one char
  }
}

void ili9341_println(char *str, int16_t color, uint8_t size)
{
  for (int i = 0; str[i]; i++)
  {
    write(str[i], color, size);
  }
}