

#include "../../inc/mdma.h"
# include "../../inc/tone.h"


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

void	setupTimer1(uint32_t ocr, uint8_t prescaler)
{
	cli();
	TCCR1A = 0;
	TCCR1B = 0;
	TCNT1 = 0;
  // 1 Hz (16000000/((15624+1)*1024))

  OCR1A = 1953;
  // CTC
  TCCR1B |= (1 << WGM12);
  // Prescaler 1024
  TCCR1B |= (1 << CS12) | (1 << CS10);
  // Output Compare Match A Interrupt Enable
  TIMSK1 |= (1 << OCIE1A);
	sei();
}


ISR(TIMER0_COMPA_vect)
{
	if (!duration_ticks)
	{
		TIMSK0 &= ~_BV(OCIE0A);
		TCCR0B = 0x00;
	}
	else
	{
		PORTC ^= tone_port_mask;
		duration_ticks--;
	}
}

void timer_freq_prescale(uint32_t a_freq, uint32_t *a_ocr, uint8_t *a_prescaler)
{
	// prescaler table for timer 0
	// uint8_t prescalers[] = {0x00, 0x03, 0x06, 0x08, 0x0a, 0x00};
	uint32_t ocr = 0x00;
	uint8_t prescaler = 0x00;
	ocr = F_CPU / a_freq / 2 - 1;
	prescaler = 0b001; // ck/1: same for both timers
	if (ocr > 255)
	{
		ocr = F_CPU / a_freq / 2 / 8 - 1;
		prescaler = 0b010; // ck/8: same for both timers
		if (ocr > 255)
		{
			ocr = F_CPU / a_freq / 2 / 64 - 1;
			prescaler = 0b011;
			if (ocr > 255)
			{
				ocr = F_CPU / a_freq / 2 / 256 - 1;
				prescaler = 0b100;
				if (ocr > 255)
				{
					// can't do any better than /1024
					ocr = F_CPU / a_freq / 2 / 1024 - 1;
					prescaler = 0b101;
				}
			}
		}
	}
	*a_ocr = ocr;
	*a_prescaler = prescaler;
}

void tone(uint8_t mask , uint32_t frequence, uint32_t duration)
{
	duration *= 8;
	frequence /= 6;
	// tone_port_addr = (volatile uint8_t *)addr;
	tone_port_mask = mask;
	uint32_t ocr = 0;
	uint8_t prescaler = 0;
	duration_ticks =  2 * frequence * duration / 1000;
	timer_freq_prescale(frequence, &ocr, &prescaler);
	setupTimer0(ocr, prescaler);
}
