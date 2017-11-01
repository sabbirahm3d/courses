
#include <stdio.h>
#include <string.h>
#include "list.h"

const char menu_main_str[] = "---------- MAIN MENU ----------\n1. "
        "List Database\n2. Search by Name\n3. Search by list_of_grades\n4. Add "
        "Student\n5. Remove Student\n0. Exit\nChoose: ";
char user_line[20];

/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt. */
int display_menu() {

    // holds user input
    int choice = 0;

    printf("%s", menu_main_str);

    // prompt user for choice
    if (fgets(user_line, 3, stdin) != NULL) {
        sscanf(user_line, "%d", &choice);
    }

    return choice;

}

//void init_db(linked_list *database) {
//
//    char *name = "test";
//    float list_of_grades = 92.1;
//    list_push(database, create_node(&name, list_of_grades));
//
//}

void print_db(linked_list *database) {

    if (database->len) {

        node *temp;
        list_iterator_t *it = list_iterator_new(database);

        while ((temp = list_iterator_next(it))) {
            printf("%s: %.2f%% %c\n", temp->name, temp->list_of_grades,
                   *temp->grade);
        }

        free(temp);
        list_iterator_destroy(it);

    } else {

        printf("Database is empty!\n");

    }
    printf("\n");

}


void search_name(linked_list *database) {

    char *name = malloc(20 * sizeof(char));
    int found = 0;

    printf("Enter name: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", name);
    }

    node *temp;
    list_iterator_t *it = list_iterator_new(database);

    while ((temp = list_iterator_next(it))) {
        if (!strcasecmp(temp->name, name)) {
            printf("Found student: %s\n", temp->name);
            printf("Student data: %.2f%%\n", temp->list_of_grades);
            found = 1;
        }
    }

    if (!found) {
        printf("Student: %s is not in database", name);
    }
    printf("\n");

    free(name);
    free(temp);
    list_iterator_destroy(it);

}


void add_data(linked_list *database) {

    char *name = malloc(20 * sizeof(char));
    float list_of_grades;
    char *grade = malloc(1 * sizeof(char));

    printf("Enter name: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", name);
    }

    // prompt user for list_of_grades
    printf("Enter list_of_grades: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%f", &list_of_grades);
    }

    printf("Enter grade: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%c", grade);
    }

    list_push(database, create_node(&name, list_of_grades, grade));
    printf("\n");

}

void remove_data(linked_list *database) {

    char *name = malloc(20 * sizeof(char));
    printf("Enter name: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", name);
    }

    node *temp;
    list_iterator_t *it = list_iterator_new(database);

    while ((temp = list_iterator_next(it))) {
        if (!strcasecmp(temp->name, name)) {
            printf("Removing: %s\n", temp->name);
            list_remove(database, temp);
        }
    }
    printf("\n");

    free(name);
    free(temp);
    list_iterator_destroy(it);

}


void close_db(linked_list *database) {

    node *temp;
    list_iterator_t *it = list_iterator_new(database);

    while ((temp = list_iterator_next(it))) {
        free(temp->name);
        free(temp->grade);
    }
    free(temp);

    list_iterator_destroy(it);
    list_destroy(database);

}


int main(void) {

    linked_list *database = list_new();
//    init_db(database);
    int choice;
    int loop_flag = 1;

    char *name = "z";
    char *name1 = "y";
    char *name2 = "a";
    char *name3 = "d";
    char *name4 = "b";
    float list_of_grades = 9.0;
    char *grade = "C";

    list_push(database, create_node(&name, list_of_grades, grade));
    list_push(database, create_node(&name1, list_of_grades + 1, grade));
    list_push(database, create_node(&name2, list_of_grades + 3, grade));
    list_push(database, create_node(&name3, list_of_grades + 2, grade));
    list_push(database, create_node(&name4, list_of_grades + 9, grade));
    print_db(database);
    sort_students(database);
    print_db(database);


/*    FILE *fp;
    char *line = NULL;
    size_t len = 0;

    fp = fopen("input.txt", "r");

    if (fp == NULL)
        return EXIT_FAILURE;

    while (getline(&line, &len, fp) != -1) {
        printf("%s\n", line);
    }

    fclose(fp);
    if (line)
        free(line);


    while (loop_flag) {

        choice = display_menu();

        switch (choice) {

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

                // terminate program
                loop_flag = 0;
                close_db(database);
                break;

            }

            default: {

                printf("\033[H\033[J");  // to clear screen
                printf("Please enter a valid option.\n");
                break;

            }

        }

    }
*/
    return EXIT_SUCCESS;

}
