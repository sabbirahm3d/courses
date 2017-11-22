/* Dynamic Programming C/C++ implementation of LCS problem */
#include<bits/stdc++.h>

int max(int a, int b);

/* Returns length of LCS for X[0..m-1], Y[0..n-1] */
size_t lcs(char *X, char *Y, size_t m, size_t n) {

    int L[m + 1][n + 1];

    /* Following steps build L[m+1][n+1] in bottom up fashion. Note
       that L[i][j] contains length of LCS of X[0..i-1] and Y[0..j-1] */
    for (size_t i = 0; i <= m; i++) {
        for (size_t j = 0; j <= n; j++) {
            if (i == 0 || j == 0)
                L[i][j] = 0;
            else if (X[i - 1] == Y[j - 1])
                L[i][j] = L[i - 1][j - 1] + 1;
            else
                L[i][j] = max(L[i - 1][j], L[i][j - 1]);
        }
    }

    // Following code is used to print LCS
    int index = L[m][n];

    // Create a character array to store the lcs string
    char lcs[index + 1];
    lcs[index] = '\0'; // Set the terminating character

    // Start from the right-most-bottom-most corner and
    // one by one store characters in lcs[]
    size_t i = m, j = n;
    while (i > 0 && j > 0) {
        // If current character in X[] and Y are same, then
        // current character is part of LCS
        if (X[i - 1] == Y[j - 1]) {
            lcs[index - 1] = X[i - 1]; // Put current character in result
            i--;
            j--;
            index--;     // reduce values of i, j and index
        }

            // If not same, then find the larger of two and
            // go in the direction of larger value
        else if (L[i - 1][j] > L[i][j - 1])
            i--;
        else
            j--;
    }

    // Print the lcs
    std::cout << "LCS of " << X << " and " << Y << " is " << lcs << std::endl;

    return strlen(lcs);
}

/* Utility function to get max of 2 integers */
int max(int a, int b) {

    return (a > b) ? a : b;

}

/* Driver program to test above function */
int main() {

    char X[] = "GTAGCC";
    char Y[] = "CATACATCATACGTGTAGGCCGAAGCGGCTGCGACGAGCCCCAAGGGGAAGA";

    size_t length = lcs(X, Y, strlen(X), strlen(Y));
    printf("Length of LCS is %zu\n", length);

    return 0;

}
