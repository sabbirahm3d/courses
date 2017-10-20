/*
 * music.c
 *
 * This file contains the implementation of all the functionalities related
 * to parsing user inputted song notes, packing and unpacking song notes, and
 * utilizing the ports of the AVR to produce the notes via its speaker.
 *
 * */

#include "music.h"

/*
 * Unpacks the packed note to retrieve the ASCII character. */
uint8_t unpack_note_letter_ascii(uint8_t packed_note) {

    // shift right the packed note by 5 to retrieve the original ASCII
    // character
    return packed_note >> 5;

}


/*
 * Unpacks the packed note to retrieve the duration. */
uint8_t unpack_note_duration(uint8_t packed_note) {

    // bitwise AND the packed note with 0b0001 1111 to retrieve the original
    // duration
    return (uint8_t) (packed_note & 0x1F);

}

/*
 * Assigns ASCII character notes to their corresponding frequencies. */
unsigned int get_frequency(uint8_t letter_ascii) {

    unsigned int frequency = 0;

    switch (letter_ascii) {

        case NOTE_A: {

            frequency = FREQ_A;
            break;

        }

        case NOTE_B: {

            frequency = FREQ_B;
            break;

        }

        case NOTE_C: {

            frequency = FREQ_C;
            break;

        }

        case NOTE_D: {

            frequency = FREQ_D;
            break;

        }

        case NOTE_E: {

            frequency = FREQ_E;
            break;

        }

        case NOTE_F: {

            frequency = FREQ_F;
            break;

        }

        case NOTE_G: {

            frequency = FREQ_G;
            break;

        }

        case NOTE_R: {

            frequency = FREQ_R;

        }

        default: {
            break;
        }

    }

    return (uint8_t) frequency;

}

/*
 * Assigns ASCII characters and their durations to the corresponding note
 * values. */
uint8_t pack_note(char letter_ascii, uint8_t duration) {

    // assigns ASCII characters to their corresponding note values
    switch (letter_ascii) {

        case 'A':
        case 'a': {
            letter_ascii = NOTE_A;
            break;
        }

        case 'B':
        case 'b': {
            letter_ascii = NOTE_B;
            break;
        }

        case 'C':
        case 'c': {
            letter_ascii = NOTE_C;
            break;
        }

        case 'D':
        case 'd': {
            letter_ascii = NOTE_D;
            break;
        }

        case 'E':
        case 'e': {
            letter_ascii = NOTE_E;
            break;
        }

        case 'F':
        case 'f': {
            letter_ascii = NOTE_F;
            break;
        }

        case 'G':
        case 'g': {
            letter_ascii = NOTE_G;
            break;
        }

        case 'R':
        case 'r': {
            letter_ascii = NOTE_R;
            break;
        }

        default: {
            break;
        }
    }

    // shift-left the 3-bit ASCII character note and add the 5-bit duration to
    // the remaining 5 bits
    return (uint8_t) (letter_ascii << 5) + duration;

}


/*
 * Helper function to delay the AVR system for variable times. */
void delay_ms(int ms) {

    while (ms--) {
        _delay_ms(1);
    }

}

/*
 * Plays individual notes from the songs. */
void play_note(uint8_t letter_ascii, uint8_t quarters) {

    unsigned int num_iter, half_periods, freq;

    // assign the frequency associated with the ASCII character note
    freq = get_frequency(letter_ascii);
    // compute the half period; 500000 / freq
    half_periods = FREQ_TO_MS / freq;
    // compute the number of iterations; (freq / 4) * duration
    num_iter = freq / 4 * quarters;

    // loop for num_iter times to play a note
    for (int i = 0; i < num_iter; ++i) {

        // set port B pin 5 low, and delay for half_period ms
        PORTB = (PORTB5_SPEAKER_MASK & 0x00);
        delay_ms(half_periods);

        // set port B pin 5 high, and delay for half_period ms
        PORTB = (PORTB5_SPEAKER_MASK & 0xFF);
        delay_ms(half_periods);

    }

}

/*
 * Calls 'play_note()' on every note in the song. */
void play_song(uint8_t song[]) {

    uint8_t str, dur;

    // loop until the termination of a song
    for (size_t i = 0; song[i] != ZERO_REST; i++) {

        // unpack the ASCII character and duration of the note
        str = unpack_note_letter_ascii(song[i]);
        dur = unpack_note_duration(song[i]);

        // play the note after being unpacked
        play_note(str, dur);

    }

}

/*
 * Determines if the note in the user inputted song is 'R0' */
int is_zero_rest(const char letter_ascii, const char duration) {

    // if 'R0' or 'r0'
    return (letter_ascii == 'R' || letter_ascii == 'r') && (duration == '0');

}

/*
 * Manually concatenates a zero rest note at the end of the user inputted
 * song. */
char *add_zero_rest(const char a[]) {

    // allocates 2 more bytes to append "R0"
    char *ret = (char *) malloc((strlen(a) + 2) * sizeof(char) + 1);
    *ret = '\0';

    // return the concatenated string
    return strcat(strcat(ret, a), "R0");

}


/*
 * Converts user inputted ASCII notes and durations into an array of packed
 * notes. */
void store_songs(uint8_t song[], const char song_str[]) {

    // get length of song_str
    const size_t len = strlen(song_str);
    // independent index for song[] (since len(song) == len(song_str)/2),
    // where: j = (i+1)/2 if i is odd and j = i/2 if i is even
    uint8_t j = 0;

    // loop through the entire song_str, incrementing by 2 to parse both the
    // ASCII character and the duration
    for (uint8_t i = 0; i < len; i += 2) {

        // if the duration is a 2 digit number (> 9), increment the index
        // again after packing the notes
        if (isdigit(song_str[i + 1]) && isdigit(song_str[i + 2])) {

            // assign the jth index of the song to the note
            song[j] = pack_note(
                    song_str[i],
                    (uint8_t) (song_str[i + 1] - '0') * 10 + (song_str[i + 2]
                            - '0')
            );
            i++;

        } else {

            // if the zero rest note is found, terminate the loop
            if (is_zero_rest(song_str[i], song_str[i + 1])) {

                // assign the jth index of the song to ZERO_REST
                song[j] = ZERO_REST;
                break;

            } else {

                // assign the jth index of the song to the note
                song[j] = pack_note(song_str[i], (uint8_t) (song_str[i + 1] -
                        '0'));

            }
        }

        // independently increment
        j++;

    }

}
