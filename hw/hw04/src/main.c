/*
 * main.c
 *
 * Driver file for Homework 2: Song Composer. This script contains the
 * declarations and implementations of the menu functions and other functions
 * to handle user inputs and outputs (I/O).
 *
 * */

// AVR libraries
#include <string.h>
#include <stdio.h>
#include <stdlib.h>

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd_driver.h"
#include "adc_controller.h"

// --- constant strings stored in the program space for repeated use ---
// strings to build menus
const char PROGMEM ftl_str[] = "FTL";
const char PROGMEM atl_str[] = "ATL";


// ------------------ Helper function declarations ------------------

// JOYSTICK FUNCTIONS
uint8_t press_up();

uint8_t press_down();

uint8_t press_right();




// Displays the
uint8_t display_menu(const char[]);

void list_menu();

void play_menu();

void create_menu();

int match_score(const char *, const char *);

int best_match(char *user);


// ------------------ Helper function implementations ------------------

/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt. */
uint8_t display_menu(const char menu[]) {

    int choice, index = 0;
    // copy the const string main menu prompt to be tokenized
    char *menu_str_copy = strdup(menu);
    char *menu_ptr = menu_str_copy;
    char *menu_tokens;

    // iterate through the main menu prompt and print at each newline char
    while ((menu_tokens = strtok_r(menu_ptr, "\n", &menu_ptr))) {

        // only print indices [1, 2, 3, 4]
        if (index) {
            printf_P("%d. ", index);
        }
        index++;
        printf_P("%s\n", menu_tokens);
    }
    free(menu_str_copy);  // free up copy of string

    // prompt user for choice
    printf_P("%s", choice_str);
    if (fgets(user_line, NUMBER_OF_SONGS - 1, stdin) != NULL) {
        sscanf_P(user_line, "%d", &choice);
    }

    return (uint8_t) choice;

}

/*
 * Iterates through and lists out all the song titles. */
void list_menu() {

    printf_P("%s", database_str);
    for (int i = 0; i < NUMBER_OF_SONGS; i++) {
        printf_P("%d: %s%s\n", i, title_str, song_title_list[i]);
    }


}

/*
 * Compares the user inputted query against title in the song title array.
 * `total_matches` is incremented after every successful matches of the two
 * tokenized strings and returned. */
int match_score(const char count_query_string[], const char database[]) {

    const char PROGMEM *count_query_ptr = count_query_string;
    const char PROGMEM *database_ptr = database;
    char *token_user, *token_stored;
    int total_matches = 0;

    // loop until the string does not contain any whitespace (' ') chars
    while ((token_stored = strtok_r(database_ptr, " ", &database_ptr))) {

        // loop until the string does not contain any whitespace (' ') chars
        while ((token_user = strtok_r(count_query_ptr, " ", &count_query_ptr))) {

            // case-insensitively compare the two tokens
            if (!strcasecmp(token_user, token_stored)) {
                total_matches++;
            }

        }

    }

    return total_matches;

}

/*
 * Calls 'match_score()' on individual titles in
 * the song title array to compare against the user inputted query.
 * 'best_choice' stores the index at which the 'match_score()' function
 * determined the title to best match the user query. */
int best_match(char user[]) {

    int best_choice = 0, highest_score = 0, cursor = 0;

    // loop through each of the titles in the song title array and find their
    // match score
    for (int i = 0; i < NUMBER_OF_SONGS; i++) {

        // only compare song titles that are non-empty
        if (song_title_list[i] != '\0') {

            // current match score
            cursor = match_score(user, song_title_list[i]);

            // best_choice gets assigned the index at which the maximum match
            // score was achieved
            if (cursor > highest_score) {
                highest_score = cursor;
                best_choice = i;
            }
        }
    }

    return best_choice;

}


/*
 * Displays the play menu to the user and prompts for their input. The user's
 * first input is treated as their choice in playing a song. The user is
 * prompted a second time to locate the desired song. */
void play_menu() {

    int play_choice, song_ix;
    int index = 0;
    // copy the const string main menu prompt to be tokenized
    char *menu_str_copy = strdup(menu_play_str);
    const char PROGMEM *menu_ptr = menu_str_copy;
    char *menu_tokens;

    // iterate through the main menu prompt and print at each newline char
    while ((menu_tokens = strtok_r(menu_ptr, "\n", &menu_ptr))) {

        // only print indices [1, 2]
        if (index) {
            printf_P("%d. ", index);
        }

        index++;
        printf_P("%s\n", menu_tokens);

    }
    free(menu_str_copy);  // free up copy of string

    // prompt user for their choice in the play menu
    printf_P("%s", choice_str);
    if (fgets(user_line, NUMBER_OF_SONGS - 1, stdin) != NULL) {
        sscanf_P(user_line, "%d", &play_choice);
    }

    switch (play_choice) {

        // search by title
        case 1: {

            char user_query[MAX_TITLE_LENGTH];
            printf_P("%s", title_str);
            if (fgets(user_line, MAX_TITLE_LENGTH, stdin) != NULL) {
                sscanf_P(user_line, "%[^\n]", user_query);
            }
            // index of the user's desired song title
            song_ix = best_match(user_query);

            break;

        }

            // search by index
        case 2: {

            printf_P("%s", index_str);
            if (fgets(user_line, 3, stdin) != NULL) {
                sscanf_P(user_line, "%d", &song_ix);
            }
            break;

        }

        default: {
            break;
        }
    }

    // call 'play_song()' to play the user's desired song
    play_song((uint8_t *) song_list[song_ix]);

}

/*
 * Displays the create menu to the user and prompts for their input. The user's
 * first input is treated as the title of the new song. The second input is
 * the notes of the song, finally followed by the third input indicating
 * their desired location to save the song. */
void create_menu() {

    char song_ascii[USER_LINE_MAX];
    char song_title[MAX_TITLE_LENGTH];
    char *full_song;
    int new_song_ix;

    // prompt for song title
    printf_P("%s", title_str);
    if (fgets(user_line, MAX_TITLE_LENGTH, stdin) != NULL) {
        sscanf_P(user_line, "%[^\n]", song_title);
    }

    // prompt for song notes
    printf_P("%s", notes_str);
    if (fgets(user_line, USER_LINE_MAX, stdin) != NULL) {
        sscanf_P(user_line, "%s", song_ascii);
    }

    // manually append a zero rest to the song
    full_song = add_zero_rest(song_ascii);
    // dynamically allocate size for the packed song array with half the size
    // of the original user inputted notes array
    uint8_t packed_song[strlen(full_song) / 2];
    memset(packed_song, 0, sizeof(packed_song));
    // store the user inputted notes array by packing individual notes and
    // storing them into the packed_array
    store_songs(packed_song, full_song);

    // prompt for the desired location
    printf_P("%s", index_str);
    if (fgets(user_line, NUMBER_OF_SONGS - 1, stdin) != NULL) {
        sscanf_P(user_line, "%d", &new_song_ix);
    }

    // assign the new title to the desired location of the song title array
    memcpy(song_title_list[new_song_ix], song_title, MAX_SONG_LENGTH);
    // assign the new song to the desired location of the song array
    memcpy(song_list[new_song_ix], packed_song, MAX_SONG_LENGTH);

    // alert the user on the successful addition of their song
    printf_P("%s", song_success_str);

}

/*
 * Main function for the program. Sitting in a loop until terminated by the
 * user, this function acts as the controller for the rest of the program. It
 * prompts users on their choices in the main menu and directs them to the
 * desired functionalities. */
int main() {

    LCD_Init();
    ADCSetup();

    uint8_t mode;

    while (!press_right()) {

        if (press_up()) {
            mode++;
        } else if (press_down()) {
            mode--;
        }

        if (!(mode % 2)) {
            lcd_puts_P(ftl_str);
        } else {
            lcd_puts_P(atl_str);
        }

        if (press_right) {
            if (!(mode % 2)) {
                avoid_the_light(ftl_str);
            } else {
                follow_the_light(atl_str);
            }

        }
    }


    return EXIT_SUCCESS;

}
