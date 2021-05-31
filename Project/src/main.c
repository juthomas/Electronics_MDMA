#include "../inc/mdma.h"
#include "../inc/tone.h"
#include "../inc/leds.h"

#define CPU_CLOCK 2000000

int main()
{
	// serial_init();
	// serial_putstr("Reboot\n\r");
	uint8_t led_buffer[62 * 3 * 5];
	init_leds(led_buffer);
	for (;;)
	{
		draw_cirle_pit(led_buffer, 1000, 5, D_WAWES, LED_ROW_MAX, 0x110000, 0x000000);
		// play_music();
		// led_draw_animation(64);
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
