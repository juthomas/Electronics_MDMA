#ifndef LEDS_H
# define LEDS_H
# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
#  define F_CPU 16000000
# endif
# include <stdint.h>
# include <avr/io.h>
# include <avr/interrupt.h>

// #ifndef MDMA_H
//# include <./mdma.h>
// #endif


typedef void(*t_asm_sender)(uint8_t mask, uint8_t *, uint16_t);
void	led_send_data(enum e_pins pin, uint8_t *pixels, uint16_t pixels_number);

void led_send_data_PORTA(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);


enum			e_matrix_activation{
	MAT_1 = 1 << PIN4,
	MAT_2 = 1 << PIN2,
	MAT_3 = 1 << PIN1,
	MAT_4 = 1 << PIN0,
	MAT_5 = 1 << PIN3,
	MAT_ALL = MAT_1 | MAT_2 | MAT_3 | MAT_4 | MAT_5,
	LEDS_REG = 1 << PIN5
};

enum e_led_directions
{
	D_PLAYERS = 1,
	D_SCREEN,
	D_CLOCKWISE,
	D_COUNTERCLOCKWISE,
	D_WAWES,
};

enum e_led_rows
{
	LED_ROW_1 = 1 << 0,
	LED_ROW_2 = 1 << 1,
	LED_ROW_3 = 1 << 2,
	LED_ROW_4 = 1 << 3,
	LED_ROW_5 = 1 << 4,
	LED_ROW_6 = 1 << 5,
	LED_ROW_7 = 1 << 6,
	LED_ROW_8 = 1 << 7,
	LED_ROW_ALL = LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4 | LED_ROW_5 | LED_ROW_6,
	LED_ROW_MAX = LED_ROW_ALL | LED_ROW_7 | LED_ROW_8
};

enum e_players
{
	PLAYER_1 = 1 << 0,
	PLAYER_2 = 1 << 1,
	PLAYER_3 = 1 << 2,
	PLAYER_4 = 1 << 3,
	PLAYER_5 = 1 << 4,
	PLAYER_ALL = PLAYER_1 | PLAYER_2 | PLAYER_3 | PLAYER_4 | PLAYER_5
};

void	matrix_send_data(enum e_matrix_activation activation, uint8_t *pixels, uint16_t pixels_number);



uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color);
uint16_t *rotate_some_fifth(uint16_t *pixels_to_draw, uint16_t pixels_to_draw_size, uint8_t fifths);
uint8_t *feed_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color);
void	feed_array_of_pixels_with_transparency(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, \
												uint32_t color, uint32_t transparency);
uint8_t *clear_led_buffer(uint8_t *pixels, uint16_t buffer_size, uint32_t color);

uint8_t *animate_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color);
uint32_t get_pixel_color(uint8_t *pixels, uint16_t index);
uint32_t led_wawe_color(uint8_t pos, uint32_t color, uint32_t background_color);
uint8_t *wawe_animate_arraw_of_pixels(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color);
uint32_t led_rainbow_wheel(uint8_t pos);
uint32_t led_reduce_luminosity(uint32_t color, uint8_t percentage);
int32_t ft_sqrt(int32_t x);
void led_matrix_draw_line(uint8_t *pixels, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_filled_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_fill_screen(uint8_t *pixels, uint32_t color);
void led_matrix_draw_anti_aliased_line(uint8_t *pixels, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_circle(uint8_t *pixels, int8_t xm, int8_t ym, int8_t r, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_send_progmem(enum e_matrix_activation activation, const uint8_t *progmem);
void wawe_on_segment(uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint8_t progression, uint32_t color1, uint32_t color2);
void draw_interactions_with_screen(uint8_t *buffer, uint32_t max_ticks, uint32_t ticks_increment, uint8_t direction, uint8_t player, uint32_t color);
void draw_cirle_pit(uint8_t *buffer, uint32_t max_ticks, uint32_t ticks_increment, uint8_t animation, uint32_t rows_activation, uint32_t color1, uint32_t color2);
void	draw_halo(uint8_t *buffer, uint8_t players, uint32_t color);
void draw_timer_state(uint8_t *pixels, uint16_t time, uint32_t color, uint32_t background_color);

void draw_ammo_amount(uint8_t *buffer, uint8_t players, uint8_t ammo_amount, uint32_t color, uint32_t background_color);


void draw_satanic_circle();
void draw_roulette();
void led_test();
void launch_dice();
void reverse_array(uint16_t *pixels_to_draw, int size);
void manage_array_of_pixels(uint8_t animate, uint16_t *pixels_indexes, uint16_t pixels_indexes_size, uint8_t *pixels, uint32_t color);
void draw_line_between_players(uint8_t *buffer, uint8_t from, uint8_t to, uint8_t animate, uint32_t color);
void init_leds(uint8_t *led_buffer);
void led_draw_animation(uint16_t pixels_number);
void draw_numbers(uint8_t *pixels, uint8_t number, uint32_t color);
void draw_segment(uint8_t *pixels, uint8_t segment, uint8_t x_offset, uint8_t y_offset, uint32_t color);
void draw_numeral(uint8_t *pixels, uint8_t numeral, uint8_t x_offset, uint8_t y_offset, uint32_t color);









void draw_satanic_circle();

uint8_t g_led_exit_animation;


#endif