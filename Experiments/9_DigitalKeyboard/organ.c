/*
Simple routines to play notes out to a speaker
*/

#include <avr/io.h>
#include <util/delay.h>
#include "organ.h"
#include "pinDefines.h"

void playNote(uint16_t wavelength, uint16_t duration) {
  uint16_t elapsed;
  uint16_t i;
  for (elapsed = 0; elapsed < duration; elapsed += wavelength) {
                     /* For loop with variable delay selects the pitch */
    for (i = 0; i < wavelength; i++) {
      _delay_us(1);
    }
    SPEAKER_PORT ^= (1 << SPEAKER);
  }
  //SPEAKER_PORT &= ~(1 << SPEAKER); // Drop signal to 0V after note is played
}

void rest(uint16_t duration) {
  do {
    _delay_us(1);
  } while (--duration);
}