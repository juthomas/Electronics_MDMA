#ifndef GAMES_H
# define GAMES_H

#include "background.h"
#include "intro.h"

typedef struct  s_game
{
	char *name1;
	char *name2;
    char *rules;
    const uint8_t *background;
	const uint16_t *backgroundPalette;
}               t_game;

const t_game games[10] = {
  {"Lucky", "Luck", "Press Green button to save civilian and red to kill bandit", LuckyBG, LuckyBGPalette},
  {"High", "Score", "Press the most times the red and green button successivly to beat THE HIGH SCORE", HighScoreBG, HighScoreBGPalette},
  {"Tic", "Tac", "You have 30 sec to not being the one with a bomb. Good luck.", TicBG, TicBGPalette},
  {"The", "Liar", "Tell a story then players have to devine if it was true or false. At the end reveal if you were a LIAR.", LiarBG, LiarBGPalette},
  {"Ping", "Pong", "Basicly it's an evil ping pong party with 5 players. Press the right color when the line arrive to you", SnailBG, SnailBGPalette},
  {"You", "Prefere ?", "Play the game 'you prefere ?' majority win at the end. Vote with buttons", ChoiceBG, ChoiceBGPalette},
  {"Friend", "Roulette", "You have 30 sec to select a player to kill.", RouletteBG, RouletteBGPalette},
  {"RPC", "Ultimate", "Here is the most complex game ever. Rock Paper Cisor. Prove your skills.", RockBG, RockBGPalette},
  {"Drift", "Racer", "Simple Be The first to press the right color, it can stay only one", SpeedBG, SpeedBGPalette},
  {"The", "WORLDO", "press the green button the closest of the 5sec", TimerBG, TimerBGPalette}
};




#endif