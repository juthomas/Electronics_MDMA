#include <avr/io.h>
#include "../../inc/mdma.h"
#include <avr/interrupt.h>


static int v[5] = {0, 0, 0, 0, 0};
static int nb[5] = {0, 0, 0, 0, 0};
static int yo = 0;


void bouton_state(int now, int index)
{

	if ((v[index] == 0 && now == 2) || (v[index] == 2 && now == 3) || (v[index] == 3 && now == 1) || (v[index] == 1 && now == 0))
	{
			nb[index]++;
			ft_digital_write(4, FT_HIGH);
	}
	else if (((v[index] == 0 && now == 1) || (v[index] == 2 && now == 0) || (v[index] == 3 && now == 2) || (v[index] == 1 && now == 3)))
	{
			nb[index]--;
		ft_digital_write(4, FT_LOW);
	}
	v[index] = now;
}

ISR(PCINT0_vect)
{
	//ili9341_println("yo", ILI9341_WHITE, 1, 0);


	int a = 0;
	a = ((PINB & (1 << PINB5)) >> PINB5) << 1;
	a += (PINB & (1 << PINB4)) >> PINB4;
	bouton_state(a, 0);

	a = ((PINB & (1 << PINB7)) >> PINB7) << 1;
	a += (PINB & (1 << PINB6)) >> PINB6;
	bouton_state(a, 1);

	yo = 1;
}

ISR(PCINT2_vect)
{

	int a = 0;
	a = ((PINK & (1 << PINK1)) >> PINK1) << 1;
	a += (PINK & (1 << PINK0)) >> PINK0;
	bouton_state(a, 2);

	a = ((PINK & (1 << PINK3)) >> PINK3) << 1;
	a += (PINK & (1 << PINK2)) >> PINK2;
	bouton_state(a, 3);

	a = ((PINK & (1 << PINK5)) >> PINK5) << 1;
	a += (PINK & (1 << PINK4)) >> PINK4;
	bouton_state(a, 4);

	yo = 1;
}

void init_turn()
{
	
	DDRB = 0b00000000;
	// PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs
	PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB6)); // turn On the Pull-up
	
	
	PORTK |= 0b00111111;													  // activer de portk0 as portk5

	PCICR |= ((1 << PCIE0) | (1 << PCIE2));
	PCMSK0 |= ((1 << PCINT7) | (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT6)); //autoriser les interupt sur pcint0 et pcint2

	PCMSK2 |= 0b00111111;


	SREG = 0b10000000; //global interrupt enable

	//	ft_pin_mode(CLK, FT_INPUT);

	return ;
}