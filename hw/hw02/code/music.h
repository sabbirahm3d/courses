/*
 * music.h
 *
 * This file contains the declarations for the functions in music.c and main.c
 *
 * */

#ifndef MUSIC_H
#define MUSIC_H

#include <ctype.h>
#include <inttypes.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// AVR libraries
#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

// standard I/O to the AVR UART
#include "U0_UART.h"

extern FILE uart_stream;

// PORTB pin 5
#define PORTB5_SPEAKER_MASK 0b00100000

// constraints on sizes of strings
#define USER_LINE_MAX 128
#define NUMBER_OF_SONGS 4
#define MAX_SONG_LENGTH 64
#define MAX_TITLE_LENGTH 30

// ASCII character notes mapped to their assigned values
#define NOTE_A 0
#define NOTE_B 1
#define NOTE_C 2
#define NOTE_D 3
#define NOTE_E 4
#define NOTE_F 5
#define NOTE_G 6
#define NOTE_R 7
#define ZERO_REST (NOTE_R << 5)  // R0

// frequencies mapped to individual ASCII notes
#define FREQ_A 440
#define FREQ_B 494
#define FREQ_C 262
#define FREQ_D 294
#define FREQ_E 330
#define FREQ_F 350
#define FREQ_G 392
#define FREQ_R 4
#define FREQ_TO_MS 500000  // required for computing the number of iterations

// holds user input
char user_line[USER_LINE_MAX];

// -------------------------- HELPER FUNCTIONS --------------------------
char *add_zero_rest(const char[]);

void delay_ms(int);

int is_zero_rest(char, char);

unsigned int get_frequency(uint8_t);

uint8_t pack_note(char, uint8_t);

uint8_t unpack_note_letter_ascii(uint8_t);

uint8_t unpack_note_duration(uint8_t);

void store_songs(uint8_t[], const char[]);

void play_note(uint8_t, uint8_t);

void play_song(uint8_t[]);

#endif //MAIN_H
