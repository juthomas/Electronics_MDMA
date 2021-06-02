//#include "../../inc/mdma.h"
#include "../../inc/leds.h"
#include "../../inc/math.h"
#include "../../inc/matrix_progmem.h"

# define TRUE 1
# define FALSE 0
# define ABS(x) x < 0 ? -x : x

// #define WAWE 2




/**
 * @brief Feed one pixel at desired index with hexa color
 * @param pixel_index Current pixel index
 * @param pixel Pixels array
 * @param color Hexadecimal 0xRRGGBB format
 * @return Pixels array
 */
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


/**
 * @brief Rotate pixels selected by X pizzas parts
 * @param pixels_to_draw Array of pixels to draws (array of indexes)
 * @param pixels_to_draw_size pixels_to_draw Array size
 * @param fifths Number of pizzas parts to rotate
 * @return pixels_to_draw
 */
uint16_t *rotate_some_fifth(uint16_t *pixels_to_draw, uint16_t pixels_to_draw_size, uint8_t fifths)
{
	fifths = fifths % 5;

	fifths = 5 - fifths;
	
	fifths = fifths % 5;


	for (int i = 0; i < pixels_to_draw_size; i++)
	{
		pixels_to_draw[i] = (pixels_to_draw[i] + (62 * fifths)) % (62 * 5);
	}
	return (pixels_to_draw);
}


/**
 * @brief Feed color to pixels indexed in pixels_index
 * @param pixels_indexes Array of pixels to draws (array of indexes)
 * @param pixels_indexes_size pixels_indexes Array size
 * @param pixels Pixels array
 * @param color Hexadecimal 0xRRGGBB format
 * @return pixels_to_draw
 */
uint8_t *feed_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color)
{
	for (int i = 0; i < pixels_indexes_size; i++)
	{
		pixels[pixels_indexes[i] * 3] = (color & 0x00FF00) >> 8;
		pixels[pixels_indexes[i] * 3 + 1] = (color & 0xFF0000) >> 16;
		pixels[pixels_indexes[i] * 3 + 2] = color & 0x0000FF;
	}
	return (pixels);
}

/**
 * @brief Clear pixels array with color
 * @param pixels Pixels array
 * @param color Hexadecimal 0xRRGGBB format
 * @return pixels_to_draw
 */
uint8_t *clear_led_buffer(uint8_t *pixels, uint32_t color)
{
	for (int i = 0; i < 62 * 5; i++)
	{
		pixels[i * 3] = (color & 0x00FF00) >> 8;
		pixels[i * 3 + 1] = (color & 0xFF0000) >> 16;
		pixels[i * 3 + 2] = color & 0x0000FF;
	}
	return (pixels);
}

/**
 * @brief Animate pixels indexed with color
 * @param pixels_indexes Array of pixels to draws (array of indexes)
 * @param pixels_indexes_size pixels_indexes Array size
 * @param pixels Pixels array
 * @param color Hexadecimal 0xRRGGBB format
 * @return pixels_to_draw
 */
uint8_t *animate_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color)
{

	for (int i = 0; i < pixels_indexes_size; i++)
	{
		pixels[pixels_indexes[i] * 3] = (color & 0x00FF00) >> 8;
		pixels[pixels_indexes[i] * 3 + 1] = (color & 0xFF0000) >> 16;
		pixels[pixels_indexes[i] * 3 + 2] = color & 0x0000FF;
		led_send_data_PORTA(1 << PIN5, pixels, 62 * 5);
		for (int32_t i = 0; i < 5000; i++)
			;
	}
	return (pixels);
}

/**
 * @brief Get pixel color in pixels array at index
 * @param index index to search
 * @param pixels Pixels array
 * @return color with Hexadecimal 0xRRGGBB format
 */
uint32_t get_pixel_color(uint8_t *pixels, uint16_t index)
{
	return ((uint32_t)(pixels[index * 3] << 8) +
			((uint32_t)pixels[index * 3 + 1] << 16) +
			((uint32_t)pixels[index * 3 + 2]));
}

/**
 * @brief Get color for wawe effect
 * @param pos Current wawe position (between 0 and 100)
 * @param color Wawe color
 * @param background_color Background of wawe color (secondary color)
 * @return color with Hexadecimal 0xRRGGBB format
 */
uint32_t led_wawe_color(uint8_t pos, uint32_t color, uint32_t background_color)
{
  if (pos > 50)
  {
    return (((uint32_t)(((double)((color & 0xFF0000) >> 16) * (double)((double)100 - pos) / 50) + ((double)((background_color & 0xFF0000) >> 16) * (1. - ((double)100 - pos) / 50))) << (uint32_t)16)\
      + ((uint32_t)(((double)((color & 0x00FF00) >> 8) * (double)((double)100 - pos) / 50) + ((double)((background_color & 0x00FF00) >> 8) * (1. - ((double)100 - pos) / 50))) << (uint32_t)8)\
      + (uint32_t)((double)((color & 0x0000FF) * (double)((double)100 - pos) / 50)) + ((double)(background_color & 0x0000FF) * (1. - ((double)100 - pos) / 50)));
  }
  else
  {
    return (((uint32_t)(((double)((color & 0xFF0000) >> 16) * (double)((double)pos) / 50) + ((double)((background_color & 0xFF0000) >> 16) * (1. - ((double)pos) / 50))) << (uint32_t)16)\
      + ((uint32_t)(((double)((color & 0x00FF00) >> 8) * (double)((double)pos) / 50) + ((double)((background_color & 0x00FF00) >> 8) * (1. - ((double)pos) / 50))) << (uint32_t)8)\
      + (uint32_t)((double)((color & 0x0000FF) * (double)((double)pos) / 50)) + ((double)(background_color & 0x0000FF) * (1. - ((double)pos) / 50)));
  }
}

/**
 * @brief Create a wawe effect on pixels indexed
 * @param pixels_indexes Array of pixels to draws (array of indexes)
 * @param pixels_indexes_size pixels_indexes Array size
 * @param pixels Pixels array
 * @param color Hexadecimal 0xRRGGBB format
 * @return pixels
 */
uint8_t *wawe_animate_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color)
{
	uint32_t color_tmp = 0x000000;
	uint32_t position = 0;
	uint32_t drawned_index = 0;
	uint32_t undraw_index = 0;
	uint16_t turns = 0;
	uint16_t max_turns = 5;
	uint32_t delay = 300000;
	uint32_t oldColors[pixels_indexes_size];
	for (int i = 0; i < pixels_indexes_size; i++)
	{
		oldColors[i] = get_pixel_color(pixels, pixels_indexes[i]);
	}

	delay /= pixels_indexes_size;

	for (int u = 0; u < 1000; u++)
	{
		if (g_led_exit_animation == 1)
		{
			g_led_exit_animation = 0;
			break;
		}
		for (int i = 0; i < pixels_indexes_size && i <= drawned_index; i++)
		{
			color_tmp = led_wawe_color(((pixels_indexes_size - ((position - i) % pixels_indexes_size)) * 100 / pixels_indexes_size) % 100, color, oldColors[i]);
			pixels[pixels_indexes[i] * 3] = (color_tmp & 0x00FF00) >> 8;
			pixels[pixels_indexes[i] * 3 + 1] = (color_tmp & 0xFF0000) >> 16;
			pixels[pixels_indexes[i] * 3 + 2] = color_tmp & 0x0000FF;
		}
		led_send_data_PORTA(1 << PIN5, pixels, 62 * 5);
		for (int32_t z = 0; z < delay; z++)
			;
		position++;
		if (drawned_index <= pixels_indexes_size)
		{
			drawned_index++;
		}

		if (turns == max_turns && (position % pixels_indexes_size) == 0)
		{
			while (undraw_index < pixels_indexes_size)
			{

				for (int i = 0; i < pixels_indexes_size; i++)
				{
					if (undraw_index >= i)
						color_tmp = oldColors[i];
					else
						color_tmp = led_wawe_color(((pixels_indexes_size - ((position - i) % pixels_indexes_size)) * 100 / pixels_indexes_size) % 100, color, oldColors[i]);
					pixels[pixels_indexes[i] * 3] = (color_tmp & 0x00FF00) >> 8;
					pixels[pixels_indexes[i] * 3 + 1] = (color_tmp & 0xFF0000) >> 16;
					pixels[pixels_indexes[i] * 3 + 2] = color_tmp & 0x0000FF;
				}
				led_send_data_PORTA(1 << PIN5, pixels, 62 * 5);
				for (int32_t z = 0; z < delay; z++)
					;
				position++;
				undraw_index++;
			}
			return (pixels);
		}
		else if ((position % pixels_indexes_size) == 0)
		{
			turns++;
		}
	}
	return (pixels);
}

/**
 * @brief Get a color in rainbow
 * @param pos color position (between 0 and 255)
 * @return color with Hexadecimal 0xRRGGBB format
 */
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

/**
 * @brief Reduce color luminosity
 * @param color color to reduce
 * @param percentage luminosity desired between 0 and 100 (0 = off, 100 = max luminosity)
 * @return color with Hexadecimal 0xRRGGBB format
 */
uint32_t led_reduce_luminosity(uint32_t color, uint8_t percentage)
{
	return (
		((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +
		((((color & 0x00FF00) >> (int32_t)8) * percentage / 100) << (int32_t)8) +
		((((color & 0x0000FF) >> (int32_t)0) * percentage / 100) << (int32_t)0));
}

/**
 * @brief Get square root of x
 * @param x
 * @return Square root
 */
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

/**
 * @brief Draw line on led matrix
 */
void led_matrix_draw_line(uint8_t *pixels, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t red, uint8_t green, uint8_t blue)
{
	int dx = ABS(x1 - x0), sx = x0 < x1 ? 1 : -1;
	int dy = -ABS(y1 - y0), sy = y0 < y1 ? 1 : -1;
	int err = dx + dy, e2; /* error value e_xy */

	for (;;)
	{ /* loop */
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
		pixels[((x)*8 + (y + tmph)) * 3] = green;
		pixels[((x)*8 + (y + tmph)) * 3 + 1] = red;
		pixels[((x)*8 + (y + tmph)) * 3 + 2] = blue;
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

void led_matrix_send_progmem(enum e_matrix_activation activation, const uint8_t *progmem)
{
	uint8_t buffer[64 * 3];
	for (unsigned char i = 0; i < 64 * 3; i++)
		buffer[i] = (uint8_t)pgm_read_byte_near((progmem + i));
	// led_send_data(26, (uint8_t *)buffer, 64);
	//MAT_1 | MAT_3 | MAT_4 | MAT_2
	matrix_send_data(activation, (uint8_t *)buffer, 64);
}

// ?
void wawe_on_segment(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint8_t progression, uint32_t color1, uint32_t color2)
{
	uint32_t color_tmp;

	for (int i = 0; i < pixels_indexes_size; i++)
	{
		color_tmp = led_wawe_color((map(i, 0, pixels_indexes_size, 0, 100) + progression) % 100, color1, color2);
		// color_tmp = led_wawe_color((progression) % 100, 0x100000, 0x001000);
		// color_tmp = map(i, 0, pixels_indexes_size, 0x100000, 0x000000);
		pixels[pixels_indexes[i] * 3] = (color_tmp & 0x00FF00) >> 8;
		pixels[pixels_indexes[i] * 3 + 1] = (color_tmp & 0xFF0000) >> 16;
		pixels[pixels_indexes[i] * 3 + 2] = color_tmp & 0x0000FF;
	}
}

void draw_interactions_with_screen(uint8_t *buffer, uint32_t max_ticks, uint32_t ticks_increment, uint8_t direction, uint8_t player, uint32_t color)
{
	for (int position = 0; position < max_ticks; position += ticks_increment)
	{
		uint8_t current_player_index = 0;
								/*    XXXIX   XXXV    XXXIV   XXVII   XVIII   XVII     IX    III     II  */
		uint16_t pixels_to_draw[] = {39 - 1, 35 - 1, 34 - 1, 27 - 1, 18 - 1, 17 - 1, 9 - 1, 3 - 1, 2 - 1};
		if (player & PLAYER_1)
		{
			wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, direction == D_SCREEN ? (100 - (position % 100)) : (position % 100), color, 0x000000);
		}
		if (player & PLAYER_2)
		{
			rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1 - current_player_index);
			wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, direction == D_SCREEN ? (100 - (position % 100)) : (position % 100), color, 0x000000);
			current_player_index += 1 - current_player_index;
		}
		if (player & PLAYER_3)
		{
			rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 2 - current_player_index);
			wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, direction == D_SCREEN ? (100 - (position % 100)) : (position % 100), color, 0x000000);
			current_player_index += 2 - current_player_index;
		}
		if (player & PLAYER_4)
		{
			rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 3 - current_player_index);
			wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, direction == D_SCREEN ? (100 - (position % 100)) : (position % 100), color, 0x000000);
			current_player_index += 3 - current_player_index;
		}
		if (player & PLAYER_5)
		{
			rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 4 - current_player_index);
			wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, direction == D_SCREEN ? (100 - (position % 100)) : (position % 100), color, 0x000000);
			current_player_index += 4 - current_player_index;
		}
		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	}
}

void draw_cirle_pit(uint8_t *buffer, uint32_t max_ticks, uint32_t ticks_increment, uint8_t animation, uint32_t rows_activation, uint32_t color1, uint32_t color2)
{
	for (int position = 0; position < max_ticks; position += ticks_increment)
	{
		if (g_led_exit_animation == 1)
		{
			g_led_exit_animation = 0;
			break;
		}
		if (rows_activation & LED_ROW_1)
		{
			/*     I    II     II      IV     V */
			uint16_t pixels_to_draw[] = {1 - 1, 2 - 1, 3 - 1, 4 - 1, 5 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_COUNTERCLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, position % 100, color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}

			// led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);

			//  pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, color);
		}
		if (rows_activation & LED_ROW_2)
		{
			/*     VI    VII    VIII    IX      X      XI      XII    XIII   */
			uint16_t pixels_to_draw[] = {6 - 1, 7 - 1, 8 - 1, 9 - 1, 10 - 1, 11 - 1, 12 - 1, 13 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_COUNTERCLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, position % 100, color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
			// led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		}
		if (rows_activation & LED_ROW_3)
		{
			/*     XIV     XV      XVI     XVII   XVIII    IXX     XX      XXI     XXII   */
			uint16_t pixels_to_draw[] = {14 - 1, 15 - 1, 16 - 1, 17 - 1, 18 - 1, 19 - 1, 20 - 1, 21 - 1, 22 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_CLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
			// led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		}
		if (rows_activation & LED_ROW_4)
		{
			/*    XXIII    XXIV    XXV    XXVI    XXVII   XXVIII   XXIX    XXX     XXXI   */
			uint16_t pixels_to_draw[] = {23 - 1, 24 - 1, 25 - 1, 26 - 1, 27 - 1, 28 - 1, 29 - 1, 30 - 1, 31 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_CLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
			// led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		}
		if (rows_activation & LED_ROW_5)
		{
			/*    XXXII  XXXIII   XXXIV   XXXV    XXXVI    XXXVII   */
			uint16_t pixels_to_draw[] = {32 - 1, 33 - 1, 34 - 1, 35 - 1, 36 - 1, 37 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_COUNTERCLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, position % 100, color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
			// led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		}
		if (rows_activation & LED_ROW_6)
		{
			/*   XXXVIII XXXXIX     XL   */
			uint16_t pixels_to_draw[] = {38 - 1, 39 - 1, 40 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_COUNTERCLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, position % 100, color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
		}
		if (rows_activation & LED_ROW_7)
		{
									/*    XLI     XLII    XLIII   XLIV     XLV    XLVI    XLVII  XLVIII    IL      L      LI      LII     LIII */
			uint16_t pixels_to_draw[] = {41 - 1, 42 - 1, 43 - 1, 44 - 1, 45 - 1, 46 - 1, 47 - 1, 48 - 1, 49 - 1, 50 - 1, 51 - 1, 52 - 1, 53 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_CLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
		}
		if (rows_activation & LED_ROW_8)
		{
									/*    LIV      LV      LVI     LVII    LVIII   LIX      LX      LXI    LXII*/
			uint16_t pixels_to_draw[] = {54 - 1, 55 - 1, 56 - 1 , 57 - 1, 58 - 1, 59 - 1, 60 - 1, 61 - 1, 62 - 1};

			for (int i = 0; i < 5; i++)
			{
				if (animation == D_WAWES || animation == D_CLOCKWISE)
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, (position % 100), color1, color2);
				}
				else
				{
					wawe_on_segment(pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, 100 - (position % 100), color1, color2);
				}
				rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, 1);
			}
		}



		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	}
}

void draw_satanic_circle()
{
	uint8_t buffer[62 * 3 * 5];
	// uint8_t color = 10;

	for (int u = 0; u < 10; u++)
	{
		for (int i = 0; i < 62 * 5; i++)
		{
			if (i % 62 == 37 ||
				i % 62 == 32 ||
				i % 62 == 24 ||
				i % 62 == 14 ||
				i % 62 == 5 ||
				i % 62 == 39 ||
				i % 62 == 35 ||
				i % 62 == 28 ||
				i % 62 == 19 ||
				i % 62 == 11 ||
				i % 62 == 4 ||
				i % 62 == 45 ||
				i % 62 == 46)
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x10;
				buffer[i * 3 + 2] = 0;
			}
			else if (i % 62 >= 53 && i % 62 <= 61)
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x10;
				buffer[i * 3 + 2] = 0;
			}
			else if (i % 62 >= 0 && i % 62 <= 5)
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x10;
				buffer[i * 3 + 2] = 0;
			}
			else
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x0;
				buffer[i * 3 + 2] = 0;
			}
			// feed_one_pixel(i, buffer, led_rainbow_wheel((colors + i * 60) % 256) + 0x10000000 );
		}
		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		// led_send_data(27, buffer, 62 * 5);
		led_matrix_send_progmem(MAT_1, SAT_SYMB_1);
		led_matrix_send_progmem(MAT_2, SAT_SYMB_2);
		led_matrix_send_progmem(MAT_3, SAT_SYMB_3);
		led_matrix_send_progmem(MAT_4, SAT_SYMB_4);
		led_matrix_send_progmem(MAT_5, SAT_SYMB_5);
		// led_matrix_send_progmem(MAT_5, SAT_SYMB_1RE);
		// SAT_SYMB_1HD
		// led_matrix_send_progmem(MAT_1 | MAT_2 | MAT_3 |MAT_4 | MAT_5, SAT_SYMB_4);

		// for (int32_t i = 0; i < 900000; i++)
		// 	;
		// led_matrix_send_progmem(MAT_5, LINK);
	}
}

void draw_roulette()
{
	uint8_t buffer[62 * 3 * 5];
	// uint8_t color = 10;

	for (int i = 0; i < 62 * 5; i++)
	{
		if (i % 62 == 37 ||
			i % 62 == 32 ||
			i % 62 == 24 ||
			i % 62 == 14 ||
			i % 62 == 5 ||
			i % 62 == 39 ||
			i % 62 == 35 ||
			i % 62 == 28 ||
			i % 62 == 19 ||
			i % 62 == 11 ||
			i % 62 == 4 ||
			i % 62 == 45 ||
			i % 62 == 46)
		{
			buffer[i * 3] = 0x10;
			buffer[i * 3 + 1] = 0x0;
			buffer[i * 3 + 2] = 0;
		}
		else if (i % 62 >= 53 && i % 62 <= 61)
		{
			buffer[i * 3] = 0x10;
			buffer[i * 3 + 1] = 0x0;
			buffer[i * 3 + 2] = 0;
		}
		else if (i % 62 >= 0 && i % 62 <= 5)
		{
			buffer[i * 3] = 0x10;
			buffer[i * 3 + 1] = 0x0;
			buffer[i * 3 + 2] = 0;
		}
		else
		{
			buffer[i * 3] = 0x10;
			buffer[i * 3 + 1] = 0x0;
			buffer[i * 3 + 2] = 0;
		}
		// feed_one_pixel(i, buffer, led_rainbow_wheel((colors + i * 60) % 256) + 0x10000000 );
	}
	led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	// led_send_data(27, buffer, 62 * 5);

	// led_matrix_send_progmem(MAT_1 | MAT_2 | MAT_3 |MAT_4 | MAT_5, SAT_SYMB_4);
}

void led_test()
{
	uint8_t buffer[62 * 3 * 5];
	uint32_t colors = 0xFF0000;
	for (int u = 0; u < 1000; u++)
	{

		for (int i = 0; i < 62 * 5; i++)
		{
			if (i % 62 >= 40 && i % 62 <= 61)
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x10;
				buffer[i * 3 + 2] = 0;
			}
			else
			{
				buffer[i * 3] = 0;
				buffer[i * 3 + 1] = 0x0;
				buffer[i * 3 + 2] = 0;
			}
			// feed_one_pixel(i, buffer, led_rainbow_wheel((colors + i * 60) % 256) + 0x10000000 );
		}
		if (colors > 0xFFFFFF)
		{
			colors = 0;
		}
		colors += 1;
		// led_send_data(27, buffer, 62 * 5);
		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);

		// for (int32_t i = 0; i < 3000; i++)
		// 	;
	}
}

void launch_dice()
{
	for (int32_t u = 1; u < 10; u++)
	{
		led_matrix_send_progmem(MAT_1, DICE_1);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1, DICE_2);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1, DICE_3);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1, DICE_4);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1, DICE_5);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1, DICE_6);
		for (int32_t i = 0; i < 3000 * u; i++)
			;
	};
}

void reverse_array(uint16_t *pixels_to_draw, int size)
{
	// uint16_t high;
	// uint16_t low;
	for (uint16_t low = 0, high = size - 1; low < high; low++, high--)
	{
		uint16_t temp = pixels_to_draw[low];
		pixels_to_draw[low] = pixels_to_draw[high];
		pixels_to_draw[high] = temp;
	}
}

void manage_array_of_pixels(uint8_t animate, uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color)
{
	// animate = WAWE;//DEBUG

	if (animate == TRUE)
	{
		animate_arraw_of_pixels(pixels_indexes, pixels_indexes_size, pixels, color);
	}
	else if (animate == D_WAWES)
	{
		wawe_animate_arraw_of_pixels(pixels_indexes, pixels_indexes_size, pixels, color);
	}
	else
	{
		feed_arraw_of_pixels(pixels_indexes, pixels_indexes_size, pixels, color);
	}
}

void draw_line_between_players(uint8_t *buffer, uint8_t from, uint8_t to, uint8_t animate, uint32_t color)
{
	//Clockwise interations
	if ((from == 1 && to == 2) || (from == 2 && to == 3) || (from == 3 && to == 4) || (from == 4 && to == 5) || (from == 5 && to == 1))
	{
		//                           LVII     LVI     LV     LIV
		uint16_t pixels_to_draw[] = {57 - 1, 56 - 1, 55 - 1, 54 - 1, /*  LXII         LXI          LX           LIX           LIIX */
									 62 - 1 + 62 * 4, 61 - 1 + 62 * 4, 60 - 1 + 62 * 4, 59 - 1 + 62 * 4, 58 - 1 + 62 *4};
	

		rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, from - 1);

		manage_array_of_pixels(animate, pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, color);
	}
	//Counter Clockwise interations
	else if ((from == 2 && to == 1) || (from == 3 && to == 2) || (from == 4 && to == 3) || (from == 5 && to == 4) || (from == 1 && to == 5))
	{
		//                           LVII     LVI     LV     LIV
		uint16_t pixels_to_draw[] = {57 - 1, 56 - 1, 55 - 1, 54 - 1, /*  LXII         LXI          LX           LIX           LIIX */
									 62 - 1 + 62 * 4, 61 - 1 + 62 * 4, 60 - 1 + 62 * 4, 59 - 1 + 62 * 4, 58 - 1 + 62 * 4};

		reverse_array(pixels_to_draw, sizeof(pixels_to_draw) / 2);
		rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, from + 3);
		manage_array_of_pixels(animate, pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, color);
	}
	//Clockwise Star interations
	else if ((from == 1 && to == 3) || (from == 2 && to == 4) || (from == 3 && to == 5) || (from == 4 && to == 1) || (from == 5 && to == 2))
	{
		//                            XLVI   XXXVIII  XXXIII     XXV     LXV    VI
		uint16_t pixels_to_draw[] = {46 - 1, 38 - 1, 33 - 1, 25 - 1, 15 - 1, 6 - 1,				 /*   V           IV          III        II           I    */
									 5 - 1 + 310 - 62, 4 - 1 + 310 - 62, 3 - 1 + 310 - 62, 2 - 1 + 310 - 62, 1 - 1 + 310 - 62, /*      V          XII          XX           XXIX          XXXVI        XL            XLVII   */
									 5 - 1 + 310 - 124, 12 - 1 + 310 - 124, 20 - 1 + 310 - 124, 29 - 1 + 310 - 124, 36 - 1 + 310 - 124, 40 - 1 + 310 - 124, 47 - 1 + 310 - 124};

		// reverse_array(pixels_to_draw, sizeof(pixels_to_draw) / 2);
		rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, from - 1);
		manage_array_of_pixels(animate, pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, color);
	}
	//Counter Clockwise Star interations
	else if ((from == 3 && to == 1) || (from == 4 && to == 2) || (from == 5 && to == 3) || (from == 1 && to == 4) || (from == 2 && to == 5))
	{
		//                            XLVI   XXXVIII  XXXIII     XXV     LXV    VI
		uint16_t pixels_to_draw[] = {46 - 1, 38 - 1, 33 - 1, 25 - 1, 15 - 1, 6 - 1,				 /*   V           IV          III        II           I    */
									 5 - 1 + 310 - 62, 4 - 1 + 310 - 62, 3 - 1 + 310 - 62, 2 - 1 + 310 - 62, 1 - 1 + 310 - 62, /*      V          XII          XX           XXIX          XXXVI        XL            XLVII   */
									 5 - 1 + 310 - 124, 12 - 1 + 310 - 124, 20 - 1 + 310 - 124, 29 - 1 + 310 - 124, 36 - 1 + 310 - 124, 40 - 1 + 310 - 124, 47 - 1 + 310 - 124};

		reverse_array(pixels_to_draw, sizeof(pixels_to_draw) / 2);
		rotate_some_fifth(pixels_to_draw, sizeof(pixels_to_draw) / 2, from + 2);
		manage_array_of_pixels(animate, pixels_to_draw, sizeof(pixels_to_draw) / 2, buffer, color);
	}
}

void draw_players_interactions()
{
}

/**
 * @brief Init led library
 * @param led_buffer buffer for leds (must have a size of 62 * 3 * 5)
 */
void init_leds(uint8_t *led_buffer)
{
	g_led_exit_animation = 0;
	DDRA |= 1 << PIN0;
	DDRA |= 1 << PIN1;
	DDRA |= 1 << PIN2;
	DDRA |= 1 << PIN3;
	DDRA |= 1 << PIN4;
	DDRA |= 1 << PIN5;
	for (int i = 0; i < 62 * 3 * 5; i++)
	{
		led_buffer[i] = 0;
	}
}

void led_draw_animation(uint16_t pixels_number)
{
	// uint8_t pixels[pixels_number * 3];
	// uint32_t colors = 0xFF0000;
	g_led_exit_animation = 0;
	uint8_t buffer[62 * 3 * 5];
	for (int i = 0; i < 62 * 3 * 5; i++)
	{
		buffer[i] = 0;
	}

	DDRA |= 1 << PIN0;
	DDRA |= 1 << PIN1;
	DDRA |= 1 << PIN2;
	DDRA |= 1 << PIN3;
	DDRA |= 1 << PIN4;
	DDRA |= 1 << PIN5;
	// led_test();
	draw_satanic_circle();
	// g_led_exit_animation = 1;
	// 	draw_interactions_with_screen(buffer, 2000, 2, D_PLAYERS, PLAYER_2 | PLAYER_5, 0x101010);
	// 	for (int32_t i = 0; i < 1000000; i++)
	// 		;
	// draw_interactions_with_screen(buffer, 2000, 2, D_PLAYERS, PLAYER_1 | PLAYER_3 | PLAYER_4, 0x101010);
	// 	for (int32_t i = 0; i < 1000000; i++)
	// 		;

	// draw_interactions_with_screen(buffer, 2000, 2, D_PLAYERS, PLAYER_ALL, 0x101010);
	// 	for (int32_t i = 0; i < 1000000; i++)
	// 		;


	// draw_cirle_pit(buffer, 5000, 5, D_WAWES, LED_ROW_MAX, 0x001113, 0x000003);
	// draw_cirle_pit(buffer, 5000, 5, D_WAWES, LED_ROW_MAX, 0x110000, 0x000000);


	// for (int32_t i = 0; i < 200000; i++)
	// ;

	uint32_t interactions_color = 0x101010;
	//Clockwise interactions
	for (int i = 0; i < 5; i++)
	{
		clear_led_buffer(buffer, 0x000000);
		// draw_line_between_players(buffer, 1, 2, FALSE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 1) % 5) + 1, FALSE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 2) % 5) + 1, FALSE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 3) % 5) + 1, FALSE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 4) % 5) + 1, FALSE, interactions_color);
		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		for (int32_t i = 0; i < 200000; i++)
			;
	}
	for (int i = 0; i < 5; i++)
	{
		clear_led_buffer(buffer, 0x000000);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 1) % 5) + 1, TRUE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 2) % 5) + 1, TRUE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 3) % 5) + 1, TRUE, interactions_color);
		draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 4) % 5) + 1, TRUE, interactions_color);
		led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
		for (int32_t i = 0; i < 100000; i++)
			;
	}
	// interactions_color = 0x000010;
	// for (int i = 0; i < 5; i++)
	// {
	// 	clear_led_buffer(buffer, 0x000000);
	// 	draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 1) % 5) + 1, D_WAWES, interactions_color);
	// 	draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 2) % 5) + 1, D_WAWES, interactions_color);
	// 	draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 3) % 5) + 1, D_WAWES, interactions_color);
	// 	draw_line_between_players(buffer, ((i + 0) % 5) + 1, ((i + 4) % 5) + 1, D_WAWES, interactions_color);
	// 	led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	// 	for (int32_t i = 0; i < 100000; i++)
	// 		;
	// }
	// // Counter-Clockwise interactions
	// for (int i = 0; i < 10; i++)
	// {
	// 	clear_led_buffer(buffer, 0x000000);
	// 	draw_line_between_players(buffer,((i + 1) % 5) + 1, ((i)% 5) + 1, TRUE, interactions_color);
	// 	led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	// 	for (int32_t i = 0; i < 200000; i++)
	// 	;
	// }
	// // Star Clockwise interactions
	// for (int i = 0; i < 10; i++)
	// {
	// 	clear_led_buffer(buffer, 0x000000);
	// 	draw_line_between_players(buffer,((i) % 5) + 1, ((i + 2)% 5) + 1, TRUE, interactions_color);
	// 	led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	// 	for (int32_t i = 0; i < 200000; i++)
	// 	;
	// }
	// // Star Counter-Clockwise interactions
	// for (int i = 0; i < 10; i++)
	// {
	// 	clear_led_buffer(buffer, 0x000000);
	// 	draw_line_between_players(buffer,((i + 2) % 5) + 1, ((i)% 5) + 1, TRUE, interactions_color);
	// 	led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
	// 	for (int32_t i = 0; i < 200000; i++)
	// 	;
	// }
	draw_satanic_circle();

	led_matrix_send_progmem(MAT_5, SAT_SYMB_5);
	for (int32_t i = 0; i < 500000; i++)
		;
	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, SWORD);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, PURSE);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, BOW);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, POTION);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, COIN);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, GEM);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, MARIO);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, GHOST);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LINK);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DONALD);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, STEEVE);
	for (int32_t i = 0; i < 500000; i++)
		;

	led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, CREEPER);
	for (int32_t i = 0; i < 500000; i++)
		;

	for (int32_t u = 1; u < 10; u++)
	{
		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_1);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_2);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_3);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_4);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_5);
		for (int32_t i = 0; i < 3000 * u; i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, DICE_6);
		for (int32_t i = 0; i < 3000 * u; i++)
			;
	};
	for (int u = 0; u < 1; u++)
	{
		uint8_t *pixels = (uint8_t[64 * 3]){};
		for (int32_t y = 0; y < 8; y++)
		{
			led_matrix_draw_line(pixels, 0, 0, 7, y, 0x0, 0x10, 0x10);
			// led_send_data(3, pixels, 64);
			led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

			for (int32_t i = 0; i < 100000; i++)
				;
		}
		for (int32_t y = 0; y < 8; y++)
		{
			led_matrix_draw_line(pixels, 0, 0, 7 - y, 7, 0x10, 0x10, 0x10);
			// led_send_data(3, pixels, 64);
			led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

			for (int32_t i = 0; i < 100000; i++)
				;
		}
		led_matrix_draw_circle(pixels, 2, 2, 2, 0x10, 0x0, 0x0);
		// led_send_data(3, pixels, 64);
		led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

		for (int32_t i = 0; i < 500000; i++)
			;
		led_matrix_draw_circle(pixels, 5, 5, 2, 0x0, 0x10, 0x0);
		// led_send_data(3, pixels, 64);
		led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

		for (int32_t i = 0; i < 500000; i++)
			;
		led_matrix_fill_screen(pixels, 0, 0, 0);
		// led_send_data(3, pixels, 64);
		led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

		for (int32_t i = 0; i < 300000; i++)
			;
		for (int d = 0; d < 4; d++)
		{
			led_matrix_draw_filled_rectangle(pixels, d, d, (4 - d) * 2 - 1, (4 - d) * 2 - 1, 0x0, d % 2 == 0 ? 0x10 : 0x0, d % 2 == 0 ? 0x0 : 0x10);
			// led_send_data(3, pixels, 64);
			led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

			for (int32_t i = 0; i < 300000; i++)
				;
		}
		for (int32_t i = 0; i < 100000; i++)
			;
		led_matrix_fill_screen(pixels, 0, 0, 0);
		for (int d = 0; d < 4; d++)
		{
			led_matrix_draw_rectangle(pixels, d, d, (4 - d) * 2 - 1, (4 - d) * 2 - 1, 0x0, d % 2 == 0 ? 0x10 : 0x0, d % 2 == 0 ? 0x0 : 0x10);
			// led_send_data(3, pixels, 64);
			led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

			for (int32_t i = 0; i < 300000; i++)
				;
		}
		for (int32_t i = 0; i < 100000; i++)
			;
	}

	for (int32_t u = 0; u < 40; u++)
	{
		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_0);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_10);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_20);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_30);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_40);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_50);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_60);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_70);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_80);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_90);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_100);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_110);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_120);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_130);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_140);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_150);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_160);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;

		led_matrix_send_progmem(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, LOADING_170);
		for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u); i++)
			;
	}
}
