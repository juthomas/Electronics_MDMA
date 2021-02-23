#ifndef MDMA_H
# define MDMA_H
# ifndef __AVR_ATmega2560__
#  define __AVR_ATmega2560__
# endif
# include "avr/io.h"
# include "pin_registers.h"

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

#endif