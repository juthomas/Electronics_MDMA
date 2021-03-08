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
}

void	led_send_data_PORTB(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	asm volatile(
		"headB:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeB"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeB"          "\n\t" // Bit 1
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
		"brne headB"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneB"             "\n\t"


		"bitTimeB:"               "\n\t" //      nop nop nop
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
		 "doneB:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTB)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

void	led_send_data_PORTC(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	asm volatile(
		"headC:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeC"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeC"          "\n\t" // Bit 1
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
		"brne headC"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneC"             "\n\t"


		"bitTimeC:"               "\n\t" //      nop nop nop
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
		 "doneC:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTC)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

void	led_send_data_PORTD(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	asm volatile(
		"headD:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
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
		"brne headD"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneD"             "\n\t"


		"bitTimeD:"               "\n\t" //      nop nop nop
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
		 "doneD:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTD)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

void	led_send_data_PORTE(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	// for(;;);
	asm volatile(
		"headE:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeE"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeE"          "\n\t" // Bit 1
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
		"brne headE"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneE"             "\n\t"


		"bitTimeE:"               "\n\t" //      nop nop nop
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
		 "doneE:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTE)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

void	led_send_data_PORTF(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	asm volatile(
		"headF:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeF"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeF"          "\n\t" // Bit 1
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
		"brne headF"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneF"             "\n\t"


		"bitTimeF:"               "\n\t" //      nop nop nop
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
		 "doneF:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTF)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

void	led_send_data_PORTG(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
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
	asm volatile(
		"headG:"                   "\n\t" //        (T =  0)	
		"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
		"rcall bitTimeG"          "\n\t" // Bit 7  (T = 15)
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 6
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 5
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 4
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 3
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 2
		"out   %[port], %[hi]"    "\n\t"
		"rcall bitTimeG"          "\n\t" // Bit 1
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
		"brne headG"              "\n\t" // 2    if(i != 0) -> (next byte)
		 "rjmp doneG"             "\n\t"


		"bitTimeG:"               "\n\t" //      nop nop nop
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
		 "doneG:"                 "\n"
		: [byte]  "+r" (b),
		  [next]  "+r" (next),
		  [count] "+w" (i)
		: [port]   "I" (_SFR_IO_ADDR(PORTG)),
		  [ptr]    "e" (ptr),
		  [hi]     "r" (hi),
		  [lo]     "r" (lo));
}

//https://www.nongnu.org/avr-libc/user-manual/inline_asm.html
//https://github.com/pololu/pololu-led-strip-arduino/blob/master/PololuLedStrip.h
void	led_send_data_PORTH(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
{
	// volatile uint16_t	i;//bytes count
	// volatile uint8_t	*ptr;
	// volatile uint8_t	b;
	// volatile uint8_t	hi;
	// volatile uint8_t	lo;
	// volatile uint8_t	next;

	// i = pixels_number*3;
	// ptr = pixels;
	// b = (*ptr);
	// ptr++;
	// hi = DDRB | mask;
	// lo = DDRB & ~mask;
	// next = lo;
	// if ((int)b & 0x80)
	// {
	// 	next = hi;
	// }
	// asm volatile(
	// 	"headH:"                   "\n\t" //        (T =  0)	
	// 	"cbi   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
	// 	"rcall bitTimeH"          "\n\t" // Bit 7  (T = 15)
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 6
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 5
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 4
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 3
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 2
	// 	"cbi   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeH"          "\n\t" // Bit 1
	// 	// Bit 0:
	// 	"cbi  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
	// 	"nop"                    "\n\t" // 1
	// 	"nop"                    "\n\t" // 1
	// 	"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
	// 	"cbi  %[port] , %[next]"  "\n\t" // 1    PORT = next
	// 	"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo
	// 	"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi
	// 	"nop"                     "\n\t" // 1
	// 	"cbi  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
	// 	"sbiw %[count], 1"        "\n\t" // 2    i--
	// 	"brne headH"              "\n\t" // 2    if(i != 0) -> (next byte)
	// 	 "rjmp doneH"             "\n\t"
	// 	"bitTimeH:"               "\n\t" //      nop nop nop
	// 	 "cbi  %[port], %[next]"  "\n\t" // 1    PORT = next
	// 	 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo
	// 	 "rol  %[byte]"           "\n\t" // 1    b <<= 1
	// 	 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi
	// 	 "nop"                    "\n\t" // 1
	// 	 "cbi  %[port], %[lo]"    "\n\t" // 1    PORT = lo
	// 	 "ret"                    "\n\t" // 4    nop nop nop nop
	// 	 "doneH:"                 "\n"
	// 	: [byte]  "+r" (b),
	// 	  [next]  "+r" (next),
	// 	  [count] "+w" (i)
	// 	: [port]   "I" (_SFR_IO_ADDR(PORTH)),
	// 	  [ptr]    "e" (ptr),
	// 	  [hi]     "r" (hi),
	// 	  [lo]     "r" (lo));

	





}




void	led_send_data_PORTJ(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
{
	// volatile uint16_t	i;//bytes count
	// volatile uint8_t	*ptr;
	// volatile uint8_t	b;
	// volatile uint8_t	hi;
	// volatile uint8_t	lo;
	// volatile uint8_t	next;

	// i = pixels_number*3;
	// ptr = pixels;
	// b = (*ptr);
	// ptr++;
	// hi = DDRB | mask;
	// lo = DDRB & ~mask;
	// next = lo;
	// if ((int)b & 0x80)
	// {
	// 	next = hi;
	// }
	// asm volatile(
	// 	"headJ:"                   "\n\t" //        (T =  0)	
	// 	"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
	// 	"rcall bitTimeJ"          "\n\t" // Bit 7  (T = 15)
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 6
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 5
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 4
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 3
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 2
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeJ"          "\n\t" // Bit 1
	// 	// Bit 0:
	// 	"out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
	// 	"nop"                    "\n\t" // 1
	// 	"nop"                    "\n\t" // 1
	// 	"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
	// 	"out  %[port] , %[next]"  "\n\t" // 1    PORT = next
	// 	"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo
	// 	"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi
	// 	"nop"                     "\n\t" // 1
	// 	"out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
	// 	"sbiw %[count], 1"        "\n\t" // 2    i--
	// 	"brne headJ"              "\n\t" // 2    if(i != 0) -> (next byte)
	// 	 "rjmp doneJ"             "\n\t"
	// 	"bitTimeJ:"               "\n\t" //      nop nop nop
	// 	 "out  %[port], %[next]"  "\n\t" // 1    PORT = next
	// 	 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo
	// 	 "rol  %[byte]"           "\n\t" // 1    b <<= 1
	// 	 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi
	// 	 "nop"                    "\n\t" // 1
	// 	 "out  %[port], %[lo]"    "\n\t" // 1    PORT = lo
	// 	 "ret"                    "\n\t" // 4    nop nop nop nop
	// 	 "doneJ:"                 "\n"
	// 	: [byte]  "+r" (b),
	// 	  [next]  "+r" (next),
	// 	  [count] "+w" (i)
	// 	: [port]   "M" (_SFR_IO_ADDR(PORTJ)),
	// 	  [ptr]    "e" (ptr),
	// 	  [hi]     "r" (hi),
	// 	  [lo]     "r" (lo));
}


void	led_send_data_PORTK(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
{
	// volatile uint16_t	i;//bytes count
	// volatile uint8_t	*ptr;
	// volatile uint8_t	b;
	// volatile uint8_t	hi;
	// volatile uint8_t	lo;
	// volatile uint8_t	next;

	// i = pixels_number*3;
	// ptr = pixels;
	// b = (*ptr);
	// ptr++;
	// hi = DDRB | mask;
	// lo = DDRB & ~mask;
	// next = lo;
	// if ((int)b & 0x80)
	// {
	// 	next = hi;
	// }
	// asm volatile(
	// 	"headK:"                   "\n\t" //        (T =  0)	
	// 	"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
	// 	"rcall bitTimeK"          "\n\t" // Bit 7  (T = 15)
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 6
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 5
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 4
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 3
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 2
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeK"          "\n\t" // Bit 1
	// 	// Bit 0:
	// 	"out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
	// 	"nop"                    "\n\t" // 1
	// 	"nop"                    "\n\t" // 1
	// 	"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
	// 	"out  %[port] , %[next]"  "\n\t" // 1    PORT = next
	// 	"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo
	// 	"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi
	// 	"nop"                     "\n\t" // 1
	// 	"out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
	// 	"sbiw %[count], 1"        "\n\t" // 2    i--
	// 	"brne headK"              "\n\t" // 2    if(i != 0) -> (next byte)
	// 	 "rjmp doneK"             "\n\t"
	// 	"bitTimeK:"               "\n\t" //      nop nop nop
	// 	 "out  %[port], %[next]"  "\n\t" // 1    PORT = next
	// 	 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo
	// 	 "rol  %[byte]"           "\n\t" // 1    b <<= 1
	// 	 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi
	// 	 "nop"                    "\n\t" // 1
	// 	 "out  %[port], %[lo]"    "\n\t" // 1    PORT = lo
	// 	 "ret"                    "\n\t" // 4    nop nop nop nop
	// 	 "doneK:"                 "\n"
	// 	: [byte]  "+r" (b),
	// 	  [next]  "+r" (next),
	// 	  [count] "+w" (i)
	// 	: [port]   "M" (_SFR_IO_ADDR(PORTK)),
	// 	  [ptr]    "e" (ptr),
	// 	  [hi]     "r" (hi),
	// 	  [lo]     "r" (lo));
}


void	led_send_data_PORTL(uint8_t mask, uint8_t *pixels, uint16_t pixels_number)
{
	// volatile uint16_t	i;//bytes count
	// volatile uint8_t	*ptr;
	// volatile uint8_t	b;
	// volatile uint8_t	hi;
	// volatile uint8_t	lo;
	// volatile uint8_t	next;

	// i = pixels_number*3;
	// ptr = pixels;
	// b = (*ptr);
	// ptr++;
	// hi = DDRB | mask;
	// lo = DDRB & ~mask;
	// next = lo;
	// if ((int)b & 0x80)
	// {
	// 	next = hi;
	// }
	// asm volatile(
	// 	"headL:"                   "\n\t" //        (T =  0)	
	// 	"out   %[port], %[hi]"    "\n\t" //        (T =  1) // 1 Tick = 0.0625ms
	// 	"rcall bitTimeL"          "\n\t" // Bit 7  (T = 15)
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 6
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 5
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 4
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 3
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 2
	// 	"out   %[port], %[hi]"    "\n\t"
	// 	"rcall bitTimeL"          "\n\t" // Bit 1
	// 	// Bit 0:
	// 	"out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
	// 	"nop"                    "\n\t" // 1
	// 	"nop"                    "\n\t" // 1
	// 	"ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
	// 	"out  %[port] , %[next]"  "\n\t" // 1    PORT = next
	// 	"mov  %[next] , %[lo]"    "\n\t" // 1    next = lo
	// 	"sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	 "mov %[next] , %[hi]"    "\n\t" // 0-1    next = hi
	// 	"nop"                     "\n\t" // 1
	// 	"out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
	// 	"sbiw %[count], 1"        "\n\t" // 2    i--
	// 	"brne headL"              "\n\t" // 2    if(i != 0) -> (next byte)
	// 	 "rjmp doneL"             "\n\t"
	// 	"bitTimeL:"               "\n\t" //      nop nop nop
	// 	 "out  %[port], %[next]"  "\n\t" // 1    PORT = next
	// 	 "mov  %[next], %[lo]"    "\n\t" // 1    next = lo
	// 	 "rol  %[byte]"           "\n\t" // 1    b <<= 1
	// 	 "sbrc %[byte], 7"        "\n\t" // 1-2  if(b & 0x80)
	// 	  "mov %[next], %[hi]"    "\n\t" // 0-1   next = hi
	// 	 "nop"                    "\n\t" // 1
	// 	 "out  %[port], %[lo]"    "\n\t" // 1    PORT = lo
	// 	 "ret"                    "\n\t" // 4    nop nop nop nop
	// 	 "doneL:"                 "\n"
	// 	: [byte]  "+r" (b),
	// 	  [next]  "+r" (next),
	// 	  [count] "+w" (i)
	// 	: [port]   "M" (_SFR_IO_ADDR(PORTL)),
	// 	  [ptr]    "e" (ptr),
	// 	  [hi]     "r" (hi),
	// 	  [lo]     "r" (lo));
}

void	led_send_data(enum e_pins pin, uint8_t *pixels, uint16_t pixels_number)
{
	//For inform strange pins
	if (g_pin_associations[pin].register_port_addr == FT_PORTH ||
		g_pin_associations[pin].register_port_addr == FT_PORTJ ||
		g_pin_associations[pin].register_port_addr == FT_PORTK ||
		g_pin_associations[pin].register_port_addr == FT_PORTL)
	{
		//Go check this project : //https://github.com/pololu/pololu-led-strip-arduino/blob/master/PololuLedStrip.h
		serial_putstrln("Error Port >= H not yet implemented");
	}
	(*g_asm_sender[pin].func)(g_pin_associations[pin].register_mask, pixels, pixels_number);
	

}