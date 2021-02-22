#ifndef __AVR_ATmega2560__
# define __AVR_ATmega2560__
#endif

#include "avr/io.h"
#include "../inc/pin_registers.h"

int main()
{
	
	PORTB = 42;
	nothing();
	return (0);
}