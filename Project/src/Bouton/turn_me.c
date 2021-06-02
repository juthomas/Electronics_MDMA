#include <avr/io.h>
#include "../../inc/mdma.h"
#include <avr/interrupt.h>



static int old_state[5] = {0, 0, 0, 0, 0};
static int nb[5] = {0, 0, 0, 0, 0};
int touch[NB_T] = {0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};



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

ISR(TIMER2_COMPA_vect)
{
	static const uint8_t tab[NB_T] = {PC0,PC1,PE2,PC2,PC3,PE5,PE0,PE1,PE6,PC6,PC7,PG5,PC4,PC5,PE7};
	static const volatile uint8_t* value[NB_T] = {&PINC, &PINC, &PINE, &PINC, &PINC, &PINE, &PINE, &PINE, &PINE, &PINC, &PINC, &PING, &PINC, &PINC, &PINE};

	for (int i = 0; i < 1 ;i++)
	{
		if (!((*(value[i]) & (1 << tab[i])))) {
			touch[i] = 1;
		}
		else
			touch[i] = 0;
	}

}



void setupTimer2(uint32_t ocr, uint8_t prescaler)
{
	cli();
	// Clear registers
	TCCR2A = 0;
	TCCR2B = 0;
	TCNT2 = 0;
	// 100.16025641025641 Hz (16000000/((155+1)*1024))
	OCR2A = ocr;
	// CTC
	TCCR2A |= (1 << WGM21);
	// Prescaler 1024
	TCCR2B = (TCCR2B & 0b11111000) | prescaler;
	
	// TCCR0B = prescaler & 0x07;

	//TCCR0B |= (1 << CS02) | (1 << CS00);
	// Output Compare Match A Interrupt Enable
	TIMSK2 |= (1 << OCIE2A);
	sei();
}



void init_turn()
{
	
	DDRA |= (1 << DDA7);
	setupTimer2(3000, 100);
	cli();


	//DDRB = 0b00000000;
	// PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs
	PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB6)); // turn On the Pull-up
	DDRC |= (1 << DDC6);
	DDRA |= (1 << DDA7);

	PORTK |= 0b00111111;
	// activer de portk0 as portk5

	PCICR |= ((1 << PCIE0) | (1 << PCIE2));
	PCMSK0 |= ((1 << PCINT7) | (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT6)); //autoriser les interupt sur pcint0 et pcint2

	PCMSK2 |= 0b00111111;


	sei(); 
					DDRC |= (1 << DDC6);
while (1){
			if (touch[0])
			{
				PINC = (1 << DDC6);
			} 
			else 
			{
				PINC = 0;
			}
}

	return;
}