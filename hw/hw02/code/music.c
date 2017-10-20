#include "music.h"
#include "notes.h"

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
            break;
        }
    }

    return (uint8_t) (letter_ascii << 5) + duration;

}

void delay_ms(int ms) {

    while (ms--) {
        _delay_ms(1);
    }

}

void play_note(uint8_t letter_ascii, uint8_t quarters) {

    unsigned int num_iter, half_periods, freq;

    freq = get_frequency(letter_ascii, quarters);
    half_periods = FREQ_TO_MS / freq;
    num_iter = freq / 4 * quarters;

    for (int i = 0; i < num_iter; ++i) {

        PORTB = (PORTB5_SPEAKER_MASK & 0x00);
        delay_ms(half_periods);
        PORTB = (PORTB5_SPEAKER_MASK & 0xFF);
        delay_ms(half_periods);

    }

}

void play_song(uint8_t song[]) {

    uint8_t str, dur;

    for (size_t i = 0; song[i] != ZERO_REST; i++) {

        str = unpack_note_letter_ascii(song[i]);
        dur = unpack_note_duration(song[i]);

        play_note(str, dur);
    }

}

int is_zero_rest(const char letter_ascii, const char duration) {

    return (letter_ascii == 'R' || letter_ascii == 'r') && (duration == '0');

}

char *add_zero_rest(const char a[]) {

    char *ret = (char *) malloc((strlen(a) + 2) * sizeof(char) + 1);
    *ret = '\0';

    return strcat(strcat(ret, a), "R0");

}

void store_songs(uint8_t song[], const char song_str[]) {

    const size_t len = strlen(song_str);
    uint8_t j = 0;

    for (uint8_t i = 0; i < len; i += 2) {

        if (isdigit(song_str[i + 1]) && isdigit(song_str[i + 2])) {

            song[j] = pack_note(
                    song_str[i],
                    (uint8_t) (song_str[i + 1] - '0') * 10 + (song_str[i + 2]
                            - '0')
            );
            i++;

        } else {

            if (is_zero_rest(song_str[i], song_str[i + 1])) {

                song[j] = ZERO_REST;
                break;

            } else {

                song[j] = pack_note(song_str[i], (uint8_t) (song_str[i + 1] -
                        '0'));

            }
        }

        j++;

    }


}
