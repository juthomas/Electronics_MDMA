#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../../inc/millis.h"
#include "../../inc/encoders.h"

// int encoder1 = 0;
// int encoder2 = 0;
// int encoder3 = 0;
// int encoder4 = 0;
// int encoder5 = 0;

static uint32_t time_encoder1 = 0;
static uint32_t time_encoder2 = 0;
static uint32_t time_encoder3 = 0;
static uint32_t time_encoder4 = 0;
static uint32_t time_encoder5 = 0;

static uint8_t last_state_encoder1 = 0;
static uint8_t last_state_encoder2 = 0;
static uint8_t last_state_encoder3 = 0;
static uint8_t last_state_encoder4 = 0;
static uint8_t last_state_encoder5 = 0;

void init_encoders()
{
	init_millis();
	//   Serial.begin(9600);
	DDRB &= !(0b11110000);
	PCICR |= 0b00000101;
	//  PCMSK0 |= (1 << PCINT4) | (1 << PCINT5) | (1 << PCINT6) | (1 << PCINT7);
	PCMSK0 |= (1 << PCINT4) | (1 << PCINT6);
	//  PCMSK2 |= (1 << PCINT16) | (1 << PCINT17) | (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);
	PCMSK2 |= (1 << PCINT16) | (1 << PCINT18) | (1 << PCINT20);
}

ISR(PCINT0_vect)
{

	if (PINB & (1 << 4))
	{
		uint8_t state_encoder1 = (PINB & (1 << 4)) >> 4;

		if (millis - time_encoder1 > 50)
		{
			if ((PINB & (1 << 5)) >> 5 != last_state_encoder1)
			{
				encoder1--;
			}
			else
			{
				encoder1++;
			}

			time_encoder1 = millis;
		}
		last_state_encoder1 = state_encoder1;
	}

	if (PINB & (1 << 6))
	{
		uint8_t state_encoder2 = (PINB & (1 << 6)) >> 6;

		if (millis - time_encoder2 > 50)
		{
			if ((PINB & (1 << 7)) >> 7 != last_state_encoder2)
			{
				encoder2--;
			}
			else
			{
				encoder2++;
			}

			time_encoder2 = millis;
		}
		last_state_encoder2 = state_encoder2;
	}
}

ISR(PCINT2_vect)
{
	if (PINK & (1 << 0))
	{
		uint8_t state_encoder3 = (PINK & (1 << 0)) >> 0;

		if (millis - time_encoder3 > 50)
		{
			if ((PINK & (1 << 1)) >> 1 != last_state_encoder3)
			{
				encoder3--;
			}
			else
			{
				encoder3++;
			}

			time_encoder3 = millis;
		}
		last_state_encoder3 = state_encoder3;
	}

	if (PINK & (1 << 2))
	{
		uint8_t state_encoder4 = (PINK & (1 << 2)) >> 2;

		if (millis - time_encoder4 > 50)
		{
			if ((PINK & (1 << 3)) >> 3 != last_state_encoder4)
			{
				encoder4--;
			}
			else
			{
				encoder4++;
			}

			time_encoder1 = millis;
		}
		last_state_encoder4 = state_encoder4;
	}

	if (PINK & (1 << 4))
	{
		uint8_t state_encoder5 = (PINK & (1 << 4)) >> 4;

		if (millis - time_encoder5 > 50)
		{
			if ((PINK & (1 << 5)) >> 5 != last_state_encoder5)
			{
				encoder5--;
			}
			else
			{
				encoder5++;
			}

			time_encoder5 = millis;
		}
		last_state_encoder5 = state_encoder5;
	}
}