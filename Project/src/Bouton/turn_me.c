#include <avr/io.h>
#include "../../inc/mdma.h"
#include <avr/interrupt.h>

static int old_state[5] = {0, 0, 0, 0, 0};
static int nb[5] = {0, 0, 0, 0, 0};

//bouton state vas geree si le bouton vas actuellment vers + ou -
//on as pris le partie pris de sous diviser chaque if en 4 cela permet de contrer le saut detat

void bouton_state(int now, int index)
{

	if ((old_state[index] == 0 && now == 2) || (old_state[index] == 2 && now == 3) || (old_state[index] == 3 && now == 1) || (old_state[index] == 1 && now == 0))
	{
		nb[index]++;
		ft_digital_write(4, FT_HIGH);
	}
	else if (((old_state[index] == 0 && now == 1) || (old_state[index] == 2 && now == 0) || (old_state[index] == 3 && now == 2) || (old_state[index] == 1 && now == 3)))
	{
		nb[index]--;
		ft_digital_write(4, FT_LOW);
	}
	old_state[index] = now;
}

//PCINT0 et PCINT2 socupe de savoir qui as ete apller en fesant apelle as bouton state
//lapelle as bouton_state pourais etre fait : (a faire)

ISR(PCINT0_vect)
{
	int state = 0;
	state = ((PINB & (1 << PINB5)) >> PINB5) << 1;
	state += (PINB & (1 << PINB4)) >> PINB4;
	bouton_state(state, 0);

	state = ((PINB & (1 << PINB7)) >> PINB7) << 1;
	state += (PINB & (1 << PINB6)) >> PINB6;
	bouton_state(state, 1);
}

ISR(PCINT2_vect)
{

	int state = 0;
	state = ((PINK & (1 << PINK1)) >> PINK1) << 1;
	state += (PINK & (1 << PINK0)) >> PINK0;
	bouton_state(state, 2);

	state = ((PINK & (1 << PINK3)) >> PINK3) << 1;
	state += (PINK & (1 << PINK2)) >> PINK2;
	bouton_state(state, 3);

	state = ((PINK & (1 << PINK5)) >> PINK5) << 1;
	state += (PINK & (1 << PINK4)) >> PINK4;
	bouton_state(state, 4);
}

ISR(TIMER0_COMPB_vect)
{
	PORTC = (1 << PORTC6);
	if (!((PINE & (1 << PE5)))) // bouton brancher as la PE5
		PORTC = (1 << PORTC6); // led brancher sur PC6
	if (!((PING & (1 << PG5))))
		PORTA = (1 << PORTA7);
		/* 
		lideal serais d avoir un tbleaux comun as tout le monde pour pouvoir balader une matrice de bouton appuier ou non 
		 je vais mettre un tableaux de [5][3] pour plus de clarter . et peu etre [6][3] pour les bouton sur la bord du milieux 
		*/
}

void init_turn()
{
	cli();

	//set toggle
	TCCR0B |= (1 << FOC0B);
	//set le mode 2
	TCCR0B |= (0 << WGM02);
	TCCR0A |= (1 << WGM01);
	TCCR0A |= (0 << WGM00);
	//set maske
	TIMSK0 |= (1 << OCIE0B);
	OCR0B = 25; //max value
	
	//set clock timer a 1024
	TCCR0B |= (1 << CS02);
	TCCR0B |= (1 << CS00);

	//DDRB = 0b00000000;
	// PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs
	PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB6)); // turn On the Pull-up
	DDRC |= (1 << DDC6);
	DDRA |= (1 << DDA7);

	/*while (1)
	{
	}*/
	PORTK |= 0b00111111;
	// activer de portk0 as portk5

	PCICR |= ((1 << PCIE0) | (1 << PCIE2));
	PCMSK0 |= ((1 << PCINT7) | (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT6)); //autoriser les interupt sur pcint0 et pcint2

	PCMSK2 |= 0b00111111;

	sei(); //global interrupt enable

	//	ft_pin_mode(CLK, FT_INPUT);

	return;
}