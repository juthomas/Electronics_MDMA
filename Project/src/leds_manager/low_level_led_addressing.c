#include "../inc/mdma.h"

void	led_send_data()
{



	
	// serial_test();
		// nothing();

	volatile uint8_t red = 255;
	volatile uint8_t green = 255;
	volatile uint8_t blue = 255;
	volatile uint8_t registerLowMask = 0b00000000;//ancien registre + etat haut pin
	volatile uint8_t registerHighMask = 0b00000011;//ancien registre + etat bas pin
	volatile uint8_t output = 0;
	cli();
	DDRB |= (1 << 0);
	DDRB |= (1 << 1);

	uint8_t data = &DDRB;
	serial_init();
	serial_putstr("data : ");
	serial_putnbr(data);
	serial_putstr("\r\n");


	for (;;)
	{
		// PORTB = 0b00000001;//~= 0.33us
		// PORTB = 0b00000000;//~= 0.33us 

		// PORTB = 0b00000001;
		// PORTB = 0b00000000;

		// PORTB = 0b00000001;
		// PORTB = 0b00000000;

		// PORTB = 0b00000001;
		// PORTB = 0b00000000;


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
			[portb] "i" (_SFR_IO_ADDR(PORTB))
		);

		    asm volatile (
			"ld __tmp_reg__ , %a0 \n\t"
			"or __tmp_reg__, %1 \n\t"
			"st %a0, __tmp_reg__ \n\t"
			:: "e" (data),
				"r" (1 << 1)
    		);



	}
	sei();
	return (0);



}