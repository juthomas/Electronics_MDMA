#include "../../inc/mdma.h"
#include "../../inc/tone.h"

#define NOTE_B0  31
#define NOTE_C1  33
#define NOTE_CS1 35
#define NOTE_D1  37
#define NOTE_DS1 39
#define NOTE_E1  41
#define NOTE_F1  44
#define NOTE_FS1 46
#define NOTE_G1  49
#define NOTE_GS1 52
#define NOTE_A1  55
#define NOTE_AS1 58
#define NOTE_B1  62
#define NOTE_C2  65
#define NOTE_CS2 69
#define NOTE_D2  73
#define NOTE_DS2 78
#define NOTE_E2  82
#define NOTE_F2  87
#define NOTE_FS2 93
#define NOTE_G2  98
#define NOTE_GS2 104
#define NOTE_A2  110
#define NOTE_AS2 117
#define NOTE_B2  123
#define NOTE_C3  131
#define NOTE_CS3 139
#define NOTE_D3  147
#define NOTE_DS3 156
#define NOTE_E3  165
#define NOTE_F3  175
#define NOTE_FS3 185
#define NOTE_G3  196
#define NOTE_GS3 208
#define NOTE_A3  220=
#define NOTE_AS3 233
#define NOTE_B3  247
#define NOTE_C4  262
#define NOTE_CS4 277
#define NOTE_D4  294
#define NOTE_DS4 311
#define NOTE_E4  330
#define NOTE_F4  349
#define NOTE_FS4 370
#define NOTE_G4  392
#define NOTE_GS4 415
#define NOTE_A4  440
#define NOTE_AS4 466
#define NOTE_B4  494
#define NOTE_C5  523
#define NOTE_CS5 554
#define NOTE_D5  587
#define NOTE_DS5 622
#define NOTE_E5  659
#define NOTE_F5  698
#define NOTE_FS5 740
#define NOTE_G5  784
#define NOTE_GS5 831
#define NOTE_A5  880
#define NOTE_AS5 932
#define NOTE_B5  988
#define NOTE_C6  1047
#define NOTE_CS6 1109
#define NOTE_D6  1175
#define NOTE_DS6 1245
#define NOTE_E6  1319
#define NOTE_F6  1397
#define NOTE_FS6 1480
#define NOTE_G6  1568
#define NOTE_GS6 1661
#define NOTE_A6  1760
#define NOTE_AS6 1865
#define NOTE_B6  1976
#define NOTE_C7  2093
#define NOTE_CS7 2217
#define NOTE_D7  2349
#define NOTE_DS7 2489
#define NOTE_E7  2637
#define NOTE_F7  2794
#define NOTE_FS7 2960
#define NOTE_G7  3136
#define NOTE_GS7 3322
#define NOTE_A7  3520
#define NOTE_AS7 3729
#define NOTE_B7  3951
#define NOTE_C8  4186
#define NOTE_CS8 4435
#define NOTE_D8  4699
#define NOTE_DS8 4978

// static volatile uint8_t *music_port_addr;
static volatile uint8_t music_port_mask;
static volatile uint32_t current_music_tick;
static volatile int32_t current_left_duration;
static volatile uint32_t current_note;

const int buzzer = 33; //buzzer to arduino pin 9
int melody[] = {
//12
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,
  NOTE_D4, NOTE_D4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,//60
  NOTE_C4, NOTE_C4, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,//72
  NOTE_B3, NOTE_B3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,//84
  NOTE_AS3, NOTE_AS3, NOTE_D5, NOTE_A4, 0, NOTE_GS4, 0, NOTE_G4, NOTE_F4, NOTE_D4, NOTE_F4, NOTE_G4,//96
  NOTE_D5, NOTE_D5, NOTE_D6, NOTE_A5, 0, NOTE_GS5, 0, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_G5,//108
  NOTE_C5, NOTE_C5, NOTE_D6, NOTE_A5, 0, NOTE_GS5, 0, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_G5,//120
  NOTE_B4, NOTE_B4, NOTE_D6, NOTE_A5, 0, NOTE_GS5, 0, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_G5,//132
  NOTE_AS4, NOTE_AS4, NOTE_D6, NOTE_A5, 0, NOTE_GS5, 0, NOTE_G5, NOTE_F5, NOTE_D5, NOTE_F5, NOTE_G5,//144
};

// note durations: 4 = quarter note, 8 = eighth note, etc.:
int noteDurations[] = {

  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
  8,        8,        4,        4,    8,   8,      8,    4,       8,         8,      8,      8,
};

// void	wait_x_cpu_clocks(int32_t cpu_clocks)
// {
// 	while (cpu_clocks > 0)
// 	{
// 		cpu_clocks-=3;
// 	}
// }

// void	custom_delay(uint32_t milli)
// {
// 	milli = milli *	2000;
// 	wait_x_cpu_clocks(milli - 5);
// }



void start_background_music()
{
  current_music_tick = 0;
  current_left_duration = 0;
  current_note = 0;
	music_port_mask = 1 << PIN1;
	// music_port_addr = (uint8_t)PORTJ;
	setupTimer1(0, 0);
}


ISR(TIMER1_COMPA_vect)
{
	PORTJ ^= music_port_mask;
  if (current_note > 144)
  {
    TIMSK1 &= ~_BV(OCIE1A);
		TCCR1B = 0x00;
  }
  if (current_left_duration < 0)
  {
    current_note++;
    current_left_duration = 600 / noteDurations[current_note];
	  tone(1 << PIN4, melody[current_note], current_left_duration);
    current_left_duration *= 1.3;
  }
  else
  {
    current_left_duration -= 1000/8;
  }
}


void play_music()
{
	// serial_init();
   DDRC |= 1 << PIN4;
   DDRJ |= 1 << PIN1;

  // ft_pin_mode(33, FT_OUTPUT);
  // ft_pin_mode(14, FT_OUTPUT);
  // ft_pin_mode(15, FT_OUTPUT);
  // ft_pin_mode(16, FT_OUTPUT);
  // ft_pin_mode(17, FT_OUTPUT);

  start_background_music();
}

