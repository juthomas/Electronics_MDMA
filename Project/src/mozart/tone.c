

#include "../../inc/mdma.h"
#include "../../inc/tone.h"

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

// static volatile uint8_t *tone_port_addr;
static volatile uint8_t tone_port_mask;
static volatile uint32_t duration_ticks = 0x00;

// static volatile uint8_t *music_port_addr;
// static volatile uint8_t music_port_mask;

void set_timer1(uint32_t frequency)
{
}

void setupTimer0(uint32_t ocr, uint8_t prescaler)
{
	cli();
	// Clear registers
	TCCR0A = 0;
	TCCR0B = 0;
	TCNT0 = 0;
	// 100.16025641025641 Hz (16000000/((155+1)*1024))
	OCR0A = ocr;
	// CTC
	TCCR0A |= (1 << WGM01);
	// Prescaler 1024
	TCCR0B = (TCCR0B & 0b11111000) | prescaler;

	// TCCR0B = prescaler & 0x07;

	//TCCR0B |= (1 << CS02) | (1 << CS00);
	// Output Compare Match A Interrupt Enable
	TIMSK0 |= (1 << OCIE0A);
	sei();
}

// void	setupTimer1(uint32_t ocr, uint8_t prescaler)
// {
// 	cli();
// 	TCCR1A = 0;
// 	TCCR1B = 0;
// 	TCNT1 = 0;
//   // 1 Hz (16000000/((15624+1)*1024))

//   OCR1A = 1953;
//   // CTC
//   TCCR1B |= (1 << WGM12);
//   // Prescaler 1024
//   TCCR1B |= (1 << CS12) | (1 << CS10);
//   // Output Compare Match A Interrupt Enable
//   TIMSK1 |= (1 << OCIE1A);
// 	sei();
// }

void setupTimer1(uint32_t ocr, uint8_t prescaler)
{
	cli();
	// Clear registers
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;

	// 13.000520020800833 Hz (16000000/((19229+1)*64))
	OCR1A = 19229;
	// CTC
	TCCR1B |= (1 << WGM12);
	// Prescaler 64
	TCCR1B |= (1 << CS11) | (1 << CS10);
	// Output Compare Match A Interrupt Enable
	TIMSK1 |= (1 << OCIE1A);
	sei();
}

void setupTimer5(uint32_t ocr, uint8_t prescaler)
{
	cli();
	// Clear registers
	TCCR5A = 0;
	TCCR5B = 0;
	TCNT5 = 0;

	OCR5A = ocr;
	//   OCR5A = 499;
	// CTC
	TCCR5B |= (1 << WGM52);
	// Prescaler
	TCCR5B |= prescaler;
	//   TCCR5B |= (1 << CS51);
	// Output Compare Match A Interrupt Enable
	TIMSK5 |= (1 << OCIE5A);
	sei();
}

ISR(TIMER5_COMPA_vect)
{
	// PORTK ^= 1 << PIN6;

	if (!duration_ticks)
	{
		// TIMSK5 &= ~_BV(OCIE5A);
		// TCCR5B = 0x00;
		cli();

		TCCR5A = 0;
		TCCR5B = 0;
		TCNT5 = 0;
		sei();
	}
	else
	{
		PORTK ^= tone_port_mask;
		duration_ticks--;
	}
}

void timer_freq_prescale(uint32_t a_freq, uint32_t *a_ocr, uint8_t *a_prescaler)
{
	// prescaler table for timer 0
	// uint8_t prescalers[] = {0x00, 0x03, 0x06, 0x08, 0x0a, 0x00};
	uint32_t ocr = 0x00;
	uint8_t prescaler = 0b000;

	// FCPU	/ FREQ - 1
	ocr = 16000000 / a_freq - 1;
	// Prescaler 1  CS2 CS1 CS0
	prescaler = 0b001;

	// if (a_freq < 2)
	// {
	// 	ocr = 16000000 / a_freq / 1024 - 1;
	// 	prescaler = 0b101;
	// }
	// else if (a_freq < 1000)
	// {
	// 	ocr = 16000000 / a_freq / 256 - 1;
	// 	prescaler = 0b100;
	// }
	// else if (a_freq < 1000)
	// {
	// 	ocr = 16000000 / a_freq / 64 - 1;
	// 	prescaler = 0b011;
	// }
	// else if (a_freq < 100000)
	// {
	// 	ocr = 16000000 / a_freq / 8 - 1;
	// 	prescaler = 0b010;
	// }
	// else
	// {
	// 	ocr = 16000000 / a_freq - 1;
	// 	prescaler = 0b001;
	// }
	if (ocr > 0xFFFF)
	{
		// FCPU	/ FREQ / PRESCALER - 1
		ocr = 16000000 / a_freq / 8 - 1;
		// Prescaler 8 CS2 CS1 CS0
		prescaler = 0b010;
		if (ocr > 0xFFFF)
		{
			// FCPU	/ FREQ / PRESCALER - 1
			ocr = 16000000 / a_freq / 64 - 1;
			// Prescaler 64 CS2 CS1 CS0
			prescaler = 0b011;
			if (ocr > 0xFFFF)
			{
				// FCPU	/ FREQ / PRESCALER - 1
				ocr = 16000000 / a_freq / 256 - 1;
				// Prescaler 256 CS2 CS1 CS0
				prescaler = 0b100;
				if (ocr > 0xFFFF) // Max prescaler
				{
					// FCPU	/ FREQ / PRESCALER - 1
					ocr = 16000000 / a_freq / 1024 - 1;
					// Prescaler 1024 CS2 CS1 CS0
					prescaler = 0b101;
				}
			}
		}
	}
	*a_ocr = ocr;
	*a_prescaler = prescaler;
}

void tone(uint8_t mask, uint32_t frequence, uint32_t duration)
{
	// frequence *= 100;
	// duration /= 8;
	// frequence = 880;
	// frequence /= 6;
	// tone_port_addr = (volatile uint8_t *)addr;
	tone_port_mask = mask;
	uint32_t ocr = 0;
	uint8_t prescaler = 0;
	duration_ticks = frequence * duration / 1000;
	timer_freq_prescale(frequence, &ocr, &prescaler);

	// ocr = 499;
	// prescaler = 0b010;

	setupTimer5(ocr, prescaler);
}
