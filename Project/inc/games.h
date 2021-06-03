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
}               t_game;

const t_game games[10] = {
  {"Lucky", "Luck", "Press the green\nbutton to save\ncivilians and red\nto kill bandits.\nBe careful if you\nmake a mistake\nyou are JAILED.\nNo one can bypass\n\n     The LAW.\n", LuckyBG, LuckyBGPalette},
  {"High", "Score", "Press the most\ntimes the red\nand green button\none after another\nto beat the\n  HIGH SCORE.\nSome people will\nbe LEGENDS and\nother WONT.\n", HighScoreBG, HighScoreBGPalette},
  {"Tic", "Tac", "You have 30 sec\nto not being the\none with a bomb.\nChoose ur target\nwith the encoder\nand launch with\nthe green button.\n\n   Good luck.", TicBG, TicBGPalette},
  {"The", "Liar", "Select with the\ngreen or red\nbutton if ur \ngonna tell the\n      TRUTH.\nThen tell a story\nPlayers have to\nguess the truth.\nThe real liar is\n    SOCIETY.", LiarBG, LiarBGPalette},
  {"Ping", "Pong", "Basicly it's an\nevil ping pong\ngame at 5.\nPress the right\ncolor when the\nline arrive\nto the last light\nof your side.\nPray to not be\nTHE WEAK", SnailBG, SnailBGPalette},
  {"You", "Rather?", "Play the game\n 'you rather?' \nThe majority win.\nIndicate what \nbutton nis linked\nto each choice.\nSometimes not\neveryone can be\n\n     SAVED", ChoiceBG, ChoiceBGPalette},
  {"Friend", "Roulette", "You have 30 sec to select a player to kill.", RouletteBG, RouletteBGPalette},
  {"RPC", "Ultimate", "Here is the most complex game ever. Rock Paper Cisor. Prove your skills.", RockBG, RockBGPalette},
  {"Drift", "Racer", "Simple Be The first to press the right color, it can stay only one", SpeedBG, SpeedBGPalette},
  {"The", "WORLDO", "press the green button the closest of the 5sec", TimerBG, TimerBGPalette}
};




#endif