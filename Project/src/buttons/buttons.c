#include "../../inc/buttons.h"
# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
#  define F_CPU 16000000
# endif
# include <avr/io.h>
# include <avr/interrupt.h>

#define FALSE 0
#define TRUE 1


static uint16_t order_counter = 1;

void	clear_buttons()
{
	order_counter = 1;
	for (uint8_t i = 0; i < 16; i++)
	{
		buttons_clicks_order[i] = 0;
	}
}

void init_buttons()
{
	clear_buttons();
	//Input Mode for respectively (from right to left)
	//Player 1 : A B
	//Player 2 : A B
	//Player 5 : A B
	//Player 4 : A B
	DDRC &= !(0b11111111);
	//Player 3 : A B
	DDRE &= !(0b00011000);
	//Encoders Clicks
	DDRE &= !(0b01110100);
	DDRG &= !(0b00100000);

	// noInterrupts
	cli();
	// Clear registers
	TCCR3A = 0;
	TCCR3B = 0;
	TCNT3 = 0;

	// 100 Hz (16000000/((624+1)*256))
	OCR3A = 624;
	// CTC
	TCCR3B |= (1 << WGM32);
	// Prescaler 256
	TCCR3B |= (1 << CS32);
	// Output Compare Match A Interrupt Enable
	TIMSK3 |= (1 << OCIE3A);
	// interrupts
	sei();
}



ISR(TIMER3_COMPA_vect)
{
	uint8_t is_button_clicked = FALSE;
	//Player 1 A
	if (PINC & (1 << 0))
	{
		if (!buttons_clicks_order[0])
		{
			buttons_clicks_order[0] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 1 B
	if (PINC & (1 << 1))
	{
		if (!buttons_clicks_order[1])
		{
			buttons_clicks_order[1] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Encoder 1
	if (PINE & (1 << 2))
	{
		if (!buttons_clicks_order[2])
		{
			buttons_clicks_order[2] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 2 A/
	if (PINC & (1 << 4))
	{
		if (!buttons_clicks_order[3])
		{
			buttons_clicks_order[3] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 2 B
	if (PINC & (1 << 5))
	{
		if (!buttons_clicks_order[4])
		{
			buttons_clicks_order[4] = order_counter;
			is_button_clicked = TRUE;

		}
	}
	//Encoder 2
	if (PINE & (1 << 7))
	{
		if (!buttons_clicks_order[5])
		{
			buttons_clicks_order[5] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 3 A/
	if (PINC & (1 << 6))
	{
		if (!buttons_clicks_order[6])
		{
			buttons_clicks_order[6] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 3 B
	if (PINC & (1 << 7))
	{
		if (!buttons_clicks_order[7])
		{
			buttons_clicks_order[7] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Encoder 3
	if (PING & (1 << 5))
	{
		if (!buttons_clicks_order[8])
		{
			buttons_clicks_order[8] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 4 A
	if (PINE & (1 << 3))
	{
		if (!buttons_clicks_order[9])
		{
			buttons_clicks_order[9] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 4 B
	if (PINE & (1 << 4))
	{
		if (!buttons_clicks_order[10])
		{
			buttons_clicks_order[10] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Encoder 4
	if (PINE & (1 << 6))
	{
		if (!buttons_clicks_order[11])
		{
			buttons_clicks_order[11] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 5 A/
	if (PINC & (1 << 2))
	{
		if (!buttons_clicks_order[12])
		{
			buttons_clicks_order[12] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Player 5 B
	if (PINC & (1 << 3))
	{
		if (!buttons_clicks_order[13])
		{
			buttons_clicks_order[13] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Encoder 5
	if (PINE & (1 << 5))
	{
		if (!buttons_clicks_order[14])
		{
			buttons_clicks_order[14] = order_counter;
			is_button_clicked = TRUE;
		}
	}
	//Global Switch
	if (PING & (1 << 4))
	{
		if (!buttons_clicks_order[15])
		{
			is_button_clicked = TRUE;
			buttons_clicks_order[15] = order_counter;
		}
	}

	//Check if button is pressed and increment counter then
	if (is_button_clicked == TRUE)
	{
		if (order_counter < 65530)
		{
			order_counter++;
		}
	}

	// digitalWrite(ledPin, digitalRead(ledPin) ^ 1);
}