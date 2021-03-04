#include "../../inc/mdma.h"

static int32_t		ft_strlen_error(char *base)
{
	int32_t			i;
	int32_t			j;

	i = 0;
	j = i + 1;
	while (base[i] != '\0')
	{
		while (base[j] != '\0')
		{
			if (base[i] == base[j] || base[i] == '+' || base[i] == '-'
					|| base[j] == '+' || base[j] == '-')
				return (1);
			j++;
		}
		i++;
		j = i + 1;
	}
	if (i <= 1)
		return (1);
	return (i);
}

static void		limite(int32_t n, char *base, int32_t u)
{
	if (n < 0)
	{
		serial_putchar('-');
		n = n * -1;
	}
	if (n >= u)
		limite(n / u, base, u);
	serial_putchar(base[(n % u)]);
}

void			serial_putnbr_base(int32_t nbr, char *base)
{
	int32_t			u;
	int32_t			n;

	u = ft_strlen_error(base);
	if (nbr == -2147483648 && u > 1)
	{
		n = -2147483648;
		limite(n, base, u);
	}
	else if (u > 1)
	{
		if (nbr < 0)
		{
			serial_putchar('-');
			nbr = nbr * -1;
		}
		if (nbr >= u)
			serial_putnbr_base(nbr / u, base);
		serial_putchar(base[(nbr % u)]);
	}
}

void			serial_putnbr_baseln(int32_t nbr, char *base)
{
	serial_putnbr_base(nbr, base);
	serial_putstr("\r\n");
}
