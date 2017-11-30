/*
 * Sabbir Ahmed
 * 11/30/2017
 *
 *
 * main.cpp
 *
 * The main driver file for Project 2: Multithread LCS. This file contains
 * the implementation of the serial longest common subsequence algorithm.
 *
 * Usage after build:
 *
 *      ./lcs_length /path/to/seq1.txt seq1_len /path/to/seq2.txt seq2_len
 *
 * The attached Makefile may be utilized to build and run this script with
 * the command line arguments.
 *
 * The C++ compiler is set to gcc by default:
 *
 *      make build
 *
 * The Intel compiler may instead be used by:
 *
 *      make build CC=icpc
 *
 * For running the executable:
 *
 *      make run SEQ1 SEQ1LEN SEQ2 SEQ2LEN
 *
 * where the default values are:
 *
 *      SEQ1 = seq1.txt
 *      SEQ1LEN = 10000
 *      SEQ2 = seq2.txt
 *      SEQ2LEN = 10000
 *
 * Memory leaks may also be checked with a target with similar arguments and
 * default values:
 *
 *      make val SEQ1 SEQ1LEN SEQ2 SEQ2LEN
 *
 */

#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>

#include <omp.h>

// ------------------------- FUNCTION PROTOTYPES -------------------------

int max2(int, int);

int serial_lcs(const char *, const char *, size_t, size_t, int **);

void print_lcs(const char *, const char *, size_t, size_t, int **);

char *read_sequence(const char *, size_t);


// ------------------------- FUNCTION DECLARATIONS -------------------------


/*
 * Finds the maximum of two integers
 *
 * inputs:
 *      int1: first integer
 *      int2: second integer
 *
 * output:
 *      maximum of the two integers
 *
 */
int max2(int a, int b) {

    return (a > b) ? a : b;

}


/*
 * Reads sequence file into buffer
 *
 * inputs:
 *      file_name   : name of sequence file to be read
 *      seq_len     : user inputted length of sequence
 *
 * output:
 *      sequence buffer
 *
 */
char *read_sequence(const char *file_name, size_t seq_len) {

    FILE *file = fopen(file_name, "rb");

    // read entire one-line file into buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    auto buffer = new char[file_size + 1];
    fread(buffer, file_size, 1, file);
    fclose(file);

    // null terminate the full buffer
    buffer[file_size] = '\0';

    // truncate the buffer to the user inputted length if < max length
    if (seq_len > strlen(buffer)) {
        seq_len = strlen(buffer);
    }
    memcpy(buffer, buffer, seq_len);
    buffer[seq_len] = '\0';

    return buffer;

}


/*
 * Computes the longest common subsequence between the two sequences using
 * a serial implementation of the memoization method
 *
 * inputs:
 *      seq1        : sequence 1 buffer
 *      seq2        : sequence 2 buffer
 *      m           : size of sequence 1
 *      n           : size of sequence 2
 *      lcs_matrix  : empty 2D array to construct the LCS matrix
 *
 * output:
 *      length of the longest common subsequence
 *
 */
int serial_lcs(const char *X, const char *Y, size_t m, size_t n,
               int **lcs_matrix) {

    // use the memoization method to find the longest common subsequence
    for (size_t i = 0; i <= m; i++) {

        for (size_t j = 0; j <= n; j++) {

            // upper-leftmost cell
            if (!i || !j) {

                lcs_matrix[i][j] = 0;

            } else if (X[i - 1] == Y[j - 1]) {

                // current cell gets value of left diagonal cell and
                // incremented
                lcs_matrix[i][j] = lcs_matrix[i - 1][j - 1] + 1;

            } else {

                // current cell gets maximum of the value between previous row
                // and previous column
                lcs_matrix[i][j] = max2(lcs_matrix[i - 1][j],
                                        lcs_matrix[i][j - 1]);

            }

        }
    }

    // the last value of the matrix is the length of the LCS
    return lcs_matrix[m][n];
}


/*
 * Prints the longest common subsequence found
 *
 * inputs:
 *      seq1        : sequence 1 buffer
 *      seq2        : sequence 2 buffer
 *      m           : size of sequence 1
 *      n           : size of sequence 2
 *      lcs_matrix  : LCS matrix
 *
 * output:
 *      none
 *
 */
void print_lcs(const char *X, const char *Y, size_t m, size_t n,
               int **lcs_matrix) {

    // cursor of the matrix
    int cursor = lcs_matrix[m][n];

    // create a character array to store the lcs string
    auto lcs_str = new char[cursor + 1];
    lcs_str[cursor] = '\0'; // Set the terminating character

    // init from the bottom-rightmost cell and store characters in lcs[]
    size_t i = m, j = n;
    while (i > 0 && j > 0) {

        // if current character in X[] and Y[] are same, then current
        // character is part of LCS
        if (X[i - 1] == Y[j - 1]) {

            // result gets current character
            lcs_str[cursor - 1] = X[i - 1];

            // decrement i, j and cursor
            i--;
            j--;
            cursor--;

        }

            // if not same, then find the larger of two and go in the
            // direction of larger value
        else if (lcs_matrix[i - 1][j] > lcs_matrix[i][j - 1]) {

            i--;

        } else {

            j--;

        }

    }

    // print the lcs
    std::cout << "Longest common subsequence:" << std::endl << lcs_str <<
              std::endl;
    delete lcs_str;
    lcs_str = NULL;

}


/*
 * Main function for the script
 *
 */
int main(int argc, char *argv[]) {

    // streaming strings to validate sequence length inputs
    std::istringstream m_ss(argv[2]), n_ss(argv[4]);
    size_t m, n;
    if (!((m_ss >> m) || (n_ss >> n))) {
        std::cerr << "Invalid integer inputted." << std::endl;
        return EXIT_FAILURE;
    }

    // initialize the two sequence buffers
    char *X = read_sequence(argv[1], m);
    char *Y = read_sequence(argv[3], n);

    // actual lengths of truncated strings;
    // if inputted length > max length then inputted length = max length
    m = strlen(X);
    n = strlen(Y);

    // dynamically allocate the (m + 1) * (n + 1) LCS matrix on heap
    auto **lcs_matrix = new int *[m + 1];
    for (size_t i = 0; i < m + 1; ++i) {
        lcs_matrix[i] = new int[n + 1];
    }

    double start_t, end_t;  // timing variables

    // start timer
    start_t = omp_get_wtime();

    // get length of LCS
    int serial_lcs_len = serial_lcs(X, Y, m, n, lcs_matrix);

    // stop timer
    end_t = omp_get_wtime() - start_t;

    std::cout.precision(5);  // set precision of floats in stdout
    std::cout << "Length of LCS is " << serial_lcs_len << std::endl;
    std::cout << "Serial algorithm took " << std::fixed << end_t << " seconds"
            " to compute the LCS." << std::endl;

    // for debugging purposes - uncomment the following line to print the LCS
    // print_lcs(X, Y, m, n, lcs_matrix);

    // delete dynamically allocated arrays
    for (size_t i = 0; i < m + 1; ++i) {
        delete[] lcs_matrix[i];
        lcs_matrix[i] = NULL;
    }
    delete[]lcs_matrix;
    lcs_matrix = NULL;

    // delete buffers
    delete X;
    X = NULL;
    delete Y;
    Y = NULL;

    return EXIT_SUCCESS;

}
