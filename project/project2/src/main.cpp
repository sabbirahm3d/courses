/*
 * Sabbir Ahmed, Zafar Mamarakhimov
 * 11/30/2017
 *
 *
 * main.cpp
 *
 * The main driver file for Project 2: Multithread LCS. This file contains
 * the implementation of the serial longest common subsequence algorithm.
 *
 * */

#include <fstream>
#include <iostream>
#include <cstring>

// ------------------------- FUNCTION PROTOTYPES -------------------------

int max2(int, int);

int serial_lcs(const char *, const char *, size_t, size_t, bool= false);

char *read_sequence(const char *);


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
 *      file_name: name of sequence file to be read
 *
 * output:
 *      sequence buffer
 *
 */
char *read_sequence(const char *file_name) {

    FILE *file = fopen(file_name, "rb");

    // read entire one-line file into buffer
    fseek(file, 0, SEEK_END);
    long file_size = ftell(file);
    fseek(file, 0, SEEK_SET);

    auto buffer = new char[file_size + 1];
    fread(buffer, file_size, 1, file);
    fclose(file);

    buffer[file_size] = '\0';

    return buffer;

}


/*
 * Computes the longest common subsequence between the two sequences
 *
 * inputs:
 *      seq1        : sequence 1 buffer
 *      seq2        : sequence 2 buffer
 *      m           : size of sequence 1
 *      n           : size of sequence 2
 *      print_lcs   : <default: false> flag to print the longest common
 *                    subsequence
 *
 * output:
 *      length of the longest common subsequence
 *
 */
int serial_lcs(const char *seq1, const char *seq2, size_t m, size_t n,
               bool print_lcs) {

    // dynamically allocate the (m + 1) * (n + 1) LCS table on heap
    auto **lcs_table = new int *[m + 1];
    for (size_t i = 0; i < m + 1; ++i) {
        lcs_table[i] = new int[n + 1];
    }

    // use the memoization method to find the longest common subsequence
    for (size_t i = 0; i <= m; i++) {

        for (size_t j = 0; j <= n; j++) {

            // upper-leftmost cell
            if (!i || !j) {

                lcs_table[i][j] = 0;

            } else if (seq1[i - 1] == seq2[j - 1]) {

                // current cell gets value of left diagonal cell and
                // incremented
                lcs_table[i][j] = lcs_table[i - 1][j - 1] + 1;

            } else {

                // current cell gets maximum of the value between previous row
                // and previous column
                lcs_table[i][j] = max2(lcs_table[i - 1][j],
                                       lcs_table[i][j - 1]);

            }

        }
    }

    // the last value of the table is the length of the LCS
    int lcs_len = lcs_table[m][n];

    // if printing LCS flag is true
    if (print_lcs) {

        // cursor of the table
        int cursor = lcs_len;

        // create a character array to store the lcs string
        auto lcs_str = new char[cursor + 1];
        lcs_str[cursor] = '\0'; // Set the terminating character

        // init from the bottom-rightmost cell and store characters in lcs[]
        size_t i = m, j = n;
        while (i > 0 && j > 0) {

            // if current character in seq1[] and seq2[] are same, then current
            // character is part of LCS
            if (seq1[i - 1] == seq2[j - 1]) {

                // result gets current character
                lcs_str[cursor - 1] = seq1[i - 1];

                // decrement i, j and cursor
                i--;
                j--;
                cursor--;

            }

                // if not same, then find the larger of two and go in the
                // direction of larger value
            else if (lcs_table[i - 1][j] > lcs_table[i][j - 1]) {

                i--;

            } else {

                j--;

            }

        }

        // print the lcs
        std::cout << "LCS: " << lcs_str << std::endl;
        delete lcs_str;
        lcs_str = NULL;

    }

    // delete dynamically allocated arrays
    for (size_t i = 0; i < m + 1; ++i) {
        delete[] lcs_table[i];
        lcs_table[i] = NULL;
    }
    delete[]lcs_table;
    lcs_table = NULL;

    return lcs_len;

}


/*
 * Main function for the script
 *
 * */
int main(int argc, char *argv[]) {

    // initialize the two sequence buffers
    auto seq1 = read_sequence(argv[1]);
    auto seq2 = read_sequence(argv[2]);

    // get length of LCS
    int lcs_len = serial_lcs(seq1, seq2, strlen(seq1), strlen(seq2));
    std::cout << "Length of LCS is " << lcs_len << std::endl;

    delete seq1;
    seq1 = NULL;
    delete seq2;
    seq2 = NULL;

    return EXIT_SUCCESS;

}
