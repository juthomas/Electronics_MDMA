#include <avr/io.h>
#include "../inc/mdma.h"

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(uint32_t milli)
{
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int main()
{
	ili9341_begin();
	ili9341_fillRect(0,0, ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT, ILI9341_BLACK);
	serial_init();
  	ili9341_setCursor(0, 0);
  	ili9341_setTextColor(ILI9341_WHITE);
	ili9341_setTextSize(10);
  	ili9341_println("Hello World!");
	serial_putstr("Ended as it can lol");
	for (;;);
	return (0);
}