/* Dynamic Programming C/C++ implementation of LCS problem */
#include <fstream>
#include <iostream>
#include <cstring>

// MAX on local: 1446
// MAX on GL: 1772

int max(int a, int b);

int lcs(const char *, const char *, size_t, size_t, bool);

char *read_sequence(const char *file_name) {

    FILE *file = fopen(file_name, "rb");
    fseek(file, 0, SEEK_END);
    long fsize = ftell(file);
    fseek(file, 0, SEEK_SET);

    auto buffer = (char *) malloc(fsize + 1);
    fread(buffer, fsize, 1, file);
    fclose(file);

    buffer[fsize] = '\0';

    return buffer;

}


/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
int lcs(const char *seq1, const char *seq2, size_t m, size_t n,
        bool print_lcs) {

    int L[m + 1][n + 1];

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of seq1[0..i-1] and Y[0..j-1] */
    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (seq1[i - 1] == seq2[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    if (print_lcs) {

        // Following code is used to print LCS
        int index = L[m][n];

        // Create a character array to store the lcs string
        auto lcs = new char[index + 1];
        lcs[index] = '\0'; // Set the terminating character

        // Start from the right-most-bottom-most corner and
        // one by one store characters in lcs[]
        size_t i = m, j = n;
        while (i > 0 && j > 0) {

            // If current character in seq1[] and Y are same, then current
            // character is part of LCS
            if (seq1[i - 1] == seq2[j - 1]) {

                // Put current character in result
                lcs[index - 1] = seq1[i - 1];

                // reduce values of i, j and index
                i--;
                j--;
                index--;

            } else if (L[i - 1][j] > L[i][j - 1]) {
                // if not same, then find the larger of two and
                // go in the direction of larger value
                i--;
            } else {
                j--;
            }

        }

        // Print the lcs
        printf("LCS: %s\n", lcs);
        free(lcs);
        lcs = NULL;

    }

    return L[m][n];

}

/* Utility function to get max of 2 integers */
int max(int a, int b) {

    return (a > b) ? a : b;

}

/* Driver program to test above function */
int main(int argc, char *argv[]) {

    auto seq1 = read_sequence(argv[1]);
    auto seq2 = read_sequence(argv[2]);

    int lcs_len = lcs(seq1, seq2, strlen(seq1), strlen(seq2), false);
    std::cout << "Length of LCS is " << lcs_len << std::endl;

    free(seq1);
    seq1 = NULL;
    free(seq2);
    seq2 = NULL;

    return EXIT_SUCCESS;

}