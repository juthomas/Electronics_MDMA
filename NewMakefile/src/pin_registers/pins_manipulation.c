#include "../../inc/mdma.h"

void ft_pin_mode(enum e_pins pin, enum e_modes mode)
{
	volatile uint8_t *addr;

	addr = (volatile uint8_t*)g_pin_associations[pin].register_ddr_addr;
	if (mode == FT_OUTPUT)
	{
		*addr |= g_pin_associations[pin].register_mask;
	}
	else if (mode == FT_INPUT)
	{
		*addr &= ~g_pin_associations[pin].register_mask;
	}
}

void ft_digital_write(enum e_pins pin, enum e_states state)
{
	volatile uint8_t *addr;

	addr = (volatile uint8_t*)g_pin_associations[pin].register_port_addr;
	if (state == FT_HIGH)
	{
		*addr |= g_pin_associations[pin].register_mask;
	}
	else if (state == FT_LOW)
	{
		*addr &= ~g_pin_associations[pin].register_mask;
	}
}

int ft_digital_read(enum e_pins pin)
{
	volatile uint8_t *addr;

	addr = (volatile uint8_t*)g_pin_associations[pin].register_pin_addr;
	return (*addr & g_pin_associations[pin].register_mask);
}