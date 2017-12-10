/*
 * main.c
 *
 * Driver file for Homework 5: 777 for 7s. This script contains the
 * declarations and implementations of the ADC driver, LCD interface, menu
 * functions and other functions to handle user inputs and outputs (I/O).
 *
 */


#include <stdlib.h>
#include <stdio.h>
#include <stdint.h>
#include <string.h>


const char WELCOMESTR[] = "HELLO\n";
int WALLET = 10;
int BET = 0;


uint8_t multiplier(char word[]) {

    if (!strcmp(word, "BAC") || !strcmp(word, "CAF") || !strcmp(word, "DEF")
            || !strcmp(word, "FAB") || !strcmp(word, "FAE")
            || !strcmp(word, "FAC")) {

        return 1;

    } else if (!strcmp(word, "ADC") || !strcmp(word, "CAD") ||
            !strcmp(word, "DAE") || !strcmp(word, "DEB")
            || !strcmp(word, "FEB")) {

        return 2;

    } else if (!strcmp(word, "CAB") || !strcmp(word, "FAD")
            || !strcmp(word, "FDA")) {

        return 3;

    } else if (!strcmp(word, "ACE") || !strcmp(word, "BAD")) {

        return 4;

    } else if (!strcmp(word, "BED") || !strcmp(word, "DAB")
            || !strcmp(word, "FED")) {

        return 5;

    }

}

uint8_t push_button() {

    int choice;
    char user_line[20];

    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return (uint8_t) choice;


}


char *slot_machine() {

//    demo stuff
////////////////////////////
#include <time.h>

    void delay(int number_of_seconds) {
        // Converting time into milli_seconds
        int milli_seconds = 1000 * number_of_seconds;

        // Stroing start time
        clock_t start_time = clock();

        // looping till required time is not acheived
        while (clock() < start_time + milli_seconds);
    }
///////////////////////////

    for (unsigned int i = 0; i < 100; i++)
        for (char c = 'A'; c <= 'F'; ++c) {
            delay(10);
            printf("\033[H\033[J");
            printf("%cAB\n", c);
        }

}


/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt. */
uint8_t display_menu() {

    int choice;
    char user_line[20];

    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return (uint8_t) choice;

}


uint8_t which_button() {

    printf(WELCOMESTR);
    return display_menu();


}


/*
 * Main function for the program. Sitting in a loop until terminated by the
 * user, this function acts as the controller for the rest of the program. It
 * prompts users on their choices in the main menu and directs them to the
 * desired functionalities.
 */
int main() {

    uint8_t loop_flag = 1;
    uint8_t btn_pressed = 0;

    while (loop_flag) {

        btn_pressed = which_button();

        switch (btn_pressed) {

            // up button
            case 1: {
                printf("UP\n");
                slot_machine();
                break;
            }

            case 4: {
                loop_flag = 0;
                break;
            }

            default: {
                break;
            }
        }


    }


    return EXIT_SUCCESS;

}
