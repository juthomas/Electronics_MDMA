#ifndef BUTTONS_H
# define BUTTONS_H
# include <stdint.h>

/**
 *  Ticks activation  Order
 *    |||| |||| |||  ||||
 * 0b 0000 0000 0000 0000
 *                 |
 *                 Is activate?
 */
uint16_t buttons_clicks_order[16];
void clear_buttons();
void init_buttons();
#define get_button_ticks(index) (buttons_clicks_order[index] >> 5)
#define get_button_order(index) (buttons_clicks_order[index] & 0b1111)
#define get_button_activation(index) ((buttons_clicks_order[index] & 0b10000) >> 4)
#endif