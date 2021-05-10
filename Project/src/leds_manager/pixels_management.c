#include "../../inc/mdma.h"
#include "../../inc/leds.h"
#include "../../inc/matrix_progmem.h"



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

uint32_t led_rainbow_wheel(uint8_t pos)
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

uint32_t led_reduce_luminosity(uint32_t color, uint8_t percentage)
{
	return (
		((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +
		((((color & 0x00FF00) >> (int32_t)8) * percentage / 100) << (int32_t)8) +
		((((color & 0x0000FF) >> (int32_t)0) * percentage / 100) << (int32_t)0));
}



int32_t ft_sqrt(int32_t x)
{
	if (x == 0 || x == 1)
	{
		return x;
	}
	int32_t i = 1, result = 1;
	while (result <= x)
	{
		i++;
		result = i * i;
	}
	return i - 1;
}

void led_matrix_draw_line(uint8_t *pixels, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t red, uint8_t green, uint8_t blue)
{
	int dx = ABS(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -ABS(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	for (;;)
	{	/* loop */
		//   setPixel(x0,y0);
		pixels[(x0 * 8 + y0) * 3] = green;
		pixels[(x0 * 8 + y0) * 3 + 1] = red;
		pixels[(x0 * 8 + y0) * 3 + 2] = blue;
		if (x0 == x1 && y0 == y1)
			break;
		e2 = 2 * err;
		if (e2 >= dy)
		{
			err += dy;
			x0 += sx;
		} /* e_xy+e_x > 0 */
		if (e2 <= dx)
		{
			err += dx;
			y0 += sy;
		} /* e_xy+e_y < 0 */
	}
}

void led_matrix_draw_filled_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue)
{
	for (uint8_t tmph = 0; tmph < h + 1; tmph++)
	{
		for (uint8_t tmpw = 0; tmpw < w + 1; tmpw++)
		{
			pixels[((x + tmpw) * 8 + (y + tmph)) * 3] = green;
			pixels[((x + tmpw) * 8 + (y + tmph)) * 3 + 1] = red;
			pixels[((x + tmpw) * 8 + (y + tmph)) * 3 + 2] = blue;
		}
	}
}

void led_matrix_draw_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue)
{
	for (uint8_t tmph = 0; tmph < h; tmph++)
	{
		pixels[((x) * 8 + (y + tmph)) * 3] = green;
		pixels[((x) * 8 + (y + tmph)) * 3 + 1] = red;
		pixels[((x) * 8 + (y + tmph)) * 3 + 2] = blue;
		pixels[((x + w) * 8 + (y + tmph)) * 3] = green;
		pixels[((x + w) * 8 + (y + tmph)) * 3 + 1] = red;
		pixels[((x + w) * 8 + (y + tmph)) * 3 + 2] = blue;
	}
	for (uint8_t tmpw = 0; tmpw < w + 1; tmpw++)
	{
		pixels[((x + tmpw) * 8 + (y)) * 3] = green;
		pixels[((x + tmpw) * 8 + (y)) * 3 + 1] = red;
		pixels[((x + tmpw) * 8 + (y)) * 3 + 2] = blue;
		pixels[((x + tmpw) * 8 + (y + h)) * 3] = green;
		pixels[((x + tmpw) * 8 + (y + h)) * 3 + 1] = red;
		pixels[((x + tmpw) * 8 + (y + h)) * 3 + 2] = blue;
	}
}

void led_matrix_fill_screen(uint8_t *pixels, uint8_t red, uint8_t green, uint8_t blue)
{
	for (int i = 0; i < 64; i++)
	{
		pixels[i * 3] = green;
		pixels[i * 3 + 1] = red;
		pixels[i * 3 + 2] = blue;
	}
}


//Didnt work !
void led_matrix_draw_anti_aliased_line(uint8_t *pixels, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint8_t red, uint8_t green, uint8_t blue)
{
	int32_t dx = ABS(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int32_t dy = ABS(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int32_t err = dx - dy, e2; /* error value e_xy */
	int32_t ed = dx + dy == 0 ? 1 : ft_sqrt((float)dx * dx + (float)dy * dy);

	for (;;)
	{ /* pixel loop */
		pixels[(x0 * 8 + y0) * 3] = green * ABS(err - dx + dy) / ed;
		pixels[(x0 * 8 + y0) * 3 + 1] = red * ABS(err - dx + dy) / ed;
		pixels[(x0 * 8 + y0) * 3 + 2] = blue * ABS(err - dx + dy) / ed;

		e2 = err;
		if (2 * e2 >= -dx)
		{ /* x step */
			if (x0 == x1)
				break;
			if (e2 + dy < ed)
			{
				pixels[(x0 * 8 + y0) * 3] = green * (e2 + dy) / ed;
				pixels[(x0 * 8 + y0) * 3 + 1] = red * (e2 + dy) / ed;
				pixels[(x0 * 8 + y0) * 3 + 2] = blue * (e2 + dy) / ed;
			}
			err -= dy;
			x0 += sx;
		}
		if (2 * e2 <= dy)
		{ /* y step */
			if (y0 == y1)
				break;
			if (dx - e2 < ed)
			{
				pixels[(x0 * 8 + y0) * 3] = green * (dx - e2) / ed;
				pixels[(x0 * 8 + y0) * 3 + 1] = red * (dx - e2) / ed;
				pixels[(x0 * 8 + y0) * 3 + 2] = blue * (dx - e2) / ed;
			}
			err += dx;
			y0 += sy;
		}
	}
}

void led_matrix_draw_circle(uint8_t *pixels, int8_t xm, int8_t ym, int8_t r, uint8_t red, uint8_t green, uint8_t blue)
{
	int x = -r, y = 0, err = 2 - 2 * r; /* II. Quadrant */
	do
	{
		pixels[((xm - x) * 8 + (ym + y)) * 3] = green;
		pixels[((xm - x) * 8 + (ym + y)) * 3 + 1] = red;
		pixels[((xm - x) * 8 + (ym + y)) * 3 + 2] = blue;

		pixels[((xm - y) * 8 + (ym - x)) * 3] = green;
		pixels[((xm - y) * 8 + (ym - x)) * 3 + 1] = red;
		pixels[((xm - y) * 8 + (ym - x)) * 3 + 2] = blue;

		pixels[((xm + x) * 8 + (ym - y)) * 3] = green;
		pixels[((xm + x) * 8 + (ym - y)) * 3 + 1] = red;
		pixels[((xm + x) * 8 + (ym - y)) * 3 + 2] = blue;

		pixels[((xm + y) * 8 + (ym + x)) * 3] = green;
		pixels[((xm + y) * 8 + (ym + x)) * 3 + 1] = red;
		pixels[((xm + y) * 8 + (ym + x)) * 3 + 2] = blue;
		r = err;
		if (r <= y)
			err += ++y * 2 + 1; /* e_xy+e_y < 0 */
		if (r > x || err > y)
			err += ++x * 2 + 1; /* e_xy+e_x > 0 or no 2nd y-step */
	} while (x < 0);
}

void led_matrix_send_progmem(const uint8_t *progmem)
{
	uint8_t buffer[64 * 3];
	for (unsigned char i = 0; i < 64 * 3; i++)
		buffer[i] = (uint8_t)pgm_read_byte_near((progmem + i));
	
	led_send_data(3, (uint8_t *)buffer, 64);
	led_send_data(2, (uint8_t *)buffer, 64);
	led_send_data(9, (uint8_t *)buffer, 64);
	led_send_data(5, (uint8_t *)buffer, 64);
	led_send_data(8, (uint8_t *)buffer, 64);


}

void led_draw_animation(uint16_t pixels_number)
{
	// uint8_t pixels[pixels_number * 3];
	// uint32_t colors = 0xFF0000;

	ft_pin_mode(51, FT_OUTPUT);
	ft_pin_mode(3, FT_OUTPUT);
	ft_pin_mode(2, FT_OUTPUT);
	ft_pin_mode(5, FT_OUTPUT);
	ft_pin_mode(9, FT_OUTPUT);
	ft_pin_mode(8, FT_OUTPUT);

	led_matrix_send_progmem(SWORD);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(PURSE);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(BOW);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(POTION);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(COIN);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(GEM);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MARIO);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(GHOST);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(LINK);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(DONALD);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(STEEVE);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(CREEPER);
	for (int32_t i = 0; i < 500000; i++)
		;

	for (int32_t u = 1; u < 10; u++)
	{
		led_matrix_send_progmem(DICE_1);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(DICE_2);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(DICE_3);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(DICE_4);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(DICE_5);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(DICE_6);
		for (int32_t i = 0; i < 3000 * u; i++)
			;
	};
	for (int u = 0; u < 1; u++)
	{
		uint8_t *pixels = (uint8_t[64 * 3]){};
		for (int32_t y = 0; y < 8; y++)
		{
			led_matrix_draw_line(pixels, 0, 0, 7, y, 0x0, 0x10, 0x10);
			led_send_data(3, pixels, 64);
			led_send_data(2, pixels, 64);
			for (int32_t i = 0; i < 100000; i++)
				;
		}
		for (int32_t y = 0; y < 8; y++)
		{
			led_matrix_draw_line(pixels, 0, 0, 7 - y, 7, 0x10, 0x10, 0x10);
			led_send_data(3, pixels, 64);
			led_send_data(2, pixels, 64);
			for (int32_t i = 0; i < 100000; i++)
				;
		}
		led_matrix_draw_circle(pixels, 2, 2, 2, 0x10, 0x0, 0x0);
		led_send_data(3, pixels, 64);
		led_send_data(2, pixels, 64);
		for (int32_t i = 0; i < 500000; i++)
			;
		led_matrix_draw_circle(pixels, 5, 5, 2, 0x0, 0x10, 0x0);
		led_send_data(3, pixels, 64);
		for (int32_t i = 0; i < 500000; i++)
			;
		led_matrix_fill_screen(pixels, 0,0,0);
		led_send_data(3, pixels, 64);
		for (int32_t i = 0; i < 300000; i++)
			;
		for (int d = 0; d < 4; d++)
		{
			led_matrix_draw_filled_rectangle(pixels, d, d, (4-d) *2 -1, (4-d)*2 -1, 0x0, d % 2 == 0 ? 0x10 : 0x0, d % 2 == 0 ? 0x0 : 0x10);
			led_send_data(3, pixels, 64);
			for (int32_t i = 0; i < 300000; i++)
				;
		}
		for (int32_t i = 0; i < 100000; i++)
			;
		led_matrix_fill_screen(pixels, 0,0,0);
		for (int d = 0; d < 4; d++)
		{
			led_matrix_draw_rectangle(pixels, d, d, (4-d) *2 -1, (4-d)*2 -1, 0x0, d % 2 == 0 ? 0x10 : 0x0, d % 2 == 0 ? 0x0 : 0x10);
			led_send_data(3, pixels, 64);
			for (int32_t i = 0; i < 300000; i++)
				;
		}
		for (int32_t i = 0; i < 100000; i++)
			;
	}

	for (int32_t u = 0; u < 40; u++)
	{
		led_matrix_send_progmem(LOADING_0);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_10);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_20);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_30);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_40);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_50);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_60);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_70);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_80);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_90);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_100);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_110);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_120);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_130);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_140);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_150);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_160);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(LOADING_170);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;
	}
}
