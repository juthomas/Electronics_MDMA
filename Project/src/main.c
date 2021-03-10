#include "../inc/mdma.h"


#define CPU_CLOCK 2000000
#define DT 61
#define CLK 21


#define ENC_CTL	DDRB	//encoder port control
#define ENC_WR	PORTB	//encoder port write	
#define ENC_RD	PINB	//encoder port read
#define ENC_A 0	
#define ENC_B 1	

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

//ma meilleur interupt
ISR (INT0_vect){
	serial_putnbr(ft_digital_read(CLK));
	serial_putnbr(ft_digital_read(DT));
	if(ft_digital_read(CLK) || ft_digital_read(DT))
 		serial_putstr("droite");
	else
		 serial_putstr("gauche");
  serial_putstr(" id:0 \n\r");
}

//mon meilleur main
int main()
{

	serial_init();

//PCICR |= 0b10; 
	EIMSK |= (1 << INT0); //autoriser interupt sur INT0
	EICRA = (1 << ISC01); //interupt on higt
	SREG = 0b10000000; //global interrupt enable


	ft_pin_mode(CLK, FT_INPUT);
	ft_pin_mode(DT, FT_INPUT);
	for (;;)	
	{		
	}


	return (0);
}