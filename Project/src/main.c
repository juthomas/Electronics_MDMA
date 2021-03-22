#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
//#include "ili9341/dragon.h"

// #define CLK 3
// #define DT 2
// #define SW 4

//int8_t btnState = 0;

#define CPU_CLOCK 2000000
#define DT 61
#define CLK 11
static int v[5] = {0, 0, 0, 0, 0};
static int nb[5] = {0, 0, 0, 0, 0};
static int yo = 0;

void wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks -= 3;
	}
}

void custom_delay(uint32_t milli)
{
	milli = milli * 2000;
	wait_x_cpu_clocks(milli - 5);
}

void bouton_state(int now, int index)
{

	if ((v[index] == 0 && now == 2) || (v[index] == 2 && now == 3) || (v[index] == 3 && now == 1) || (v[index] == 1 && now == 0))
		nb[index]++;
	else if (((v[index] == 0 && now == 1) || (v[index] == 2 && now == 0) || (v[index] == 3 && now == 2) || (v[index] == 1 && now == 3)))
		nb[index]--;
	v[index] = now;
}

ISR(PCINT0_vect)
{
	//ili9341_println("yo", ILI9341_WHITE, 1, 0);

		ft_digital_write(4, FT_HIGH);

	int a = 0;
	a = ((PINB & (1 << PINB5)) >> PINB5) << 1;
	a += (PINB & (1 << PINB4)) >> PINB4;
	bouton_state(a, 0);

	a = ((PINB & (1 << PINB7)) >> PINB7) << 1;
	a += (PINB & (1 << PINB6)) >> PINB6;
	bouton_state(a, 1);

	yo = 1;
}

ISR(PCINT2_vect)
{

	int a = 0;
		ft_digital_write(4, FT_HIGH);
	a = ((PINK & (1 << PINK1)) >> PINK1) << 1;
	a += (PINK & (1 << PINK0)) >> PINK0;
	bouton_state(a, 2);

	a = ((PINK & (1 << PINK3)) >> PINK3) << 1;
	a += (PINK & (1 << PINK2)) >> PINK2;
	bouton_state(a, 3);

	a = ((PINK & (1 << PINK5)) >> PINK5) << 1;
	a += (PINK & (1 << PINK4)) >> PINK4;
	bouton_state(a, 4);

	yo = 1;
}

int button_POC()
{
	//serial_init();
	// enable UDRE interrupt and enable transmit
	// UCSR0B |= (1 << UDRIE0) | (1 << TXEN0);

	// // set character data size to 8
	// UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);

	// // baud rate 9600
	// UBRR0 = 103;

	//PCIFR = (1 << PCIF0);
	//DDRB &= ~((1 << DDB7) | (1 << DDB5) | (1 << DDB4) | (1 << DDB6)); // Clear the PB0, PB1, PB2 pin

	DDRB = 0b00000000;
	// PB0,PB1,PB2 (PCINT0, PCINT1, PCINT2 pin) are now inputs
	PORTB |= ((1 << PORTB7) | (1 << PORTB5) | (1 << PORTB4) | (1 << PORTB6)); // turn On the Pull-up
	DDRB = 0b00000000;
	
	
	PORTK |= 0b00111111;													  // activer de portk0 as portk5
	//PORTB = 0b11100000;
	// PB0, PB1 and PB2 are now inputs with pull-up enabled
	PCICR |= ((1 << PCIE0) | (1 << PCIE2));
	//EIMSK |= (1 << INT0 | 1 << INT1); //autoriser interupt sur INT0
	PCMSK0 = ((1 << PCINT7) | (1 << PCINT5) | (1 << PCINT4) | (1 << PCINT6)); //autoriser les interupt sur pcint0 et pcint2
	PCMSK0 = 0b00111111;
	PCMSK2 = 0b00111111;
	//PCMSK0 = 0b11100000; // Hard code pcq nsm
	//EICRA |= (1 << ISC01 | 1 << ISC11); //interupt on higt

	SREG = 0b10000000; //global interrupt enable

	//	ft_pin_mode(CLK, FT_INPUT);

	for (;;)
	{
		if (yo)
		{
			//ft_digital_write(13,  FT_LOW);
			// ili9341_print("id 0:[", ILI9341_WHITE, 1, 0);
			// ili9341_putnbr(nb[0], ILI9341_WHITE, 1, 0);
			// ili9341_print("]id 1:[", ILI9341_WHITE, 1, 0);
			// ili9341_putnbr(nb[1], ILI9341_WHITE, 1, 0);
			// ili9341_print("]id 2:[", ILI9341_WHITE, 1, 0);
			// ili9341_putnbr(nb[2], ILI9341_WHITE, 1, 0);
			// ili9341_print("]id 3:[", ILI9341_WHITE, 1, 0);
			// ili9341_putnbr(nb[3], ILI9341_WHITE, 1, 0);
			// ili9341_print("]id 4:[", ILI9341_WHITE, 1, 0);
			// ili9341_putnbr(nb[4], ILI9341_WHITE, 1, 0);
			// ili9341_println("", ILI9341_WHITE, 1, 0);
			yo = 0;
		}
	}

	return (0);
}

//mon meilleur main
int main()
{
	int16_t clign = ILI9341_WHITE;
	int16_t x = 0;
	int16_t y = 0;
	int8_t delay = 2;
	ft_pin_mode(4, FT_OUTPUT);
	ft_digital_write(4, FT_LOW);

	//initSPI();

	//init_rfid();

	//ili9341_begin();
	//ili9341_fillScreen(ILI9341_BLACK);
	button_POC();

	  ili9341_setRotation(3);
	  ili9341_fillScreen(ILI9341_BLACK);
	  play_music();
		led_draw_animation(64);
	  play_music();

	  for (;;)
	  {
	    //serial_putstrln("Nope For The moment");
	    ili9341_setCursor(0, 0);
	    ili9341_print("MEGA\nDRINKING\n", ILI9341_WHITE, 5, delay);
	    ili9341_print("MACHINA\n", ILI9341_RED, 5, delay);
	    ili9341_print("ADVENTURE\n\n", ILI9341_WHITE, 5, delay);
	    x = cursor_x;
	    y = cursor_y;
	    while (!test_rfid())
	    {
	    	ili9341_setCursor(x, y);
	    	ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, delay);
	    }
	    ili9341_fillScreen(ILI9341_BLACK);
	    ili9341_setCursor(0, 0);
	    while(1)
	    {
	      ili9341_setCursor(0, 0);
	      ili9341_println("WELCOME ", ILI9341_WHITE, 5, 0);
	      ili9341_println("PARTY BOI", clign = (clign == ILI9341_YELLOW ? ILI9341_RED : ILI9341_YELLOW), 5, 0);
	      ili9341_println("!!!!", ILI9341_WHITE, 5, 0);
	      ili9341_println("(le boss)", ILI9341_WHITE, 1, 0);
		  custom_delay(1000);
	    }
	    test_rfid();
	  }
	serial_putstr("Ended as it can lol");
	return (0);
}
// int main()
// {
// 	// serial_init();
// 	// serial_putstr("Reboot\n\r");

//    for(;;)
//    {
// 	play_music();
// 	led_draw_animation(64);
//    }
//    ft_pin_mode(33, FT_OUTPUT);

// 	// uint8_t pixels[3];
// 	// uint16_t pixels_number = 1;
// 	// pixels[0] = 0xFF;//green
// 	// pixels[1] = 0xFF;//red
// 	// pixels[2] = 0xFF;//blue
// 	// led_send_data(pixels, pixels_number);

// 	//70 fps loop (88 leds)
// 	led_draw_animation(64);

//    return 0;
// }

