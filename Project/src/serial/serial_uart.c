#include "../../inc/mdma.h"

#define ISR(vector, ...)            \
    void vector (void) __attribute__ ((signal,__INTR_ATTRS)) __VA_ARGS__; \
    void vector (void)


static void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

static void	custom_delay(int32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}
//#define UCSR0A 0xC0
//#define UCSR0B 0xC1
//#define UCSR0C 0xC2

//#define UBRR0H 0xC5
//#define UBRR0L 0xC4
#define U2X0  1
#define RXEN0  4
#define TXEN0  3
#define RXCIE0  7
#define UDRIE0   5


static void uart_init(uint32_t baud, uint8_t config)
{
  // enable UDRE interrupt and enable transmit
  /*UCSR0B |= (1 << UDRIE0) | (1 << TXEN0);

  // set character data size to 8
  UCSR0C |= (1 << UCSZ00) | (1 << UCSZ01);

  // baud rate 9600
	UBRR0 = 103;*/

	uint16_t baud_setting = (1600000UL / 4 / baud - 1) / 2;
	UCSR0A = (1 << U2X0);
	UBRR0H = baud_setting >> 8;
	UBRR0L = baud_setting;

	UCSR0C = config;
	UCSR0B |= (1 << RXEN0) | (1 << TXEN0) | (1 << RXCIE0);
	UCSR0B &= ~(1 << (UDRIE0));
}

void serial_putchar(char c)
{
	//Wait for empty buffer (20.6.1)
	while (!( UCSR0A & (1<<UDRE0)));
	//Put char into register buffer
	UDR0 = c;
}

void serial_putstr(const char* str)
{
	while (*str)
	{
		serial_putchar(*str++);
	}
}

char serial_rx(void)
{
	//(20.7)
	/* Wait for data to be received */
	while (!(UCSR0A & (1 << RXC0)));
	/* Get and return received data from buffer */
	return UDR0;
}

void	serial_putnbr(int32_t n)
{
	if (n == -2147483648)
		serial_putstr("-2147483648");
	else
	{
		if (n < 0)
		{
			serial_putchar('-');
			n = -n;
		}
		if (n / 10 != 0)
			serial_putnbr(n / 10);
		serial_putchar(n % 10 + 48);
	}
}

void	serial_init()
{
	uart_init(9600, SERIAL_8N1);
}

int serial_test()
{
	serial_init();

	//Loop
	for(;;)
	{
		serial_putnbr(42);
		serial_putstr(" : hello word\r\n");
		custom_delay(100);
	}
}