#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../../inc/millis.h"

void init_millis()
{
	// noInterrupts
	cli();
	// Clear registers
	TCCR4A = 0;
	TCCR4B = 0;
	TCNT4 = 0;
	// 1000 Hz (16000000/((249+1)*64))
	OCR4A = 249;
	// CTC
	TCCR4B |= (1 << WGM42);
	// Prescaler 64
	TCCR4B |= (1 << CS41) | (1 << CS40);
	// Output Compare Match A Interrupt Enable
	TIMSK4 |= (1 << OCIE4A);
	// interrupts
	sei();
}

ISR(TIMER4_COMPA_vect)
{
	millis++;
}