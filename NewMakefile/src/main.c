#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include "avr/io.h"
#include "avr/interrupt.h"

void nothing();





//https://www.codeproject.com/Articles/15971/Using-Inline-Assembly-in-C-C
//https://developer.arm.com/documentation/100748/0606/Using-Assembly-and-Intrinsics-in-C-or-C---Code/Writing-inline-assembly-code
//https://stackoverflow.com/questions/36560646/r-vs-r-assembly-clarification

// pour le truc de "I" _SFR_IO_ADDR(PORT)
//https://www.avrfreaks.net/forum/undefined-reference-pre-pro-symbols-asm
int main()
{
	nothing();

	volatile uint8_t red = 255;
	volatile uint8_t green = 255;
	volatile uint8_t blue = 255;
	volatile uint8_t registerLowMask = 0b00000000;//ancien registre + etat haut pin
	volatile uint8_t registerHighMask = 0b00000011;//ancien registre + etat bas pin
	volatile uint8_t output = 0;
	cli();
	DDRB |= (1 << 0);
	DDRB |= (1 << 1);
	for (;;)
	{
		PORTB = 0b00000001;//~= 0.33us
		PORTB = 0b00000000;//~= 0.33us 

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		asm volatile(
			// ".INCLUDE \"8515def.inc\"\n"
			// "out %[portb], %[low]  \n"//
			// "out %[portb], %[high] \n"//~= 0.08333us
			// "out %[portb], %[high] \n"//~= 0.08333us+0.08333us // fait un "bas haut" chelou
			// "out %[portb], %[high] \n"//~= 0.08333us+0.08333us // fait un "bas haut" chelou
			// "out %[portb], %[high] \n"//~= 0.08333us+0.08333us // fait un "bas haut" chelou
			// "out %[portb], %[high] \n"//~= 0.08333us+0.08333us // fait un "bas haut" chelou
			// "out %[portb], %[low]  \n"//~= 0.1666us
			// "out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			"out %[portb], %[low]  \n"
			"out %[portb], %[high] \n"
			: :
			[red] "r" (red),
			[green] "r" (green),
			[blue] "r" (blue),
			[low] "r" (registerLowMask),
			[high] "r" (registerHighMask),
			[portb] "I" (_SFR_IO_ADDR(PORTB))
		);


	}
	sei();
	return (0);
}