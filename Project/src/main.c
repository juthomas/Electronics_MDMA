#include "../inc/mdma.h"

#define CPU_CLOCK 2000000
#define DT 61
#define CLK 11
static int v[5] = {0, 0, 0, 0,0};
static int nb[5] = {0, 0, 0, 0,0};
static int yo = 0;
//5 - 4
// v[1]oid	wait_x_cpu_clocks(int32_t cpu_clocks)
// {
// 	while (cpu_clocks > 0)
// 	{
// 		cpu_clocks-=3;
// 	}
// }

// v[1]oid	custom_delay(uint32_t milli)
// {
// 	milli = milli *	2000;
// 	wait_x_cpu_clocks(milli - 5);
// }

//ma meilleur interupt
/*ISR (INT1v[0]ect){
	serial_putnbr(ft_digital_read(CLK));
	serial_putnbr(ft_digital_read(DT));
	if(ft_digital_read(CLK) || ft_digital_read(DT))
 		serial_putstr("droite");
	else
		 serial_putstr("gauche");
  serial_putstr(" id:2 \n\r");
}

ISR (INT0v[0]ect){

  serial_putstr(" id:0 \n\r");
}*/

void bouton_state(int previous, int now, int index){

		if ((previous == 0 && now == 2) || (previous == 2 && now == 3) || (previous == 3 && now == 1) || (previous == 1 && now == 0))
			nb[index]++;
		else if (((previous == 0 && now == 1) || (previous == 2 && now == 0) || (previous == 3 && now == 2) || (previous == 1 && now == 3)))
			nb[index]--;
		v[index] = now;

}


ISR(PCINT0_vect)
{

	int a = 0;
		a = ((PINB & (1 << PINB5)) >> PINB5) << 1;
		a += (PINB & (1 << PINB4)) >> PINB4;
		bouton_state(v[0], a, 0);

		a = ((PINB & (1 << PINB7)) >> PINB7) << 1;
		a += (PINB & (1 << PINB6)) >> PINB6;
		bouton_state(v[1], a, 1);
		
		yo = 1;
}

ISR(PCINT2_vect){

	int a = 0;
		a = ((PINK & (1 << PINK1)) >> PINK1) << 1;
		a += (PINK & (1 << PINK0)) >> PINK0;
		bouton_state(v[2], a, 2);

		a = ((PINK & (1 << PINK3)) >> PINK3) << 1;
		a += (PINK & (1 << PINK2)) >> PINK2;
		bouton_state(v[3], a, 3);

		a = ((PINK & (1 << PINK5)) >> PINK5) << 1;
		a += (PINK & (1 << PINK6)) >> PINK6;
		bouton_state(v[4], a, 4);

		yo = 1;
}


//mon meilleur main
int main()
{
		//serial_init();
		// enable UDRE interrupt and enable transmit
		//UCSR0B |= (1 << UDRIE0) | (1 << TXEN0);

		// set character data size to 8
		UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);

		// baud rate 9600
		UBRR0 = 103;

		//PCIFR = (1 << PCIF0);
		//DDRB &= ~((1 << DDB7) | (1 << DDB5) | (1 << DDB4) | (1 << DDB6)); // Clear the PB0, PB1, PB2 pin
		
		// PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs
		PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB6)); // turn On the Pull-up
		PORTK |= 0b00111111; // activer de portk0 as portk5
		//PORTB = 0b11100000;
		// PB0, PB1 and PB2 are now inputs with pull-up enabled
		PCICR |= ((1 << PCIE0) | (1 << PCIE2));
		//EIMSK |= (1 << INT0 | 1 << INT1); //autoriser interupt sur INT0
		PCMSK0 = ((1 << PCINT7) | (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT6)); //autoriser les interupt sur pcint0 et pcint2
		PCMSK2 = 0b00111111;
		//PCMSK0 = 0b11100000; // Hard code pcq nsm
		//EICRA |= (1 << ISC01 | 1 << ISC11); //interupt on higt

		SREG = 0b10000000; //global interrupt enable

		//	ft_pin_mode(CLK, FT_INPUT);

		for (;;)
		{

			if (yo)
			{
				serial_putstr("id 0:[");
				serial_putnbr(nb[0]);
				serial_putstr("]id 1:[");
				serial_putnbr(nb[1]);
				serial_putstr("]id 2:[");
				serial_putnbr(nb[2]);
				serial_putstr("]id 3:[");
				serial_putnbr(nb[3]);
				serial_putstr("]id 4:[");
				serial_putnbr(nb[4]);
				serial_putstr("]\n\r");
				yo = 0;
			}
		}

		return (0);
}