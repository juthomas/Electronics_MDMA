#include <avr/io.h>
#include "../inc/mdma.h"
#include <avr/interrupt.h>
#include "ili9341/dragon.h"
#define CLK 3
#define DT 2
#define SW 4

int8_t btnState = 0;

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

ISR(INT4_vect)
{
	btnState = !btnState;
}

ISR(INT5_vect)
{
	//btnState = !btnState;
}

void init_interrupt()
{
	cli();
	DDRA = 0xff;
	DDRB = 0xff;
	DDRE &= 0b11001111;
	//PORTE = (1<<PIN5)|(1<<PIN4);
	EICRB = (1 << ISC50) | (1 << ISC40);
	EIMSK = (1 << INT5) | (1 << INT4);
	sei();
}

int main()
{
	int16_t clign = ILI9341_WHITE;
	int16_t x = 0;
	int16_t y = 0;
	ft_pin_mode(CLK, FT_INPUT);
	ft_pin_mode(DT, FT_INPUT);
	ft_pin_mode(SW, FT_INPUT);
	ili9341_begin();
	serial_init();
	ili9341_fillScreen(ILI9341_BLACK);
	ili9341_draw_256IMG(dragonBitmap, 0, 0, DRAGON_WIDTH, DRAGON_HEIGHT, 1);
	//init_interrupt();

	//ili9341_setRotation(3);
	//graphic_test();

	// // //ili9341_fillScreen(ILI9341_BLACK);
	// // for (;;)
	// // {
	// // 	serial_putstrln("Nope For The moment");
	// // 	ili9341_setCursor(0, 0);
	// // 	ili9341_println("MEGA\nDRINKING\n", ILI9341_WHITE, 5, 2);
	// // 	ili9341_println("MACHINA\n", ILI9341_RED, 5, 2);
	// // 	ili9341_println("ADVENTURE\n\n", ILI9341_WHITE, 5, 2);
	// // 	x = cursor_x;
	// // 	y = cursor_y;
	// // 	while (1)
	// // 	{
	// // 		btnState = ft_digital_read(SW);
	// // 		ili9341_setCursor(x, y);
	// // 		ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, 2);
	// // 	}
	// // }
	// // serial_putstr("Ended as it can lol");
	return (0);
}

// #define CLK 3
// #define DT 2
// #define SW 4

// int counter = 0;
// int currentStateCLK;
// int btnState = 0;
// int lastStateCLK;
// char *currentDir = "";
// unsigned long lastButtonPress = 0;

// int main()
// {
// 	// Set encoder pins as inputs
// 	ft_pin_mode(CLK, FT_INPUT);
// 	ft_pin_mode(DT, FT_INPUT);
// 	ft_pin_mode(SW, FT_INPUT);

// 	// Setup Serial Monitor
// 	serial_init();

// 	// Read the initial state of CLK
// 	lastStateCLK = ft_digital_read(CLK);
// 	btnState = ft_digital_read(SW);
// 	// Read the current state of CLK

// 	while (1)
// 	{
// 		currentStateCLK = ft_digital_read(CLK);
// 		btnState = ft_digital_read(SW);
// 		if (currentStateCLK != lastStateCLK && currentStateCLK == 1)
// 		{
// 			if (ft_digital_read(DT) != currentStateCLK)
// 			{
// 				counter--;
// 				currentDir = "CCW";
// 			}
// 			else
// 			{
// 				counter++;
// 				currentDir = "CW";
// 			}
// 			serial_putstrln("Direction: ");
// 			serial_putstrln(currentDir);
// 			serial_putstrln(" | Counter: ");
// 			serial_putnbrln(counter);
// 		}
// 		lastStateCLK = currentStateCLK;
// 		if (btnState == FT_HIGH)
// 				serial_putstrln("Button pressed!");
// 		custom_delay(1);
// 	}
// }