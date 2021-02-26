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
	// cli();
	DDRB |= (1 << 0);
	DDRB |= (1 << 1);

	// uint8_t data = &DDRB;
	// serial_init();
	// serial_putstr("data : ");
	// serial_putnbr(data);
	// serial_putstr("\r\n");

	uint16_t bytes_number; //(pixels * 3)
	uint8_t pixels[3];

	bytes_number = 3;
	pixels[0] = 0xFF;//green
	pixels[1] = 0x00;//red
	pixels[2] = 0x00;//blue




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
	volatile uint16_t	i;//bytes count
	volatile uint8_t	*ptr;
	volatile uint8_t	*b;
	volatile uint8_t	hi;
	volatile uint8_t	lo;
	volatile uint8_t	next;

	i = bytes_number;
	ptr = pixels;
	b = *ptr++;
	hi = 0b00000011;
	lo = 0b00000000;

	 if((int)b & 0x80)
	 {
		 next = hi;
	 }
	  // Don't "optimize" the OUT calls into the bitTime subroutine;
	  // we're exploiting the RCALL and RET as 3- and 4-cycle NOPs!
	  asm volatile(
	   "headD:"                   "\n\t" //        (T =  0)
		"out   %[port], %[hi]"    "\n\t" //        (T =  1)
		"rcall bitTimeD"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeD"          "\n\t" // Bit 1
		// Bit 0:
		"out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi    (T =  1)
		"rjmp .+0"                "\n\t" // 2    nop nop      (T =  3)
		"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++   (T =  5)
		"out  %[port] , %[next]"  "\n\t" // 1    PORT = next  (T =  6)
		"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo    (T =  7)
		"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80) (T =  8)
		 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi  (T =  9)
		"nop"                     "\n\t" // 1                 (T = 10)
		"out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo    (T = 11)
		"sbiw %[count], 1"        "\n\t" // 2    i--          (T = 13)
		"brne headD"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneD"             "\n\t"
		"bitTimeD:"               "\n\t" //      nop nop nop     (T =  4)
		 "out  %[port], %[next]"  "\n\t" // 1    PORT = next     (T =  5)
		 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo       (T =  6)
		 "rol  %[byte]"           "\n\t" // 1    b <<= 1         (T =  7)
		 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)    (T =  8)
		  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi      (T =  9)
		 "nop"                    "\n\t" // 1                    (T = 10)
		 "out  %[port], %[lo]"    "\n\t" // 1    PORT = lo       (T = 11)
		 "ret"                    "\n\t" // 4    nop nop nop nop (T = 15)
		 "doneD:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTB)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));


		for (int i = 0; i < 1000;i++);

	}
	sei();
}