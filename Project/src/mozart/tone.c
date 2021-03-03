

#include "../../inc/mdma.h"

volatile int8_t pin_timer = 0;
volatile int8_t *pin_port = 0;
volatile int8_t pin_mask = 0;
volatile long pin_toggle_count = 0;

#define bitRead(value, bit) (((value) >> (bit)) & 0x01)
#define bitSet(value, bit) ((value) |= (1UL << (bit)))
#define bitClear(value, bit) ((value) &= ~(1UL << (bit)))
#define bitToggle(value, bit) ((value) ^= (1UL << (bit)))
#define bitWrite(value, bit, bitvalue) ((bitvalue) ? bitSet(value, bit) : bitClear(value, bit))


void tone(uint8_t _pin, unsigned int frequency, unsigned long duration)
{
  cli(); // Désactive l'interruption globale

  uint32_t ocr = 0;
  uint8_t prescalarbits = 0b001;
  long tmp_pin_toggle_count = 0;

  //  ft_pin_mode(_pin, FT_OUTPUT);
  serial_putstr("HI !\r\n");
  pin_port = (volatile uint8_t*)g_pin_associations[_pin].register_port_addr;
  pin_mask = g_pin_associations[_pin].register_mask;
  tmp_pin_toggle_count = 1000;
ocr = F_CPU / frequency / 2 - 1;
  prescalarbits = 0b001;  // ck/1: same for both timers
      if (ocr > 255)
      {
        ocr = F_CPU / frequency / 2 / 8 - 1;
        prescalarbits = 0b010;  // ck/8: same for both timers

        if ( ocr > 255)
        {
          ocr = F_CPU / frequency / 2 / 32 - 1;
          prescalarbits = 0b011;
        }

        if (ocr > 255)
        {
          ocr = F_CPU / frequency / 2 / 64 - 1;
          prescalarbits =  0b100;

          if ( ocr > 255)
          {
            ocr = F_CPU / frequency / 2 / 128 - 1;
            prescalarbits = 0b101;
          }

          if (ocr > 255)
          {
            ocr = F_CPU / frequency / 2 / 256 - 1;
            prescalarbits =  0b110;
            if (ocr > 255)
            {
              // can't do any better than /1024
              ocr = F_CPU / frequency / 2 / 1024 - 1;
              prescalarbits =  0b111;
            }
          }
        }
      }
    if (duration > 0)
    {
      tmp_pin_toggle_count = 2 * frequency * duration / 1000;
    }
    else
    {
      tmp_pin_toggle_count = -1;
    }
// serial_putnbr(ocr);
// serial_putstr(" : ocr\r\n");


  // cli(); // Désactive l'interruption globale
        TCCR2A = 0;
        TCCR2B = 0;
        bitWrite(TCCR2A, WGM21, 1);
        bitWrite(TCCR2B, CS20, 1);
                OCR2A = ocr;
        pin_toggle_count = tmp_pin_toggle_count;
        bitWrite(TIMSK2, OCIE2A, 1);
  sei(); 
}

void noTone(uint8_t _pin)
{

}

void disable_timer()
{
		//TIMSK2 = 0;
        bitWrite(TIMSK2, OCIE2A, 0); // disable interrupt
       	TCCR2A = (1 << WGM20);
        TCCR2B = (TCCR2B & 0b11111000) | (1 << CS22);
        OCR2A = 0;
}

ISR(TIMER2_COMPA_vect)
{
  if (pin_toggle_count > 0)
  {
  serial_putstr(".");

    *pin_port ^= pin_mask;

      pin_toggle_count--;
  }
  else
  {
  }

}