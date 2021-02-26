#include "../../inc/mdma.h"
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))


volatile long timer2_toggle_count;
volatile uint8_t *timer2_pin_port;
volatile uint8_t timer2_pin_mask;
#define INPUT 0x0
#define OUTPUT 0x1
#define INPUT_PULLUP 0x2
#define NOT_A_PIN 0
#define NOT_A_PORT 0


// frequency (in hertz) and duration (in milliseconds).

void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
	uint8_t prescalarbits = 0b001;
	long toggle_count = 0;
	uint32_t ocr = 0;
	TCCR2A = 0;
	TCCR2B = 0;
	bitWrite(TCCR2A, WGM21, 1);
	bitWrite(TCCR2B, CS20, 1);
	timer2_pin_port = (volatile uint8_t*)g_pin_associations[_pin].register_port_addr;
	// timer2_pin_port = portOutputRegister(digitalPinToPort(_pin));
	timer2_pin_mask = g_pin_associations[_pin].register_mask;
	// timer2_pin_mask = digitalPinToBitMask(_pin);
	// Set the pinMode as OUTPUT
	ft_pin_mode(_pin, FT_OUTPUT);
    // pinMode(_pin, OUTPUT);
	serial_putstr("timer2 port : ");
    serial_putnbr((int)timer2_pin_port);
    serial_putstr("\r\n");
	serial_putstr("timer2 mask : ");
    serial_putnbr((int)timer2_pin_mask);
    serial_putstr("\r\n");


    // ft_pin_mode(_pin, FT_OUTPUT);
	// if we are using an 8 bit timer, scan through prescalars to find the best fit

	ocr = F_CPU / frequency / 2 - 1;
	prescalarbits = 0b001; // ck/1: same for both timers
	if (ocr > 255)
	{
		ocr = F_CPU / frequency / 2 / 8 - 1;
		prescalarbits = 0b010; // ck/8: same for both timers

		if (ocr > 255)
		{
			ocr = F_CPU / frequency / 2 / 32 - 1;
			prescalarbits = 0b011;
		}

		if (ocr > 255)
		{
			ocr = F_CPU / frequency / 2 / 64 - 1;
			prescalarbits = 0b100;

			if (ocr > 255)
			{
				ocr = F_CPU / frequency / 2 / 128 - 1;
				prescalarbits = 0b101;
			}

			if (ocr > 255)
			{
				ocr = F_CPU / frequency / 2 / 256 - 1;
				prescalarbits = 0b110;
				if (ocr > 255)
				{
					// can't do any better than /1024
					ocr = F_CPU / frequency / 2 / 1024 - 1;
					prescalarbits = 0b111;
				}
			}
		}
	}
	TCCR2B = (TCCR2B & 0b11111000) | prescalarbits;

	if (duration > 0)
	{
		toggle_count = 2 * frequency * duration / 1000;
	}
	else
	{
		toggle_count = -1;
	}
	OCR2A = ocr;
	timer2_toggle_count = toggle_count;
	bitWrite(TIMSK2, OCIE2A, 1);
}



void noTone(uint8_t _pin)
{

	volatile uint8_t *out = (uint8_t *)0xF1;
	*out &= 0b11111101;

}

ISR(TIMER2_COMPA_vect)
{
	if (timer2_toggle_count != 0)
	{
		*timer2_pin_port ^= timer2_pin_mask;
		if (timer2_toggle_count > 0)
			timer2_toggle_count--;
	}
	else
	{
		noTone(255);
	}
}