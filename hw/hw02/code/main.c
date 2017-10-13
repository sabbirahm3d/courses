//
// Created by sabbir on 10/10/17.
//

#include "music.h"

//// some initial song with notes
const char *menu_main = "--------- Main Menu ---------\n1. List Songs\n2. Play "
        "Song\n3. Create Song\nPlease enter a choice: \0";
const char *menu_play = "Play Menu\nSearch By Title\nNumber\n";
char song_list[NUMBER_OF_SONGS][USER_LINE_MAX] = {"Title1", "Title2", "Title3",
        "Title4"};
char song[NUMBER_OF_SONGS][MAX_SONG_LENGTH] = {
        {(NOTE_B << 5) + 2, (NOTE_A << 5) + 2, (NOTE_G << 5) + 2},
        {NOTE_R << 5},
        {NOTE_R << 5},
        {NOTE_R << 5}
};

uint8_t display_menu(const char *);

uint8_t display_menu(const char *menu) {


    int choice;
    printf("%s", menu);
    scanf("%d*[^\\n]", &choice);

    return (uint8_t) choice;

}


void create_song() {


    char song_ascii[USER_LINE_MAX];

    printf("Enter song name: ");
    getc(stdin);
    fgets(song_ascii, USER_LINE_MAX, stdin);
    printf("Song name: %s", song_ascii);

}

int main() {


    uint8_t choice;
    uint8_t flag = 1;
    stderr = stdout = stdin = &uart_stream;
    UARTInit();


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

                flag = 0;
                break;

            }

            case 3: {

                create_song();
                break;

            }

            default: {
                printf("%d is an invalid choice.\n", choice);
                flag = 0;
                break;
            }

        }


//        song_ascii = add_zero_rest(song_ascii);
//
//        uint8_t song_packed[strlen(song_ascii) / 2];
//        memset(song_packed, 0, sizeof song_packed);
//
//        store_songs(song_packed, song_ascii);
//
//        printf("Array: ");
//        for (size_t i = 0; song_packed[i] != ZERO_REST; i++) {
//            printf("%d ", song_packed[i]);
//        }
//
//        printf("\nSong: ");
//        play_song(song_packed);
    }

    return EXIT_SUCCESS;

}

