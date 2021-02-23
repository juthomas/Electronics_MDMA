#include "../inc/mdma.h"

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
	ft_pin_mode(FT_D11, FT_OUTPUT);
	ft_pin_mode(FT_D13, FT_OUTPUT);
	ft_pin_mode(FT_D14, FT_OUTPUT);
	ft_pin_mode(FT_D30, FT_OUTPUT);
	ft_pin_mode(FT_A3, FT_OUTPUT);

	for (;;)	
	{
		ft_digital_write(FT_D11, FT_LOW);
		ft_digital_write(FT_D13, FT_HIGH);
		ft_digital_write(FT_D14, FT_HIGH);
		ft_digital_write(FT_D30, FT_LOW);
		ft_digital_write(FT_A3, FT_LOW);
		
		custom_delay(10);
		ft_digital_write(FT_D11, FT_HIGH);
		ft_digital_write(FT_D13, FT_LOW);
		ft_digital_write(FT_D14, FT_LOW);
		ft_digital_write(FT_D30, FT_HIGH);
		ft_digital_write(FT_A3, FT_HIGH);

		custom_delay(10);
		ft_digital_write(FT_D30, FT_LOW);
		custom_delay(10);
		ft_digital_write(FT_D30, FT_HIGH);
		custom_delay(10);

		ft_digital_write(FT_A3, FT_LOW);
		custom_delay(10);
		ft_digital_write(FT_A3, FT_HIGH);
		custom_delay(10);
	}
	return (0);
}