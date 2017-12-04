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
 * The C compiler is set to gcc by default:
 *
 *      make build
 *
 * The Intel compiler may instead be used by:
 *
 *      make build CC=icc
 *
 * For running the executable:
 *
 *      make run SEQ1 SEQ1LEN SEQ2 SEQ2LEN
 *
 * where the default values are:
 *
 *      SEQ1    = seq1.txt
 *      SEQ1LEN = 10000
 *      SEQ2    = seq2.txt
 *      SEQ2LEN = 10000
 *
 * Memory leaks may also be checked with a target with similar arguments and
 * default values:
 *
 *      make val SEQ1 SEQ1LEN SEQ2 SEQ2LEN
 *
 */

#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include <math.h>

#include <omp.h>

// ------------------------- FUNCTION PROTOTYPES -------------------------

int max2(int, int);

int is_num(const char []);


int lcs_length(const char *, const char *, unsigned int, unsigned int, int **);

int p_lcs_length(const char *, const char *, unsigned int, unsigned int, int
**);

void lcs_print(const char *, const char *, unsigned int, unsigned int, int **);

char *read_sequence(const char *, unsigned int);


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
 * Checks if char array is an integer
 *
 * inputs:
 *      num: char array containing integer
 *
 * output:
 *      0 if string is not an integer, 1 if it is
 *
 */
int is_num(const char num[]) {


    if (num[0] == '-') {  // negative numbers
        return 0;
    }
    for (int i = 0; num[i]; i++) {
        if (!isdigit(num[i])) {
            return 0;
        }
    }

    return 1;

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
char *read_sequence(const char *file_name, unsigned int seq_len) {

    FILE *file = fopen(file_name, "rb");

    // read entire one-line file into buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    char *buffer = (char *) malloc(file_size);
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
int lcs_length(const char *X, const char *Y, unsigned int m, unsigned int n,
               int **lcs_matrix) {

    // use the memoization method to find the longest common subsequence
    for (unsigned int i = 1; i <= m; i++) {

        for (unsigned int j = 1; j <= n; j++) {

//            // upper-leftmost cell
//            if (!i || !j) {
//
//                printf("Here\n");
//
//                lcs_matrix[i][j] = 0;
//
//            } else
            if (X[i - 1] == Y[j - 1]) {

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

int p_lcs_length(const char *X, const char *Y, unsigned int m, unsigned int n,
                 int **lcs_matrix) {


    // use the memoization method to find the longest common subsequence
    for (unsigned int i = 1; i <= n; i++) {
#pragma omp parallel for
        for (unsigned int j = 1; j <= i; j++) {

            if (Y[i - j] == X[j - 1]) {

                lcs_matrix[i - j + 1][j] = lcs_matrix[i - j][j - 1] + 1;

            } else if (lcs_matrix[i - j][j] >= lcs_matrix[i - j + 1][j - 1]) {

                lcs_matrix[i - j + 1][j] = lcs_matrix[i - j][j];

            } else {

                lcs_matrix[i - j + 1][j] = lcs_matrix[i - j + 1][j - 1];

            }

        }
    }


    int weight = 0;
    for (unsigned int k = 2; k <= m; k++) {
        if (weight < (m - n)) {
            weight++;
        }

#pragma omp parallel for
        for (unsigned int j = k; j <= (n + weight); j++) {

            if (Y[n - j + k - 1] == X[j - 1]) {

                lcs_matrix[n - j + k][j] = lcs_matrix[n - j + k - 1][j - 1] + 1;

            } else if (lcs_matrix[n - j + k - 1][j] >= lcs_matrix[n - j + k][j -
                    1]) {

                lcs_matrix[n - j + k][j] = lcs_matrix[n - j + k - 1][j];

            } else {

                lcs_matrix[n - j + k][j] = lcs_matrix[n - j + k][j - 1];

            }
        }
    }

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
void lcs_print(const char *X, const char *Y, unsigned int m, unsigned int n,
               int **lcs_matrix) {

    // cursor of the matrix
    int cursor = lcs_matrix[m][n];

    // create a character array to store the lcs string
    char *lcs_str = (char *) malloc(cursor + 1);
    lcs_str[cursor] = '\0'; // Set the terminating character

    // init from the bottom-rightmost cell and store characters in lcs[]
    unsigned int i = m, j = n;
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
    printf("Longest common subsequence:\n%s\n", lcs_str);
    free(lcs_str);
    lcs_str = NULL;

}


/*
 * Main function for the script
 *
 */
int main(int argc, char *argv[]) {

    // validate user inputted sequence lengths
    unsigned int m, n;
    if (is_num(argv[2]) && is_num(argv[4])) {
        m = (unsigned int) atoi(argv[2]);
        n = (unsigned int) atoi(argv[4]);
    } else {
        printf("Invalid integer inputted.\n");
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
    int *lcs_matrix_serial[m + 1], *lcs_matrix_parallel[m + 1];

    int nthreads, tid;
#pragma omp parallel shared(nthreads) private(tid)
    {
        tid = omp_get_thread_num();
        if (tid == 0) {
            nthreads = omp_get_num_threads();
            printf("Number of threads = %d\n", nthreads);
        }

        printf("Thread %d starting...\n", tid);

#pragma omp for
        for (unsigned int i = 0; i < m + 1; ++i) {
            lcs_matrix_serial[i] = (int *) malloc((n + 1) * sizeof(int));
            lcs_matrix_parallel[i] = (int *) malloc((n + 1) * sizeof(int));
        }
    }

    double start_t, end_t;  // timing variables

    // start timer
    start_t = omp_get_wtime();

    // get length of LCS
    int lcs_len = lcs_length(X, Y, m, n, lcs_matrix_serial);
    // stop timer
    end_t = omp_get_wtime() - start_t;

    printf("Length of X %d\n", m);
    printf("Length of Y %d\n", n);
    printf("Length of LCS %d\n", lcs_len);
    printf("Serial algorithm took %.5f\n", end_t);

    // start timer
    start_t = omp_get_wtime();

    // get length of LCS
    lcs_len = p_lcs_length(X, Y, m, n, lcs_matrix_parallel);
    // stop timer
    end_t = omp_get_wtime() - start_t;

    printf("Length of LCS %d\n", lcs_len);
    printf("Parallel algorithm took %.5f\n", end_t);

    // for debugging purposes - uncomment the following line to print the LCS
    // lcs_print(X, Y, m, n, lcs_matrix_serial);

    // delete dynamically allocated arrays
    for (unsigned int i = 0; i < m + 1; ++i) {
        free(lcs_matrix_serial[i]);
        lcs_matrix_serial[i] = NULL;
    }

    // delete buffers
    free(X);
    X = NULL;
    free(Y);
    Y = NULL;

    return EXIT_SUCCESS;

}
