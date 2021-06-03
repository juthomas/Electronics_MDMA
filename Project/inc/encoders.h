#ifndef ENCODERS_H
# define ENCODERS_H

#ifndef __AVR_ATmega2560__
#define __AVR_ATmega2560__
#define F_CPU 16000000
#endif
#include <avr/io.h>
#include <stdint.h>

static int encoder1 = 0;
static int encoder2 = 0;
static int encoder3 = 0;
static int encoder4 = 0;
static int encoder5 = 0;

#endif