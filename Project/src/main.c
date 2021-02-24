#include <avr/io.h>

#define BAUDRATE 115200
#define BAUD_PRESCALLER (((F_CPU / (BAUDRATE * 16UL))) - 1)

//Declaration of our functions
void USART_init(void);
unsigned char USART_receive(void);
void USART_send( unsigned char data);

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(int32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

int main(void){
USART_init();        //Call the USART initialization code

while(1){        //Infinite loop
 USART_send('A');
 custom_delay(1000);        //Delay for 5 seconds so it will re-send the string every 5 seconds
 }

return 0;
}

void USART_init(void){

 UBRR1H = (uint8_t)(BAUD_PRESCALLER>>8);
 UBRR1L = (uint8_t)(BAUD_PRESCALLER);
 UCSR1B = (1<<RXEN1)|(1<<TXEN1);
 UCSR1C = (3<<UCSZ10);
}

unsigned char USART_receive(void){

 while(!(UCSR1A & (1<<RXC1)));
 return UDR1;

}

void USART_send( unsigned char data){

 while(!(UCSR1A & (1<<UDRE1)));
 UDR1 = data;

}