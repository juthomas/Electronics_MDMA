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
	pixels[0] = 0xFF;
	pixels[1] = 0xFF;
	pixels[2] = 0xFF;




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
	volatile uint8_t	n1;
	volatile uint8_t	n2;

	i = bytes_number;
	ptr = pixels;
	b = *ptr++;
	hi = 0b00000011;
	lo = 0b00000000;
	n1 = lo;


      asm volatile(
       "headD:"                   "\n\t" // Clk  Pseudocode
        // Bit 7:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n2]   , %[lo]"    "\n\t" // 1    n2   = lo
        "out  %[port] , %[n1]"    "\n\t" // 1    PORT = n1
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 6"        "\n\t" // 1-2  if(b & 0x40)
         "mov %[n2]   , %[hi]"    "\n\t" // 0-1   n2 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 6:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n1]   , %[lo]"    "\n\t" // 1    n1   = lo
        "out  %[port] , %[n2]"    "\n\t" // 1    PORT = n2
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 5"        "\n\t" // 1-2  if(b & 0x20)
         "mov %[n1]   , %[hi]"    "\n\t" // 0-1   n1 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 5:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n2]   , %[lo]"    "\n\t" // 1    n2   = lo
        "out  %[port] , %[n1]"    "\n\t" // 1    PORT = n1
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 4"        "\n\t" // 1-2  if(b & 0x10)
         "mov %[n2]   , %[hi]"    "\n\t" // 0-1   n2 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 4:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n1]   , %[lo]"    "\n\t" // 1    n1   = lo
        "out  %[port] , %[n2]"    "\n\t" // 1    PORT = n2
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 3"        "\n\t" // 1-2  if(b & 0x08)
         "mov %[n1]   , %[hi]"    "\n\t" // 0-1   n1 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 3:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n2]   , %[lo]"    "\n\t" // 1    n2   = lo
        "out  %[port] , %[n1]"    "\n\t" // 1    PORT = n1
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 2"        "\n\t" // 1-2  if(b & 0x04)
         "mov %[n2]   , %[hi]"    "\n\t" // 0-1   n2 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 2:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n1]   , %[lo]"    "\n\t" // 1    n1   = lo
        "out  %[port] , %[n2]"    "\n\t" // 1    PORT = n2
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 1"        "\n\t" // 1-2  if(b & 0x02)
         "mov %[n1]   , %[hi]"    "\n\t" // 0-1   n1 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "rjmp .+0"                "\n\t" // 2    nop nop
        // Bit 1:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n2]   , %[lo]"    "\n\t" // 1    n2   = lo
        "out  %[port] , %[n1]"    "\n\t" // 1    PORT = n1
        "rjmp .+0"                "\n\t" // 2    nop nop
        "sbrc %[byte] , 0"        "\n\t" // 1-2  if(b & 0x01)
         "mov %[n2]   , %[hi]"    "\n\t" // 0-1   n2 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "sbiw %[count], 1"        "\n\t" // 2    i-- (don't act on Z flag yet)
        // Bit 0:
        "out  %[port] , %[hi]"    "\n\t" // 1    PORT = hi
        "mov  %[n1]   , %[lo]"    "\n\t" // 1    n1   = lo
        "out  %[port] , %[n2]"    "\n\t" // 1    PORT = n2
        "ld   %[byte] , %a[ptr]+" "\n\t" // 2    b = *ptr++
        "sbrc %[byte] , 7"        "\n\t" // 1-2  if(b & 0x80)
         "mov %[n1]   , %[hi]"    "\n\t" // 0-1   n1 = hi
        "out  %[port] , %[lo]"    "\n\t" // 1    PORT = lo
        "brne headD"              "\n"   // 2    while(i) (Z flag set above)
      : [byte]  "+r" (b),
        [n1]    "+r" (n1),
        [n2]    "+r" (n2),
        [count] "+w" (i)
      : [port]   "I" (_SFR_IO_ADDR(PORTB)),
        [ptr]    "e" (ptr),
        [hi]     "r" (hi),
        [lo]     "r" (lo));

		for (int i = 0; i < 1000;i++);

	}
	sei();
}