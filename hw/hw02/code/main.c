//
// Created by sabbir on 10/10/17.
//

#include "music.h"

const char menu_main_str[] = "\n--------- Main Menu ---------\n1. List "
        "songs\n2. Play song\n3. Create song\n0. Exit\nPlease enter a choice: ";
const char menu_play_str[] = "--------- Play Menu ---------\n1. Search by "
        "title\n2. Play by number\nPlease enter a choice: ";

char song_title_list[NUMBER_OF_SONGS][USER_LINE_MAX] = {
        {"Title1"}, {"Title2"}, {"Title3"}, {"Title4"}
};
char song_list[NUMBER_OF_SONGS][MAX_SONG_LENGTH] = {
        {NOTE_R << 5}, {NOTE_R << 5}, {NOTE_R << 5}, {NOTE_R << 5}
};

uint8_t display_menu(const char[]);

void list_menu();

void play_menu();

void create_menu();

int match_score(const char *, const char *);

int best_match(char *user);

void strip_eol();


// -------------------------
void strip_eol() {

    char ch;

    ch = getchar();
    while (ch != '\n') {
        ch = getchar();
    }

}


uint8_t display_menu(const char menu[]) {


    int choice;

    printf("%s", menu);
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return (uint8_t) choice;

}


void list_menu() {

    printf("---------------------------\nSongs in the database\n");
    for (int i = 0; i < NUMBER_OF_SONGS; i++) {
        printf("%d: Title: %s\n", i, song_title_list[i]);
    }


}


int match_score(const char count_query_string[], const char database[]) {

    char *token_user = strtok(count_query_string, " ");
    char *token_stored = strtok(database, " ");
    int matches = 0;

    while (token_stored != NULL) {
        printf("token: %s\n", token_stored);

        while (token_user != NULL) {
            printf("token_user: %s\n", token_user);

            if (!strcasecmp(token_user, token_stored)) {
                matches++;
            }

            token_user = strtok(NULL, " ");

        }

        token_stored = strtok(NULL, " ");
    }

    return matches;


}


int best_match(char user[]) {


}

void play_menu() {

    int play_choice, song_ix;

    printf("%s", menu_play_str);
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf(user_line, "%d", &play_choice);
    }

    switch (play_choice) {
        case 1: {
            printf("Searching not implemented yet");
            break;
        }

        case 2: {
            printf("Enter index of the song: ");
            if (fgets(user_line, 3, stdin) != NULL) {
                sscanf(user_line, "%d", &song_ix);
                play_song(song_list[song_ix]);
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
    char song_title[50];
    char *full_song;
    int new_song_ix;


    printf("Enter song title: ");
    if (fgets(user_line, 50, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", song_title);
        printf("Song name: %s\n", song_title);
    }

    printf("Enter song notes using ABCDEFGR followed by quarter seconds: ");
    if (fgets(user_line, USER_LINE_MAX, stdin) != NULL) {
        sscanf(user_line, "%s", song_ascii);
        printf("Song notes: %s\n", song_ascii);
    }

    full_song = add_zero_rest(song_ascii);
    uint8_t packed_song[strlen(full_song) / 2];
    memset(packed_song, 0, sizeof(packed_song));

    printf("Packing song... ");
    store_songs(packed_song, full_song);
    printf("done\n");

    printf("Enter index to save the new song: ");
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf(user_line, "%d", &new_song_ix);
        printf("Index: %d", new_song_ix);
    }

    memcpy(song_title_list[new_song_ix], song_title, MAX_SONG_LENGTH);
    memcpy(song_list[new_song_ix], packed_song, MAX_SONG_LENGTH);

}


int main() {


    uint8_t choice;
    uint8_t flag = 1;
//    stderr = stdout = stdin = &uart_stream;
//    UARTInit();

//    char str[] ="one two three";
//    char str1[] ="four five six";
//    int y = match_score(str, str1);
//    printf("%d", y);
    while (flag) {

        choice = display_menu(menu_main_str);

        switch (choice) {

            case 1: {

                list_menu();
                break;

            }

            case 2: {

                play_menu();
                break;

            }

            case 3: {

                create_menu();
                break;

            }

            case 0: {
                printf("Quitting program...\n");
                flag = 0;
                break;
            }

            default: {
                printf("%d is an invalid choice.\n", choice);
                break;
            }

        }

    }

    return EXIT_SUCCESS;

}

