#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
//#include "ili9341/dragon.h"

// #define CLK 3
// #define DT 2
// #define SW 4

//int8_t btnState = 0;

#define CPU_CLOCK 2000000
/*
static int v[5] = {0, 0, 0, 0, 0};
static int nb[5] = {0, 0, 0, 0, 0};
static int yo = 0;
*/
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

int main()
{
	//init_turn(); 
	
	int16_t clign = ILI9341_WHITE;
	int16_t x = 0;
	int16_t y = 0;
	int8_t delay = 2;
	ft_pin_mode(4, FT_OUTPUT);
	ft_digital_write(4, FT_LOW);

	initSPI();

	init_rfid();

	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);

	init_turn();

	  ili9341_setRotation(3);

	  play_music();
	led_draw_animation(64);
	  //play_music();

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
	    	//ili9341_setCursor(x, y);
	    	//ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, delay);
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

