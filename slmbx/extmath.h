//
// Created by sabbir on 3/11/18.
//

#ifndef RAND_H
#define RAND_H

#include <stdio.h>

static unsigned int next_random = 9001;
unsigned int MAXLVL;
unsigned int PROB;

static unsigned int generate_random_int() {

    next_random = next_random * 1103515245 + 12345;
    return (next_random / 65536) % 32768;

}

static void seed_random(unsigned int seed) {

    next_random = seed;

}

static void ceil_log(unsigned int opand, unsigned int base) {

    unsigned int level = 0;
    unsigned int total = 1;

    while (total < opand) {
        total = total * base;
        level++;
    }

    MAXLVL = level;
    PROB = base;

}


#endif // RAND_H
