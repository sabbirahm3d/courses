
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

const char menu_main_str[] = "---------- MAIN MENU ----------\n1. List "
        "Database\n2. Search by Name\n3. Search by Grade\n4. Add Student\n5. "
        "Remove Student\n0. Exit\nChoose: ";
char user_line[20];
char user_grade[5];

int UNSORTED = 1;

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

//void init_db(Database *database) {
//
//    char *name = "test";
//    float list_of_grades = 92.1;
//    list_push(database, new_student(&name, list_of_grades));
//
//}

void print_db(Database *database) {

    if (database->len) {

        if (UNSORTED) {
            sort_students(database);
            UNSORTED = 0;
        }

        Student *temp;
        list_iterator_t *it = list_iterator_new(database);

//        while ((temp = database->head->next)) {
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


void search_name(Database *database) {

    char *name = malloc(20 * sizeof(char));
    int found = 0;

    printf("Enter name: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", name);
    }

    Student *temp;
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


void search_by_grade(Database *database) {

    char *grade = malloc(sizeof(char));
    int found = 0;

    printf("Enter grade: ");
    if (fgets(user_grade, 5, stdin) != NULL) {
        sscanf(user_grade, "%c", grade);
    }

    Student *temp;
    list_iterator_t *it = list_iterator_new(database);

    while ((temp = list_iterator_next(it))) {
        if (!strcmp(temp->grade, grade)) {
            printf("Found student: %s\n", temp->name);
            printf("Student data: %.2f%%\n", temp->list_of_grades);
            found = 1;
        }
    }

    if (!found) {
        printf("No students with a grade of %c in database", *grade);
    }
    printf("\n");

    free(grade);
    free(temp);
    list_iterator_destroy(it);

}


void add_data(Database *database) {

    char *name = malloc(20 * sizeof(char));
    float list_of_grades;
    char *grade = malloc(sizeof(char));

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
    if (fgets(user_grade, 5, stdin) != NULL) {
        sscanf(user_grade, "%c", grade);
    }

    list_push(database, new_student(&name, list_of_grades, grade));
    UNSORTED = 1;

    printf("\n");

}


void remove_data(Database *database) {

    char *name = malloc(20 * sizeof(char));
    printf("Enter name: ");
    if (fgets(user_line, 20, stdin) != NULL) {
        sscanf(user_line, "%[^\n]", name);
    }

    Student *temp;
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


void close_db(Database *database) {

    Student *temp;
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

    Database *database = list_new();
//    init_db(database);
    int choice;
    int loop_flag = 1;


    FILE *fp;
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
    return EXIT_SUCCESS;

}
