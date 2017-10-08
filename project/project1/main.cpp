#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <gmpxx.h>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

/************************************************************/
/* Complex type                                             */
/************************************************************/

struct complex_struct {
    mpz_class r; // real part
    mpz_class i; // imaginary part
};

typedef struct complex_struct complex;

/************************************************************/
/* Prototypes                                               */
/************************************************************/

// Complex four-multiply (four real multiplies)
//   a, b - number to multiply
//   z - return value (product)
//void cmul4(complex a, complex b, complex *z);

// Complex three-multiply (three real multiplies)
//   a, b - number to multiply
//   z - return value (product)
//void cmul3(complex a, complex b, complex *z);

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

//void init(complex *a) {
//    mpz_init(a->r);
//    mpz_init(a->i);
//}


std::vector<mpz_class> cmul3(std::vector<mpz_class> z1, std::vector<mpz_class> z2) {

    mpz_class r, s, t;
    std::vector<mpz_class> pair(2);

    r = z1[0] * z2[0];  // x1 * x2
    s = z1[1] * z2[1];  // y1 * y2
    t = (z1[0] + z1[1]) * (z2[0] + z2[1]);  // (x1 + y1)(x2 + y2)

    pair[0] = r - s;
    pair[1] = t - r - s;

    return pair;

}


std::vector<mpz_class> cmul4(std::vector<mpz_class> z1, std::vector<mpz_class> z2) {

    mpz_class r, s, t;
    std::vector<mpz_class> pair(2);

//    (x1x2−y1y2)+i(x1y2 + y1x2);
    pair[0] = z1[0] * z2[0] - z1[1] * z2[1];
    pair[1] = z1[0] * z2[1] + z1[1] * z2[0];

    return pair;

}


// ---------------------------------- OUR IMPLEMENTATION ----------------------------------
std::vector<mpz_class> line_to_mpz(const std::string &str) {

    std::string next;
    std::vector<mpz_class> pair(2);
    size_t str_size;

//    mpz_init(pair[0]);
//    mpz_init(pair[1]);

    // for each char
    for (char it : str) {
        // if the char == ','
        if (it == ',') {
            // If we have some characters accumulated
            if (!next.empty()) {
                str_size = next.size();
                pair[0] = mpz_class(next.substr(1, str_size).c_str(), 10);
                // a test to verify conversion
//                gmp_printf("mpz %Zd\n", pair[0]);
                next.clear();
            }
        } else {
            // Accumulate the next character into the sequence
            next += it;
        }
    }

    if (!next.empty()) {
        str_size = next.size();
        pair[1] = mpz_class(next.substr(0, str_size - 1).c_str(), 10);
        // a test to verify conversion
//        gmp_printf("mpz %Zd\n", pair[1]);
    }

//    destructors for mpz objects - works fine here, but may need to be called later instead
//    mpz_clear(pair[0]);
//    mpz_clear(pair[1]);

    return pair;

}


void read_from_file(const char *file_name) {

    std::ifstream file(file_name);
    std::string line;
    std::vector<std::vector<mpz_class>> complex_nums;

    std::vector<mpz_class> test;

    while (std::getline(file, line)) {
        complex_nums.push_back(line_to_mpz(line));
    }
    
    gmp_printf("%Zd + i%Zd\n", complex_nums[0][0], complex_nums[0][1]);
    gmp_printf("%Zd + i%Zd\n", complex_nums[1][0], complex_nums[1][1]);
    test = cmul3(complex_nums[0], complex_nums[1]);
    gmp_printf("%Zd + i%Zd\n", test[0], test[1]);
    test = cmul4(complex_nums[0], complex_nums[1]);
    gmp_printf("%Zd + i%Zd\n", test[0], test[1]);

}

int main(int argc, char *argv[]) {

    if (argc == 2) {

        read_from_file(argv[1]);
        return EXIT_SUCCESS;

    } else {

        std::cout << "Please provide a valid file name" << std::endl;
        return EXIT_FAILURE;

    }

}
