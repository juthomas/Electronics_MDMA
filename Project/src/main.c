#include "../inc/mdma.h"
#include "../inc/ili9341.h"

#define CPU_CLOCK 2000000

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
	ili9341_fillRect(0, 0, ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT, ILI9341_PINK);
	for (;;);
	return (0);
}