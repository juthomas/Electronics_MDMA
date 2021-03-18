#include "../../inc/mdma.h"
#define SWORD "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\15\15\15\20\21\20\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\15\15\15\20\21\20\10\11\12\0\1\0\0\1\0\0\0\0\1\1\1\15\15\15\20\21\20\10\11\12\0\0\1\13\21\0\13\21\0\1\2\1\15\15\15\20\21\20\10\11\12\0\0\1\0\0\0\1\2\0\13\21\1\15\15\15\20\21\20\10\11\12\0\0\1\0\0\0\0\0\0\0\1\0\5\14\3\13\21\1\10\11\12\1\1\1\0\0\0\0\0\0\0\0\0\5\13\3\5\13\3\3\11\5\13\21\0\13\21\0\0\1\0\0\0\0\0\0\0\2\10\5\2\10\5\0\0\0\1\2\0\13\21\0\0\1\0\0\0\0\0\0\0"

#define PURSE "\0\0\0\0\0\0\7\16\3\7\16\4\7\16\4\2\11\5\1\1\1\0\0\0\0\0\0\0\0\0\0\1\0\13\21\0\13\21\0\2\3\0\0\0\0\0\0\0\0\0\0\0\0\0\13\21\0\7\16\3\7\16\4\3\11\5\0\1\0\0\0\0\2\3\0\7\16\3\13\21\0\7\16\3\7\16\4\7\16\4\2\11\5\0\1\0\7\16\3\7\16\4\7\16\4\13\21\0\7\16\3\7\16\4\2\11\5\2\10\5\7\16\3\7\16\4\7\16\4\7\16\4\7\16\4\3\11\5\2\10\5\2\10\5\7\16\4\7\16\4\7\16\4\7\16\4\3\11\5\2\10\5\2\10\5\2\10\5\0\2\0\2\10\5\2\10\5\2\10\5\2\10\5\2\10\5\2\10\5\0\1\0"

#define BOW "\0\0\0\0\0\0\0\1\0\5\13\3\5\13\3\5\13\3\5\13\3\0\0\0\0\0\0\0\1\0\5\13\3\2\10\5\1\3\4\15\15\15\1\1\1\0\0\0\0\0\0\5\13\3\2\10\5\1\2\4\1\3\4\20\21\20\1\1\1\0\0\0\0\0\0\5\13\3\2\10\5\0\2\4\1\3\4\20\21\20\1\1\1\0\0\0\0\1\0\5\13\3\2\10\5\0\2\4\1\3\4\20\21\20\1\1\1\0\0\0\0\1\0\5\13\3\2\10\5\1\2\4\1\3\4\20\21\20\1\1\1\0\0\0\0\1\0\0\1\0\5\13\3\2\10\5\2\3\4\20\21\20\1\1\1\0\0\0\0\0\0\0\0\0\0\1\0\5\13\3\5\13\3\5\14\4\5\13\3\0\0\0"

#define POTION "\0\0\0\1\1\1\20\21\20\20\21\20\20\21\20\20\21\20\1\1\1\0\0\0\0\0\0\0\0\0\1\2\1\15\15\15\15\15\15\1\2\1\0\0\0\0\0\0\0\0\0\0\0\0\2\2\2\20\21\20\20\21\20\2\2\2\0\0\0\0\0\0\0\0\0\2\2\2\20\21\20\10\11\13\10\11\13\20\21\20\2\2\2\0\0\0\1\1\1\20\21\20\14\3\21\14\3\21\14\3\21\14\3\21\20\21\20\1\1\1\1\1\1\20\21\20\14\3\21\14\2\21\14\2\21\14\3\21\20\21\20\1\1\1\0\0\0\15\15\15\14\3\21\14\3\21\14\3\21\14\3\21\15\15\15\0\0\0\0\0\0\1\1\1\15\15\15\15\15\15\15\15\15\15\15\15\1\1\1\0\0\0"

#define COIN "\0\0\0\2\2\0\20\21\3\20\21\3\20\21\3\7\16\4\0\1\0\0\0\0\2\2\0\20\21\2\7\16\3\13\21\0\13\21\0\20\21\2\7\16\3\0\1\0\20\21\2\7\16\4\13\21\0\20\21\2\7\16\3\13\21\0\20\21\2\7\16\4\20\21\2\7\16\4\20\21\2\20\21\2\20\21\2\7\16\4\20\21\2\7\16\4\20\21\2\7\16\4\20\21\2\20\21\2\20\21\2\7\16\4\20\21\2\7\16\4\20\21\2\7\16\4\13\21\0\20\21\2\7\16\3\13\21\0\20\21\2\7\16\4\2\2\0\20\21\2\7\16\3\13\21\0\13\21\0\20\21\2\7\16\3\0\1\0\0\0\0\2\2\0\20\21\3\20\21\3\20\21\3\7\16\4\0\1\0\0\0\0"

#define GEM "\0\0\0\0\0\0\2\2\2\20\21\20\14\3\21\1\1\2\0\0\0\0\0\0\0\0\0\2\2\2\20\21\20\20\21\20\14\3\21\14\2\21\1\0\2\0\0\0\2\2\2\20\21\20\20\21\20\20\21\20\14\3\21\14\2\21\14\2\21\1\1\2\20\21\20\20\21\20\20\21\20\20\21\20\14\3\21\14\3\21\14\3\21\14\3\21\14\3\21\14\3\21\14\3\21\14\3\21\10\11\13\10\11\12\10\11\12\10\11\12\2\1\2\14\2\21\14\2\21\14\3\21\10\11\12\10\11\12\10\11\12\0\1\1\0\0\0\1\0\2\14\2\21\14\3\21\10\11\12\10\11\12\0\0\1\0\0\0\0\0\0\0\0\0\2\1\2\14\3\21\10\11\12\0\1\1\0\0\0\0\0\0"

#define MARIO "\0\0\0\0\0\0\0\1\0\1\21\5\0\21\5\1\21\5\20\21\20\1\2\1\0\0\0\0\0\0\0\1\0\1\21\5\0\21\5\0\21\5\1\21\5\0\21\5\0\0\0\0\0\0\5\13\3\16\21\13\5\14\4\1\2\0\16\21\13\1\3\1\1\1\1\0\0\0\5\13\3\16\21\13\16\21\13\6\14\4\6\14\4\16\21\13\0\0\1\0\1\0\0\2\0\6\14\4\16\21\13\16\21\13\16\21\13\1\2\1\1\2\1\0\21\5\1\21\5\21\21\3\14\3\21\14\3\21\13\21\2\0\1\0\20\21\17\1\2\2\13\3\21\14\3\21\14\2\21\14\2\21\3\2\6\10\11\12\1\1\1\0\0\0\5\13\4\1\0\2\1\0\1\0\0\1\2\10\5\0\0\0"

#define GHOST "\0\0\0\0\0\0\0\1\0\0\2\0\0\2\0\0\1\0\1\1\1\0\0\0\0\0\0\0\2\0\0\21\5\0\21\5\0\21\5\2\11\5\0\0\0\0\1\0\0\2\0\0\21\5\1\21\5\1\21\5\0\21\5\1\21\5\2\11\5\0\0\0\0\21\5\1\21\5\20\21\20\20\21\20\1\21\5\16\21\13\16\21\13\3\11\5\0\21\5\1\21\5\20\21\20\2\3\2\0\21\5\1\3\1\16\21\13\2\10\5\0\21\5\0\21\5\1\21\5\0\21\5\0\21\5\0\21\5\2\11\5\2\10\5\1\21\5\0\21\5\0\21\5\0\21\5\0\21\5\0\21\5\2\10\5\2\10\5\0\21\5\0\3\0\0\21\5\0\21\5\0\3\0\0\21\5\2\10\5\2\10\5"

#define LINK "\0\0\0\2\1\1\20\0\6\20\2\5\21\21\3\21\21\2\13\21\0\1\2\0\1\1\1\20\21\20\20\3\6\21\21\3\16\21\13\21\21\3\21\21\2\13\21\0\11\1\5\20\21\20\16\21\13\21\21\3\2\3\1\16\21\13\2\3\1\0\1\0\1\2\1\20\21\20\2\3\2\16\21\13\16\21\13\16\21\13\16\21\13\1\2\1\1\2\2\20\21\20\20\1\6\20\2\6\16\21\13\11\2\5\2\2\1\15\15\15\13\3\21\14\3\21\14\3\21\6\13\4\13\21\0\5\13\3\11\1\5\10\11\12\1\2\2\16\21\13\11\1\5\20\0\5\20\1\5\11\1\5\1\0\0\10\11\12\0\2\0\1\1\0\5\13\3\1\1\0\1\0\0\2\10\5\0\0\0\0\1\0"

#define DONALD "\0\0\0\0\0\0\1\0\0\1\0\1\14\3\21\14\3\21\10\11\12\0\0\0\0\0\0\0\0\0\0\0\0\3\2\5\20\21\20\20\21\20\20\21\20\1\2\1\0\0\0\0\0\0\0\0\0\1\1\1\20\21\20\4\4\6\20\21\20\1\2\1\0\0\0\0\0\0\0\0\0\1\1\1\13\21\2\13\21\0\13\21\1\13\21\0\0\0\0\1\1\1\1\1\2\14\2\21\14\4\21\1\21\5\0\2\0\1\2\1\1\1\2\20\21\20\20\21\20\14\4\21\20\21\20\10\11\12\3\2\5\10\11\12\0\0\0\2\3\2\20\21\20\20\21\20\15\15\15\15\15\15\1\1\1\0\0\1\0\1\0\13\21\0\13\21\1\1\2\1\5\13\3\5\13\3\5\13\3\0\0\0"

#define STEEVE "\2\3\0\2\3\0\2\3\1\1\2\0\1\2\0\1\2\0\2\3\0\2\2\0\2\3\0\2\3\0\2\3\0\2\3\1\2\4\1\2\4\1\2\3\0\1\2\0\2\3\0\11\14\7\11\15\7\12\15\10\11\15\7\11\15\10\10\14\6\2\3\1\10\13\7\11\14\7\10\13\7\10\14\7\7\12\6\11\15\7\7\12\5\7\12\5\11\14\7\21\21\21\4\5\11\10\14\7\11\15\7\4\5\11\21\21\21\10\13\7\6\12\4\10\14\6\11\14\7\4\7\3\4\7\3\11\15\7\7\13\4\5\10\3\6\12\4\6\12\4\4\10\3\4\10\3\4\10\3\4\10\3\6\12\4\5\11\3\4\7\3\4\7\2\5\11\3\5\11\3\5\10\3\5\11\4\5\11\4\5\10\3"

#define CREEPER "\16\13\13\13\1\1\14\5\4\15\12\12\16\16\16\17\11\10\16\10\7\12\5\5\12\2\2\15\6\6\14\4\3\16\7\7\12\5\5\17\7\6\15\7\5\16\16\16\15\4\3\5\2\1\6\3\3\17\12\11\12\6\6\5\2\1\6\3\3\17\17\17\16\5\4\5\2\1\0\0\0\16\7\5\14\4\3\0\0\0\4\1\1\16\10\7\16\11\11\14\7\6\17\12\11\5\1\1\5\2\1\16\15\15\11\5\4\16\6\5\16\13\12\12\5\5\6\3\3\0\0\0\0\0\0\5\2\1\17\7\5\16\15\15\17\15\15\13\7\7\0\0\0\0\0\0\0\0\0\0\0\0\15\6\5\12\5\5\17\7\5\17\11\7\4\1\1\16\12\11\16\14\13\5\2\1\11\4\3\16\7\6"

#define DICE_1 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define DICE_2 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define DICE_3 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define DICE_4 "\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21"

#define DICE_5 "\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21"

#define DICE_6 "\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21\0\0\0\21\21\21\21\21\21"

#define LOADING_0 "\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0"

#define LOADING_10 "\0\0\0\0\0\0\0\0\0\13\13\13\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\14\14\14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\17\17\17\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\17\17\17\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\14\14\14\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\13\13\13\0\0\0\0\0\0\0\0\0"

#define LOADING_20 "\0\0\0\0\0\0\0\0\0\2\2\2\17\17\17\17\17\17\6\6\6\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\21\21\21\20\20\20\5\5\5\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\16\16\16\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\16\16\16\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\5\5\5\20\20\20\21\21\21\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\6\6\6\17\17\17\17\17\17\2\2\2\0\0\0\0\0\0\0\0\0"

#define LOADING_30 "\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\16\16\16\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\2\2\2\17\17\17\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\20\20\20\7\7\7\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\14\14\14\0\0\0\0\0\0\0\0\0\0\0\0\14\14\14\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\7\7\7\20\20\20\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\17\17\17\2\2\2\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\16\16\16\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_40 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\21\21\21\7\7\7\0\0\0\0\0\0\0\0\0\10\10\10\20\20\20\21\21\21\15\15\15\1\1\1\0\0\0\0\0\0\6\6\6\17\17\17\21\21\21\16\16\16\4\4\4\0\0\0\0\0\0\4\4\4\16\16\16\21\21\21\17\17\17\6\6\6\0\0\0\0\0\0\1\1\1\15\15\15\21\21\21\20\20\20\10\10\10\0\0\0\0\0\0\0\0\0\7\7\7\21\21\21\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_50 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\15\15\15\21\21\21\11\11\11\0\0\0\0\0\0\0\0\0\6\6\6\16\16\16\21\21\21\21\21\21\12\12\12\0\0\0\0\0\0\10\10\10\17\17\17\21\21\21\20\20\20\12\12\12\0\0\0\0\0\0\12\12\12\20\20\20\21\21\21\17\17\17\10\10\10\0\0\0\0\0\0\12\12\12\21\21\21\21\21\21\16\16\16\6\6\6\0\0\0\0\0\0\0\0\0\11\11\11\21\21\21\15\15\15\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\1\1\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_60 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\15\15\15\11\11\11\0\0\0\0\0\0\0\0\0\4\4\4\14\14\14\20\20\20\21\21\21\16\16\16\0\0\0\2\2\2\12\12\12\20\20\20\21\21\21\21\21\21\17\17\17\10\10\10\10\10\10\17\17\17\21\21\21\21\21\21\20\20\20\12\12\12\2\2\2\0\0\0\16\16\16\21\21\21\20\20\20\14\14\14\4\4\4\0\0\0\0\0\0\0\0\0\11\11\11\15\15\15\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_70 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\5\5\5\6\6\6\0\0\0\0\0\0\0\0\0\4\4\4\11\11\11\16\16\16\20\20\20\17\17\17\2\2\2\10\10\10\15\15\15\20\20\20\21\21\21\21\21\21\21\21\21\17\17\17\17\17\17\21\21\21\21\21\21\21\21\21\20\20\20\15\15\15\10\10\10\2\2\2\17\17\17\20\20\20\16\16\16\11\11\11\4\4\4\0\0\0\0\0\0\0\0\0\6\6\6\5\5\5\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_80 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\7\7\7\12\12\12\14\14\14\15\15\15\13\13\13\15\15\15\17\17\17\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\20\20\20\17\17\17\15\15\15\13\13\13\15\15\15\14\14\14\12\12\12\7\7\7\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_90 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_100 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\14\14\14\12\12\12\7\7\7\4\4\4\0\0\0\0\0\0\0\0\0\21\21\21\21\21\21\21\21\21\21\21\21\20\20\20\17\17\17\15\15\15\13\13\13\13\13\13\15\15\15\17\17\17\20\20\20\21\21\21\21\21\21\21\21\21\21\21\21\0\0\0\0\0\0\0\0\0\4\4\4\7\7\7\12\12\12\14\14\14\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_110 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\6\6\6\5\5\5\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\17\17\17\20\20\20\16\16\16\11\11\11\4\4\4\0\0\0\0\0\0\0\0\0\17\17\17\21\21\21\21\21\21\21\21\21\20\20\20\15\15\15\10\10\10\2\2\2\2\2\2\10\10\10\15\15\15\20\20\20\21\21\21\21\21\21\21\21\21\17\17\17\0\0\0\0\0\0\0\0\0\4\4\4\11\11\11\16\16\16\20\20\20\17\17\17\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\5\5\5\6\6\6\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_120 "\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\15\15\15\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\16\16\16\21\21\21\20\20\20\14\14\14\4\4\4\0\0\0\0\0\0\0\0\0\10\10\10\17\17\17\21\21\21\21\21\21\20\20\20\12\12\12\2\2\2\0\0\0\0\0\0\2\2\2\12\12\12\20\20\20\21\21\21\21\21\21\17\17\17\10\10\10\0\0\0\0\0\0\0\0\0\4\4\4\14\14\14\20\20\20\21\21\21\16\16\16\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\15\15\15\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0"

#define LOADING_130 "\0\0\0\7\7\7\1\1\1\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\21\21\21\15\15\15\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\21\21\21\16\16\16\6\6\6\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\20\20\20\21\21\21\17\17\17\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\17\17\17\21\21\21\20\20\20\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\6\6\6\16\16\16\21\21\21\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\15\15\15\21\21\21\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\7\7\7\0\0\0"

#define LOADING_140 "\0\0\0\11\11\11\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\21\21\21\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\1\1\1\15\15\15\21\21\21\20\20\20\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\16\16\16\21\21\21\17\17\17\6\6\6\0\0\0\0\0\0\0\0\0\0\0\0\6\6\6\17\17\17\21\21\21\16\16\16\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\20\20\20\21\21\21\15\15\15\1\1\1\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\21\21\21\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\11\11\11\0\0\0"

#define LOADING_150 "\0\0\0\11\11\11\16\16\16\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\17\17\17\2\2\2\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\20\20\20\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\14\14\14\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\14\14\14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\20\20\20\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\2\2\2\17\17\17\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\16\16\16\11\11\11\0\0\0"

#define LOADING_160 "\0\0\0\6\6\6\17\17\17\17\17\17\2\2\2\0\0\0\0\0\0\0\0\0\0\0\0\5\5\5\20\20\20\21\21\21\10\10\10\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\16\16\16\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\11\11\11\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\11\11\11\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\16\16\16\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\10\10\10\21\21\21\20\20\20\5\5\5\0\0\0\0\0\0\0\0\0\0\0\0\2\2\2\17\17\17\17\17\17\6\6\6\0\0\0"

#define LOADING_170 "\0\0\0\0\0\0\15\15\15\21\21\21\13\13\13\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\14\14\14\21\21\21\15\15\15\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\12\12\12\21\21\21\17\17\17\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\7\7\7\21\21\21\20\20\20\4\4\4\0\0\0\0\0\0\0\0\0\0\0\0\4\4\4\20\20\20\21\21\21\7\7\7\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\17\17\17\21\21\21\12\12\12\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\15\15\15\21\21\21\14\14\14\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\13\13\13\21\21\21\15\15\15\0\0\0\0\0\0"

uint8_t *feed_one_pixel(uint16_t pixel_index, uint8_t *pixels, uint32_t color)
{
		// ((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +

	if (color & 0xFF000000)
	{
		pixels[pixel_index * 3] = ((color & 0x00FF00) >> 8) * ((color & 0xFF000000) >> 24) / 0xFF;
		pixels[pixel_index * 3 + 1] = ((color & 0xFF0000) >> 16) * ((color & 0xFF000000) >> 24) / 0xFF;
		pixels[pixel_index * 3 + 2] = (color & 0x0000FF) * ((color & 0xFF000000) >> 24) / 0xFF;
	}
	else
	{
		pixels[pixel_index * 3] = (color & 0x00FF00) >> 8;
		pixels[pixel_index * 3 + 1] = (color & 0xFF0000) >> 16;
		pixels[pixel_index * 3 + 2] = color & 0x0000FF;
	}
	
	return (pixels);
}

uint32_t	rainbow_wheel(uint8_t pos)
{
	uint8_t red;
	uint8_t green;
	uint8_t blue;

	if (pos < 85)
	{
		red = pos * 3;
		green = 255 - pos * 3;
		blue = 0;
		
	}
	else if (pos < 170)
	{
		pos -= 85;
		red = 255 - pos * 3;
		green = 0;
		blue = pos * 3;

	}
	else 
	{
		pos -= 170;
		red = 0;
		green = pos * 3;
		blue = 255 - pos * 3;
	}
	return (((int32_t)red << (int32_t)16) + ((int32_t)green << (int32_t)8) + (int32_t)blue);
}

uint32_t	reduce_luminosity(uint32_t color, uint8_t percentage)
{
	return (
			((((color & 0xFF0000) >> (int32_t)16) * percentage / 100) << (int32_t)16) +
			((((color & 0x00FF00) >> (int32_t)8) * percentage / 100) << (int32_t)8) +
			((((color & 0x0000FF) >> (int32_t)0) * percentage / 100) << (int32_t)0)
		);
}


void		draw_line(uint8_t *pixels, uint8_t x0, uint8_t y0, uint8_t x1, uint8_t y1, uint8_t r, uint8_t g, uint8_t b)
{
    int dx, dy, p, x, y;
 
	dx=x1-x0;
	dy=y1-y0;
 
	x=x0;
	y=y0;
 
	p=2*dy-dx;
 
	while(x<x1)
	{
		if(p>=0)
		{
			// putpixel(x,y,7);
			pixels[(x * 8 + y) * 3] = 0x10;
			y=y+1;
			p=p+2*dy-2*dx;
		}
		else
		{
			pixels[(x * 8 + y) * 3] = 0x10;

			p=p+2*dy;
		}
		x=x+1;
	}
}

void	led_draw_animation(uint16_t pixels_number)
{
	uint8_t pixels[pixels_number * 3];
	uint32_t colors = 0xFF0000;

	// const uint8_t *sword = led_gimp_sword();
	// const uint8_t *purse = led_gimp_purse();
	// const uint8_t *bow = led_gimp_bow();
	// const uint8_t *potion = led_gimp_potion();
	// const uint8_t *coin = led_gimp_coin();
	// const uint8_t *gem = led_gimp_gem();

	serial_putstr("hello\r\n");

	ft_pin_mode(51, FT_OUTPUT);
	ft_pin_mode(3, FT_OUTPUT);


	// uint8_t red = 0;
	for (;;)
	{


		led_send_data(3, (uint8_t*)SWORD, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)PURSE, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)BOW, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)POTION, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)COIN, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)GEM, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)MARIO, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)GHOST, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)LINK, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)DONALD, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)STEEVE, 64);
		for (int32_t i = 0; i < 500000; i++);
		led_send_data(3, (uint8_t*)CREEPER, 64);
		for (int32_t i = 0; i < 500000; i++);
		for (int32_t u = 1; u < 10; u++)
		{
			led_send_data(3, (uint8_t*)DICE_1, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
			led_send_data(3, (uint8_t*)DICE_2, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
			led_send_data(3, (uint8_t*)DICE_3, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
			led_send_data(3, (uint8_t*)DICE_4, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
			led_send_data(3, (uint8_t*)DICE_5, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
			led_send_data(3, (uint8_t*)DICE_6, 64);
			for (int32_t i = 0; i < 3000 * u; i++);
		};
		for (int u = 0; u < 10; u++)
		{
			uint8_t *pixels = (uint8_t*)"\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0\0";
			draw_line(pixels, 0, 2, 8, 7, 0x10, 0x10, 0x10);
			led_send_data(3, pixels, 64);
			for (int32_t i = 0; i < 300000; i++);
			// draw_line(pixels, 1, 1, 5, 5, 0x0, 0x0, 0x10);
			// led_send_data(3, pixels, 64);
			// for (int32_t i = 0; i < 300000; i++);


			// for (int y = 0; y < 8; y++)
			// {
			// 	for (int x = 0; x < 8; x++)
			// 	{
			// 		pixels[(y * 8 + x) * 3] = 0x00;
			// 		led_send_data(3, pixels, 64);
			// 		for (int32_t i = 0; i < 30000; i++);
			// 	}
			// }
		}

		// for (int32_t u = 0; u < 40; u++)
		// {
		// 	led_send_data(3, (uint8_t*)LOADING_0, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);

		// 	led_send_data(3, (uint8_t*)LOADING_10, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_20, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_30, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_40, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_50, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_60, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_70, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_80, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_90, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_100, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_110, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_120, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_130, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_140, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_150, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_160, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);
		// 	led_send_data(3, (uint8_t*)LOADING_170, 64);
		// 	for (int32_t i = 0; i < 200 * (u <= 20 ? u : 40 - u ) ; i++);

		// }


	}

}
