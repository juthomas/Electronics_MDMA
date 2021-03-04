#ifndef MDMA_H
# define MDMA_H
# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
#  define F_CPU 16000000
# endif
// # include <avr/io.h>
// # include <avr/interrupt.h>
# include <stdint.h>
# include "./pin_registers.h"
# include "./tone.h"
# include <avr/interrupt.h>
# include <avr/io.h>

# define CPU_CLOCK 2000000 // 16Mhz -> / 8 2Mhz
# define SERIAL_8N1 0x06

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

uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color);
void	led_draw_animation(uint16_t pixels_number);
void	led_send_data(uint8_t *pixels, uint16_t pixels_number);


int		serial_test();
void	serial_init();
void	serial_putnbr(int32_t n);
void	serial_putnbrln(int32_t n);
void	serial_putstr(const char* str);
void	serial_putstrln(const char* str);

void	serial_putchar(char c);
void	serial_putnbrln(int32_t n);
void	serial_putnbr_base(int nbr, char *base);
void	serial_putnbr_baseln(int nbr, char *base);




// void pinMode(uint8_t pin, uint8_t mode);
// void digitalWrite(uint8_t pin, uint8_t val);



#endif