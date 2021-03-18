

#include "../../inc/mdma.h"

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))

static volatile uint8_t *tone_port_addr;
static volatile uint8_t tone_port_mask;
static volatile uint32_t duration_ticks = 0x00;

void setupTimer0(uint8_t ocr, uint8_t prescaler) {
  cli();
  // Clear registers
  TCCR0A = 0;
  TCCR0B = 0;
  TCNT0 = 0;

  // 100.16025641025641 Hz (16000000/((155+1)*1024))
  OCR0A = ocr;
  // CTC
  TCCR0A |= (1 << WGM01);
  // Prescaler 1024
  TCCR0B = prescaler & 0x07;
  //TCCR0B |= (1 << CS02) | (1 << CS00);
  // Output Compare Match A Interrupt Enable
  TIMSK0 |= (1 << OCIE0A);
  sei();
}




ISR(TIMER0_COMPA_vect)
{
    if(!duration_ticks)
    {
        TIMSK0 &= ~_BV(OCIE0A);
        TCCR0B = 0x00;
    }
    else
    {
        *tone_port_addr ^= tone_port_mask;
        // ft_digital_write(33, divider % 2 == 1 ? FT_LOW : FT_HIGH);
        duration_ticks--;
    }
  // divider++;
  // divider%=100;
}

void timer_freq_prescale(uint32_t a_freq, uint8_t *a_ocr, uint8_t *a_prescaler) 
{
    // prescaler table for timer 0
    uint8_t prescalers[] = { 0x00, 0x03, 0x06, 0x08, 0x0a, 0x00 };

    uint16_t ocr = 0x00;
    uint8_t prescaler = 0x00;

    do {
        ocr = (uint16_t) (F_CPU / ((a_freq << 1) * (0x01 << prescalers[prescaler])));
        ++prescaler;        
    } while ((ocr > 255) && (prescalers[prescaler]));

    --ocr;
    if (ocr > 255) ocr = 255;

    *a_ocr = ocr & 0xff;
    *a_prescaler = prescaler;
}

void    tone(enum e_pins pin, uint32_t frequence, uint32_t duration)
{
    duration *= 2;
    frequence /= 10;
    tone_port_addr = (volatile uint8_t*)g_pin_associations[pin].register_port_addr;
    tone_port_mask = g_pin_associations[pin].register_mask;
    uint8_t ocr = 0;
    uint8_t prescaler = 0;
    duration_ticks = (uint32_t)((uint32_t)((uint32_t)frequence * (uint32_t)duration)/(uint32_t)500);
    timer_freq_prescale(frequence, &ocr, &prescaler);
    setupTimer0(ocr, prescaler);
}