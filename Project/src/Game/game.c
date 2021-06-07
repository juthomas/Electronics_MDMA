#include "../../inc/ili9341.h"
#include "../../inc/games.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"
#include "../inc/millis.h"

unsigned long int next = 56345345540;
void custom_delay(uint32_t milli);

uint16_t createRGB(uint8_t r, uint8_t g, uint8_t b)
{
    r /= 8;
    g /= 4;
    b /= 8;
    return ((r & 0xff) << 11) + ((g & 0xff) << 5) + (b & 0xff);
}

int rand(void)
{
    next = next * 1103515243 + 12345;
    return (unsigned int)(next / 65536) % 32768;
}

void srand(unsigned int seed)
{
    next = seed;
}

void endGame()
{
    int8_t indexPlayer = 0;
    uint8_t *pixels = (uint8_t[64 * 3]){};
    uint8_t matTab[5] = {MAT_1, MAT_2, MAT_3, MAT_4, MAT_5};
    while (indexPlayer < 5)
    {
        indexPlayer = 0;
        for (int8_t i = 0; i < 5; i++)
        {
            if ((buttons_clicks_order[i * 3] || buttons_clicks_order[i * 3 + 1]) && players[i].sipNeeded)
            {
                players[i].sipNeeded--;
                draw_numbers(pixels, players[i].sipNeeded, 0x101010);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
        }
        clear_buttons();
        while (indexPlayer < 5)
        {
            if (players[indexPlayer].sipNeeded > 0)
                break;
            indexPlayer++;
        }
    }
}

void distribute_sip(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t sips)
{
    uint8_t matTab[5] = {MAT_1, MAT_2, MAT_3, MAT_4, MAT_5};
    uint8_t *pixels = (uint8_t[64 * 3]){};
    while(sips > 0)
    {
        if(buttons_clicks_order[currentPlayer * 3])
        {
            players[encoders[currentPlayer] / 4 % 4 + 1 + currentPlayer].sipNeeded++;
            sips--;
            clear_buttons();
        }
    }
}

void lucky_luck(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}

void high_score(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void tic_tac(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}

void the_liar(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void tokyo_drift(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void friend_roulette(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void rpc_ultimate(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void capitalism_vantura(uint8_t currentPlayer, uint8_t *led_buffer)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}
void zero_zero(uint8_t currentPlayer, uint8_t *led_buffer)
{
    uint8_t matTab[5] = {MAT_1, MAT_2, MAT_3, MAT_4, MAT_5};
    uint8_t *pixels = (uint8_t[64 * 3]){};
    uint32_t startTime;
    clear_buttons();
    clear_encoders();
    while (SOMEONE_ALIVE)
    {
        startTime = millis;
        while (millis - startTime > 10000 && (!buttons_clicks_order[0]) || (!buttons_clicks_order[3]) || (!buttons_clicks_order[6]) || (!buttons_clicks_order[9]) || (!buttons_clicks_order[12]))
        {
            for (int i = 0; i < 5; i++)
            {
                if (buttons_clicks_order[i * 3 + 1])
                {
                    buttons_clicks_order[i * 3] = 0;
                    buttons_clicks_order[i * 3 + 1] = 0;
                }
                if (buttons_clicks_order[i * 3])
                    led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
                else matTab[i] = pixel[encoders[i] / 4 % 3]; // Pixel Art
            }
        }
        for (int j = 0; j < 5; j++)
        {
            if (!players[j].dead)
            {
                if (encoders[j] / 4 % 3 == 0 && players[j].amo)
                {
                    if (!players[j * 2 % 5].dead && encoders[j] / 4 % 3 != 1);
                       
                }
            }
        }
    }
}

void red_button(uint8_t currentPlayer, uint8_t *led_buffer)
{
    int8_t redButtonsPushed = 0;
    ili9341_fillScreen(ILI9341_BLACK);
    uint32_t startTime = millis;
    uint32_t leftTime = (30000 - (millis - startTime)) / 1000;
    uint32_t oldTime = 0;
    clear_buttons();
    while (millis - startTime < 30000 && redButtonsPushed < 4)
    {
        if (leftTime - oldTime)
        {
            ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
            ili9341_putnbrln(leftTime, createRGB(255, 8 * leftTime, 8 * leftTime), 20, 0);
            redButtonsPushed = (!(!(buttons_clicks_order[1]))) + (!(!(buttons_clicks_order[4]))) + (!(!(buttons_clicks_order[7]))) + (!(!(buttons_clicks_order[10]))) + (!(!(buttons_clicks_order[13])));
            if (leftTime == 10)
            {
                ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
                ili9341_putnbrln(leftTime, ILI9341_BLACK, 20, 0);
            }
            oldTime = leftTime;
        }
        leftTime = (30000 - (millis - startTime)) / 1000;
        for (int i = 0; i < redButtonsPushed; i++)
            ili9341_print("x   ", ILI9341_RED, 4, 0, 0, width);
    }
    for (int j = 0; j < 5; j++)
    {
        if (!(buttons_clicks_order[j * 3 + 1]))
            players[j].sipNeeded = redButtonsPushed + 1;
    }
    clear_buttons();
}

void you_rather(uint8_t currentPlayer, uint8_t *led_buffer)
{
    uint8_t *pixels = (uint8_t[64 * 3]){};
    uint8_t matTab[5] = {MAT_1, MAT_2, MAT_3, MAT_4, MAT_5};
    uint8_t redScore = 0;
    uint8_t greenScore = 0;
    clear_buttons();
    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
    led_matrix_fill_screen(pixels, 0x000000);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

    while ((!buttons_clicks_order[0] && !buttons_clicks_order[1]) || (!buttons_clicks_order[3] && !buttons_clicks_order[4]) || (!buttons_clicks_order[6] && !buttons_clicks_order[7]) || (!buttons_clicks_order[9] && !buttons_clicks_order[10]) || (!buttons_clicks_order[12] && !buttons_clicks_order[13]))
    {
        for (int i = 0; i < 5; i++)
        {
            if (buttons_clicks_order[i * 3] || buttons_clicks_order[i * 3 + 1])
            {
                led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if (buttons_clicks_order[j * 3] > buttons_clicks_order[j * 3 + 1])
        {
            greenScore++;
            led_matrix_fill_screen(pixels, 0x100000);
        }
        else
        {
            redScore++;
            led_matrix_fill_screen(pixels, 0x001000);
        }
        led_send_data_PORTA(matTab[j], pixels, 64);
    }
    for (int l = 0; l < 5; l++)
    {
        if (greenScore < redScore && buttons_clicks_order[l * 3] > buttons_clicks_order[l * 3 + 1])
            players[l].sipNeeded = redScore - greenScore;
        else if (greenScore > redScore && buttons_clicks_order[l * 3] < buttons_clicks_order[l * 3 + 1])
            players[l].sipNeeded = greenScore - redScore;
    }
    custom_delay(1000);
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

void display_selection()
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_setCursor(width / 6, 10);
    ili9341_println("WELCOME\n", ILI9341_WHITE, 4, 0);
    ili9341_println("Select your roles\nand press start\nto play your\n", ILI9341_WHITE, 3, 0);
    ili9341_println("    SOULS", ILI9341_RED, 4, 0);
}

void display_dice_result(uint8_t result1, uint8_t result2)
{
    if (result2)
    {
        ili9341_drawfillRect(width - 40 - 80, 20, 80, 80, ILI9341_BLACK, 0);
        for (int i = 0; i < 9; i++)
        {
            if (dice[result2 - 1][i])
            {
                ili9341_drawfillRect((width - 25 - 80) + 20 * (i % 3), 35 + 20 * (i / 3), 10, 10, ILI9341_WHITE, 0);
            }
        }
    }
    else if (result1)
    {
        ili9341_drawfillRect(40, 20, 80, 80, ILI9341_BLACK, 0);
        for (int i = 0; i < 9; i++)
        {
            if (dice[result1 - 1][i])
            {
                ili9341_drawfillRect(55 + 20 * (i % 3), 35 + 20 * (i / 3), 10, 10, ILI9341_WHITE, 0);
            }
        }
    }
}

void laugthing_demon()
{
    ili9341_draw_IMG(DevilEyesBG, DevilEyesBGPalette, 0, 0, 32, 12, 10);
    for (int timer = 0; timer < 3; timer++)
    {
        ili9341_draw_IMG(DevilSmileBG, DevilSmileBGPalette, 0, 120, 32, 12, 10);
        ili9341_draw_IMG(DevilSmile2BG, DevilSmile2BGPalette, 0, 120, 32, 12, 10);
    }
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
    ili9341_draw_IMG(BaphometBG, BaphometBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(KingCrimsonBG, KingCrimsonBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(CorridorBG, CorridorBGPalette, 0, 0, 32, 24, 10);
    ili9341_draw_IMG(PentacleBG, PentacleBGPalette, 0, 0, 32, 24, 10);
}

void display_intro_game(int8_t index, int8_t side, uint8_t currentPlayer)
{
    ili9341_setRotation(side);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
    ili9341_draw_IMG(CadreBG, CadreBGPalette, 40, 120, 60, 30, 4);
    ili9341_setCursor(70, 140);
    ili9341_print(games[index].name1, ILI9341_WHITE, 4, 0, 80, width - 40);
    ili9341_setCursor(70, 180);
    ili9341_print(games[index].name2, ILI9341_WHITE, 4, 0, 80, width - 40);
    clear_buttons();
    while (!buttons_clicks_order[currentPlayer * 3] && !buttons_clicks_order[currentPlayer * 3 + 1])
        ;
    ili9341_draw_IMG(CadreBigBG, CadreBigBGPalette, 40, 40, 60, 50, 4);
    ili9341_setCursor(60, 60);
    ili9341_print(games[index].rules, ILI9341_WHITE, 2, 0, 60, width - 50);
    custom_delay(1000);
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

void start_game(uint8_t *led_buffer)
{
    uint8_t dice_result_1;
    uint8_t dice_result_2;
    clear_buttons();
    red_button(1, led_buffer);
    for (;;)
        ;
    while (totalDice < 666)
    {
        ili9341_draw_IMG(DemonFace2BG, DemonFace2BGPalette, 0, 0, 32, 24, 10);
        dice_result_1 = dice_game(currentPlayer + 1);
        display_dice_result(dice_result_1 + 1, 0);
        dice_result_2 = dice_game(currentPlayer + 1);
        display_dice_result(0, dice_result_2 + 1);
        totalDice = dice_result_2 + dice_result_1;
        custom_delay(1000);
        ili9341_fillScreen(ILI9341_BLACK);
        for (int8_t i = 0; i < 6; i++)
        {
            ili9341_setCursor(50 + (totalDice + 2 < 10 ? 50 : 0), 50);
            ili9341_putnbr(totalDice + 2, createRGB(21 * (totalDice + 2), 255 / (totalDice + 2), 255 / (totalDice + 2)), 20, 0);
            ili9341_setCursor(50 + (totalDice + 2 < 10 ? 50 : 0), 50);
            ili9341_putnbr(totalDice + 2, ILI9341_BLACK, 20, 0);
        }
        laugthing_demon();
        display_intro_game(totalDice, (currentPlayer && currentPlayer < 3) ? 1 : 3, currentPlayer);
        clear_buttons();
        (*((games[totalDice]).gameFunction))(currentPlayer, led_buffer);
        endGame();
        currentPlayer = currentPlayer < 4 ? currentPlayer + 1 : 0;
    }
}