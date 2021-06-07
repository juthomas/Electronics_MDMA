#include "../../inc/encoders.h"
#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <avr/interrupt.h>
#include <stdint.h>
#include "../../inc/millis.h"

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
	rot = 0;
	encoder1 = 2;
	encoder2 = 2;
	encoder3 = 2;
	encoder4 = 2;
	encoder5 = 2;
	// init_millis();
	//   Serial.begin(9600);
	DDRB &= !(0b11110000);
	PCICR |= 0b00000101;
	// PCMSK0 |= (1 << PCINT4) | (1 << PCINT5) | (1 << PCINT6) | (1 << PCINT7);
	PCMSK0 |= (1 << PCINT4) | (1 << PCINT6);
	// PCMSK2 |= (1 << PCINT16) | (1 << PCINT17) | (1 << PCINT18) | (1 << PCINT19) | (1 << PCINT20) | (1 << PCINT21);
	PCMSK2 |= (1 << PCINT16) | (1 << PCINT18) | (1 << PCINT20);
}

static uint8_t encoder1_last = 0;
static uint8_t encoder2_last = 0;
static uint8_t encoder3_last = 0;
static uint8_t encoder4_last = 0;
static uint8_t encoder5_last = 0;

volatile uint8_t portbhistory = 0x00;     // default is high because the pull-down
volatile uint8_t portkhistory = 0x00;     // default is high because the pull-down
ISR(PCINT0_vect)
{
    uint8_t changedbits;

    changedbits = PINB ^ portbhistory;
    portbhistory = PINB;

	// uint8_t PINB = PINB;
	uint8_t minus;
	uint8_t plus;
	uint8_t state;
	if (changedbits & (1 << 4))
	{

		minus = PINB & (1 << 4);
		plus = PINB & (1 << 5);
		state = encoder1_last & 0b11;
		if (minus)
			state |= 1 << 2;
		if (plus)
			state |= 1 << 3;
		encoder1_last = (state >> 2);
		switch (state)
		{
		case 0b0001:
		case 0b0111:
		case 0b1000:
		case 0b1110:
			encoder1++;
			return;
		case 0b0010:
		case 0b0100:
		case 0b1011:
		case 0b1101:
			encoder1--;
			return;
		case 0b0011:
		case 0b1100:
			encoder1 += 2;
			return;
		case 0b0110:
		case 0b1001:
			encoder1 -= 2;
			return;
		}
	}

	if (changedbits & (1 << 6))
	{

		minus = PINB & (1 << 6);
		plus = PINB & (1 << 7);
		state = encoder5_last & 0b11;
		if (minus)
			state |= 1 << 2;
		if (plus)
			state |= 1 << 3;
		encoder5_last = (state >> 2);
		switch (state)
		{
		case 0b0001:
		case 0b0111:
		case 0b1000:
		case 0b1110:
			encoder5++;
			return;
		case 0b0010:
		case 0b0100:
		case 0b1011:
		case 0b1101:
			encoder5--;
			return;
		case 0b0011:
		case 0b1100:
			encoder5 += 2;
			return;
		case 0b0110:
		case 0b1001:
			encoder5 -= 2;
			return;
		}
	}
}

ISR(PCINT2_vect)
{
	// uint8_t PINK = PINK;
	uint8_t minus;
	uint8_t plus;
	uint8_t state;

    uint8_t changedbits;

    changedbits = PINK ^ portkhistory;
    portbhistory = PINK;

	if (changedbits & (1 << 0))
	{
		minus = PINK & (1 << 0);
		plus = PINK & (1 << 1);
		state = encoder4_last & 0b11;
		if (minus)
			state |= 1 << 2;
		if (plus)
			state |= 1 << 3;
		encoder4_last = (state >> 2);
		switch (state)
		{
		case 0b0001:
		case 0b0111:
		case 0b1000:
		case 0b1110:
			encoder4++;
			return;
		case 0b0010:
		case 0b0100:
		case 0b1011:
		case 0b1101:
			encoder4--;
			return;
		case 0b0011:
		case 0b1100:
			encoder4 += 2;
			return;
		case 0b0110:
		case 0b1001:
			encoder4 -= 2;
			return;
		}
	}

	if (changedbits & (1 << 2))
	{

		minus = PINK & (1 << 2);
		plus = PINK & (1 << 3);
		state = encoder3_last & 0b11;
		if (minus)
			state |= 1 << 2;
		if (plus)
			state |= 1 << 3;
		encoder3_last = (state >> 2);
		switch (state)
		{
		case 0b0001:
		case 0b0111:
		case 0b1000:
		case 0b1110:
			encoder3++;
			return;
		case 0b0010:
		case 0b0100:
		case 0b1011:
		case 0b1101:
			encoder3--;
			return;
		case 0b0011:
		case 0b1100:
			encoder3 += 2;
			return;
		case 0b0110:
		case 0b1001:
			encoder3 -= 2;
			return;
		}
	}

	if (changedbits & (1 << 4))
	{

		minus = PINK & (1 << 4);
		plus = PINK & (1 << 5);
		state = encoder2_last & 0b11;
		if (minus)
			state |= 1 << 2;
		if (plus)
			state |= 1 << 3;
		encoder2_last = (state >> 2);
		switch (state)
		{
		case 0b0001:
		case 0b0111:
		case 0b1000:
		case 0b1110:
			encoder2++;
			return;
		case 0b0010:
		case 0b0100:
		case 0b1011:
		case 0b1101:
			encoder2--;
			return;
		case 0b0011:
		case 0b1100:
			encoder2 += 2;
			return;
		case 0b0110:
		case 0b1001:
			encoder2 -= 2;
			return;
		}
	}
}