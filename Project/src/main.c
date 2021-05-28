#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
#include "devilface.h"
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

void display_menu()
{
	int16_t clign = ILI9341_WHITE;
	ili9341_fillScreen(ILI9341_BLACK);
	ili9341_setCursor(0, 0);
	ili9341_print("MEGA\nDRINKING\n", ILI9341_WHITE, 5, 2);
	ili9341_print("MACHINA\n", ILI9341_RED, 5, 2);
	ili9341_print("ADVENTURE\n\n", ILI9341_WHITE, 5, 2);
	int32_t x = cursor_x;
	int32_t y = cursor_y;
	for (int timer = 0; timer < 3; timer++)
	{
		ili9341_setCursor(x, y);
		ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, 2);
	}
}

uint16_t createRGB(uint8_t r, uint8_t g, uint8_t b)
{
	r /= 8;
	g /= 4;
	b /= 8;
	return ((r & 0xff) << 11) + ((g & 0xff) << 5) + (b & 0xff);
}

void display_selection()
{
	ili9341_fillScreen(ILI9341_BLACK);
	ili9341_setCursor(width / 6, 10);
	ili9341_println("WELCOME\n", ILI9341_WHITE, 4, 0);
	ili9341_println("Select your roles\nand press start\nto play your\n", ILI9341_WHITE, 3, 0);
	ili9341_println("    SOULS", ILI9341_RED, 4, 0);
}

unsigned long int next = 56345345540;

int rand(void)
{
	next = next * 1103515243 + 12345;
	return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
	next = seed;
}

void display_intro()
{
	uint8_t red = 255;
	uint8_t green = 255;
	uint8_t blue = 255;
	int position = height / 2 - 10;
	ili9341_setCursor(0, position);
	ili9341_println("    What do you seek ?\n", createRGB(255, 255, 255), 2, 2);
	custom_delay(2000);
	for (int timer = 0; timer < 10; timer++)
	{
		ili9341_setCursor(0, position);
		ili9341_println("    What do you seek ?\n", createRGB(0, 0, 0), 2, 0);
		ili9341_setCursor(0, position);
		ili9341_println("    What do you seek ?\n", createRGB(255, 255, 255), 2, 0);
	}
	ili9341_setCursor(0, position);
	ili9341_print("    What do you seek ?", ILI9341_RED, 2, 0);
	for (int timer = 0; timer < 80; timer++)
	{
		red = (255 - timer * 4) >= 0 ? 255 - timer * 4 : 0;
		ili9341_setCursor(cursor_x, cursor_y);
		ili9341_print("    What do you seek ?", createRGB(red, 0, 0), 2, 0);
		cursor_y = rand() % height;
		cursor_x = rand() % width;
	}
	ili9341_draw_256IMG(DevilEyes, 0, 0, 32, 12, 10);
	for (int timer = 0; timer < 3; timer++)
	{
		ili9341_draw_256IMG(DevilSmile, 0, 120, 32, 12, 10);
		ili9341_draw_256IMG(DevilSmile2, 0, 120, 32, 12, 10);
	}
	ili9341_draw_256IMG(baphomet, 0, 0, 32, 24, 10);
	ili9341_draw_256IMG(pentacle, 0, 0, 32, 24, 10);
}

void reset_button()
{
	//	hit_but = 0;
	for (int i = 0; i < NB_T; i++)
	{
		touch[i] = 0;
	}
}

void mini_gun(){
DDRA = 0b11111111;
while(1)
	PORTA = test[0]

}

void lucky_luck()
{
	uint8_t low = 251;
	uint8_t addr = 20;


	for (int i = 0; i < 5; i++)
	{
		custom_delay(200);
		PORTC |= (1 << 6);
		PORTC |= (1 << 7);
		PORTA |= (1 << 6);
		custom_delay(200);
		PORTA = 0;
		PORTC = 0;
	}
	reset_button();
	low = 251;
	addr = 20;
	custom_delay(2000);
	for (int i = 0; i < NB_T; i++)
	{
		if (touch[i] < low && touch[i])
		{
			addr = i;
			low = touch[i];
		}
	}
	if(addr == 28)
	{
		PORTC |= (1 <<6) && (1 << 7);
		PORTA |= (1 << 6);
	}
	if (addr == 0)
		PORTC |= (1 << 6);
	if (addr == 1)
		PORTC |= (1 << 7);
	if (addr == 2)
		PORTA |= (1 << 6);
	custom_delay(2000);
	lucky_luck(5);
}

int main()
{
	// DDRC |=(1 << 6);
	// 	PORTC |= (1 << 6);
	init_turn();
	uint8_t low = 251;
	uint8_t addr = 20;

	DDRC |= (1 << 6);

	DDRC |= (1 << 7);
	DDRA |= (1 << 6);
	initSPI();
	PORTC = 0;
	//while(1)
	//	test_rfid();  
	//lucky_luck(5);
	mini_gun();
	// for (;;)
	// {
	// 	//demo du fonctionnement des boutons
	// 	PORTA &= ~(1 << 7);
	// 	PORTC = 0;
	// 	PORTA = 0;
	// 	low = 251;
	// 	addr = 20;
	// 	for (int i = 0; i < NB_T; i++)
	// 	{
	// 		if (touch[i] < low && touch[i])
	// 		{
	// 			addr = i;
	// 			low = touch[i];
	// 		}
	// 	}
	// 	reset_button();
	// 	if (addr == 0)
	// 		PORTC |= (1 << 6);
	// 	if (addr == 1)
	// 		PORTC |= (1 << 7);
	// 	if (addr == 2)
	// 		PORTA |= (1 << 6);

	// 	PORTA |= (1 << 7);

	// 	//    if (touch[0])
	// 	// 	{
	// 	// 		PORTC |= (1 << 6);
	// 	// 		touch[0] = 0;
	// 	// 		custom_delay(100);
	// 	// 		PORTC &= ~(1 << 6);

	// 	// 	}
	// 	// 	else
	// 	// 	{
	// 	// 		PORTC &= ~(1 << 6);
	// 	// 	}
	// 	//display_menu();
	// 	// display_selection();
	// 	// PORTC |= (1 << 6);

	// 	//if (*((volatile uint8_t *)38) & (1 << 1))
	// 	//{
	// 	// 	ili9341_setCursor(0,0);
	// 	// 	ili9341_putnbr(counter, ILI9341_BLACK, 2);
	// 	// 	counter++;
	// 	// 	ili9341_setCursor(0,0);
	// 	// 	ili9341_putnbr(counter, ILI9341_WHITE, 2, 0);
	// 	//}
	// 	// if (*((volatile uint8_t *)38) & (1 << 0))
	// 	// {
	// 	// 	ili9341_setCursor(0,0);
	// 	// 	ili9341_putnbr(counter, ILI9341_BLACK, 2, 0);
	// 	// 	counter--;
	// 	// 	ili9341_setCursor(0,0);
	// 	// 	ili9341_putnbr(counter, ILI9341_WHITE, 2, 0);
	// 	// }
	// 	custom_delay(2000);
	// }
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
	display_intro();
	display_menu();
	display_selection();
	DDRC |= (1 << 6);
	for (;;)
	{
		//demo du fonctionnement des boutons
		//display_menu();
		// display_selection();

		//if (*((volatile uint8_t *)38) & (1 << 1))
		//{
		// 	ili9341_setCursor(0,0);
		// 	ili9341_putnbr(counter, ILI9341_BLACK, 2);
		// 	counter++;
		// 	ili9341_setCursor(0,0);
		// 	ili9341_putnbr(counter, ILI9341_WHITE, 2, 0);
		//}
		// if (*((volatile uint8_t *)38) & (1 << 0))
		// {
		// 	ili9341_setCursor(0,0);
		// 	ili9341_putnbr(counter, ILI9341_BLACK, 2, 0);
		// 	counter--;
		// 	ili9341_setCursor(0,0);
		// 	ili9341_putnbr(counter, ILI9341_WHITE, 2, 0);
		// }
		custom_delay(2000);
	}
	return (0);
}
