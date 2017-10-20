//
// Created by sabbir on 10/10/17.
//

#include "music.h"

const char PROGMEM menu_main_str[] = "MAIN MENU\nList songs\nPlay song\n"
"Create song\nExit";
const char PROGMEM menu_play_str[] = "PLAY MENU\nSearch by title\nPlay by "
"number";
const char PROGMEM title_str[] = "Title: ";
const char PROGMEM index_str[] = "Index: ";
const char PROGMEM database_str[] = "\nDatabase\n";
const char PROGMEM choice_str[] = "\nChoice: ";
const char PROGMEM song_success[] = "Song added successfully";
const char PROGMEM notes_str[] = "Song notes: ";

// const char menu_main_str[] = "MAIN MENU\nList songs\nPlay song\nCreate song\n"
//         "Exit";
// const char menu_play_str[] = "PLAY MENU\nSearch by title\nPlay by number";
// const char title_str[] = "Title: ";
// const char index_str[] = "Index: ";
// const char database_str[] = "\nDatabase\n";
// const char choice_str[] = "\nChoice: ";
// const char song_success[] = "Song added successfully!\n";
// const char notes_str[] = "Song notes: ";


char song_title_list[NUMBER_OF_SONGS][USER_LINE_MAX] = {
        {"<EMPTY>"}, {"<EMPTY>"}, {"<EMPTY>"}, {"<EMPTY>"}
};
char song_list[NUMBER_OF_SONGS][MAX_SONG_LENGTH] = {
        {ZERO_REST}, {ZERO_REST}, {ZERO_REST}, {ZERO_REST}
};

uint8_t display_menu(const char[]);

void list_menu();

void play_menu();

void create_menu();

int match_score(const char *, const char *);

int best_match(char *user);

void strip_eol();


// -------------------------
//void strip_eol() {
//
//    char ch;
//
//    ch = getchar();
//    while (ch != '\n') {
//        ch = getchar();
//    }
//
//}


uint8_t display_menu(const char menu[]) {


    int choice, index = 0;
    char *menu_str_copy = strdup(menu);
    char *menu_ptr = menu_str_copy;
    char *menu_tokens;

    while ((menu_tokens = strtok_r(menu_ptr, "\n", &menu_ptr))) {
        if (index) {
            printf_P("%d. ", index);
        }
        index++;
        printf_P("%s\n", menu_tokens);
    }
    free(menu_str_copy);

    printf_P("%s", choice_str);
    if (fgets(user_line, NUMBER_OF_SONGS - 1, stdin) != NULL) {
        sscanf_P(user_line, "%d", &choice);
    }

    return (uint8_t) choice;

}


void list_menu() {

    printf_P("%s", database_str);
    for (int i = 0; i < NUMBER_OF_SONGS; i++) {
        printf_P("%d: %s%s\n", i, title_str, song_title_list[i]);
    }


}


int match_score(const char count_query_string[], const char database[]) {

    const char *count_query_ptr = count_query_string;
    const char *database_ptr = database;
    char *token_user, *token_stored;
    int total_matches = 0;

    while ((token_stored = strtok_r(database_ptr, " ", &database_ptr))) {

        while ((token_user = strtok_r(count_query_ptr, " ", &count_query_ptr))) {

            if (!strcasecmp(token_user, token_stored)) {
                total_matches++;
            }

        }

    }

    return total_matches;

}


int best_match(char user[]) {

    int best_choice = 0, highest_score = 0, cursor = 0;
    for (int i = 0; i < NUMBER_OF_SONGS; i++) {
        if (song_title_list[i] != '\0') {
            cursor = match_score(user, song_title_list[i]);
            if (cursor > highest_score) {
                highest_score = best_choice;
                best_choice = i;
            }
        }
    }

    return best_choice;

}

void play_menu() {

    int play_choice, song_ix;

    int index = 0;
    char *menu_str_copy = strdup(menu_play_str);
    const char *menu_ptr = menu_str_copy;
    char *menu_tokens;

    while ((menu_tokens = strtok_r(menu_ptr, "\n", &menu_ptr))) {
        if (index) {
            printf_P("%d. ", index);
        }
        index++;
        printf_P("%s\n", menu_tokens);
    }
    free(menu_str_copy);

    printf_P("%s", choice_str);
    if (fgets(user_line, NUMBER_OF_SONGS - 1, stdin) != NULL) {
        sscanf_P(user_line, "%d", &play_choice);
    }

    switch (play_choice) {
        case 1: {
            char user_query[MAX_TITLE_LENGTH];
            printf_P("%s", title_str);
            if (fgets(user_line, MAX_TITLE_LENGTH, stdin) != NULL) {
                sscanf_P(user_line, "%[^\n]", user_query);
            }
            song_ix = best_match(user_query);
            play_song((uint8_t *) song_list[song_ix]);

            break;
        }

        case 2: {
            printf_P("%s", index_str);
            if (fgets(user_line, 3, stdin) != NULL) {
                sscanf_P(user_line, "%d", &song_ix);
                play_song((uint8_t *) song_list[song_ix]);
            }
            break;
        }

        default: {
            break;
        }
    }

}

void create_menu() {

    char song_ascii[USER_LINE_MAX];
    char song_title[MAX_TITLE_LENGTH];
    char *full_song;
    int new_song_ix;


    printf_P("%s", title_str);
    if (fgets(user_line, MAX_TITLE_LENGTH, stdin) != NULL) {
        sscanf_P(user_line, "%[^\n]", song_title);
    }

    printf_P("%s", notes_str);
    if (fgets(user_line, USER_LINE_MAX, stdin) != NULL) {
        sscanf_P(user_line, "%s", song_ascii);
    }

    full_song = add_zero_rest(song_ascii);
    uint8_t packed_song[strlen(full_song) / 2];
    memset(packed_song, 0, sizeof(packed_song));
    store_songs(packed_song, full_song);

    printf_P("%s", index_str);
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf_P(user_line, "%d", &new_song_ix);
    }

    printf_P("%s", song_success);

    memcpy(song_title_list[new_song_ix], song_title, MAX_SONG_LENGTH);
    memcpy(song_list[new_song_ix], packed_song, MAX_SONG_LENGTH);

}


int main() {


    uint8_t choice;
    uint8_t flag = 1;

    while (flag) {

        choice = display_menu(menu_main_str);

        switch (choice) {

            case 1: {

                list_menu();
                printf_P("\n");
                break;

            }

            case 2: {

                play_menu();
                printf_P("\n");
                break;

            }

            case 3: {

                create_menu();
                printf_P("\n");
                break;

            }

            case 4: {
                flag = 0;
                break;
            }

            default: {
                break;
            }

        }

    }

    return EXIT_SUCCESS;

}

