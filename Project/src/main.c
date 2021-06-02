#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
//#include "../inc/ili9341.h"
//#include "../inc/games.h"
//#include "ili9341/dragon.h"

// #define CLK 3
// #define DT 2
// #define SW 4

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
	*((volatile uint8_t *)39) &= ~(1 << 1);
	*((volatile uint8_t *)39) &= ~(1 << 0);
	display_intro_game(0, 1);
	for(;;)
	//display_intro();
	//display_menu();
	for (;;)
	{
		custom_delay(100);
	}
	return (0);
}
