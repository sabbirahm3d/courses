//
// Created by sabbir on 10/14/17.
//

#include "music.h"
#include "notes.h"

unsigned int get_frequency(uint8_t letter_ascii, uint8_t quarters) {

    switch (letter_ascii) {

        case NOTE_A: {

            printf("A");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_A0;
                }

                case 1: {
                    return (int) FREQ_A1;
                }

                case 2: {
                    return (int) FREQ_A2;
                }

                case 3: {
                    return (int) FREQ_A3;
                }

                case 4: {
                    return (int) FREQ_A4;
                }

                case 5: {
                    return (int) FREQ_A5;
                }

                case 6: {
                    return (int) FREQ_A6;
                }

                case 7: {
                    return (int) FREQ_A7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_B: {

            printf("B");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_B0;
                }

                case 1: {
                    return (int) FREQ_B1;
                }

                case 2: {
                    return (int) FREQ_B2;
                }

                case 3: {
                    return (int) FREQ_B3;
                }

                case 4: {
                    return (int) FREQ_B4;
                }

                case 5: {
                    return (int) FREQ_B5;
                }

                case 6: {
                    return (int) FREQ_B6;
                }

                case 7: {
                    return (int) FREQ_B7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_C: {

            printf("C");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_C0;
                }

                case 1: {
                    return (int) FREQ_C1;
                }

                case 2: {
                    return (int) FREQ_C2;
                }

                case 3: {
                    return (int) FREQ_C3;
                }

                case 4: {
                    return (int) FREQ_C4;
                }

                case 5: {
                    return (int) FREQ_C5;
                }

                case 6: {
                    return (int) FREQ_C6;
                }

                case 7: {
                    return (int) FREQ_C7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_D: {

            printf("D");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_D0;
                }

                case 1: {
                    return (int) FREQ_D1;
                }

                case 2: {
                    return (int) FREQ_D2;
                }

                case 3: {
                    return (int) FREQ_D3;
                }

                case 4: {
                    return (int) FREQ_D4;
                }

                case 5: {
                    return (int) FREQ_D5;
                }

                case 6: {
                    return (int) FREQ_D6;
                }

                case 7: {
                    return (int) FREQ_D7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_E: {

            printf("E");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_E0;
                }

                case 1: {
                    return (int) FREQ_E1;
                }

                case 2: {
                    return (int) FREQ_E2;
                }

                case 3: {
                    return (int) FREQ_E3;
                }

                case 4: {
                    return (int) FREQ_E4;
                }

                case 5: {
                    return (int) FREQ_E5;
                }

                case 6: {
                    return (int) FREQ_E6;
                }

                case 7: {
                    return (int) FREQ_E7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_F: {

            printf("F");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_F0;
                }

                case 1: {
                    return (int) FREQ_F1;
                }

                case 2: {
                    return (int) FREQ_F2;
                }

                case 3: {
                    return (int) FREQ_F3;
                }

                case 4: {
                    return (int) FREQ_F4;
                }

                case 5: {
                    return (int) FREQ_F5;
                }

                case 6: {
                    return (int) FREQ_F6;
                }

                case 7: {
                    return (int) FREQ_F7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_G: {

            printf("G");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_G0;
                }

                case 1: {
                    return (int) FREQ_G1;
                }

                case 2: {
                    return (int) FREQ_G2;
                }

                case 3: {
                    return (int) FREQ_G3;
                }

                case 4: {
                    return (int) FREQ_G4;
                }

                case 5: {
                    return (int) FREQ_G5;
                }

                case 6: {
                    return (int) FREQ_G6;
                }

                case 7: {
                    return (int) FREQ_G7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        case NOTE_R: {

            printf("R");
            switch (quarters) {

                case 0: {
                    return (int) FREQ_G0;
                }

                case 1: {
                    return (int) FREQ_G1;
                }

                case 2: {
                    return (int) FREQ_G2;
                }

                case 3: {
                    return (int) FREQ_G3;
                }

                case 4: {
                    return (int) FREQ_G4;
                }

                case 5: {
                    return (int) FREQ_G5;
                }

                case 6: {
                    return (int) FREQ_G6;
                }

                case 7: {
                    return (int) FREQ_G7;
                }

                default : {
                    printf("Invalid note\n");
                    break;
                }

            }

            break;
        }

        default: {
            printf("Invalid note\n");
            break;
        }

    }


}
