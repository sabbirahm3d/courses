#include <stdio.h>
#include <string.h>

char* caesar(char cipher[], short shift) {

    int i = 0;

    while (cipher[i] != '\0') {
        if ((cipher[i] + shift) >= 65 && (cipher[i] + shift) <= 90) {
            cipher[i] += shift;
        } else {
            cipher[i] += (shift - 25); 
        }
        i++;
    }

    return cipher;
}

int main(void) {
    char master[25];
    char secret[25];
    short n = 2;
    short shift = 9;

    printf("Enter master password\n");
    fgets(master, 25, stdin);
    printf("\033[H\033[J");  // to clear screen

    printf("Enter password to compare\n");
    fgets(secret, 25, stdin);

    while (n >= 0) {

        if (!strcmp(caesar(secret, shift), caesar(master, shift))) {
            printf("secret message\n");
            n = -1;
        } else {
            printf("Wrong password\n");
            fgets(secret, 25, stdin);
        }

        n--;

        if (!n) {
            printf("FAILED");
            break;
        }

    }

}