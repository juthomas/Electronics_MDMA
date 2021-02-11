#ifndef __AVR_ATmega328P__
# define __AVR_ATmega328P__
#endif
#include "avr/io.h"
//https://www.codeproject.com/Articles/15971/Using-Inline-Assembly-in-C-C
//https://developer.arm.com/documentation/100748/0606/Using-Assembly-and-Intrinsics-in-C-or-C---Code/Writing-inline-assembly-code
//https://stackoverflow.com/questions/36560646/r-vs-r-assembly-clarification

int main()
{

	uint8_t red = 255;
	uint8_t green = 255;
	uint8_t blue = 255;
	uint8_t registerLowMask = 0b00000000;//ancien registre + etat haut pin
	uint8_t registerHighMask = 0b00000000;//ancien registre + etat bas pin
	DDRB |= (1 << 0);
	for (;;)
	{
		PORTB = 0b00000001;
		PORTB = 0b00000000;

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		PORTB = 0b00000001;
		PORTB = 0b00000000;

		asm (
			"mov %[high], %[low]\n"
			: :
			[red] "r" (red),
			[green] "r" (green),
			[blue] "r" (blue),
			[low] "r" (registerLowMask),
			[high] "r" (registerHighMask)
			
		);


	}
	return (0);
}