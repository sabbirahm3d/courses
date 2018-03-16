//
// Created by sabbir on 3/11/18.
//

#ifndef RAND_H
#define RAND_H

static unsigned int next_random = 9001;

static unsigned int generate_random_int() {

    next_random = next_random * 1103515245 + 12345;
    return (next_random / 65536) % 32768;

}

static void seed_random(unsigned int seed) {

    next_random = seed;

}


#endif // RAND_H
