#include "../inc/mdma.h"


uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color)
{
	pixels[pixel_index * 3] = (color & 0x00FF00) >> 8;
	pixels[pixel_index * 3 + 1] = (color & 0xFF0000) >> 16;
	pixels[pixel_index * 3 + 2] = color & 0x0000FF;
	return (pixels);
}

void	led_draw_animation(uint16_t pixels_number)
{
	uint8_t pixels[pixels_number * 3];
	uint32_t colors = 0xFF0000;

	serial_putstr("hello\r\n");


	for (;;)
	{

		for (int i = 0; i < pixels_number; i++)
		{
			feed_one_pixel(i, pixels, colors);
			colors += 2;
		}
		led_send_data(pixels, pixels_number);
		for (int i = 0; i < 10000;i++);
		if (colors > 0xFFFFFF)
		{
			colors = 0;
		}
	}

}


void	led_send_data(uint8_t *pixels, uint16_t pixels_number)
{


	// cli();
	DDRB |= (1 << 0);
	DDRB |= (1 << 1);







	volatile uint16_t	i;//bytes count
	volatile uint8_t	*ptr;
	volatile uint8_t	*b;
	volatile uint8_t	hi;
	volatile uint8_t	lo;
	volatile uint8_t	next;

	i = pixels_number*3;
	ptr = pixels;
	b = (uint8_t)(*ptr++);
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

	// sei();
}