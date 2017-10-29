
#include <stdio.h>
#include <string.h>
#include "list.h"

const char menu_main_str[] = "----- MAIN MENU -----\n1. Database\n2. Search"
        " by Name\n3. Search by Grade\n4. Add\n5. Remove\n0. Exit";
char user_line[20];

/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt. */
int display_menu() {

    // holds user input
    int choice = 0;

    printf("%s\n", menu_main_str);

    // prompt user for choice
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return choice;

}

int main(void) {


    linked_list *langs = list_new();

    float ptr = 9;
//    char *n = "Ana";
//    float ptr1 = 12.9;
//    char *n1 = "Sabbir";
//    float ptr2 = 19;
//    char *n2 = "Us";


    int choice;
    int loop_flag = 1;

    while (loop_flag) {

        choice = display_menu();

        switch (choice) {

            // call list menu
            case 1: {

                // list_menu();
                printf("\n");
                break;

            }

                // call play menu
            case 2: {

                // play_menu();
                printf("\n");
                break;

            }

                // call create menu
            case 3: {

                // create_menu();
                printf("\n");
                break;

            }

                // call create menu
            case 4: {

                // holds user input
                float grade;
                char *name = malloc(20 * sizeof(char));;
                printf("Enter name: ");
                if (fgets(user_line, 20, stdin) != NULL) {
                    sscanf(user_line, "%[^\n]", name);
                }

                // prompt user for grade
                printf("Enter grade: ");
                if (fgets(user_line, 3, stdin) != NULL) {
                    sscanf(user_line, "%f", &grade);
                }

                printf("%s\n", menu_main_str);

                // prompt user for choice
                if (fgets(user_line, 3, stdin) != NULL) {
                    sscanf(user_line, "%d", &choice);
                }


                list_rpush(langs, create_node(&name, &ptr));

                break;

            }

            case 0: {  // terminate program

                loop_flag = 0;
                node *temp;

                list_iterator_t *it = list_iterator_new(langs, LIST_HEAD);
                while ((temp = list_iterator_next(it))) {
                    printf("%s: %f\n", temp->name, *temp->grade);
                }

//                node *found = list_find(langs, n);
//                printf("found %s: %f\n", found->name, *found->grade);
//
//                node *found1 = list_get(langs, 2);
//                printf("found %s: %f\n", found1->name, *found1->grade);
                list_iterator_destroy(it);
                list_destroy(langs);
                break;

            }

            default: {
                break;
            }

        }

    }

    return EXIT_SUCCESS;

}
