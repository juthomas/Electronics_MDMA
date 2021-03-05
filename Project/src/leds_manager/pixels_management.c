#include "../../inc/mdma.h"

uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color)
{
		// ((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +

	if (color & 0xFF000000)
	{
		pixels[pixel_index * 3] = ((color & 0x00FF00) >> 8) * ((color & 0xFF000000) >> 24) / 0xFF;
		pixels[pixel_index * 3 + 1] = ((color & 0xFF0000) >> 16) * ((color & 0xFF000000) >> 24) / 0xFF;
		pixels[pixel_index * 3 + 2] = (color & 0x0000FF) * ((color & 0xFF000000) >> 24) / 0xFF;
	}
	else
	{
		pixels[pixel_index * 3] = (color & 0x00FF00) >> 8;
		pixels[pixel_index * 3 + 1] = (color & 0xFF0000) >> 16;
		pixels[pixel_index * 3 + 2] = color & 0x0000FF;
	}
	
	return (pixels);
}

uint32_t	rainbow_wheel(uint8_t pos)
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	if (pos < 85)
	{
		red = pos * 3;
		green = 255 - pos * 3;
		blue = 0;
		
	}
	else if (pos < 170)
	{
		pos -= 85;
		red = 255 - pos * 3;
		green = 0;
		blue = pos * 3;

	}
	else 
	{
		pos -= 170;
		red = 0;
		green = pos * 3;
		blue = 255 - pos * 3;
	}
	return (((int32_t)red << (int32_t)16) + ((int32_t)green << (int32_t)8) + (int32_t)blue);
}

uint32_t	reduce_luminosity(uint32_t color, uint8_t percentage)
{
	return (
			((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +
			((((color & 0x00FF00) >> (int32_t)8) * percentage / 100) << (int32_t)8) +
			((((color & 0x0000FF) >> (int32_t)0) * percentage / 100) << (int32_t)0)
		);
}

void	led_draw_animation(uint16_t pixels_number)
{
	uint8_t pixels[pixels_number * 3];
	uint32_t colors = 0xFF0000;

	serial_putstr("hello\r\n");

	ft_pin_mode(51, FT_OUTPUT);
	ft_pin_mode(52, FT_OUTPUT);


	// uint8_t red = 0;
	for (;;)
	{
		for (int i = 0; i < pixels_number; i++)
		{
			feed_one_pixel(i, pixels, rainbow_wheel((colors + i * 10) % 256) + 0x20000000 );
		}
		led_send_data(51, pixels, pixels_number);
		if (colors > 0xFFFFFF)
		{
			colors = 0;
		}
		colors += 5;
	}
}
