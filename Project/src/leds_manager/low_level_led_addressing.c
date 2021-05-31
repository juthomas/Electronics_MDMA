#include "../inc/mdma.h"
#include "../inc/leds.h"

void	led_send_data_PORTA(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
{
	volatile uint16_t	i;//bytes count
	volatile uint8_t	*ptr;
	volatile uint8_t	b;
	volatile uint8_t	hi;
	volatile uint8_t	lo;
	volatile uint8_t	next;

	i = pixels_number*3;
	ptr = pixels;
	b = (*ptr);
	ptr++;
	hi = DDRB | mask;
	lo = DDRB & ~mask;
	next = lo;
	if ((int)b & 0x80)
	{
		next = hi;
	}
	cli();
	asm volatile(
		"headA:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeA"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeA"          "\n\t" // Bit 1
		// Bit 0:
		"out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
		"nop"                    "\n\t" // 1
		"nop"                    "\n\t" // 1
		"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
		"out  %[port] , %[next]"  "\n\t" // 1    PORT = next
		"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo
		"nop"                     "\n\t" // 1
		"nop"                     "\n\t" // 1
		"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
		 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi
		"out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
		"sbiw %[count], 1"        "\n\t" // 2    i--
		"brne headA"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneA"             "\n\t"


		"bitTimeA:"               "\n\t" //      nop nop nop
		// "nop"                    "\n\t" // 1
		"nop"                    "\n\t" // 1
		 "out  %[port], %[next]"  "\n\t" // 1    PORT = next
		 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo
		 "rol  %[byte]"           "\n\t" // 1    b <<= 1
		 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)
		  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi
		  "nop"                    "\n\t" // 1
		 "out  %[port], %[lo]"    "\n\t" // 1    PORT = lo
		 "ret"                    "\n\t" // 4    nop nop nop nop
		 "doneA:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTA)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
		  sei();
}

void	matrix_send_data(enum e_matrix_activation activation,uint8_t *pixels, uint16_t pixels_number)
{
	led_send_data_PORTA(activation, pixels, pixels_number);
}