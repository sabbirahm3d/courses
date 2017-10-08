//
// Created by sabbir on 10/8/17.
//

#ifndef HW02_MAIN_H
#define HW02_MAIN_H

// #include <avr/io.h>
// #include <util/delay.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #include "U0_UART.h"  // to direct standard I/O to AVR UART


uint8_t PackNote (char letterASCII, uint8_t duration);
uint8_t UnpackNoteLetterASCII
        (uint8_t packedNote);
uint8_t UnpackNoteDuration (uint8_t packedNote);
void StoreSong(uint8_t song[],const char songString[]);
void PlayNote(uint8_t letterASCII, uint8_t quarters);
void PlaySong(uint8_t song[]);

#endif //HW02_MAIN_H
