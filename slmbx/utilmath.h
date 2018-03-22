//
// Created by sabbir on 3/11/18.
//

#ifndef UTILMATH_H
#define UTILMATH_H

static unsigned int next_random = 9001;
static unsigned int MULTIPLIER = 1103515245;
static unsigned int INCREMENT = 12345;
unsigned int MAXLVL;
unsigned int PROB;

static unsigned int generate_random_int(void) {

    next_random = next_random * MULTIPLIER + INCREMENT;
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

#endif // UTILMATH_H
