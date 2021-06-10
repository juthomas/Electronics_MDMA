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
	init_millis();
	uint8_t led_buffer[62 * 3 * 5];
	init_buttons();
	init_encoders();
	init_leds(led_buffer);
	    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5 | 1 << PIN5, led_buffer, 62 * 3 * 5);

	initSPI();
	
	ili9341_begin();
	ili9341_fillScreen(ILI9341_BLACK);
	start_game(led_buffer);
	return (0);
}
