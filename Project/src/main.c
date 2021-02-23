#include "../inc/mdma.h"
#include "../inc/ili9341.h"

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
	milli = milli *	2000;
	wait_x_cpu_clocks(milli - 5);
}

// void testText() {
//   tft.fillScreen(ILI9341_BLACK);
//   tft.setCursor(0, 0);
//   tft.setTextColor(ILI9341_WHITE);  tft.setTextSize(1);
//   tft.println("Hello World!");
//   tft.setTextColor(ILI9341_YELLOW); tft.setTextSize(2);
//   tft.println(1234.56);
//   tft.setTextColor(ILI9341_RED);    tft.setTextSize(3);
//   tft.println(0xDEADBEEF, HEX);
//   tft.println();
//   tft.setTextColor(ILI9341_GREEN);
//   tft.setTextSize(5);
//   tft.println("Groop");
//   tft.setTextSize(2);
//   tft.println("I implore thee,");
//   tft.setTextSize(1);
//   tft.println("my foonting turlingdromes.");
//   tft.println("And hooptiously drangle me");
//   tft.println("with crinkly bindlewurdles,");
//   tft.println("Or I will rend thee");
//   tft.println("in the gobberwarts");
//   tft.println("with my blurglecruncheon,");
//   tft.println("see if I don't!");
// }

int main()
{
	ili9341_begin();
	ili9341_fillRect(0, 0, ILI9341_TFTWIDTH, ILI9341_TFTHEIGHT, ILI9341_BLACK);
	for (;;);
	return (0);
}