#include "../inc/mdma.h"
#include "../inc/tone.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"
#define CPU_CLOCK 2000000

void draw_buttons(uint8_t *led_buffer)
{
	uint32_t interactions_color = 0x090909;
	// draw_satanic_circle();
	clear_led_buffer(led_buffer, 0x090000);

	if (buttons_clicks_order[15])
	{
		draw_cirle_pit(led_buffer, 500, 5, D_WAWES, LED_ROW_1, interactions_color, 0x000000);
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
	// serial_init();
	// serial_putstr("Reboot\n\r");
	uint8_t led_buffer[62 * 3 * 5];
	init_leds(led_buffer);
	init_buttons();
	draw_satanic_circle();

	for (;;)
	{
		// draw_cirle_pit(led_buffer, 1000, 5, D_WAWES, LED_ROW_MAX, 0x110000, 0x000000);
		// play_music();

		draw_buttons(led_buffer);
		// led_draw_animation(64);
		clear_buttons();
		for (uint32_t i = 0; i < 100000; i++)
			;
	}
	//    ft_pin_mode(33, FT_OUTPUT);
	DDRC |= 1 << PIN4;

	// uint8_t pixels[3];
	// uint16_t pixels_number = 1;
	// pixels[0] = 0xFF;//green
	// pixels[1] = 0xFF;//red
	// pixels[2] = 0xFF;//blue
	// led_send_data(pixels, pixels_number);

	//70 fps loop (88 leds)
	led_draw_animation(64);

	return 0;
}
