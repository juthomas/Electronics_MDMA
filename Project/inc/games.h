#ifndef GAMES_H
# define GAMES_H

#include "background.h"
#include "intro.h"
#include <stdint.h>

typedef struct  s_player
{
    uint8_t     index;
    uint8_t     class;
    uint8_t     manaNeeded;
    uint8_t     currentMana;
    uint8_t     sipNeeded;
    uint8_t     totalSipPlayer;
    uint8_t     totalDicePlayer;
    uint8_t     amo;
    uint8_t     dead;
}               t_player;

uint8_t     currentPlayer = 0;
uint16_t    totalDice = 0;
uint16_t    totalSip = 0;

typedef struct  s_game
{
	char            *name1;
	char            *name2;
    char            *rules;
    const uint8_t   *background;
	const uint16_t  *backgroundPalette;
    void            (*gameFunction)(uint8_t, uint8_t *, uint8_t *);
}               t_game;

void lucky_luck(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void high_score(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void tic_tac(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void the_liar(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void tokyo_drift(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void you_rather(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void friend_roulette(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void rpc_ultimate(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void capitalism_vantura(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void zero_zero(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);
void red_button(uint8_t currentPlayer, uint8_t *led_buffer, uint8_t *pixels);

const t_game games[] = {
  [0] = {"Lucky", "Luck", "Press the green\nbutton to save\ncivilians and red\nto kill bandits.\nBe careful if you\nmake a mistake\nyou are JAILED.\nNo one can bypass\n\n     The LAW.\n", LuckyBG, LuckyBGPalette, &lucky_luck},
  [1] = {"High", "Score", "Press the most\ntimes the red\nand green button\none after another\nto beat the\n  HIGH SCORE.\nSome people will\nbe LEGENDS and\nother WONT.\n", HighScoreBG, HighScoreBGPalette, &high_score},
  [2] = {"Tic", "Tac", "You have 30 sec\nto not being the\none with a bomb.\nChoose ur target\nwith the encoder\nand launch with\nthe green button.\n\n   Good luck.", TicBG, TicBGPalette, &tic_tac},
  [3] = {"The", "Liar", "Select with the\ngreen or red\nbutton if ur \ngonna tell the\n     TRUTH.\nThen tell a story\nPlayers have to\nguess the truth.\nThe real liar is\n    SOCIETY.", LiarBG, LiarBGPalette, &the_liar},
  [4] = {"Tokyo", "Drift", "Basicly it's an\nevil ping pong\ngame at 5.\nPress the right\ncolor when the\nline arrive\nto the last light\nof your side.\nPray to not be\nTHE WEAK", SpeedBG, SpeedBGPalette, &tokyo_drift},
  [5] = {"You", "Rather?", "Play the game\n 'you rather?'\nThe majority win.\nIndicate what\nbutton nis linked\nto each choice.\nSometimes not\neveryone can be\n\n     SAVED", ChoiceBG, ChoiceBGPalette, &you_rather},
  [6] = {"Friend", "Roulette", "Every player have\n30 sec to select\nanother player to\nkill with the\nencoder. It's as\neasyas it seems.\nFriendship don't\n\n last FOREVER <3 ", RouletteBG, RouletteBGPalette, &friend_roulette},
  [7] = {"RPC", "Ultimate", "Defy a player to\nthe most complex\ngame ever. Will\nyou play Rock?\nPaper? Cisor? You\nhave each only\n15sec to choose.\nProve your skills\nand become the\n     KING.", RockBG, RockBGPalette, &rpc_ultimate},
  [8] = {"Captilsm", "Vantura", "Find the price of\nan object on\nInternet between\none and 99euros.\nEnter it's value\non the board.\nOther players\nhave to guess it.\nAll can be\n     BOUGHT.", CoinBG, CoinBGPalette, &capitalism_vantura},
  [9] = {"Zero", "Zero", "You have 3 moves\n protect, reload,\nand fire. You cannot fire without amo, and you don't die if you protect yourself. The risk pay.", DuelBG, DuelBGPalette, &zero_zero},
  [10] = {"Red", "Button", "Please don't push the red button. Thank you <3", DuelBG, DuelBGPalette, &red_button}
};

static const uint8_t dice [6][9] =
{
    {0, 0, 0, 0, 1, 0, 0, 0, 0},
    {0, 0, 1, 0, 0, 0, 1, 0, 0},
    {0, 0, 1, 0, 1, 0, 1, 0, 0},
    {1, 0, 1, 0, 0, 0, 1, 0, 1},
    {1, 0, 1, 0, 1, 0, 1, 0, 1},
    {1, 0, 1, 1, 0, 1, 1, 0, 1},
};

t_player players[] = {
{1, 0, 0, 0, 0, 0, 0, 1, 0},
{2, 0, 0, 0, 0, 0, 0, 1, 0},
{3, 0, 0, 0, 0, 0, 0, 1, 0},
{4, 0, 0, 0, 0, 0, 0, 1, 0},
{5, 0, 0, 0, 0, 0, 0, 1, 0}
};

#endif