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
	FT_PORTG
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
	FT_MAX
};

typedef struct	s_pin_registers{
	int		pin_number;
	int		register_pin_addr;
	int		register_ddr_addr;
	int		register_port_addr;
	int		register_mask;
}				t_pin_registers;

static const t_pin_registers g_pin_associations[FT_MAX] = {
(t_pin_registers){
.pin_number=FT_D0,
.register_pin_addr=FT_PINE,
.register_ddr_addr=FT_DDRE,
.register_port_addr=FT_PORTE,
.register_mask=(1 << 0)}
};



#endif