//
// Created by sabbir on 10/7/17.
//

#ifndef DIVIDE_AND_CONQUER_MAIN_H
#define DIVIDE_AND_CONQUER_MAIN_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <gmpxx.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>


std::vector<std::vector<mpz_class>> parse_file(const char *);

std::vector<mpz_class> line_to_mpz(const std::string &);

/************************************************************/
/* Prototypes                                               */
/************************************************************/

// Complex four-multiply (four real multiplies)
//   a, b - number to multiply
//   z - return value (product)
std::vector<mpz_class> cmul4(std::vector<mpz_class>, std::vector<mpz_class>);

// Complex three-multiply (three real multiplies)
//   a, b - number to multiply
//   z - return value (product)
std::vector<mpz_class> cmul3(std::vector<mpz_class>, std::vector<mpz_class>);

// Complex list multiply using complex four-multiply
//   u - array of complex
//   first - index of first element to multiply
//   last - index of last element to multiply
//   z - return value, product of u[first..last]
mpz_class cmul4_list(std::vector<mpz_class>, size_t, size_t);

// Complex list multiply using complex three-multiply
//   u, first, last, z - same as for cmul4_list()
mpz_class cmul3_list(std::vector<mpz_class>, size_t, size_t);

// Random complex value; real and imaginary parts at most 2^n
//   z - complex number to be set to random values
//   rstate - state variable for GMP random number generator
//   n - number of bits in real and imaginary part
//void randz(complex *z, gmp_randstate_t rstate, mp_bitcnt_t n);

/************************************************************/
/* Main Program                                             */
/************************************************************/

//int main() {
//
//    complex a, b, z;           // three complex variables
//    gmp_randstate_t rstate;    // state for GMP random number generator
//    clock_t t0, t;             // used for timing functions
//
//    // Initialize random number generator
//
//    gmp_randinit_default(rstate);
//
//    // Test of cmul4() and cmul3()
//
//    init(&a);
//    init(&b);
//    init(&z);
//
//    randz(&a, rstate, 20);
//    randz(&b, rstate, 20);
//
//    cmul4(a, b, &z);
//    gmp_fprintf(stdout, "(%Zd, %Zd)\n", z.r, z.i);
//
//    cmul3(a, b, &z);
//    gmp_fprintf(stdout, "(%Zd, %Zd)\n", z.r, z.i);
//
//    // Test and timing of cmul4_list() and cmul3_list()
//
//    // Generate array of random complex numbers
//
//    // pairu'll need to experiment with the length of the array (n)
//    // and the size of the real and imaginary parts (third parameter
//    // to randz).
//
//    int n = 10;
//    complex v[n];
//    for (int i = 0; i < n; i++) {
//        init(&v[i]);
//        randz(&v[i], rstate, 200);
//    }
//
//    // Time call to cmul4_list()
//
//    t0 = clock();
//    cmul4_list(v, 0, n - 1, &z);
//    t = clock() - t0;
//
//    fprintf(stdout, "*** CMUL4 List ***\n");
//    fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);
//    //  gmp_fprintf(stdout, "(%Zd, %Zd)\n", z.r, z.i);
//
//    // Time call to cmul3_list()
//
//    t0 = clock();
//    cmul3_list(v, 0, n - 1, &z);
//    t = clock() - t0;
//
//    fprintf(stdout, "*** CMUL3 List ***\n");
//    fprintf(stdout, "time: %f\n", ((double) t) / CLOCKS_PER_SEC);
//    //  gmp_fprintf(stdout, "(%Zd, %Zd)\n", z.r, z.i);
//
//    return 0;
//}

///************************************************************/
///* Function Implementations                                 */
///************************************************************/
//
////
//// TO BE WRITTEN: cmul4(), cmul3(), cmul4_list(), cmul3_list(),
////                code to read data file
////
//
//void randz(complex *z, gmp_randstate_t rstate, mp_bitcnt_t n) {
//    mpz_urandomb(z->r, rstate, n);
//    mpz_urandomb(z->i, rstate, n);
//}


#endif //DIVIDE_AND_CONQUER_MAIN_H
