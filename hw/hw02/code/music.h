//
// Created by sabbir on 10/8/17.
//

#ifndef MAIN_H
#define MAIN_H

// #include <avr/io.h>
// #include <util/delay.h>
#include <inttypes.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>
// #include "U0_UART.h"  // to direct standard I/O to AVR UART

#define PORTB5_SPEAKER_MASK 0b00100000
#define USER_LINE_MAX 128
char userLine[USER_LINE_MAX];
#define NUMBER_OF_SONGS 4
#define MAX_SONG_LENGTH 64
#define NOTE_A 0
#define NOTE_B 1
#define NOTE_C 2
#define NOTE_D 3
#define NOTE_E 4
#define NOTE_F 5
#define NOTE_G 6
#define NOTE_R 7
#define ZERO_REST 224

//char songTitle[NUMBER_OF_SONGS][STR_LENGTH] = {"Title1", "Title2", "Title3", "Title4"};
char song[NUMBER_OF_SONGS][MAX_SONG_LENGTH] = {
        {(NOTE_B << 5) + 2, (NOTE_A << 5) + 2, (NOTE_G << 5) + 2},
        {NOTE_R << 5},
        {NOTE_R << 5},
        {NOTE_R << 5}
};
//// some initial song with notes
const char menuMain[] = "Main Menu\nCreate Song\nPlay Song\nList Songs\n";
const char menuPlay[] = "Play Menu\nSearch By Title\nNumber\n";

uint8_t pack_note(char, uint8_t);

uint8_t unpack_note_letter_ascii(uint8_t);

uint8_t unpack_note_duration(uint8_t);

void store_songs(uint8_t *, const char *);

void play_note(uint8_t, uint8_t);

void play_song(uint8_t *);

#endif //MAIN_H
