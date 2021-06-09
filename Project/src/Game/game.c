#include "../../inc/ili9341.h"
#include "../../inc/games.h"
#include "../inc/leds.h"
#include "../inc/buttons.h"
#include "../inc/millis.h"
#include "../inc/encoders.h"
#include "../inc/matrix_progmem.h"
#include <util/delay.h>

#define TRUE 1
#define FALSE 0

uint8_t matTab[5] = {MAT_1, MAT_2, MAT_3, MAT_4, MAT_5};
unsigned long int next = 56345345540;

void draw_satanic_circle(uint8_t *buffer)
{
    // uint8_t buffer[62 * 3 * 5];
    uint8_t matrix_buffer[64 * 3];
    // uint8_t color = 10;
    uint32_t interactions_color = 0x100000;
    clear_led_buffer(buffer, 62 * 3 * 5, 0x010101);
    led_matrix_fill_screen(matrix_buffer, 0x000000);
    // led_send_data(3, pixels, 64);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, matrix_buffer, 64);

    led_send_data_PORTA(1 << PIN5, buffer, 62 * 5);
    // for (int32_t i = 0; i < 100000; i++)
    // 	;
    _delay_ms(100);

    draw_line_between_players(buffer, 1, 3, TRUE, interactions_color);
    led_matrix_send_progmem(MAT_3, SAT_SYMB_3);
                _delay_ms(100);

    draw_line_between_players(buffer, 3, 5, TRUE, interactions_color);
    led_matrix_send_progmem(MAT_5, SAT_SYMB_5);

                _delay_ms(100);

    draw_line_between_players(buffer, 5, 2, TRUE, interactions_color);
    led_matrix_send_progmem(MAT_2, SAT_SYMB_2);

                _delay_ms(100);

    draw_line_between_players(buffer, 2, 4, TRUE, interactions_color);
    led_matrix_send_progmem(MAT_4, SAT_SYMB_4);
                _delay_ms(100);

    draw_line_between_players(buffer, 4, 1, TRUE, interactions_color);
    led_matrix_send_progmem(MAT_1, SAT_SYMB_1);
                _delay_ms(100);
    draw_line_between_players(buffer, 1, 2, TRUE, interactions_color);
    draw_line_between_players(buffer, 2, 3, TRUE, interactions_color);
    draw_line_between_players(buffer, 3, 4, TRUE, interactions_color);
    draw_line_between_players(buffer, 4, 5, TRUE, interactions_color);
    draw_line_between_players(buffer, 5, 1, TRUE, interactions_color);

    led_matrix_send_progmem(MAT_1, SAT_SYMB_1);
    led_matrix_send_progmem(MAT_2, SAT_SYMB_2);
    led_matrix_send_progmem(MAT_3, SAT_SYMB_3);
    led_matrix_send_progmem(MAT_4, SAT_SYMB_4);
    led_matrix_send_progmem(MAT_5, SAT_SYMB_5);
}

uint8_t dice_game(uint8_t player)
{
    uint8_t matrix_mask;
    if (player == 1)
    {
        matrix_mask = MAT_1;
    }
    else if (player == 2)
    {
        matrix_mask = MAT_2;
    }
    else if (player == 3)
    {
        matrix_mask = MAT_3;
    }
    else if (player == 4)
    {
        matrix_mask = MAT_4;
    }
    else if (player == 5)
    {
        matrix_mask = MAT_5;
    }

    uint16_t counter = 0;
    while (!buttons_clicks_order[(player - 1) * 3 + 1])
    {
        _delay_ms(1);
    }
    while (buttons_clicks_order[(player - 1) * 3 + 1])
    {
        clear_buttons();
        if (counter % 6 == 0)
        {
            led_matrix_send_progmem(matrix_mask, DICE_1);
        }
        if (counter % 6 == 1)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_2);
        }

        if (counter % 6 == 2)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_3);
        }
        if (counter % 6 == 3)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_4);
        }
        if (counter % 6 == 4)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_5);
        }
        if (counter % 6 == 5)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_6);
        }
        for (int32_t i = 0; i < 800; i++)
            _delay_ms(1);
        counter++;
        if (counter > 300000)
            counter = 0;
    }
    for (int32_t u = 1; u < 5; u++)
    {
        if ((counter + u) % 6 == 0)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_1);
        }
        if ((counter + u) % 6 == 1)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_2);
        }

        if ((counter + u) % 6 == 2)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_3);
        }
        if ((counter + u) % 6 == 3)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_4);
        }
        if ((counter + u) % 6 == 4)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_5);
        }
        if ((counter + u) % 6 == 5)
        {
            _delay_ms(100);
            led_matrix_send_progmem(matrix_mask, DICE_6);
        }
        for (int32_t i = 0; i < 800 * u; i++)
            _delay_ms(1);
    }
    return ((counter + 4) % 6);
}

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

void endGame(uint8_t *pixels)
{
    int8_t totalSipNeeded = 0;
    uint8_t isActive[] = {0, 0, 0, 0, 0};
    ili9341_draw_IMG(DrinkBG, DrinkBGPalette, 0, 0, 80, 60, 4);
    ili9341_draw_IMG(CadreBG, CadreBGPalette, 40, 120, 60, 30, 4);
    ili9341_setCursor(70, 165);
    ili9341_print("CHEERS", ILI9341_WHITE, 5, 0, 80, width - 40);
    for (int8_t i = 0; i < 5; i++)
    {
        pixels = (uint8_t[64 * 3]){};
        draw_numbers(pixels, players[i].sipNeeded, 0x101010);
        led_send_data_PORTA(matTab[i], pixels, 64);
        totalSipNeeded += players[i].sipNeeded;
    }
    clear_buttons();
    while (totalSipNeeded)
    {
        for (int8_t i = 0; i < 5; i++)
        {
            if (!(isActive[i]) && get_button_activation(i * 3 + 1) && players[i].sipNeeded)
            {
                players[i].sipNeeded--;
                totalSipNeeded--;
                pixels = (uint8_t[64 * 3]){};
                draw_numbers(pixels, players[i].sipNeeded, 0x101010);
                led_send_data_PORTA(matTab[i], pixels, 64);
                isActive[i] = 1;
            }
            if (!get_button_activation(i * 3 + 1))
                isActive[i] = 0;
        }
    }
}

void distribute_sip(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t sips)
{
    ili9341_fillScreen(ILI9341_BLACK);
    clear_buttons();
    clear_encoders();
    while (sips > 0)
    {
        if (get_button_order(currentPlayer * 3 + 1))
        {
            players[(encoders[currentPlayer] / 4 % 4 + currentPlayer + 1)].sipNeeded++;
            sips--;
            while (get_button_activation(currentPlayer * 3 + 1))
            {
                draw_line_between_players(led_buffer, currentPlayer + 1, (encoders[currentPlayer] / 4 % 4 + currentPlayer + 1) % 5 + 1, TRUE, 0x080000);
                if (!get_button_activation(currentPlayer * 3 + 1))
                    break;
                draw_line_between_players(led_buffer, currentPlayer + 1, (encoders[currentPlayer] / 4 % 4 + currentPlayer + 1) % 5 + 1, TRUE, 0x000000);
            }
            clear_buttons();
        }
        ili9341_setCursor(100, 50);
        ili9341_putnbrln(sips, ILI9341_RED, 20, 0);
        clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
        draw_line_between_players(led_buffer, currentPlayer + 1, (encoders[currentPlayer] / 4 % 4 + currentPlayer + 1) % 5 + 1, TRUE, 0x080000);
        draw_line_between_players(led_buffer, currentPlayer + 1, (encoders[currentPlayer] / 4 % 4 + currentPlayer + 1) % 5 + 1, TRUE, 0x000000);
    }
}

void lucky_luck(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}

void high_score(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}

void tic_tac(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    uint32_t startTime = millis;

    uint32_t leftTime = (30000 - (millis - startTime)) / 1000;
    uint32_t oldTime = 0;
    uint8_t *nb_votes;
    clear_buttons();
    clear_encoders();
    ili9341_fillScreen(ILI9341_BLACK);
    uint8_t bombPos = currentPlayer;
    led_matrix_fill_screen(pixels, 0x000000);
    led_send_data_PORTA(MAT_ALL, pixels, 64);
    led_matrix_send_progmem(matTab[bombPos], BOMB);
    while (millis - startTime < 30000)
    {
        if (leftTime - oldTime)
        {
            ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
            ili9341_putnbrln(leftTime, createRGB(255, 8 * leftTime, 8 * leftTime), 20, 0);
            //redButtonsPushed = (buttons_clicks_order[0] > 0) + (buttons_clicks_order[3] > 0) + (buttons_clicks_order[6] > 0) + (buttons_clicks_order[9] > 0) + (buttons_clicks_order[12] > 0);
            if (leftTime == 10)
            {
                ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
                ili9341_putnbrln(leftTime, ILI9341_BLACK, 20, 0);
            }
            oldTime = leftTime;
        }
        if (buttons_clicks_order[bombPos * 3 + 1])
        {
            led_matrix_fill_screen(pixels, 0x000000);
            led_send_data_PORTA(matTab[bombPos], pixels, 64);
            bombPos = (((encoders[bombPos] + 4096) / 4 % 4 + bombPos + 1) % 5);
            clear_encoders();
            led_matrix_send_progmem(matTab[bombPos], BOMB);
            clear_buttons();
        }
        clear_led_buffer(led_buffer, 62 * 3 * 5, 0x090000 | (3 * leftTime / 10) << 2 | (3 * leftTime / 10));
        draw_line_between_players(led_buffer, bombPos + 1, ((encoders[bombPos] + 4096) / 4 % 4 + bombPos + 1) % 5 + 1, TRUE, 0x000000);
        draw_line_between_players(led_buffer, bombPos + 1, ((encoders[bombPos] + 4096) / 4 % 4 + bombPos + 1) % 5 + 1, TRUE, 0x090000 | (3 * leftTime / 10) << 2 | (3 * leftTime / 10));
        leftTime = (30000 - (millis - startTime)) / 1000;
    }
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4 | LED_ROW_5, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4 | LED_ROW_5 | LED_ROW_6, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 1, 1, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4 | LED_ROW_5 | LED_ROW_6 | LED_ROW_7, 0x080000, 0x080500);
    draw_cirle_pit(led_buffer, 500, 20, D_WAWES, LED_ROW_1 | LED_ROW_2 | LED_ROW_3 | LED_ROW_4 | LED_ROW_5 | LED_ROW_6 | LED_ROW_7 | LED_ROW_8, 0x080000, 0x080500);
    players[bombPos].sipNeeded = 3;
    led_matrix_fill_screen(pixels, 0x000000);
    led_send_data_PORTA(MAT_ALL, pixels, 64);
}

void the_liar(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{

    clear_buttons();
    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
    led_matrix_fill_screen(pixels, 0x000000);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);
    while (!(buttons_clicks_order[currentPlayer * 3 + 1]))
        ;
    while (((!buttons_clicks_order[0]) && (!buttons_clicks_order[1])) || ((!buttons_clicks_order[3]) && (!buttons_clicks_order[4])) || ((!buttons_clicks_order[6]) && (!buttons_clicks_order[7])) || ((!buttons_clicks_order[9]) && (!buttons_clicks_order[10])) || ((!buttons_clicks_order[12]) && (!buttons_clicks_order[13])))
    {
        for (int i = 0; i < 5; i++)
        {
            if (i != currentPlayer && (buttons_clicks_order[i * 3] || buttons_clicks_order[i * 3 + 1]))
            {
                led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
        }
    }
    for (int j = 0; j < 5; j++)
    {
        if (buttons_clicks_order[j * 3] > buttons_clicks_order[j * 3 + 1])
            led_matrix_fill_screen(pixels, 0x100000);
        else
            led_matrix_fill_screen(pixels, 0x001000);
        led_send_data_PORTA(matTab[j], pixels, 64);
    }
    clear_buttons();
    while ((!buttons_clicks_order[currentPlayer * 3]) && (!buttons_clicks_order[currentPlayer * 3 + 1]))
        ;
    for (int l = 0; l < 5; l++)
    {
        if (l != currentPlayer && ((buttons_clicks_order[currentPlayer * 3] > buttons_clicks_order[currentPlayer * 3 + 1]) &&
                                   (buttons_clicks_order[l * 3] < buttons_clicks_order[l * 3 + 1])) ||
            ((buttons_clicks_order[currentPlayer * 3] < buttons_clicks_order[currentPlayer * 3 + 1]) &&
             (buttons_clicks_order[l * 3] > buttons_clicks_order[l * 3 + 1])))
            players[l].sipNeeded = 2;
    }
    _delay_ms(1000);
    clear_buttons();
}

void tokyo_drift(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    ili9341_fillScreen(ILI9341_BLACK);
    ili9341_println("Need to be done", ILI9341_RED, 4, 0);
}

void friend_roulette(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    ili9341_fillScreen(ILI9341_BLACK);
    uint32_t startTime = millis;
    uint32_t leftTime = (30000 - (millis - startTime)) / 1000;
    uint32_t oldTime = 0;
    uint8_t *nb_votes;
    clear_buttons();
    while (millis - startTime < 30000)
    {
        if (leftTime - oldTime)
        {
            ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
            ili9341_putnbrln(leftTime, createRGB(255, 8 * leftTime, 8 * leftTime), 20, 0);
            if (leftTime == 10)
            {
                ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
                ili9341_putnbrln(leftTime, ILI9341_BLACK, 20, 0);
            }
            oldTime = leftTime;
        }
        leftTime = (30000 - (millis - startTime)) / 1000;
        ili9341_setCursor(10, 200);
        for (int i = 0; i < 5; i++)
        {
            nb_votes[abs(encoders[i]) / 4 % 4 + 1 + i] += 1;
        }
    }
    for (int i = 0; i < 5; i++)
    {
        players[i].sipNeeded = nb_votes[i];
    }
    clear_buttons();
}

void rpc_ultimate(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{
    uint8_t player2;
    uint8_t player1Sign;
    uint8_t player2Sign;
    while (!(buttons_clicks_order[currentPlayer * 3 + 1]))
    {
        pixels = (uint8_t[64 * 3]){};
        draw_numbers(pixels, abs(encoders[currentPlayer]) / 4 % 4, 0x101010);
        led_send_data_PORTA(matTab[currentPlayer], pixels, 64);
    }
    player2 = abs(encoders[currentPlayer]) / 4 % 4 + 1 + currentPlayer;
    while ((!buttons_clicks_order[currentPlayer]) || (!buttons_clicks_order[currentPlayer]))
    {
    re_game:;
        if (buttons_clicks_order[currentPlayer * 3])
        {
            buttons_clicks_order[currentPlayer * 3] = 0;
            buttons_clicks_order[currentPlayer * 3 + 1] = 0;
        }
        if (buttons_clicks_order[currentPlayer * 3 + 1])
        {
            led_matrix_fill_screen(pixels, 0x080808);
            led_send_data_PORTA(matTab[currentPlayer], pixels, 64);
            player1Sign = abs(encoders[currentPlayer] / 4) % 3;
        }
        else
        {
            pixels = (uint8_t[64 * 3]){};
            draw_numbers(pixels, abs(encoders[currentPlayer]) / 4 % 3, 0x101010);
            led_send_data_PORTA(matTab[currentPlayer], pixels, 64);
        }
        if (buttons_clicks_order[player2 * 3])
        {
            buttons_clicks_order[player2 * 3] = 0;
            buttons_clicks_order[player2 * 3 + 1] = 0;
        }
        if (buttons_clicks_order[player2 * 3 + 1])
        {
            led_matrix_fill_screen(pixels, 0x080808);
            led_send_data_PORTA(matTab[player2], pixels, 64);
            player2Sign = abs(encoders[player2] / 4) % 3;
        }
        else
        {
            pixels = (uint8_t[64 * 3]){};
            draw_numbers(pixels, abs(encoders[player2]) / 4 % 3, 0x101010);
            led_send_data_PORTA(matTab[player2], pixels, 64);
        }
    }
    if ((player1Sign == 0 && player2Sign == 1) || (player1Sign == 1 && player2Sign == 2) || (player1Sign == 2 && player2Sign == 0))
        players[currentPlayer].sipNeeded = 3;
    else if ((player2Sign == 0 && player1Sign == 1) || (player2Sign == 1 && player1Sign == 2) || (player2Sign == 1 && player1Sign == 2))
        players[player2].sipNeeded = 2;
    else
    {
        clear_buttons();
        clear_encoders();
        goto re_game;
    }
}

void capitalism_vantura(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{

    int8_t buffer;
    uint8_t priceSelected[] = {-1, -1, -1, -1, -1};
    uint8_t leaderboard[] = {0, 1, 2, 3, 4};
    clear_buttons();
    clear_encoders();
    buttons_clicks_order[currentPlayer * 3 + 1] = 6;
    while ((!buttons_clicks_order[1]) || (!buttons_clicks_order[4]) || (!buttons_clicks_order[7]) || (!buttons_clicks_order[10]) || (!buttons_clicks_order[13]))
    {
        for (int i = 0; i < 5; i++)
        {
            if (i != currentPlayer)
            {
                if (buttons_clicks_order[i * 3])
                {
                    buttons_clicks_order[i * 3] = 0;
                    buttons_clicks_order[i * 3 + 1] = 0;
                }
                if (buttons_clicks_order[i * 3 + 1])
                {
                    led_matrix_fill_screen(pixels, 0x080808);
                    led_send_data_PORTA(matTab[i], pixels, 64);
                    priceSelected[i] = abs(encoders[i] / 4) % 99;
                }
                else
                {
                    pixels = (uint8_t[64 * 3]){};
                    draw_numbers(pixels, abs(encoders[i]) / 4 % 99, 0x101010);
                    led_send_data_PORTA(matTab[i], pixels, 64);
                    //matTab[i] = encoders[i] / 4 % 3]; // Pixel Art
                }
            }
        }
    }
    while (!buttons_clicks_order[currentPlayer * 3 + 1])
    {
        pixels = (uint8_t[64 * 3]){};
        draw_numbers(pixels, abs(encoders[currentPlayer]) / 4 % 99, 0x101010);
        led_send_data_PORTA(matTab[currentPlayer], pixels, 64);
    }
    priceSelected[currentPlayer] = abs(encoders[currentPlayer] / 4) % 99;
    for (int8_t i = 0; i < 4; i++)
    {
        if (abs(priceSelected[currentPlayer] - priceSelected[leaderboard[i]]) > abs(priceSelected[currentPlayer] - priceSelected[leaderboard[i]]))
        {
            buffer = priceSelected[leaderboard[i + 1]];
            priceSelected[leaderboard[i + 1]] = priceSelected[leaderboard[i]];
            priceSelected[leaderboard[i]] = buffer;
        }
    }
    for (int8_t i = 0; i < 5; i++)
    {
        players[leaderboard[i]].sipNeeded = i;
    }
}

void zero_zero_check_Attack(int8_t *playersAttack, uint8_t *pixels)
{
    for (int i = 0; i < 5; i++)
    {
        if (!players[i].dead)
        {
            if (buttons_clicks_order[i * 3])
            {
                buttons_clicks_order[i * 3 + 1] = 0;
                buttons_clicks_order[i * 3 + 2] = 0;
                playersAttack[i] = 0;
                _delay_ms(100);
                led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
            else if (buttons_clicks_order[i * 3 + 1])
            {
                playersAttack[i] = 1;
                buttons_clicks_order[i * 3] = 0;
                buttons_clicks_order[i * 3 + 2] = 0;
                _delay_ms(100);
                led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
            else if (buttons_clicks_order[i * 3 + 2])
            {
                playersAttack[i] = 2;
                buttons_clicks_order[i * 3] = 0;
                buttons_clicks_order[i * 3 + 1] = 0;
                _delay_ms(100);
                led_matrix_fill_screen(pixels, 0x080808);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
        }
        else if (!buttons_clicks_order[i * 3])
            buttons_clicks_order[i * 3] = 250;
    }
}

void zero_zero(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{

    uint8_t *led_buffer2 = (uint8_t[62 * 3 * 5]){};
    uint32_t startTime;
    int8_t winner;
    int8_t end = 1;
    int8_t playersAttack[] = {-1, -1, -1, -1, -1};
    clear_buttons();
    clear_encoders();
    clear_led_buffer(led_buffer2, 62 * 3 * 5, 0x000000);
    ili9341_draw_IMG(CadreBigBG, CadreBigBGPalette, 40, 40, 60, 50, 4);
    ili9341_setCursor(60, 60);
    ili9341_print("\n\nRED = FIRE\n\nGREEN = PROTEC'\n\nENCODER = RELOAD", ILI9341_WHITE, 2, 0, 60, width - 50);
    for (int i = 0; i < 5; i++)
    {
        players[i].dead = 0;
        players[i].amo = 1;
    }
    while (end)
    {
        clear_led_buffer(led_buffer, 62 * 3 * 5, 0x080000);
        led_send_data_PORTA(LEDS_REG, led_buffer, 62 * 5);
        startTime = millis;
        winner = -1;
        clear_buttons();
        for (int i = 0; i < 5; i++)
        {
            if (!players[i].dead)
            {
                led_matrix_fill_screen(pixels, 0x000000);
                led_send_data_PORTA(matTab[i], pixels, 64);
            }
            else
                playersAttack[i] = -1;
        }
        while ((((!buttons_clicks_order[0]) && (!buttons_clicks_order[1]) && (!buttons_clicks_order[2])) || ((!buttons_clicks_order[3]) && (!buttons_clicks_order[4]) && (!buttons_clicks_order[5])) || ((!buttons_clicks_order[6]) && (!buttons_clicks_order[7]) && (!buttons_clicks_order[8])) || ((!buttons_clicks_order[9]) && (!buttons_clicks_order[10]) && (!buttons_clicks_order[11])) || ((!buttons_clicks_order[12]) && (!buttons_clicks_order[13]) && (!buttons_clicks_order[14]))))
            zero_zero_check_Attack(playersAttack, pixels);
        zero_zero_check_Attack(playersAttack, pixels);
        for (int8_t i = 0; i < 5; i++)
        {
            if (!players[i].dead)
            {
                if (playersAttack[i] == 0)
                    led_matrix_send_progmem(matTab[i], GUN);
                else if (playersAttack[i] == 1)
                    led_matrix_send_progmem(matTab[i], SHIELD);
                else if (playersAttack[i] == 2)
                    led_matrix_send_progmem(matTab[i], BULLET);
                else
                    led_matrix_send_progmem(matTab[i], UNCHECK);
            }
        }
        _delay_ms(20000);
        for (int8_t j = 0; j < 5; j++)
        {
            if (playersAttack[j] == 0 && players[j].amo)
            {
                int8_t nextPlayer = -1;
                for (int8_t l = 1; l < 5 && nextPlayer == -1; l++)
                {
                    int8_t next = (j + l) % 5;
                    if (!players[next].dead)
                        nextPlayer = next;
                }
                draw_line_between_players(led_buffer, j % 5 + 1, nextPlayer % 5 + 1, TRUE, 0x080808);
                draw_line_between_players(led_buffer, j % 5 + 1, nextPlayer % 5 + 1, TRUE, 0x080000);
                if (!players[nextPlayer].dead && playersAttack[nextPlayer] != 1)
                {
                    led_send_data_PORTA(LEDS_REG, led_buffer2, 62 * 5);
                    players[nextPlayer].dead = 1;
                    led_matrix_send_progmem(matTab[nextPlayer], SKULL);
                    players[j].amo--;
                    led_send_data_PORTA(LEDS_REG, led_buffer, 62 * 5);
                }
                else
                    draw_halo(led_buffer, 1 << nextPlayer, 0x000800);
            }
            else if (playersAttack[j] == 2)
                players[j].amo += 1;
        }
        for (int8_t k = 0; k < 5 && winner != 6; k++)
        {
            if (!players[k].dead)
            {
                if (winner == -1)
                    winner = k;
                else
                    winner = 6;
            }
        }
        if (winner != 6)
        {
            ili9341_fillScreen(ILI9341_BLACK);
            ili9341_setCursor(0, 0);
            if (winner >= 0)
            {
                ili9341_println("The pleasure of the winners is to see the sunset.", ILI9341_WHITE, 3, 2);
                distribute_sip(winner, led_buffer, 7);
            }
            else
            {
                ili9341_println("\n\n  In front of death\n  no one can win.", ILI9341_WHITE, 3, 2);
                for (int8_t m = 0; m < 5; m++)
                    players[m].sipNeeded = 2;
            }
            end = 0;
        }
        _delay_ms(5000);
    }
}

void red_button(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
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
            redButtonsPushed = (buttons_clicks_order[0] > 0) + (buttons_clicks_order[3] > 0) + (buttons_clicks_order[6] > 0) + (buttons_clicks_order[9] > 0) + (buttons_clicks_order[12] > 0);
            if (leftTime == 10)
            {
                ili9341_setCursor(50 + (leftTime < 10 ? 50 : 0), 50);
                ili9341_putnbrln(leftTime, ILI9341_BLACK, 20, 0);
            }
            oldTime = leftTime;
        }
        leftTime = (30000 - (millis - startTime)) / 1000;
    }
    for (int j = 0; j < 5; j++)
    {
        if (redButtonsPushed < 3 && buttons_clicks_order[j * 3] == 0)
            players[j].sipNeeded = redButtonsPushed;
        else if (redButtonsPushed > 3 && buttons_clicks_order[j * 3] > 0)
            players[j].sipNeeded = redButtonsPushed;
    }
    clear_buttons();
}

void you_rather(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels)
{

    uint8_t redScore = 0;
    uint8_t greenScore = 0;
    clear_buttons();
    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x000000);
    led_matrix_fill_screen(pixels, 0x000000);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5, pixels, 64);

    while (((!buttons_clicks_order[0]) && (!buttons_clicks_order[1])) || ((!buttons_clicks_order[3]) && (!buttons_clicks_order[4])) || ((!buttons_clicks_order[6]) && (!buttons_clicks_order[7])) || ((!buttons_clicks_order[9]) && (!buttons_clicks_order[10])) || ((!buttons_clicks_order[12]) && (!buttons_clicks_order[13])))
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
    _delay_ms(5000);
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
    _delay_ms(2000);
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
    while ((!buttons_clicks_order[currentPlayer * 3]) && (!buttons_clicks_order[currentPlayer * 3 + 1]))
        ;
    ili9341_draw_IMG(CadreBigBG, CadreBigBGPalette, 40, 40, 60, 50, 4);
    ili9341_setCursor(60, 60);
    ili9341_print(games[index].rules, ILI9341_WHITE, 2, 0, 60, width - 50);
    _delay_ms(10000);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
    ili9341_draw_IMG(CadreSquareBG, CadreSquareBGPalette, 100, 60, 30, 30, 4);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(3, ILI9341_WHITE, 8, 0);
    _delay_ms(10000);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(2, ILI9341_WHITE, 8, 0);
    _delay_ms(10000);
    ili9341_setCursor(140, 90);
    ili9341_putnbr(1, ILI9341_WHITE, 8, 0);
    _delay_ms(10000);
    ili9341_drawfillRect(120, 80, 80, 80, ILI9341_BLACK, 0);
    ili9341_setCursor(120, 100);
    ili9341_print("GO", ILI9341_RED, 7, 0, 0, width);
    ili9341_draw_IMG(games[index].background, games[index].backgroundPalette, 0, 0, 80, 60, 4);
}

void start_game(uint8_t *led_buffer)
{
    uint8_t dice_result_1;
    uint8_t dice_result_2;
    uint8_t *pixels = (uint8_t[64 * 3]){};
    clear_buttons();
    ili9341_fillScreen(ILI9341_BLACK);
    clear_led_buffer(led_buffer, 62 * 3 * 5, 0x010101);
    led_send_data_PORTA(MAT_1 | MAT_3 | MAT_4 | MAT_2 | MAT_5 | 1 << PIN5, led_buffer, 62 * 3 * 5);
    led_matrix_fill_screen(led_buffer, 0x000000);
    draw_satanic_circle(led_buffer);
    ili9341_setRotation(3);
    //display_intro();
    //display_menu();
   // zero_zero(0, led_buffer, pixels);
   // endGame(pixels);
    while (totalDice < 666)
    {
        ili9341_draw_IMG(DemonFace2BG, DemonFace2BGPalette, 0, 0, 32, 24, 10);
        led_matrix_send_progmem(matTab[currentPlayer], CROWN);
        for (int i = 0; i < 5; i++)
        {
            if (i != currentPlayer)
                led_matrix_send_progmem(matTab[i], POOP);
            else
                led_matrix_send_progmem(matTab[i], CROWN);
        }
        clear_buttons();
        dice_result_1 = dice_game(currentPlayer + 1);
        _delay_ms(1000);
        clear_buttons();
        display_dice_result(dice_result_1 + 1, 0);
        dice_result_2 = dice_game(currentPlayer + 1);
        _delay_ms(1000);
        display_dice_result(0, dice_result_2 + 1);
        totalDice = dice_result_2 + dice_result_1;
        _delay_ms(10000);
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
        (*((games[totalDice]).gameFunction))(currentPlayer, led_buffer, pixels);
        endGame(pixels);
        currentPlayer = currentPlayer < 4 ? currentPlayer + 1 : 0;
        draw_satanic_circle(led_buffer);
    }
}