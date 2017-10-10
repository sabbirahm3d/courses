#include "music.h"

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

    return (uint8_t) (letter_ascii << 5) + duration;

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

    const size_t len = strlen(song_str);
    uint8_t j = 0;

    for (uint8_t i = 0; i < len; i += 2) {

        if (isdigit(song_str[i + 1]) && isdigit(song_str[i + 2])) {

            song[j] = pack_note(
                    song_str[i],
                    (uint8_t) (song_str[i + 1] - '0') * 10 + (song_str[i + 2] - '0')
            );
            i++;

        } else {

            if (is_zero_rest(song_str[i], song_str[i + 1])) {

                song[j] = ZERO_REST;
                break;

            } else {

                song[j] = pack_note(song_str[i], (uint8_t) (song_str[i + 1] - '0'));

            }
        }

        j++;

    }

}
