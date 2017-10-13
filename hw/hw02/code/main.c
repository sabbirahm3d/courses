//
// Created by sabbir on 10/10/17.
//

#include "music.h"

//// some initial song with notes
const char *menu_main = "\n--------- Main Menu ---------\n1. List Songs\n2. "
        "Play Song\n3. Create Song\n0. Exit\nPlease enter a choice: \0";
const char *menu_play = "--------- Play Menu ---------\n1. Search By "
        "Title\n2. Number\n";
char song_list[NUMBER_OF_SONGS][USER_LINE_MAX] = {"Title1", "Title2", "Title3",
        "Title4"};
char song[NUMBER_OF_SONGS][MAX_SONG_LENGTH] = {
        {(NOTE_B << 5) + 2, (NOTE_A << 5) + 2, (NOTE_G << 5) + 2},
        {NOTE_R << 5},
        {NOTE_R << 5},
        {NOTE_R << 5}
};

uint8_t display_menu(const char *);
void play_menu();

uint8_t display_menu(const char *menu) {


    int choice;
    printf("%s", menu);
    scanf("%d*[^\\n]", &choice);

    return (uint8_t) choice;

}


void play_menu() {

    char *song_ascii = "B22A2R11C2r14e22e2e2r1r11R0C2R1";

    char* packed_song = add_zero_rest(song_ascii);

    uint8_t song_packed[strlen(packed_song) / 2];
    memset(song_packed, 0, sizeof(song_packed));

    store_songs(song_packed, song_ascii);

    printf("Song: ");
    play_song(song_packed);
    printf("\n(The song produced above is currently hardcoded in. User \n"
        "inputted songs are currently not supported. To try a different\n"
        "song, change the string in the source code)");


}

void create_song() {

    printf("Creating songs is currently not supported\n");
/*
    // char song_ascii[USER_LINE_MAX];
    // char song_title;
    // char *packed_song;
    // int song_ix;


//     printf("Enter song title: ");
//     if (fgets(user_line, 10, stdin) != NULL) {
//        getc(stdin);
//         sscanf(user_line, "%s", &song_title);
//         printf("Song name: %s\n", song_title);
//     }
//    fflush(stdout);
//    printf("Enter song notes using ABCDEFGR followed by quarter seconds: ");
//    getc(stdin);
//    fgets(song_ascii, USER_LINE_MAX, stdin);
//    printf("Song notes: %s", song_ascii);

    // change the song ASCII here:
    // char *song_ascii = "B22A2R11C2r14e22e2e2r1r11R0C2R1";

    // packed_song = add_zero_rest(song_ascii);

    // uint8_t song_packed[strlen(packed_song) / 2];
    // memset(song_packed, 0, sizeof(song_packed));

    // store_songs(song_packed, song_ascii);

    // printf("Song: ");
    // play_song(song_packed);
    // printf("\n(The song produced above is currently hardcoded in. User "
    //     "inputted songs are currently not supported. To try a different"
    //     "song, change the string in the source code)");

    // printf("Enter index to save the new song in: ");
    // if (fgets(user_line, 10, stdin) != NULL) {
    //     sscanf(user_line, "%d", &song_ix);
    //     printf("Index: %d", song_ix);
    // }

*/
}


int main() {


    uint8_t choice;
    uint8_t flag = 1;
//    stderr = stdout = stdin = &uart_stream;
//    UARTInit();


    while (flag) {

        choice = display_menu(menu_main);
        fflush(stdout);

        switch (choice) {

            case 1: {

                printf("Songs in the Database\n");
                for (int i = 0; i < 4; i++) {
                    printf("%s\n", song_list[i]);
                }
                printf("\n");
                break;

            }

            case 2: {

                play_menu();
                break;

            }

            case 3: {

                create_song();
                break;

            }

            case 0: {
                flag = 0;
                printf("Quitting program...\n");
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

