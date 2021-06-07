#include "../../inc/encoders.h"
#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../../inc/millis.h"

static uint8_t old_state[5] = {0, 0, 0, 0, 0};

void encoders_state(uint8_t now, uint8_t index)
{
	if ((old_state[index] == 0 && now == 2) || (old_state[index] == 2 && now == 3) \
	|| (old_state[index] == 3 && now == 1) || (old_state[index] == 1 && now == 0))
	{
		encoders[index]++;
	}
	else if (((old_state[index] == 0 && now == 1) || (old_state[index] == 2 && now == 0) \
	|| (old_state[index] == 3 && now == 2) || (old_state[index] == 1 && now == 3)))
	{
		encoders[index]--;
	}
	old_state[index] = now;
}

void clear_encoders()
{
	for (int i = 0; i < 5; i++)
	{
		encoders[i] = 0;
	}
}


/**
 * PCINT4 => PINB4
 * PCINT5 => PINB5
 * PCINT6 => PINB6
 * PCINT7 => PINB7
 * PCINT16 => PINK0
 * PCINT17 => PINK1
 * PCINT18 => PINK2
 * PCINT19 => PINK3
 * PCINT20 => PINK4
 * PCINT21 => PINK5
 */
void init_encoders()
{
	DDRB &= !(0b11110000);
	PCICR |= 0b00000101;
	PCMSK0 |= (1 << PCINT4) | (1 << PCINT5) | (1 << PCINT6) | (1 << PCINT7);
	PCMSK2 |= (1 << PCINT16) | (1 << PCINT17) | (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);
	clear_encoders();
}

ISR(PCINT0_vect)
{
	uint8_t state = 0;
	state = ((PINB & (1 << PINB5)) >> PINB5) << 1;
	state += (PINB & (1 << PINB4)) >> PINB4;
	encoders_state(state, 0);

	state = ((PINB & (1 << PINB7)) >> PINB7) << 1;
	state += (PINB & (1 << PINB6)) >> PINB6;
	encoders_state(state, 4);
}

ISR(PCINT2_vect)
{
	uint8_t state = 0;
	state = (PINK & (1 << PINK5)) >> PINK5;
	state += ((PINK & (1 << PINK4)) >> PINK4) << 1;
	encoders_state(state, 1);

	state = ((PINK & (1 << PINK1)) >> PINK1);
	state += ((PINK & (1 << PINK0)) >> PINK0) << 1;
	encoders_state(state, 3);

	state = (PINK & (1 << PINK3)) >> PINK3;
	state += ((PINK & (1 << PINK2)) >> PINK2) << 1;
	encoders_state(state, 2);

}