#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
#include "ili9341/dragon.h"
#include <avr/power.h>
#include <stddef.h>

#define CLK 3
#define DT 2
#define SW 4

//int8_t btnState = 0;

void wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks -= 3;
	}
}

void custom_delay(uint32_t milli)
{
	milli = milli * 2000;
	wait_x_cpu_clocks(milli - 5);
}

int main()
{
	int16_t clign = ILI9341_WHITE;
	int16_t x = 0;
	int16_t y = 0;
	int8_t delay = 2;
	ft_pin_mode(CLK, FT_INPUT);
	ft_pin_mode(DT, FT_INPUT);
	ft_pin_mode(SW, FT_INPUT);
	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);
	ili9341_setRotation(3);
	for (;;)
	{
		serial_putstrln("Nope For The moment");
		ili9341_setCursor(0, 0);
		ili9341_print("MEGA\nDRINKING\n", ILI9341_WHITE, 5, delay);
		ili9341_print("MACHINA\n", ILI9341_RED, 5, delay);
		ili9341_print("ADVENTURE\n\n", ILI9341_WHITE, 5, delay);
		x = cursor_x;
		y = cursor_y;
		while (1)
		{
			ili9341_setCursor(x, y);
			ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, delay);
		}
	}
	serial_putstr("Ended as it can lol");
	return (0);
}