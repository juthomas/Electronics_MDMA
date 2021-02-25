#include <avr/io.h>
#include "../inc/mdma.h"

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
	ili9341_begin();
	serial_init();
	ili9341_setRotation(3);
	ili9341_fillScreen(ILI9341_BLACK);
	for (;;)
	{
		ili9341_setCursor(0, 0);
		ili9341_println("MEGA\nDRINKING\n", ILI9341_WHITE, 5);
		ili9341_println("MACHINA\n", ILI9341_RED, 5);
		ili9341_println("ADVENTURE\n\n", ILI9341_WHITE, 5);
		x = cursor_x;
		y = cursor_y;
		for(;;)
		{
			ili9341_setCursor(x, y);
			ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3);
			//custom_delay(200);
		}
		// ili9341_setTextColor(ILI9341_PINK);
		// ili9341_println("The End");
	}
	serial_putstr("Ended as it can lol");
	return (0);
}