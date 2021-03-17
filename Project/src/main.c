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
/*ISR (INT1_vect){
	serial_putnbr(ft_digital_read(CLK));
	serial_putnbr(ft_digital_read(DT));
	if(ft_digital_read(CLK) || ft_digital_read(DT))
 		serial_putstr("droite");
	else
		 serial_putstr("gauche");
  serial_putstr(" id:2 \n\r");
}

ISR (INT0_vect){

  serial_putstr(" id:0 \n\r");
}*/



ISR (PCINT0_vect){
	static unsigned long lastInterrupt = 0;
	unsigned long interruptTime = TCNT1;

	if(interruptTime - lastInterrupt > 5)
	{
		serial_putstr(", gauche: ");
		serial_putnbr(ft_digital_read(13));
		serial_putstr(", ");
		serial_putnbr(ft_digital_read(42));
		serial_putstr(", ");
		serial_putnbr(PINB);
		serial_putstr(", droite: ");
		serial_putnbr(ft_digital_read(11));
		serial_putstr(", ");
		serial_putnbr(ft_digital_read(44));
		serial_putstr(", milieux: ");
		serial_putnbr(ft_digital_read(10));
		serial_putstr(", ");
		serial_putnbr(ft_digital_read(46));
		serial_putstr("\n\r");
	}

}


//mon meilleur main
int main()
{

	serial_init();

	//PCIFR = (1 << PCIF0);
	
	 DDRB &= ~((1 << DDB7) | (1 << DDB5) | (1 << DDB4)); // Clear the PB0, PB1, PB2 pin
    // PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs

    PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4)); // turn On the Pull-up
    // PB0, PB1 and PB2 are now inputs with pull-up enabled
	PCICR |= (1 << PCIE0); 
	
	//EIMSK |= (1 << INT0 | 1 << INT1); //autoriser interupt sur INT0
	PCMSK0 = ((1 << PCINT7) | (1 < PCINT5) | (1 < PCINT4));//autoriser les interupt sur pcint0 et pcint2
	//PCMSK0 = (1 << PINB);
	//EICRA |= (1 << ISC01 | 1 << ISC11); //interupt on higt
	
	SREG = 0b10000000; //global interrupt enable


//	ft_pin_mode(CLK, FT_INPUT);

	for (;;)	
	{		
	}


	return (0);
}