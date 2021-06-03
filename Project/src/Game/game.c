#include "../../inc/ili9341.h"
#include "../../inc/games.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"

unsigned long int next = 56345345540;
void custom_delay(uint32_t milli);

int rand(void)
{
    next = next * 1103515243 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
    next = seed;
}

void do_you_rather(uint8_t *led_buffer)
{
    uint8_t *pixels = (uint8_t[64 * 3]){};
    clear_buttons();
    clear_led_buffer(led_buffer, 0x000000);
    led_matrix_fill_screen(pixels, 0, 0, 0);
    // led_send_data(3, pixels, 64);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);
    while ((!buttons_clicks_order[0] && !buttons_clicks_order[1]) || (!buttons_clicks_order[3] && !buttons_clicks_order[4]) || (!buttons_clicks_order[6] && !buttons_clicks_order[7]) || (!buttons_clicks_order[9] && !buttons_clicks_order[10]) || (!buttons_clicks_order[12] && !buttons_clicks_order[13]))
    {

        if (buttons_clicks_order[0] || buttons_clicks_order[1])
        {
            led_matrix_fill_screen(pixels, 8, 8, 8);
            led_send_data_PORTA(MAT_1, pixels, 64);
        }

        if (buttons_clicks_order[3] || buttons_clicks_order[4])
        {
            led_matrix_fill_screen(pixels, 8, 8, 8);
            led_send_data_PORTA(MAT_2, pixels, 64);
        }

        if (buttons_clicks_order[6] || buttons_clicks_order[7])
        {
            led_matrix_fill_screen(pixels, 8, 8, 8);
            led_send_data_PORTA(MAT_3, pixels, 64);
        }

        if (buttons_clicks_order[9] || buttons_clicks_order[10])
        {
            led_matrix_fill_screen(pixels, 8, 8, 8);
            led_send_data_PORTA(MAT_4, pixels, 64);
        }

        if (buttons_clicks_order[12] || buttons_clicks_order[13])
        {
            led_matrix_fill_screen(pixels, 8, 8, 8);
            led_send_data_PORTA(MAT_5, pixels, 64);
        }
    }
    if (buttons_clicks_order[0] > buttons_clicks_order[1])
    {
        led_matrix_fill_screen(pixels, 10, 0, 0);
    }
    else
    {
        led_matrix_fill_screen(pixels, 0, 10, 0);
    }
    led_send_data_PORTA(MAT_1, pixels, 64);

    if (buttons_clicks_order[3] > buttons_clicks_order[4])
    {
        led_matrix_fill_screen(pixels, 10, 0, 0);
    }
    else
    {
        led_matrix_fill_screen(pixels, 0, 10, 0);
    }
    led_send_data_PORTA(MAT_2, pixels, 64);

    if (buttons_clicks_order[6] > buttons_clicks_order[7])
    {
        led_matrix_fill_screen(pixels, 10, 0, 0);
    }
    else
    {
        led_matrix_fill_screen(pixels, 0, 10, 0);
    }
    led_send_data_PORTA(MAT_3, pixels, 64);

    if (buttons_clicks_order[9] > buttons_clicks_order[10])
    {
        led_matrix_fill_screen(pixels, 10, 0, 0);
    }
    else
    {
        led_matrix_fill_screen(pixels, 0, 10, 0);
    }
    led_send_data_PORTA(MAT_4, pixels, 64);

    if (buttons_clicks_order[12] > buttons_clicks_order[13])
    {
        led_matrix_fill_screen(pixels, 10, 0, 0);
    }
    else
    {
        led_matrix_fill_screen(pixels, 0, 10, 0);
    }
    led_send_data_PORTA(MAT_5, pixels, 64);

    for (uint32_t i = 0; i < 1000000; i++)
        ;
    clear_buttons();
}

void display_menu()
{
    int16_t clign = ILI9341_WHITE;
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_setCursor(0, 0);
    ili9341_print("MEGA\nDRINKING\n", ILI9341_WHITE, 5, 2, 0, width);
    ili9341_print("MACHINA\n", ILI9341_RED, 5, 2, 0, width);
    ili9341_print("ADVENTURE\n\n", ILI9341_WHITE, 5, 2, 0, width);
    int32_t x = cursor_x;
    int32_t y = cursor_y;
    clear_buttons();
    while (!buttons_clicks_order[15])
    {
        ili9341_setCursor(x, y);
        ili9341_println("    - Start -", clign = (clign == ILI9341_YELLOW ? ILI9341_WHITE : ILI9341_YELLOW), 3, 2);
    }
}

uint16_t createRGB(uint8_t r, uint8_t g, uint8_t b)
{
    r /= 8;
    g /= 4;
    b /= 8;
    return ((r & 0xff) << 11) + ((g & 0xff) << 5) + (b & 0xff);
}

void display_selection()
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_setCursor(width / 6, 10);
    ili9341_println("WELCOME\n", ILI9341_WHITE, 4, 0);
    ili9341_println("Select your roles\nand press start\nto play your\n", ILI9341_WHITE, 3, 0);
    ili9341_println("    SOULS", ILI9341_RED, 4, 0);
}

void display_intro()
{
    uint8_t red = 255;
    uint8_t green = 255;
    uint8_t blue = 255;
    int position = height / 2 - 10;
    ili9341_setCursor(0, position);
    ili9341_println("    What do you seek ?\n", createRGB(255, 255, 255), 2, 2);
    custom_delay(2000);
    for (int timer = 0; timer < 10; timer++)
    {
        ili9341_setCursor(0, position);
        ili9341_println("    What do you seek ?\n", createRGB(0, 0, 0), 2, 0);
        ili9341_setCursor(0, position);
        ili9341_println("    What do you seek ?\n", createRGB(255, 255, 255), 2, 0);
    }
    ili9341_setCursor(0, position);
    ili9341_print("    What do you seek ?", ILI9341_RED, 2, 0, 0, width);
    for (int timer = 0; timer < 80; timer++)
    {
        red = (255 - timer * 4) >= 0 ? 255 - timer * 4 : 0;
        ili9341_setCursor(cursor_x, cursor_y);
        ili9341_print("    What do you seek ?", createRGB(red, 0, 0), 2, 0, 0, width);
        cursor_y = rand() % height;
        cursor_x = rand() % width;
    }
    ili9341_draw_IMG(DevilEyesBG, DevilEyesBGPalette, 0, 0, 32, 12, 10);
    for (int timer = 0; timer < 3; timer++)
    {
        ili9341_draw_IMG(DevilSmileBG, DevilSmileBGPalette, 0, 120, 32, 12, 10);
        ili9341_draw_IMG(DevilSmile2BG, DevilSmile2BGPalette, 0, 120, 32, 12, 10);
    }
    ili9341_draw_IMG(BaphometBG, BaphometBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(KingCrimsonBG, KingCrimsonBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(CorridorBG, CorridorBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(PentacleBG, PentacleBGPalette, 0, 0, 32, 24, 10);
}

void display_intro_game(int8_t index, int8_t side)
{
    ili9341_setRotation(side);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
    ili9341_draw_IMG(CadreBG, CadreBGPalette, 40, 120, 60, 30, 4);
    ili9341_setCursor(80, 140);
    ili9341_print(games[index].name1, ILI9341_WHITE, 4, 0, 80, width - 40);
    ili9341_setCursor(80, 180);
    ili9341_print(games[index].name2, ILI9341_WHITE, 4, 0, 80, width - 40);
    // while (!buttons_clicks_order[0] && !buttons_clicks_order[1]);
    // ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
    clear_buttons();
    while (!buttons_clicks_order[0] && !buttons_clicks_order[1]);
    ili9341_draw_IMG(CadreBigBG, CadreBigBGPalette, 40, 40, 60, 50, 4);
    ili9341_setCursor(60, 60);
    ili9341_print(games[index].rules, ILI9341_WHITE, 2, 0, 60, width - 50);
    clear_buttons();
    while (!buttons_clicks_order[0] && !buttons_clicks_order[1]);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
    ili9341_draw_IMG(CadreSquareBG, CadreSquareBGPalette, 100, 60, 30, 30, 4);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(3, ILI9341_WHITE, 8, 0);
    custom_delay(900);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(2, ILI9341_WHITE, 8, 0);
        custom_delay(900);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(1, ILI9341_WHITE, 8, 0);
        custom_delay(900);
    ili9341_drawfillRect(120, 80, 80, 80, ILI9341_BLACK, 0);
    ili9341_setCursor(120, 100);
    ili9341_print("GO", ILI9341_RED, 7, 0, 0, width);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
}