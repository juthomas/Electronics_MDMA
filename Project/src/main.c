#include <avr/io.h>
#include "../inc/mdma.h"
#include "../inc/tone.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"
#include "../inc/matrix_progmem.h"

#define CPU_CLOCK 2000000

void draw_buttons(uint8_t *led_buffer)
{
	uint32_t interactions_color = 0x090909;
	// draw_satanic_circle();
	clear_led_buffer(led_buffer, 0x090000);

	if (buttons_clicks_order[15])
	{
		draw_cirle_pit(led_buffer, 500, 5, D_WAWES, LED_ROW_1, interactions_color, 0x090000);
	}
	for (int i = 0; i < 5; i++)
	{
		if (buttons_clicks_order[i * 3])
		{
			draw_line_between_players(led_buffer, ((i + 0) % 5) + 1, ((i + 1) % 5) + 1,
									  FALSE, interactions_color);
		}
		led_send_data_PORTA(1 << PIN5, led_buffer, 62 * 5);
		if (buttons_clicks_order[i * 3 + 1])
		{
			draw_line_between_players(led_buffer, ((i + 0) % 5) + 1, ((i + 4) % 5) + 1,
									  FALSE, interactions_color);
		}
		if (buttons_clicks_order[i * 3 + 2])
		{
			draw_line_between_players(led_buffer, ((i + 0) % 5) + 1, ((i + 2) % 5) + 1,
									  FALSE, interactions_color);
		}
	}
	led_send_data_PORTA(1 << PIN5, led_buffer, 62 * 5);
}

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

uint8_t dice_game(uint8_t player)
{
	uint8_t matrix_mask;
	if (player == 1)
	{
		matrix_mask = MAT_1;
	}
	else if (player == 2)
	{
		matrix_mask = MAT_2;
	}
	else if (player == 3)
	{
		matrix_mask = MAT_3;
	}
	else if (player == 4)
	{
		matrix_mask = MAT_4;
	}
	else if (player == 5)
	{
		matrix_mask = MAT_5;
	}



	uint16_t counter = 0;
	while (!buttons_clicks_order[(player - 1) * 3 + 1])
	{
		for (uint32_t i = 0; i < 100000; i++);
	}
	while (buttons_clicks_order[(player - 1) * 3 + 1])
	{
		clear_buttons();
		if (counter % 6 == 0)
		{
			led_matrix_send_progmem(matrix_mask, DICE_1);
		}
		if (counter % 6 == 1)
		{

		led_matrix_send_progmem(matrix_mask, DICE_2);
		}

		if (counter % 6 == 2)

		led_matrix_send_progmem(matrix_mask, DICE_3);

		if (counter % 6 == 3)

		led_matrix_send_progmem(matrix_mask, DICE_4);
		if (counter % 6 == 4)

		led_matrix_send_progmem(matrix_mask, DICE_5);

		if (counter % 6 == 5)

		led_matrix_send_progmem(matrix_mask, DICE_6);
		for (int32_t i = 0; i < 40000; i++)
			;
		counter++;
		if (counter > 300000)
		counter = 0;
	}
	for (int32_t u = 1; u < 5; u++)
	{
		if ((counter + u)% 6 == 0)
		{
			led_matrix_send_progmem(matrix_mask, DICE_1);
		}
		if ((counter + u) % 6 == 1)
		{

		led_matrix_send_progmem(matrix_mask, DICE_2);
		}

		if ((counter + u) % 6 == 2)

		led_matrix_send_progmem(matrix_mask, DICE_3);

		if ((counter + u) % 6 == 3)

		led_matrix_send_progmem(matrix_mask, DICE_4);
		if ((counter + u) % 6 == 4)

		led_matrix_send_progmem(matrix_mask, DICE_5);

		if ((counter + u) % 6 == 5)

		led_matrix_send_progmem(matrix_mask, DICE_6);
		for (int32_t i = 0; i < 40000 * u; i++)
			;
	}
	return ((counter + 4) % 6);
}

int main()
{
	//init_turn();

	// int16_t x = 0;
	// int16_t y = 0;
	// int8_t delay = 2;
	// int8_t set = 0;
	// int16_t counter = 0;
	// int8_t buttonGreenState = FT_LOW;
	// int8_t buttonRedState = FT_LOW;


	uint8_t led_buffer[62 * 3 * 5];
	init_buttons();
	init_leds(led_buffer);

	initSPI();
	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);
	draw_satanic_circle();
	ili9341_setRotation(3);
	display_intro();
	display_menu();
	ili9341_fillScreen(ILI9341_BLACK);

	
	
	uint8_t dice_result_1 = dice_game(1);
	uint8_t dice_result_2 = dice_game(1);
	display_intro_game(5, 3);
	do_you_rather(led_buffer);
	// dice_game(2);
	// dice_game(3);
	// dice_game(4);
	// dice_game(5);

	// *((volatile uint8_t *)39) &= ~(1 << 1);
	// *((volatile uint8_t *)39) &= ~(1 << 0);
	//display_intro_game(0, 1);
		// serial_init();
	// serial_putstr("Reboot\n\r");
	// uint8_t led_buffer[62 * 3 * 5];
	// init_leds(led_buffer);
	// init_buttons();
	// for (uint32_t i = 0; i < 100000; i++)
	// 	;
	// draw_satanic_circle();
	// for (uint32_t i = 0; i < 100000; i++)
	// 	;
	// draw_satanic_circle();

	// for (;;)
	// {
	// 	// draw_cirle_pit(led_buffer, 1000, 5, D_WAWES, LED_ROW_MAX, 0x110000, 0x000000);
	// 	// play_music();

	// 	draw_buttons(led_buffer);
	// 	// led_draw_animation(64);
	// 	clear_buttons();
	// 	for (uint32_t i = 0; i < 100000; i++)
	// 		;
	// }
	// //    ft_pin_mode(33, FT_OUTPUT);
	// DDRC |= 1 << PIN4;
	// for (;;)
	// {
	// 	custom_delay(100);
	// }
	return (0);
}
