#include <avr/io.h>
#include "../inc/mdma.h"
#include "../inc/tone.h"
#include "../inc/leds.h"

#define CPU_CLOCK 2000000

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

	int16_t x = 0;
	int16_t y = 0;
	int8_t delay = 2;
	int8_t set = 0;
	int16_t counter = 0;
	int8_t buttonGreenState = FT_LOW;
	int8_t buttonRedState = FT_LOW;

	
	initSPI();
	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);
	ili9341_setRotation(1);
		display_intro();
	*((volatile uint8_t *)39) &= ~(1 << 1);
	*((volatile uint8_t *)39) &= ~(1 << 0);
	//display_intro_game(0, 1);
		// serial_init();
	// serial_putstr("Reboot\n\r");
	uint8_t led_buffer[62 * 3 * 5];
	init_leds(led_buffer);
	//display_menu();
	for (;;)
	{
		//draw_cirle_pit(led_buffer, 1000, 5, D_WAWES, LED_ROW_MAX, 0x110000, 0x000000);
		// play_music();
		led_draw_animation(64);
	}
	//    ft_pin_mode(33, FT_OUTPUT);
	DDRC |= 1 << PIN4;
	for (;;)
	{
		custom_delay(100);
	}
	return (0);
}
