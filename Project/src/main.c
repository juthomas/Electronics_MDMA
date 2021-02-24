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
	serial_test();

	for (;;)	
	{
	}
	return (0);
}