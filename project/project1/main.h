/*
Sabbir Ahmed, Zafar Mamarakhimov
10/12/2017

main.h

The header file for Project 1: Divide and Conquer. This file contains the
declarations used in the main driver file.

*/

#ifndef DIVIDE_AND_CONQUER_MAIN_H
#define DIVIDE_AND_CONQUER_MAIN_H

#include <cstdio>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <string>
#include <fstream>
#include <iostream>
#include <vector>

#include <gmp.h>
#include <gmpxx.h>  // C++11 wrapper for GMP, includes class declarations

// ---------------------------- Helper functions ----------------------------

// Parses the input file from its path provided via the command line and stores
// them in a vector after conversion to MPZ integers
std::vector<std::vector<mpz_class>> parse_file(const char *);

// Converts string lines from the file to MPZ_int pairs
std::vector<mpz_class> line_to_mpz(const std::string &);


// ------------------- Functions for complex multiplication -------------------

// Uses the four-multiplication method to multiply two complex numbers
std::vector<mpz_class> cmul4(std::vector<mpz_class>, std::vector<mpz_class>);

// Uses the three-multiplication method to multiply two complex numbers
std::vector<mpz_class> cmul3(std::vector<mpz_class>, std::vector<mpz_class>);

// Uses a divide and conquer method to recursively multiply all the elements in
// the complex array using the four-multiplication method
std::vector<mpz_class> cmul4_list(std::vector<mpz_class>, size_t, size_t);

// Uses a divide and conquer method to recursively multiply all the elements in
// the complex array using the three-multiplication method
std::vector<mpz_class> cmul3_list(std::vector<mpz_class>, size_t, size_t);

#endif //DIVIDE_AND_CONQUER_MAIN_H
