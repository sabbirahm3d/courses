/*
 * main.c
 *
 * This file contains the driver function of the project.
 *
 * */

#include <stdio.h>
#include <stdlib.h>

#include "menu.h"

int main(int argc, char **argv) {

    // initialize the database_t linked list
    database_t *database = db_init();

    // if an input file was provided
    if (argc > 1) {
        // passes in user inputted file path to initialize the database
        init_db(database, argv[1]);
    }

    int menu_choice;
    int loop_flag = 1;

    while (loop_flag) {

        menu_choice = display_menu();

        switch (menu_choice) {

            case 1: {

                // print out the database
                print_db(database);
                break;

            }

            case 2: {

                // search database by name
                search_name(database);
                break;

            }

            case 3: {

                // search database by list_of_grades
                search_by_grade(database);
                break;
            }

            case 4: {

                // add student data to database
                add_data(database);
                break;

            }

            case 5: {

                // remove student data from database
                remove_data(database);
                break;

            }

            case 0: {

                // terminate program and call the destructors
                loop_flag = 0;
                close_db(database);

                break;

            }

            default: {

                // invalid option
                printf("\033[H\033[J");  // to clear screen
                printf("Please enter a valid option.\n");
                break;

            }

        }

    }


    return EXIT_SUCCESS;

}
