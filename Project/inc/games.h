#ifndef GAMES_H
# define GAMES_H

#include "background.h"
#include "intro.h"
#include <stdint.h>

typedef struct  s_game
{
	char *name1;
	char *name2;
    char *rules;
    const uint8_t *background;
	const uint16_t *backgroundPalette;
    char ratio;
}               t_game;

const t_game games[10] = {
  {"Lucky", "Luck", "Press the green\nbutton to save\ncivilians and red\nto kill bandits.\nBe careful if you\nmake a mistake\nyou are JAILED.\nNo one can bypass\n\n     The LAW.\n", LuckyBG, LuckyBGPalette, 4},
  {"High", "Score", "Press the most\ntimes the red\nand green button\none after another\nto beat the\n  HIGH SCORE.\nSome people will\nbe LEGENDS and\nother WONT.\n", HighScoreBG, HighScoreBGPalette, 4},
  {"Tic", "Tac", "You have 30 sec\nto not being the\none with a bomb.\nChoose ur target\nwith the encoder\nand launch with\nthe green button.\n\n   Good luck.", TicBG, TicBGPalette, 4},
  {"The", "Liar", "Select with the\ngreen or red\nbutton if ur \ngonna tell the\n     TRUTH.\nThen tell a story\nPlayers have to\nguess the truth.\nThe real liar is\n    SOCIETY.", LiarBG, LiarBGPalette, 4},
  {"Tokyo", "Drift", "Basicly it's an\nevil ping pong\ngame at 5.\nPress the right\ncolor when the\nline arrive\nto the last light\nof your side.\nPray to not be\nTHE WEAK", SpeedBG, SpeedBGPalette, 4},
  {"You", "Rather?", "Play the game\n 'you rather?'\nThe majority win.\nIndicate what\nbutton nis linked\nto each choice.\nSometimes not\neveryone can be\n\n     SAVED", ChoiceBG, ChoiceBGPalette, 4},
  {"Friend", "Roulette", "Every player have\n30 sec to select\nanother player to\nkill with the\nencoder. It's as\neasyas it seems.\nFriendship don't\n\n last FOREVER <3 ", RouletteBG, RouletteBGPalette, 4},
  {"RPC", "Ultimate", "Defy a player to\nthe most complex\ngame ever. Will\nyou play Rock?\nPaper? Cisor? You\nhave each only\n15sec to choose.\nProve your skills\nand become the\n     KING.", RockBG, RockBGPalette, 4},
  {"Captilsm", "Vantura", "Find the price of\nan object on\nInternet between\none and 99euros.\nEnter it's value\non the board.\nOther players\nhave to guess it.\nAll can be\n     BOUGHT.", CoinBG, CoinBGPalette, 4},
  {"Zero", "Zero", "You have 3 moves\n protect, reload,\nand fire. You cannot fire without amo, and you don't die if you protect yourself. The risk pay.", DuelBG, DuelBGPalette, 4}
};




#endif