
#ifndef TONE_H
#define TONE_H

void noTone(uint8_t _pin);
void tone(uint8_t mask , uint32_t frequency, uint32_t duration);
void play_music();
void start_background_music();
void setupTimer1(uint32_t ocr, uint8_t prescaler);

#endif