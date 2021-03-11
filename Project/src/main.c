#include "../inc/mdma.h"


#define CPU_CLOCK 2000000
#define DT 61
#define CLK 11

//5 - 4
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
ISR (INT1_vect){
	/*serial_putnbr(ft_digital_read(CLK));
	serial_putnbr(ft_digital_read(DT));
	if(ft_digital_read(CLK) || ft_digital_read(DT))
 		serial_putstr("droite");
	else
		 serial_putstr("gauche");*/
  serial_putstr(" id:2 \n\r");
}

ISR (INT0_vect){

  serial_putstr(" id:0 \n\r");
}

//mon meilleur main
int main()
{

	serial_init();

	//PCIFR = (1 << PCIF0);
	//PCICR |= (1 << PCIE0); 
	
	EIMSK |= (1 << INT0 | 1 << INT1); //autoriser interupt sur INT0
	//PCMSK0 = 0b00000101;//autoriser les interupt sur pcint0 et pcint2
	//PCMSK0 = (1 << PINB);
	EICRA |= (1 << ISC01 | 1 << ISC11); //interupt on higt
	
	SREG = 0b10000000; //global interrupt enable


	ft_pin_mode(CLK, FT_INPUT);
	ft_pin_mode(DT, FT_INPUT);
	for (;;)	
	{		
	}


	return (0);
}