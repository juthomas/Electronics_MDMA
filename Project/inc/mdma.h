#ifndef MDMA_H
# define MDMA_H
# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
//#  define F_CPU 16000000
# endif
// # include <avr/io.h>
// # include <avr/interrupt.h>
# include <stdint.h>
# include "./pin_registers.h"
# include "./ili9341.h"
# include "./rfid.h"
// # include "./tone.h"
// # include "./leds.h"
// # include "./leds.h"
# include <avr/interrupt.h>
# include <avr/io.h>
#include <avr/pgmspace.h>

# define CPU_CLOCK 2000000 // 16Mhz -> / 8 2Mhz
# define SERIAL_8N1 0x06
#define ABS(x) x < 0 ? -x : x

/*
 *
 *    ##       ##   ######     ##       ##      #####
 *    ###     ###   #######    ###     ###     #######
 *    ####   ####   ##    ##   ####   ####    ##     ##
 *    ## ## ## ##   ##    ##   ## ## ## ##   ##       ##
 *    ##  ###  ##   ##    ##   ##  ###  ##   ###########
 *    ##   #   ##   ##    ##   ##   #   ##   ##       ##
 *    ##       ##   ##    ##   ##       ##   ##       ##
 *    ##       ##   #######    ##       ##   ##       ##
 *    ##       ##   ######     ##       ##   ##       ##
 * 
*/

// pins manipulation
void	ft_pin_mode(enum e_pins pin, enum e_modes mode);
void	ft_digital_write(enum e_pins pin, enum e_states state);
int		ft_digital_read(enum e_pins pin);
void	custom_delay(uint32_t milli);

//bouton
void    init_turn();




// Leds 

// low level led adressing

// pixel management

// Fonction de test
// void	led_draw_animation(uint16_t pixels_number);

uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color);
void	led_draw_animation(uint16_t pixels_number);
void	led_send_data(enum e_pins pin, uint8_t *pixels, uint16_t pixels_number);
uint32_t	led_rainbow_wheel(uint8_t pos);
uint32_t	led_reduce_luminosity(uint32_t color, uint8_t percentage);
int32_t ft_sqrt(int32_t x);

void led_matrix_draw_line(uint8_t *pixels, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_filled_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_rectangle(uint8_t *pixels, uint8_t x, uint8_t y, uint8_t w, uint8_t h, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_fill_screen(uint8_t *pixels, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_anti_aliased_line(uint8_t *pixels, int32_t x0, int32_t y0, int32_t x1, int32_t y1, uint8_t red, uint8_t green, uint8_t blue);
void led_matrix_draw_circle(uint8_t *pixels, int8_t xm, int8_t ym, int8_t r, uint8_t red, uint8_t green, uint8_t blue);




// int		serial_test();
// void	serial_init();
// void	serial_putnbr(int32_t n);
// void	serial_putnbrln(int32_t n);
// void	serial_putstr(const char* str);
// void	serial_putstrln(const char* str);

// void	serial_putchar(char c);
// void	serial_putnbrln(int32_t n);
// void	serial_putnbr_base(int32_t nbr, char *base);
// void	serial_putnbr_baseln(int32_t nbr, char *base);
void    initSPI();




void pinMode(uint8_t pin, uint8_t mode);
void digitalWrite(uint8_t pin, uint8_t val);



#endif