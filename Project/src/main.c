#include <avr/io.h>
#include "../inc/mdma.h"
#include "../inc/tone.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"
//#include "../inc/matrix_progmem.h"
#include "../inc/millis.h"
#include "../inc/encoders.h"

#define CPU_CLOCK 2000000

void draw_buttons(uint8_t *led_buffer)
{
	uint32_t interactions_color = 0x090909;
	// draw_satanic_circle();
	clear_led_buffer(led_buffer, 62 * 3 * 5,0x090000);

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

	init_millis();
	uint8_t led_buffer[62 * 3 * 5];
	init_buttons();
	init_encoders();

	init_leds(led_buffer);
	    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5 | 1 << PIN5, led_buffer, 62 * 3 * 5);
	// led_send_data(3, pixels, 64);
	// led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5 | 1 << PIN5, led_buffer, 64*5);

	// for (int i = 0; i < 100; i++)
	// {
	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, i, 0x101010);
	// 	led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, led_buffer, 64);
	// 	for (uint32_t i = 0; i < 20000; i++);
	// }

	initSPI();
	
	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);
	start_game(led_buffer);
	//for(;;);
	//display_intro();
	//draw_satanic_circle();
	//display_intro_game(dice_result_1 + dice_result_2 - 2, 3);
	//do_you_rather(led_buffer);
	// for (;;)
	// {
		
	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, encoder1, 0x101010);
	// 	led_send_data_PORTA(MAT_1, led_buffer, 64);

	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, encoder2, 0x101010);
	// 	led_send_data_PORTA(MAT_2, led_buffer, 64);
		
	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, encoder3, 0x101010);
	// 	led_send_data_PORTA(MAT_3, led_buffer, 64);
		
	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, encoder4, 0x101010);
	// 	led_send_data_PORTA(MAT_4, led_buffer, 64);
		
	// 	led_matrix_fill_screen(led_buffer, 0, 0, 0);
	// 	draw_numbers(led_buffer, encoder5, 0x101010);
	// 	led_send_data_PORTA(MAT_5, led_buffer, 64);


	// 	for (uint32_t i = 0; i < 400000; i++);

	// }
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
