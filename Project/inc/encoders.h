#ifndef ENCODERS_H
# define ENCODERS_H

// #ifndef __AVR_ATmega2560__
// #define __AVR_ATmega2560__
// #define F_CPU 16000000
// #endif
// #include <avr/io.h>
#include <stdint.h>

int32_t encoders[5];
void clear_encoders();
void init_encoders();
#endif