#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gmp.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

/************************************************************/
/* Complex type                                             */
/************************************************************/

struct complex_struct {
    mpz_t r; // real part
    mpz_t i; // imaginary part
};

typedef struct complex_struct complex;

/************************************************************/
/* Prototypes                                               */
/************************************************************/

// Complex four-multiply (four real multiplies)
//   a, b - number to multiply
//   z - return value (product)
void cmul4(complex a, complex b, complex *z);

// Complex three-multiply (three real multiplies)
//   a, b - number to multiply
//   z - return value (product)
void cmul3(complex a, complex b, complex *z);

// Complex list multiply using complex four-multiply
//   u - array of complex
//   first - index of first element to multiply
//   last - index of last element to multiply
//   z - return value, product of u[first..last]
void cmul4_list(complex *u, int first, int last, complex *z);

// Complex list multiply using complex three-multiply
//   u, first, last, z - same as for cmul4_list()
void cmul3_list(complex *u, int first, int last, complex *z);

// Initialize a complex number; calls mpz_init()
void init(complex *a);

// Random complex value; real and imaginary parts at most 2^n
//   z - complex number to be set to random values
//   rstate - state variable for GMP random number generator
//   n - number of bits in real and imaginary part
void randz(complex *z, gmp_randstate_t rstate, mp_bitcnt_t n);

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

void init(complex *a) {
    mpz_init(a->r);
    mpz_init(a->i);
}

mpz_t* split_line(const std::string &str) {

    std::string next;
    mpz_t pair[2];
    size_t str_size;

    mpz_init(pair[0]);
    mpz_init(pair[1]);

    // for each char
    for (char it : str) {
        // if the char == ','
        if (it == ',') {
            // If we have some characters accumulated
            if (!next.empty()) {
                str_size = next.size();
                mpz_set_str(pair[0], next.substr(1, str_size).c_str(), 10);
                gmp_printf("%s is an mpz %Zd\n", "here", pair[0]);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += it;
        }
    }

    if (!next.empty()) {
        str_size = next.size();
        mpz_set_str(pair[1], next.substr(0, str_size - 1).c_str(), 10);
        gmp_printf("%s is an mpz %Zd\n", "here", pair[1]);
    }

    return pair;

}


void read_from_file(const char *file_name) {

    std::ifstream file(file_name);
    std::string line;
    std::vector<complex> complex_nums;

    while (std::getline(file, line)) {
        split_line(line);
    }

}

int main(int argc, char *argv[]) {

    if (argc == 2) {

        read_from_file(argv[1]);
        return 0;

    } else {

        std::cout << "Please provide a valid file name" << std::endl;
        return -1;

    }

}
