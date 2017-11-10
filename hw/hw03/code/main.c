
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "database.h"

const char menu_main_str[] = "---------- MAIN MENU ----------\n1. Print "
        "Database\n2. Search by Name\n3. Search by Grade\n4. Add Student\n5. "
        "Remove Student\n0. Exit\nChoose: ";
char user_line_student_name[MAXSTUDENTNAME];
char user_line_grade_name[MAXASSNNAME];
char user_grade[MAXINTINPUT];
char user_choice[MAXINTINPUT];

int UNSORTED = 1;  // flag for sorting the database

// ------------------ Helper function declarations ------------------

int display_menu();

char *get_letter_grade(float);

void print_db(database_t *);

float calculate_grade(list_of_grades_t *);

void search_name(database_t *);

void search_by_grade(database_t *);

void add_data(database_t *);

void remove_data(database_t *);

void close_db(database_t *);

void remove_cr(char *);

int init_db(database_t *, char *);


/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt.
 * */
int display_menu() {

    // holds user input
    int choice = 0;

    printf("%s", menu_main_str);

    // prompt user for choice
    if (fgets(user_line_student_name, 3, stdin) != NULL) {
        sscanf(user_line_student_name, "%d", &choice);
    }

    return choice;

}

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


void print_db(database_t *database) {

    printf("---------- Database ----------\n\n");
    if (database->len) {

        if (UNSORTED) {
            db_sort(database);
            UNSORTED = 0;
        }

        student_t *temp;
        db_iter_t *it = db_iter_init(database);

//        while ((temp = database->head->next)) {
        while ((temp = db_iter_next(it))) {

            printf("Student: %s | ", temp->name);

            grade_t *temp1;
            list_of_grades_iter_t *grades_it = list_of_grades_iter_init(
                    temp->list_of_grades);

            while ((temp1 = list_of_grades_iter_next(grades_it))) {

                if (!temp1->assn_t) {

                    printf("%s %.2f%% | ", temp1->quiz.name, temp1->quiz.grade);

                } else {

                    printf("%s %.2f%% | ", temp1->test.name, temp1->test.grade);

                }

            }

            printf("Final grade: %.2f%% (%c)", temp->final_grade,
                   *get_letter_grade(temp->final_grade));

            printf("\n");

            free(grades_it);
            free(temp1);

        }

        free(temp);
        temp = NULL;
        free(it);
        it = NULL;

    } else {

        printf("Database is empty!\n");

    }

    printf("\n");

}


float calculate_grade(list_of_grades_t *list_of_grades) {

    grade_t *temp;
    list_of_grades_iter_t *grades_it = list_of_grades_iter_init(list_of_grades);
    float final_grade = 0.0;

    while ((temp = list_of_grades_iter_next(grades_it))) {

        if (!temp->assn_t) {
            final_grade += (temp->quiz.grade * temp->quiz.weight / 100);
        } else {
            final_grade += (temp->test.grade * temp->test.weight / 100);
        }

    }

    free(grades_it);
    grades_it = NULL;
    free(temp);
    temp = NULL;

    return final_grade;

}


void search_name(database_t *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name_to_search = malloc(20 * sizeof(char));
        int found = 0;

        printf("---------- Search by Name ----------\nEnter name: ");
        if (fgets(user_line_student_name, MAXSTUDENTNAME, stdin) != NULL) {
            sscanf(user_line_student_name, "%[^\n]", name_to_search);
        }

        student_t *temp;
        db_iter_t *it = db_iter_init(database);

        while ((temp = db_iter_next(it))) {

            list_of_grades_iter_t *grades_it = list_of_grades_iter_init(temp->list_of_grades);

            if (!strcasecmp(temp->name, name_to_search)) {
                printf("Found student: %s\n", temp->name);
                printf("Student grade: %.2f%% (%c)", temp->final_grade,
                       *get_letter_grade(temp->final_grade));
                found = 1;
            }

            if (grades_it) {
                free(grades_it);
            }

        }

        if (!found) {
            printf("Student: %s is not in database", name_to_search);
        }
        printf("\n");

        printf("Search more students? (0/1): ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }

        free(name_to_search);
        name_to_search = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;

    }

}


void search_by_grade(database_t *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *letter_grade = malloc(sizeof(char));
        int found = 0;

        printf("---------- Search by Grade ----------\nEnter grade: ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%c", letter_grade);
        }

        student_t *temp;
        db_iter_t *it = db_iter_init(database);

        while ((temp = db_iter_next(it))) {

            if (*get_letter_grade(temp->final_grade) == *letter_grade) {

                printf("Found student: %s\n", temp->name);
                printf("Student data: %.2f\n", temp->final_grade);
                found = 1;

            }

        }

        if (!found) {
            printf("No students with a final_grade of %c in database",
                   *letter_grade);
        }
        printf("\n");

        printf("Search more students? (0/1): ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }

        free(letter_grade);
        letter_grade = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;
    }

}


void add_data(database_t *database) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name = malloc(MAXSTUDENTNAME * sizeof(char));
        list_of_grades_t *list_of_grades = list_of_grades_init();

        int inner_loop_flag = 1;

        printf("---------- Add Students ----------\n");

        printf("Enter name: ");
        if (fgets(user_line_student_name, MAXSTUDENTNAME, stdin) != NULL) {
            sscanf(user_line_student_name, "%[^\n]", name);
        }

        while (inner_loop_flag) {

            char *assn_name = malloc(MAXASSNNAME * sizeof(char));
            unsigned int assn_type;
            float grade, weight;

            // prompt user for list_of_grades
            printf("Enter type of assignment.\n0 = quiz, 1 = test: ");
            if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_choice, "%d", &assn_type);
            }

            if (!assn_type) {

                printf("Enter quiz name: ");

            } else {

                printf("Enter test name: ");

            }

            if (fgets(user_line_student_name, MAXASSNNAME, stdin) != NULL) {
                sscanf(user_line_student_name, "%[^\n]", assn_name);
            }

            printf("Enter grade: ");
            if (fgets(user_grade, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_grade, "%f", &grade);
            }

            printf("Enter weight: ");
            if (fgets(user_grade, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_grade, "%f", &weight);
            }

            list_of_grades_push(list_of_grades,
                                new_grade(assn_type, &assn_name, grade, weight));

            printf("Assignment: %s added to student.\n"
                           "Add more assignments? (0/1): ", assn_name);
            if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_choice, "%d", &inner_loop_flag);
            }

        }

        db_push(database, new_student(&name, list_of_grades, calculate_grade
                (list_of_grades)));
        printf("Student: %s added to database.\nAdd more students? (0/1): ",
               name);
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }

        printf("\n");

    }

    UNSORTED = 1;

}


void remove_data(database_t *database) {

    int loop_flag = 1;

    while (loop_flag) {

        int found = 0;

        char *name_to_remove = malloc(20 * sizeof(char));
        printf("---------- Remove Students ----------\nEnter name: ");
        if (fgets(user_line_student_name, 20, stdin) != NULL) {
            sscanf(user_line_student_name, "%[^\n]", name_to_remove);
        }

        student_t *temp;
        db_iter_t *it = db_iter_init(database);

        while ((temp = db_iter_next(it))) {
            if (!strcasecmp(temp->name, name_to_remove)) {
                db_remove(database, temp);
                printf("Student: %s removed.", name_to_remove);
                found = 1;
            }
        }

        if (!found) {
            printf("Student: %s is not in database", name_to_remove);
        }
        printf("\n");

        printf("\nRemove more students? (0/1): ");
        if (fgets(user_grade, 5, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        free(name_to_remove);
        name_to_remove = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;

    }

}


void close_db(database_t *database) {

    student_t *temp;
    db_iter_t *it = db_iter_init(database);

    while ((temp = db_iter_next(it))) {
        free(temp->name);
        temp->name = NULL;
        destroy_list_of_grades(temp->list_of_grades);
    }

    free(temp);
    temp = NULL;
    free(it);
    it = NULL;
    db_destory(database);

}


void remove_cr(char *str) {

    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != '\r');
    }
    *pw = '\0';

}

int init_db(database_t *database, char *file_path) {

    FILE *fp = fopen(file_path, "r");

    if (fp) {

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
        char **students = malloc(STUDENTSINFILE * sizeof(char *));

        for (int i = 0; i < STUDENTSINFILE; i++) {
            students[i] = malloc(
                    (size / STUDENTSINFILE + MAXSTUDENTNAME)
                            * sizeof(*students[i])
            );
        }

        // copy the const string main menu prompt to be tokenized
        char *file_buf_tokens = strtok(buffer, "\n");

        while (file_buf_tokens != NULL) {

            remove_cr(file_buf_tokens);

            if (strlen(file_buf_tokens) > 1) {

                students[student_id][strlen(students[student_id])] = '\n';
                strcat(students[student_id], file_buf_tokens);

            } else {
                student_id++;
            }

            file_buf_tokens = strtok(NULL, "\n");

        }

        int index = 0;

        for (int i = 0; i < STUDENTSINFILE; i++) {

            char *student_tokens = strtok(students[i], "\n");
            char *name = malloc(MAXSTUDENTNAME * sizeof(char));
            list_of_grades_t *list_of_grades = list_of_grades_init();

            while (student_tokens != NULL) {

                if (!index) {

                    sscanf(student_tokens, "%[^\n]", name);

                } else {

                    char *assn_name = malloc(MAXASSNNAME * sizeof(char));
                    float grade, weight;

                    sscanf(
                            student_tokens, "%[^:]: %f %f\n",
                            assn_name, &grade, &weight
                    );
                    list_of_grades_push(
                            list_of_grades,
                            new_grade(1, &assn_name, grade, weight)
                    );

                }

                student_tokens = strtok(NULL, "\n");
                index++;

            }
            db_push(
                    database,
                    new_student(
                            &name,
                            list_of_grades,
                            calculate_grade(list_of_grades)
                    )
            );

            index = 0;

        }

        if (buffer) {
            free(buffer);
            buffer = NULL;
        }

        for (int i = 0; i < STUDENTSINFILE; i++) {
            free(students[i]);
            students[i] = NULL;
        }
        free(students);

        fclose(fp);

        return EXIT_SUCCESS;

    }

    return EXIT_FAILURE;


}


int main(int argc, char **argv) {

    if (argc > 1) {

        database_t *database = db_init();
        int menu_choice;
        int loop_flag = 1;

        init_db(database, argv[1]);

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
