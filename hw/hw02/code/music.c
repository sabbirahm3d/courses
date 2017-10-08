#include <stdlib.h>
#include "music.h"


uint8_t *int2bin(int a, uint8_t *buffer) {

    buffer += (7);

    for (int i = 7; i >= 0; i--) {

        *buffer-- = (a & 1) + '0';
        a >>= 1;

    }

    return buffer;
}

uint8_t unpack_note_letter_ascii(uint8_t packed_note) {

    return packed_note >> 5;

}

uint8_t unpack_note_duration(uint8_t packed_note) {

    return (uint8_t) (packed_note & 0x1F);

}


uint8_t pack_note(char letter_ascii, uint8_t duration) {

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
            printf("%c Nope\n", letter_ascii);
            break;
        }
    }

    uint8_t a = (uint8_t) (letter_ascii << 5) + duration;

    return a;

}


void play_note(uint8_t letter_ascii, uint8_t quarters) {


    switch (letter_ascii) {

        case NOTE_A: {
            printf("A");
            break;
        }

        case NOTE_B: {
            printf("B");
            break;
        }

        case NOTE_C: {
            printf("C");
            break;
        }

        case NOTE_D: {
            printf("D");
            break;
        }

        case NOTE_E: {
            printf("E");
            break;
        }

        case NOTE_F: {
            printf("F");
            break;
        }

        case NOTE_G: {
            printf("G");
            break;
        }

        case NOTE_R: {
            printf("R");
            break;
        }

        default: {
            printf("Error");
            break;
        }

    }

    printf("%d*", quarters);

}

void play_song(uint8_t *song) {

    uint8_t str, dur;

    for (size_t i = 0; song[i] != ZERO_REST; i++) {

        str = unpack_note_letter_ascii(song[i]);
        dur = unpack_note_duration(song[i]);

        printf("*");
        play_note(str, dur);
    }

}


int is_zero_rest(const char letter_ascii, const char duration) {

    return (letter_ascii == 'R' || letter_ascii == 'r') && (duration == '0');

}


char *add_zero_rest(const char *a) {

    size_t len = strlen(a) + 2;
    char *ret = (char *) malloc(len * sizeof(char) + 1);
    *ret = '\0';

    return strcat(strcat(ret, a), "R0");

}

void store_songs(uint8_t *song, const char *song_str) {

    size_t len = strlen(song_str);

    for (size_t i = 0; i < len; i += 2) {

        if (is_zero_rest(song_str[i], song_str[i + 1])) {

            printf("STOP %c%c\n", song_str[i], song_str[i + 1]);
            song[i] = ZERO_REST;
            break;

        } else {

            song[i / 2] = pack_note(song_str[i], (uint8_t) (song_str[i + 1] - '0'));

        }

    }

}


int main() {

    char *song_ascii = "a2c0f0A2C2E1G6R2g9C2R9D7F6E9F9g8e1g8g8g8g7g5g8";

    song_ascii = add_zero_rest(song_ascii);

    uint8_t song_packed[strlen(song_ascii) / 2];
    memset(song_packed, ZERO_REST, sizeof song_packed);

    store_songs(song_packed, song_ascii);

    printf("Array: ");
    for (size_t i = 0; song_packed[i] != ZERO_REST; i++) {
        printf("%d ", song_packed[i]);
    }

    printf("\nSong: ");
    play_song(song_packed);

    return EXIT_SUCCESS;

}