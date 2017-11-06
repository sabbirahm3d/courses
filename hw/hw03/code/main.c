
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

const char menu_main_str[] = "---------- MAIN MENU ----------\n1. Print "
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
//    db_push(database, new_student(&name, list_of_grades));
//
//}

char *get_letter_grade(float final_grade) {

    if (90.0 <= final_grade) {

        return "A";

    } else if ((80.0 <= final_grade) && (final_grade < 90.0)) {

        return "B";

    } else if ((70.0 <= final_grade) && (final_grade < 80.0)) {

        return "C";

    } else if ((60.0 <= final_grade) && (final_grade < 70.0)) {

        return "D";

    } else {

        return "F";

    }


}


void print_db(Database *database) {

    printf("---------- Database ----------\n\n");
    if (database->len) {

        if (UNSORTED) {
            sort_students(database);
            UNSORTED = 0;
        }

        Student *temp;
        list_iterator_t *it = list_iterator_new(database);

//        while ((temp = database->head->next)) {
        while ((temp = list_iterator_next(it))) {

            printf("Student: %s | ", temp->name);

            grade_t *temp1;
            list_of_grades_it_t *grades_it = list_of_grades_iterator_new(temp->list_of_grades);

            while ((temp1 = list_of_grades_iterator_next(grades_it))) {

                if (!temp1->assn_t) {

                    printf("%s %.2f%% | ", temp1->quiz.name, temp1->quiz.grade);

                } else {

                    printf("%s %.2f%% | ", temp1->test.name, temp1->test.grade);

                }

            }

            printf("Final grade: %.2f%% (%c)", temp->final_grade,
                   *get_letter_grade(temp->final_grade));

            printf("\n\n");

            free(grades_it);
            free(temp1);

        }

        free(temp);
        list_iterator_destroy(it);

    } else {

        printf("Database is empty!\n");

    }

    printf("\n");

}


float calculate_grade(List_of_Grades *list_of_grades) {

    grade_t *temp;
    list_of_grades_it_t *grades_it = list_of_grades_iterator_new(list_of_grades);
    float final_grade = 0.0;

    while ((temp = list_of_grades_iterator_next(grades_it))) {

        if (!temp->assn_t) {
            final_grade += (temp->quiz.grade * temp->quiz.weight / 100);
        } else {
            final_grade += (temp->test.grade * temp->test.weight / 100);
        }

    }

    free(grades_it);
    free(temp);

    return final_grade;

}


void search_name(Database *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name = malloc(20 * sizeof(char));
        int found = 0;

        printf("---------- Search by Name ----------\nEnter name: ");
        if (fgets(user_line, 20, stdin) != NULL) {
            sscanf(user_line, "%[^\n]", name);
        }

        Student *temp;
        list_iterator_t *it = list_iterator_new(database);

        while ((temp = list_iterator_next(it))) {

            grade_t *temp1;
            list_of_grades_it_t *grades_it = list_of_grades_iterator_new(temp->list_of_grades);

            while ((temp1 = list_of_grades_iterator_next(grades_it))) {

                if (!strcasecmp(temp->name, name)) {
                    printf("Found student: %s\n", temp->name);
//                printf("Student data: %.2f%%\n", temp->list_of_grades);
                    found = 1;
                }
            }

            if (grades_it) {
                free(grades_it);
            }

            if (temp1) {
                free(temp1);
            }

        }

        if (!found) {
            printf("Student: %s is not in database", name);
        }
        printf("\n");

        printf("Search more students? (0/1): ");
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        free(name);
        free(temp);
        list_iterator_destroy(it);

    }

}


void search_by_grade(Database *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *letter_grade = malloc(sizeof(char));
        int found = 0;

        printf("---------- Search by Grade ----------\nEnter grade: ");
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%c", letter_grade);
        }

        Student *temp;
        list_iterator_t *it = list_iterator_new(database);

        while ((temp = list_iterator_next(it))) {

            if (!strcasecmp(get_letter_grade(temp->final_grade), letter_grade)) {

                printf("Found student: %s\n", temp->name);
                printf("Student data: %.2f\n", temp->final_grade);
                found = 1;

            }

        }

        if (!found) {
            printf("No students with a final_grade of %c in database",
                   letter_grade);
        }
        printf("\n");

        printf("Search more students? (0/1): ");
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        free(letter_grade);
        free(temp);
        list_iterator_destroy(it);
    }

}


void add_data(Database *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name = malloc(20 * sizeof(char));
        List_of_Grades *list_of_grades = list_of_grades_init();

        int inner_loop_flag = 1;

        printf("---------- Add Students ----------\n");

        printf("Enter name: ");
        if (fgets(user_line, 20, stdin) != NULL) {
            sscanf(user_line, "%[^\n]", name);
        }

        while (inner_loop_flag) {

            char *assn_name = malloc(20 * sizeof(char));
            unsigned int assn_type;
            float grade, weight;

            // prompt user for list_of_grades
            printf("Enter type of assignment.\n0 = quiz, 1 = test: ");
            if (fgets(user_grade, 5, stdin) != NULL) {
                sscanf(user_grade, "%d", &assn_type);
            }

            if (!assn_type) {

                printf("Enter quiz name: ");

            } else {

                printf("Enter test name: ");

            }

            if (fgets(user_line, 20, stdin) != NULL) {
                sscanf(user_line, "%[^\n]", assn_name);
            }

            printf("Enter grade: ");
            if (fgets(user_line, 20, stdin) != NULL) {
                sscanf(user_line, "%f", &grade);
            }

            printf("Enter weight: ");
            if (fgets(user_line, 20, stdin) != NULL) {
                sscanf(user_line, "%f", &weight);
            }

            assn_push(list_of_grades,
                      new_assn(assn_type, &assn_name, grade, weight));

            printf("Assignment: %s added to student.\n"
                           "Add more assignments? (0/1): ", assn_name);
            if (fgets(user_grade, 5, stdin) != NULL) {
                sscanf(user_grade, "%d", &inner_loop_flag);
            }

        }

        db_push(database, new_student(&name, list_of_grades, calculate_grade
                (list_of_grades)));
        printf("Student: %s added to database.\nAdd more students? (0/1): ",
               name);
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        printf("\n");

    }

    UNSORTED = 1;

}


void remove_data(Database *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name = malloc(20 * sizeof(char));
        printf("---------- Remove Students ----------\nEnter name: ");
        if (fgets(user_line, 20, stdin) != NULL) {
            sscanf(user_line, "%[^\n]", name);
        }

        Student *temp;
        list_iterator_t *it = list_iterator_new(database);

        while ((temp = list_iterator_next(it))) {
            if (!strcasecmp(temp->name, name)) {
                printf("Removing: %s\n", temp->name);
                db_remove(database, temp);
            }
        }

        printf("\nRemove more students? (0/1): ");
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        free(name);
        free(temp);
        list_iterator_destroy(it);

    }

}


void close_db(Database *database) {

    Student *temp;
    list_iterator_t *it = list_iterator_new(database);

    while ((temp = list_iterator_next(it))) {
        free(temp->name);
        destroy_list_of_grades(temp->list_of_grades);
    }

    if (temp) {
        free(temp);
    }

    list_iterator_destroy(it);
    destroy_db(database);

}


void remove_all_chars(char *str, char c) {
    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != c);
    }
    *pw = '\n';
}

void init_db(Database *database, FILE *fp, char **students) {

    /* Get the buffer size */
    fseek(fp, 0, SEEK_END); /* Go to end of file */
    size_t size = ftell(fp); /* How many bytes did we pass ? */

    /* Set position of stream to the beginning */
    rewind(fp);

    /* Allocate the buffer */
    char *buffer = malloc((size + 1) * sizeof(char));

    /* Read the file into the buffer */
    fread(buffer, size, 1, fp); /* Read 1 chunk of size bytes from fp into buffer */

    /* NULL-terminate the buffer */
    buffer[size] = '\0';

    int student_id = 0;
    for (int i = 0; i < 2; i++) {
        students[i] = malloc((size / 2 + 20) * sizeof(char));
    }

    // copy the const string main menu prompt to be tokenized
    char *file_buf_tokens = strtok(buffer, "\n");

    while (file_buf_tokens) {

        remove_all_chars(file_buf_tokens, '\r');
        if (strlen(file_buf_tokens) != 1) {
            strcat(students[student_id], file_buf_tokens);
        } else {
            student_id++;
        }

        file_buf_tokens = strtok(NULL, "\n");

    }

    char *student_tokens = NULL;
    int index = 0;

    for (int i = 0; i < 2; i++) {

        student_tokens = strtok(students[i], "\n");
        char *name = malloc(20 * sizeof(char));
        List_of_Grades *list_of_grades = list_of_grades_init();

        while (student_tokens) {

            if (!index) {

                name = student_tokens;

            } else {

                char *assn_name = malloc(20 * sizeof(char));
                float grade, weight;

                sscanf(
                        student_tokens, "%[^:]: %f %f\n",
                        assn_name, &grade, &weight
                );
                assn_push(
                        list_of_grades,
                        new_assn(1, &assn_name, grade, weight)
                );

            }

            student_tokens = strtok(NULL, "\n");
            index++;

        }
        db_push(database,
                new_student(&name, list_of_grades,
                            calculate_grade(list_of_grades)));

        index = 0;

    }


    free(file_buf_tokens);
    free(student_tokens);

    if (strlen(buffer)) {
        free(buffer);
        buffer = NULL;
    }

    fclose(fp);


}


int main(int argc, char **argv) {

    if (argc > 1) {

        Database *database = db_init();
        int choice;
        int loop_flag = 1;

        FILE *fp = fopen(argv[1], "r");

        if (!fp) {
            return EXIT_FAILURE;
        }


        char **students = malloc(2 * sizeof(char *));


        init_db(database, fp, students);


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
                    for (int i = 0; i < 2; i++) {
                        students[i] = NULL;
//                        printf("%s\n", students[i]);
//                        if (strlen(students[i])) {
//                            free(students[i]);
//                        }
                    }
                    free(students);
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

    } else {

        return EXIT_FAILURE;

    }

}
