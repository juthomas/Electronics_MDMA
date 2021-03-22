#ifndef PIN_REGISTERS_H
# define PIN_REGISTERS_H

// Offset of Registers
#define BEG_REG_ADDR 0x20

// Registers associated addr
enum e_reg_addr {
	FT_PINA = BEG_REG_ADDR,
	FT_DDRA,
	FT_PORTA,
	FT_PINB,
	FT_DDRB,
	FT_PORTB,
	FT_PINC,
	FT_DDRC,
	FT_PORTC,
	FT_PIND,
	FT_DDRD,
	FT_PORTD,
	FT_PINE,
	FT_DDRE,
	FT_PORTE,
	FT_PINF,
	FT_DDRF,
	FT_PORTF,
	FT_PING,
	FT_DDRG,
	FT_PORTG,
	// FT_PINH = 0x100,
	// FT_DDRH,
	// FT_PORTH,
	// FT_PINJ,
	// FT_DDRJ,
	// FT_PORTJ,
	// FT_PINK,
	// FT_DDRK,
	// FT_PORTK,
	// FT_PINL,
	// FT_DDRL,
	// FT_PORTL,
};

enum e_modes {
	FT_INPUT,
	FT_OUTPUT
};

enum e_states {
	FT_LOW = 0,
	FT_HIGH
};

enum e_pins {
	FT_D0 = 0,
	FT_D1,
	FT_D2,
	FT_D3,
	FT_D4,
	FT_D5,
	FT_D6,
	FT_D7,
	FT_D8,
	FT_D9,
	FT_D10,
	FT_D11,
	FT_D12,
	FT_D13,
	FT_D14,
	FT_D15,
	FT_D16,
	FT_D17,
	FT_D18,
	FT_D19,
	FT_D20,
	FT_D21,
	FT_D22,
	FT_D23,
	FT_D24,
	FT_D25,
	FT_D26,
	FT_D27,
	FT_D28,
	FT_D29,
	FT_D30,
	FT_D31,
	FT_D32,
	FT_D33,
	FT_D34,
	FT_D35,
	FT_D36,
	FT_D37,
	FT_D38,
	FT_D39,
	FT_D40,
	FT_D41,
	FT_D42,
	FT_D43,
	FT_D44,
	FT_D45,
	FT_D46,
	FT_D47,
	FT_D48,
	FT_D49,
	FT_D50,
	FT_D51,
	FT_D52,
	FT_D53,
	FT_A0,
	FT_A1,
	FT_A2,
	FT_A3,
	FT_A4,
	FT_A5,
	FT_A6,
	FT_A7,
	FT_A8,
	FT_A9,
	FT_A10,
	FT_A11,
	FT_A12,
	FT_A13,
	FT_A14,
	FT_A15,
	FT_DMAX
};

typedef struct	s_pin_registers{
	uint8_t		pin_number;
	uint8_t		register_pin_addr;
	uint8_t		register_ddr_addr;
	uint8_t		register_port_addr;
	uint8_t		register_mask;
}				t_pin_registers;

static const t_pin_registers g_pin_associations[FT_DMAX] = {
(t_pin_registers){
.pin_number=FT_D0,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D1,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,

.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D2,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D3,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D4,
.register_pin_addr=FT_PING,
.register_ddr_addr=FT_DDRG,
.register_port_addr=FT_PORTG,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D5,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D6,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D7,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D8,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D9,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_D10,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D11,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D12,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_D13,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_D14,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D15,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D16,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D17,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D18,
.register_pin_addr=FT_PIND,
.register_ddr_addr=FT_DDRD,
.register_port_addr=FT_PORTD,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D19,
.register_pin_addr=FT_PIND,
.register_ddr_addr=FT_DDRD,
.register_port_addr=FT_PORTD,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D20,
.register_pin_addr=FT_PIND,
.register_ddr_addr=FT_DDRD,
.register_port_addr=FT_PORTD,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D21,
.register_pin_addr=FT_PIND,
.register_ddr_addr=FT_DDRD,
.register_port_addr=FT_PORTD,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D22,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D23,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D24,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D25,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D26,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D27,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D28,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_D29,
.register_pin_addr=FT_PINA,
.register_ddr_addr=FT_DDRA,
.register_port_addr=FT_PORTA,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_D30,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_D31,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_D32,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D33,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D34,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D35,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D36,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D37,
.register_pin_addr=FT_PINC,
.register_ddr_addr=FT_DDRC,
.register_port_addr=FT_PORTC,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D38,
.register_pin_addr=FT_PIND,
.register_ddr_addr=FT_DDRD,
.register_port_addr=FT_PORTD,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_D39,
.register_pin_addr=FT_PING,
.register_ddr_addr=FT_DDRG,
.register_port_addr=FT_PORTG,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D40,
.register_pin_addr=FT_PING,
.register_ddr_addr=FT_DDRG,
.register_port_addr=FT_PORTG,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D41,
.register_pin_addr=FT_PING,
.register_ddr_addr=FT_DDRG,
.register_port_addr=FT_PORTG,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D42,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_D43,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_D44,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_D45,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_D46,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D47,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D48,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D49,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_D50,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_D51,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_D52,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_D53,
.register_pin_addr=FT_PINB,
.register_ddr_addr=FT_DDRB,
.register_port_addr=FT_PORTB,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_A0,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_A1,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_A2,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_A3,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_A4,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_A5,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_A6,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_A7,
.register_pin_addr=FT_PINF,
.register_ddr_addr=FT_DDRF,
.register_port_addr=FT_PORTF,
.register_mask=(1 << 7)},
(t_pin_registers){
.pin_number=FT_A8,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 0)},
(t_pin_registers){
.pin_number=FT_A9,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 1)},
(t_pin_registers){
.pin_number=FT_A10,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 2)},
(t_pin_registers){
.pin_number=FT_A11,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 3)},
(t_pin_registers){
.pin_number=FT_A12,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 4)},
(t_pin_registers){
.pin_number=FT_A13,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 5)},
(t_pin_registers){
.pin_number=FT_A14,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 6)},
(t_pin_registers){
.pin_number=FT_A15,
.register_pin_addr=0,
.register_ddr_addr=0,
.register_port_addr=0,
.register_mask=(1 << 7)},
};

#endif