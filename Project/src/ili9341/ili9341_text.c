#include "../../inc/ili9341.h"

void drawChar(int16_t x, int16_t y, unsigned char c,
              uint16_t color, uint16_t bg, uint8_t size_x,
              uint8_t size_y, uint8_t delay)
{
  if ((x >= width) ||               // Clip right
      (y >= height) ||              // Clip bottom
      ((x + 6 * size_x - 1) < 0) || // Clip left
      ((y + 8 * size_y - 1) < 0))   // Clip top
    return;

  if (!cp437 && (c >= 176))
    c++; // Handle 'classic' charset behavior

  spi_begin_transaction();
  for (int8_t i = 0; i < 5; i++)
  { // Char bitmap = 5 columns
    uint8_t line = pgm_read_byte(&font[c * 5 + i]);
    for (int8_t j = 0; j < 8; j++, line >>= 1)
    {
      if (line & 1)
      {
        if (size_x == 1 && size_y == 1)
          writePixel(x + i, y + j, color, delay);
        else
          ili9341_drawfillRect(x + i * size_x, y + j * size_y, size_x, size_y,
                               color, delay);
      }
      else if (bg != color)
      {
        if (size_x == 1 && size_y == 1)
          writePixel(x + i, y + j, bg, delay);
        else
          ili9341_drawfillRect(x + i * size_x, y + j * size_y, size_x, size_y, bg, delay);
      }
    }
  }
  spi_end_transaction();
}

void write(uint8_t c, int16_t color, uint8_t text_size, uint8_t delay, int16_t startX, int16_t endX)
{
  if (c == '\n')
  {                            // Newline?
    cursor_x = 0;              // Reset x to zero,
    cursor_y += text_size * 8; // advance y one line
  }
  else if (c != '\r')
  { // Ignore carriage returns
    if (wrap && ((cursor_x + text_size * 6) > endX))
    {                            // Off right?
      cursor_x = startX;              // Reset x to zero,
      cursor_y += text_size * 8; // advance y one line
    }
    drawChar(cursor_x, cursor_y, c, color, textbgcolor, text_size, text_size, delay);
    cursor_x += text_size * 6; // Advance x one char
  }
}

void ili9341_print(char *str, int16_t color, uint8_t size, uint8_t delay, int16_t startX, int16_t endX)
{
  for (int i = 0; str[i]; i++)
    write(str[i], color, size, delay, startX, endX);
}

void ili9341_putnbr(int8_t n, int16_t color, uint8_t size, uint8_t delay)
{
  if (n < 0)
    write('-', color, size, delay, 0, width);
  if (n >= -9 && n <= 9)
  {
    if (n < 0)
      n = -n;
    write(n + 48, color, size, delay, 0, width);
  }
  if (n < -9)
  {
    ili9341_putnbr(n / -10, color, size, delay);
    ili9341_putnbr(-(n % 10), color, size, delay);
  }
  if (n > 9)
  {
    ili9341_putnbr(n / 10, color, size, delay);
    ili9341_putnbr(n % 10, color, size, delay);
  }
}

static int		ft_strlen_error(char *base)
{
	int			i;
	int			j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

void ili9341_putnbr_base(int32_t nbr, char *base, int16_t color, uint8_t size, uint8_t delay)
{
  int32_t u;

  u = ft_strlen_error(base);
  if (nbr < 0)
  {
    write('-', color, size, delay, 0, width);
    nbr = nbr * -1;
  }
  if (nbr >= u)
    ili9341_putnbr_base(nbr / u, base, color, size, 0);
  write(base[(nbr % u)], color, size, delay, 0, width);
}

void ili9341_putnbr_baseln(int32_t nbr, char *base, int16_t color, uint8_t size, uint8_t delay)
{
  ili9341_putnbr_base(nbr, base, color, size, delay);
  write('\n', color, size, delay, 0, width);
}

void ili9341_putnbrln(int8_t n, int16_t color, uint8_t size, uint8_t delay)
{
  ili9341_putnbr(n, color, size, delay);
  write('\n', color, size, delay, 0, width);
}

void ili9341_println(char *str, int16_t color, uint8_t size, uint8_t delay)
{
  for (int i = 0; str[i]; i++)
    write(str[i], color, size, delay, 0, width);
  write('\n', color, size, delay, 0, width);
}