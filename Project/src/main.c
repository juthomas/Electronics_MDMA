#include "../inc/mdma.h"

#define CPU_CLOCK 2000000

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

// void	wait_x_cpu_clocks(int32_t cpu_clocks)
// {
// 	while (cpu_clocks > 0)
// 	{
// 		cpu_clocks-=3;
// 	}
// }

// void	custom_delay(uint32_t milli)
// {
// 	milli = milli *	2000;
// 	wait_x_cpu_clocks(milli - 5);
// }

// int main()
// {
// 		serial_init();
// 		serial_putstr("Coucou\r\n");
//     cli();          // disable global interrupts
//     TCCR1A = 0;     // set entire TCCR1A register to 0
//     TCCR1B = 0;     // same for TCCR1B

//     // set compare match register to desired timer count:
//    // OCR1A = 3123;
//     OCR1A = 1562;
//     // turn on CTC mode:
//     TCCR1B |= (1 << WGM12);
//     // Set CS10 and CS12 bits for 1024 prescaler:
//     TCCR1B |= (1 << CS10);
//     TCCR1B |= (1 << CS12);
//     // enable timer compare interrupt:
//     TIMSK1 |= (1 << OCIE1A);
//     // enable global interrupts:
//     sei();
// 		// serial_putstr("Coucou Bro\r\n");


// 	//serial_putstr("Redemarage \r\n");
// 	//play_music();
// 	//serial_putstr("fin de la musique \r\n");

// 	// ft_pin_mode(33, FT_OUTPUT);
// 	// for (;;)
// 	// {
// 	// 	ft_digital_write(33, FT_HIGH);
// 	// 	// ft_digital_write(33, FT_LOW);
// 	// 
// 	// led_send_data();
// 	// serial_putstr("Byebye\r\n");
// 	// serial_test();

// 	for (;;)	
// 	{
// 	}
// 	return (0);
// }
volatile int8_t hehe = 0;

int main()
{
	// serial_init(); 
	// serial_putstr("Reboot\n\r");

   for(;;)
   {
	play_music();
   }
   ft_pin_mode(33, FT_OUTPUT);


// // initialize Timer1
// cli(); // disable global interrupts
//         TCCR2B = (TCCR2B & 0b11111000) | 0b011;
// OCR2A = 255;
//         bitWrite(TIMSK2, OCIE2A, 1);

// sei();



// 	serial_putstr("Hello\n\r");

//    for(;;)
//    {
// 	   serial_putnbr(hehe);
// 	   serial_putstr("bbbb \r\n");
//    }
   return 0;
}

