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

//    static uint8_t buffer[9];
//    buffer[8] = '\0';
//    int2bin((letter_ascii << 5) + duration, buffer);
//    printf("b = %s\n", buffer);

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
//    printf("d = %d\n", a);

    return a;

}

void store_songs(uint8_t song[], const char song_str[]) {

    uint8_t buffer, temp;
    size_t len = strlen(song_str);

//    printf("size %c\n", song_str[len - 2]);
//    printf("size %c\n", song_str[len - 1]);
//    printf("\nSONG SIZE: %d", sizeof(song));

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
//        printf("%c%c = %d\n", song_str[i], song_str[i + 1], buffer);

        song[i / 2] = buffer;

////        to test unpacking values
//        temp = unpack_note_letter_ascii(buffer);
//        printf("Unpacking str: %c = %d\n", song_str[i], temp);
//        temp = unpack_note_duration(buffer);
//        printf("Unpacking dur: %c = %d\n\n", song_str[i + 1], temp);
    }

    for (size_t i = 0; i < sizeof(song); i++) {
        printf("%d ", song[i]);
    }


}


int main() {

    char song_ascii[] = "B2A2R1C2R0C2R1";

    uint8_t song_packed[strlen(song_ascii)];
    store_songs(song_packed, song_ascii);

    return EXIT_SUCCESS;

}
