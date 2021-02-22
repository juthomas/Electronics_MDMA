#include <avr/io.h>
#include <avr/interrupt.h>
#define CPU_CLOCK 2000000

void	wait_x_cpu_clocks(int32_t cpu_clocks)
{
	while (cpu_clocks > 0)
	{
		cpu_clocks-=3;
	}
}

void	custom_delay(uint32_t milli)
{
	//milli = 0,001s
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}


void sendDataToOneLed(uint8_t r, uint8_t g, uint8_t b)
{
	//                  76543210
	uint64_t	red = r & 0b10000000 ? (0b1100 << 28) : 0b1000 << 28;
				red += r & 0b01000000 ? 0b1100 << 24 : 0b1000 << 24;
				red += r & 0b00100000 ? 0b1100 << 20 : 0b1000 << 20;
				red += r & 0b00010000 ? 0b1100 << 16 : 0b1000 << 16;
				
				red += r & 0b00001000 ? 0b1100 << 12 : 0b1000 << 12;
				red += r & 0b10000100 ? 0b1100 << 8 : 0b1000 << 8;
				red += r & 0b10000010 ? 0b1100 << 4 : 0b1000 << 4;
				red += r & 0b10000001 ? 0b1100 : 0b1000;

	PORTC = (red & 0xF0000000) ? 1 << 5: 0;
	PORTC = (red & 0x80000000) ? 1 << 5: 0;
	PORTC = (red & 0x40000000) ? 1 << 5: 0;
	PORTC = (red & 0x10000000) ? 1 << 5: 0;
	PORTC = (red & 0x0F000000) ? 1 << 5: 0;
	PORTC = (red & 0x08000000) ? 1 << 5: 0;
	PORTC = (red & 0x04000000) ? 1 << 5: 0;
	PORTC = (red & 0x01000000) ? 1 << 5: 0;
	PORTC = (red & 0x00F00000) ? 1 << 5: 0;
	PORTC = (red & 0x00800000) ? 1 << 5: 0;
	PORTC = (red & 0x00400000) ? 1 << 5: 0;
	PORTC = (red & 0x00100000) ? 1 << 5: 0;
	PORTC = (red & 0x000F0000) ? 1 << 5: 0;
	PORTC = (red & 0x00080000) ? 1 << 5: 0;
	PORTC = (red & 0x00040000) ? 1 << 5: 0;
	PORTC = (red & 0x00010000) ? 1 << 5: 0;
	PORTC = (red & 0x0000F000) ? 1 << 5: 0;
	PORTC = (red & 0x00008000) ? 1 << 5: 0;
	PORTC = (red & 0x00004000) ? 1 << 5: 0;
	PORTC = (red & 0x00001000) ? 1 << 5: 0;
	PORTC = (red & 0x00000F00) ? 1 << 5: 0;
	PORTC = (red & 0x00000800) ? 1 << 5: 0;
	PORTC = (red & 0x00000400) ? 1 << 5: 0;
	PORTC = (red & 0x00000100) ? 1 << 5: 0;
	PORTC = (red & 0x000000F0) ? 1 << 5: 0;
	PORTC = (red & 0x00000080) ? 1 << 5: 0;
	PORTC = (red & 0x00000040) ? 1 << 5: 0;
	PORTC = (red & 0x00000010) ? 1 << 5: 0;
	PORTC = (red & 0x0000000F) ? 1 << 5: 0;
	PORTC = (red & 0x00000008) ? 1 << 5: 0;
	PORTC = (red & 0x00000004) ? 1 << 5: 0;
	PORTC = (red & 0x00000001) ? 1 << 5: 0;

	PORTC = (red & 0xF0000000) ? 1 << 5: 0;
	PORTC = (red & 0x80000000) ? 1 << 5: 0;
	PORTC = (red & 0x40000000) ? 1 << 5: 0;
	PORTC = (red & 0x10000000) ? 1 << 5: 0;
	PORTC = (red & 0x0F000000) ? 1 << 5: 0;
	PORTC = (red & 0x08000000) ? 1 << 5: 0;
	PORTC = (red & 0x04000000) ? 1 << 5: 0;
	PORTC = (red & 0x01000000) ? 1 << 5: 0;
	PORTC = (red & 0x00F00000) ? 1 << 5: 0;
	PORTC = (red & 0x00800000) ? 1 << 5: 0;
	PORTC = (red & 0x00400000) ? 1 << 5: 0;
	PORTC = (red & 0x00100000) ? 1 << 5: 0;
	PORTC = (red & 0x000F0000) ? 1 << 5: 0;
	PORTC = (red & 0x00080000) ? 1 << 5: 0;
	PORTC = (red & 0x00040000) ? 1 << 5: 0;
	PORTC = (red & 0x00010000) ? 1 << 5: 0;
	PORTC = (red & 0x0000F000) ? 1 << 5: 0;
	PORTC = (red & 0x00008000) ? 1 << 5: 0;
	PORTC = (red & 0x00004000) ? 1 << 5: 0;
	PORTC = (red & 0x00001000) ? 1 << 5: 0;
	PORTC = (red & 0x00000F00) ? 1 << 5: 0;
	PORTC = (red & 0x00000800) ? 1 << 5: 0;
	PORTC = (red & 0x00000400) ? 1 << 5: 0;
	PORTC = (red & 0x00000100) ? 1 << 5: 0;
	PORTC = (red & 0x000000F0) ? 1 << 5: 0;
	PORTC = (red & 0x00000080) ? 1 << 5: 0;
	PORTC = (red & 0x00000040) ? 1 << 5: 0;
	PORTC = (red & 0x00000010) ? 1 << 5: 0;
	PORTC = (red & 0x0000000F) ? 1 << 5: 0;
	PORTC = (red & 0x00000008) ? 1 << 5: 0;
	PORTC = (red & 0x00000004) ? 1 << 5: 0;
	PORTC = (red & 0x00000001) ? 1 << 5: 0;

	PORTC = (red & 0xF0000000) ? 1 << 5: 0;
	PORTC = (red & 0x80000000) ? 1 << 5: 0;
	PORTC = (red & 0x40000000) ? 1 << 5: 0;
	PORTC = (red & 0x10000000) ? 1 << 5: 0;
	PORTC = (red & 0x0F000000) ? 1 << 5: 0;
	PORTC = (red & 0x08000000) ? 1 << 5: 0;
	PORTC = (red & 0x04000000) ? 1 << 5: 0;
	PORTC = (red & 0x01000000) ? 1 << 5: 0;
	PORTC = (red & 0x00F00000) ? 1 << 5: 0;
	PORTC = (red & 0x00800000) ? 1 << 5: 0;
	PORTC = (red & 0x00400000) ? 1 << 5: 0;
	PORTC = (red & 0x00100000) ? 1 << 5: 0;
	PORTC = (red & 0x000F0000) ? 1 << 5: 0;
	PORTC = (red & 0x00080000) ? 1 << 5: 0;
	PORTC = (red & 0x00040000) ? 1 << 5: 0;
	PORTC = (red & 0x00010000) ? 1 << 5: 0;
	PORTC = (red & 0x0000F000) ? 1 << 5: 0;
	PORTC = (red & 0x00008000) ? 1 << 5: 0;
	PORTC = (red & 0x00004000) ? 1 << 5: 0;
	PORTC = (red & 0x00001000) ? 1 << 5: 0;
	PORTC = (red & 0x00000F00) ? 1 << 5: 0;
	PORTC = (red & 0x00000800) ? 1 << 5: 0;
	PORTC = (red & 0x00000400) ? 1 << 5: 0;
	PORTC = (red & 0x00000100) ? 1 << 5: 0;
	PORTC = (red & 0x000000F0) ? 1 << 5: 0;
	PORTC = (red & 0x00000080) ? 1 << 5: 0;
	PORTC = (red & 0x00000040) ? 1 << 5: 0;
	PORTC = (red & 0x00000010) ? 1 << 5: 0;
	PORTC = (red & 0x0000000F) ? 1 << 5: 0;
	PORTC = (red & 0x00000008) ? 1 << 5: 0;
	PORTC = (red & 0x00000004) ? 1 << 5: 0;
	PORTC = (red & 0x00000001) ? 1 << 5: 0;


}



int main()
{
	cli();
	//        76543210
	DDRC |= 0b00110000;
	for (;;)
	{
		sendDataToOneLed(255,255,255);
		custom_delay(200);
	}
	for (;;)
	{
		// //		   76543210
		// PORTC |= 0b00100000;
		// //		   76543210
		// PORTC &= 0b11011111;
		// //		   76543210
		// PORTC |= 0b00100000;
		// //		   76543210
		// PORTC &= 0b11011111;
		// //		   76543210
		// PORTC |= 0b00100000;
		// //		   76543210
		// PORTC &= 0b11011111;


		//        76543210
		PORTC = 0b00100000;
		//		  76543210
		PORTC = 0b00000000;
		//		  76543210
		PORTC = 0b00100000;
		//		  76543210
		PORTC = 0b00000000;
		//		  76543210
		PORTC = 0b00100000;
		//		  76543210
		PORTC = 0b00000000;
	}
	sei();
	return (0);
}