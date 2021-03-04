#include "../inc/mdma.h"

#define CPU_CLOCK 2000000
#define CLKA 67
#define DTA 69
#define CLKB 65
#define DTB 63
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
	ft_pin_mode(CLKA, FT_INPUT);
	ft_pin_mode(DTA, FT_INPUT);
	ft_pin_mode(CLKB, FT_INPUT);
	ft_pin_mode(DTB, FT_INPUT);
int tmpa = ft_digital_read(CLKA);
int tmpb = ft_digital_read(CLKB);
int i = 0;
	for (;;)	
	{
		int truc = ft_digital_read(CLKA);
		if (truc != tmpa && truc == 1)
		{
			if(ft_digital_read(CLKA) == ft_digital_read(DTA))
				serial_putstr("droite 3");
			else
				serial_putstr("gauche 3");
serial_putstr("\n\r");

		}
		tmpa = truc;
			truc = ft_digital_read(CLKB);
		if (truc != tmpb && truc == 1)
		{
			if(ft_digital_read(CLKB) == ft_digital_read(DTB))
				serial_putstr("droite 2 ");
			else
				serial_putstr("gauche 2");
serial_putstr("\n\r");

		}
		tmpb = truc;

		

	}
	return (0);
}