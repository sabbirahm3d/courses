//
// Created by sabbir on 10/14/17.
//

#ifndef NOTES_H
#define NOTES_H

#include <inttypes.h>

#define FREQ_TO_MS 500000
#define FREQ_R 4
#define FREQ_C0 16.35
#define FREQ_D0 18.35
#define FREQ_E0 20.60
#define FREQ_F0 21.83
#define FREQ_G0 24.50
#define FREQ_A0 27.50
#define FREQ_B0 30.87
#define FREQ_C1 32.70
#define FREQ_D1 36.71
#define FREQ_E1 41.20
#define FREQ_F1 43.65
#define FREQ_G1 49.00
#define FREQ_A1 55.00
#define FREQ_B1 61.74
#define FREQ_C2 65.41
#define FREQ_D2 73.42
#define FREQ_E2 82.41
#define FREQ_F2 87.31
#define FREQ_G2 98.00
#define FREQ_A2 110.00
#define FREQ_B2 123.47
#define FREQ_C3 130.81
#define FREQ_D3 146.83
#define FREQ_E3 164.81
#define FREQ_F3 174.61
#define FREQ_G3 196.00
#define FREQ_A3 220.00
#define FREQ_B3 246.94
#define FREQ_C4 261.63
#define FREQ_D4 293.66
#define FREQ_E4 329.63
#define FREQ_F4 349.23
#define FREQ_G4 392.00
#define FREQ_A4 440.00
#define FREQ_B4 493.88
#define FREQ_C5 523.25
#define FREQ_D5 587.33
#define FREQ_E5 659.26
#define FREQ_F5 698.46
#define FREQ_G5 783.99
#define FREQ_A5 880.00
#define FREQ_B5 987.77
#define FREQ_C6 1046.50
#define FREQ_D6 1174.66
#define FREQ_E6 1318.51
#define FREQ_F6 1396.91
#define FREQ_G6 1567.98
#define FREQ_A6 1760.00
#define FREQ_B6 1975.53
#define FREQ_C7 2093.00
#define FREQ_D7 2349.32
#define FREQ_E7 2637.02
#define FREQ_F7 2793.83
#define FREQ_G7 3135.96
#define FREQ_A7 3520.00
#define FREQ_B7 3951.07

unsigned int get_frequency(uint8_t, uint8_t);

#endif //NOTES_H
