#include "../inc/mdma.h"

#define CPU_CLOCK 2000000

// void	wait_x_cpu_clocks(int32_t cpu_clocks)
// {
// 	while (cpu_clocks > 0)
// 	{
// 		cpu_clocks-=3;
// 	}
// }

// void	custom_delay(uint32_t milli)
// {
// 	milli = milli *	2000;
// 	wait_x_cpu_clocks(milli - 5);
// }

int main()
{
	serial_init();


	play_music();
	serial_putstr("fin de la musique \r\n");
	// ft_pin_mode(33, FT_OUTPUT);
	// for (;;)
	// {
	// 	ft_digital_write(33, FT_HIGH);
	// 	// ft_digital_write(33, FT_LOW);
	// }
	led_send_data();
	// serial_test();

	for (;;)	
	{
	}
	return (0);
}