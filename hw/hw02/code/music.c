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

    static uint8_t buffer[9];
    buffer[8] = '\0';
    int2bin((letter_ascii << 5) + duration, buffer);
    printf("b = %s\n", buffer);

    uint8_t a = (uint8_t) (letter_ascii << 5) + duration;
    printf("d = %d\n", a);

    return a;

}


int main() {

    uint8_t buffer, temp;

    buffer = pack_note(NOTE_B, 2);
    printf("B2 = %d\n", buffer);
    temp = unpack_note_letter_ascii(buffer);
    printf("B = %d\n", temp);
    temp = unpack_note_duration(buffer);
    printf("2 = %d\n", temp);

    buffer = pack_note(NOTE_A, 2);
    printf("A2 = %d\n", buffer);
    temp = unpack_note_letter_ascii(buffer);
    printf("A = %d\n", temp);
    temp = unpack_note_duration(buffer);
    printf("2 = %d\n", temp);

    buffer = pack_note(NOTE_R, 1);
    printf("R1 = %d\n", buffer);
    temp = unpack_note_letter_ascii(buffer);
    printf("R = %d\n", temp);
    temp = unpack_note_duration(buffer);
    printf("1 = %d\n", temp);

    buffer = pack_note(NOTE_C, 2);
    printf("C2 = %d\n", buffer);
    temp = unpack_note_letter_ascii(buffer);
    printf("C = %d\n", temp);
    temp = unpack_note_duration(buffer);
    printf("2 = %d\n", temp);

    return 0;

}
