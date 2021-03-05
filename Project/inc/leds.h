#ifndef LEDS_H
# define LEDS_H
// # include <stdint.h>
# include <./mdma.h>

typedef void(*t_asm_sender)(uint8_t mask, uint8_t *, uint16_t);

void led_send_data_PORTA(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTB(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTC(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTD(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTE(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTF(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTG(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTH(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
// void led_send_data_PORTI(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTJ(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTK(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);
void led_send_data_PORTL(uint8_t mask, uint8_t *pixels, uint16_t pixels_number);

typedef struct	s_asm_attr_sender{
	enum e_pins		pin_number;
	t_asm_sender	func;

}				t_asm_attr_sender;

// static const t_asm_attr_sender g_asm_sender[1] = {
// (t_asm_attr_sender){
// 	.pin_number=FT_D0,
// 	.func = led_send_data_PORTB
// }
// };

static const t_asm_attr_sender g_asm_sender[FT_DMAX] = {
(t_asm_attr_sender){
.pin_number=FT_D0,
.func = led_send_data_PORTE},
(t_asm_attr_sender){
.pin_number=FT_D1,
.func = led_send_data_PORTE},
(t_asm_attr_sender){
.pin_number=FT_D2,
.func = led_send_data_PORTE},
(t_asm_attr_sender){
.pin_number=FT_D3,
.func = led_send_data_PORTE},
(t_asm_attr_sender){
.pin_number=FT_D4,
.func = led_send_data_PORTG},
(t_asm_attr_sender){
.pin_number=FT_D5,
.func = led_send_data_PORTE},
(t_asm_attr_sender){
.pin_number=FT_D6,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D7,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D8,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D9,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D10,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D11,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D12,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D13,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D14,
.func = led_send_data_PORTJ},
(t_asm_attr_sender){
.pin_number=FT_D15,
.func = led_send_data_PORTJ},
(t_asm_attr_sender){
.pin_number=FT_D16,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D17,
.func = led_send_data_PORTH},
(t_asm_attr_sender){
.pin_number=FT_D18,
.func = led_send_data_PORTD},
(t_asm_attr_sender){
.pin_number=FT_D19,
.func = led_send_data_PORTD},
(t_asm_attr_sender){
.pin_number=FT_D20,
.func = led_send_data_PORTD},
(t_asm_attr_sender){
.pin_number=FT_D21,
.func = led_send_data_PORTD},
(t_asm_attr_sender){
.pin_number=FT_D22,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D23,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D24,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D25,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D26,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D27,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D28,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D29,
.func = led_send_data_PORTA},
(t_asm_attr_sender){
.pin_number=FT_D30,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D31,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D32,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D33,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D34,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D35,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D36,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D37,
.func = led_send_data_PORTC},
(t_asm_attr_sender){
.pin_number=FT_D38,
.func = led_send_data_PORTD},
(t_asm_attr_sender){
.pin_number=FT_D39,
.func = led_send_data_PORTG},
(t_asm_attr_sender){
.pin_number=FT_D40,
.func = led_send_data_PORTG},
(t_asm_attr_sender){
.pin_number=FT_D41,
.func = led_send_data_PORTG},
(t_asm_attr_sender){
.pin_number=FT_D42,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D43,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D44,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D45,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D46,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D47,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D48,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D49,
.func = led_send_data_PORTL},
(t_asm_attr_sender){
.pin_number=FT_D50,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D51,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D52,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_D53,
.func = led_send_data_PORTB},
(t_asm_attr_sender){
.pin_number=FT_A0,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A1,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A2,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A3,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A4,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A5,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A6,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A7,
.func = led_send_data_PORTF},
(t_asm_attr_sender){
.pin_number=FT_A8,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A9,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A10,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A11,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A12,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A13,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A14,
.func = led_send_data_PORTK},
(t_asm_attr_sender){
.pin_number=FT_A15,
.func = led_send_data_PORTK},
};


#endif