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
            letter_ascii = NOTE_R;
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

    for (size_t i = 0; song[i] != NULL; i++) {

        str = unpack_note_letter_ascii(song[i]);
        dur = unpack_note_duration(song[i]);

        printf("*");
        play_note(str, dur);
    }

}


void store_songs(uint8_t *song, const char *song_str) {

    uint8_t buffer;
    size_t len = strlen(song_str);

    if (song_str[len - 2] != 'R' && song_str[len - 1] != '0') {
        printf("NEEDS TO END\n");
        song[len - 2] = 7;
        song[len - 1] = 0;
    }

    for (size_t i = 0; song_str[i] != NULL; i += 2) {

        if (song_str[i] == 'R' && song_str[i + 1] == '0') {
            printf("STOP\n");
            break;
        }

        buffer = pack_note(song_str[i], (uint8_t) (song_str[i + 1] - '0'));

        song[i / 2] = buffer;
    }

}


int main() {

    char song_ascii[] = "B2A2R1C2R2C2R7";

    uint8_t song_packed[strlen(song_ascii)];
    store_songs(song_packed, song_ascii);

    for (size_t i = 0; song_packed[i] != 0; i++) {
        printf("%d ", song_packed[i]);
    }

    printf("\n");
    store_songs(song_packed, song_ascii);

    play_song(song_packed);

    return EXIT_SUCCESS;

}
