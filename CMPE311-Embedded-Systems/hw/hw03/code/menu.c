/*
 * menu.c
 *
 * This file contains the implemention of the functions used to provide high
 * level interfaces to the data structures in the project.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "menu.h"

// main menu string
const char menu_main_str[] = "---------- MAIN MENU ----------\n1. Print "
        "Database\n2. Search by Name\n3. Search by Grade\n4. Add Student\n5. "
        "Remove Student\n0. Exit\nChoose: ";

// strings used as placeholders to set the limits to the sizes of user inputs
char user_line_student_name[MAXSTUDENTNAME];
char user_line_grade_name[MAXASSNNAME];
char user_grade[MAXINTINPUT];
char user_choice[MAXINTINPUT];

// flag for sorting the database
// the database is sorted only when this flag is set to true
int UNSORTED = 1;


/*
 * Dumps the database of students and their grade reports, sorted
 * alphabetically by their last names.
 *
 * inputs:
 *      self: pointer to the initialized list_of_grades_t
 *
 * output:
 *      computed final grade of student
 */
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


void remove_cr(char *str) {

    char *pr = str, *pw = str;
    while (*pr) {
        *pw = *pr++;
        pw += (*pw != '\r');
    }
    *pw = '\0';

}


/*
 * Displays the main menu to the user and prompts for their input. The
 * function then returns the user's input to be treated as their choice from
 * the main menu prompt.
 *
 * input:
 *      none
 *
 * output:
 *      user choice
 */
int display_menu() {

    // holds user input
    int choice = 0;

    printf("%s", menu_main_str);

    // prompt user for choice
    if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
        sscanf(user_choice, "%d", &choice);
    }

    return choice;

}

/*
 * Converts the final grade of a student to its corresponding letter grade
 *
 * input:
 *      final_grade: computed final grade of the student as float
 *
 * output:
 *      letter grade representation of the grade
 */
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


/*
 * Dumps the database of students and their grade reports, sorted
 * alphabetically by their last names.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void print_db(database_t *self) {

    printf("---------- Database ----------\n\n");

    // if database is not empty
    if (self->len) {

        // if database is unsorted, sort it before printing to console
        if (UNSORTED) {
            db_sort(self);
            UNSORTED = 0;
        }

        // temporary variables
        student_t *temp;
        db_iter_t *it = db_iter_init(self);

        // iterate through the database
        while ((temp = db_iter_next(it))) {

            // print student's name
            printf("Student: %s %s | ", temp->first_name, temp->last_name);

            // temporary variables
            grade_t *temp_grade;
            list_of_grades_iter_t *grades_it = list_of_grades_iter_init(
                    temp->list_of_grades);

            // iterate through the list of grades
            while ((temp_grade = list_of_grades_iter_next(grades_it))) {

                if (!temp_grade->assn_t) {

                    printf("%s %.2f%% | ", temp_grade->quiz.name,
                           temp_grade->quiz.grade);

                } else {

                    printf("%s %.2f%% | ", temp_grade->test.name,
                           temp_grade->test.grade);

                }

            }

            printf("Final grade: %.2f%% (%c)\n", temp->final_grade,
                   *get_letter_grade(temp->final_grade));

            free(grades_it);
            free(temp_grade);

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


/*
 * Searches the database with the user-provided last names of students.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void search_name(database_t *self) {

    int loop_flag = 1;

    while (loop_flag) {

        char *name_to_search = malloc(MAXSTUDENTNAME * sizeof(char));
        int found = 0;

        // get last name to search
        printf("---------- Search by Name ----------\nEnter name: ");
        if (fgets(user_line_student_name, MAXSTUDENTNAME, stdin) != NULL) {
            sscanf(user_line_student_name, "%[^\n]", name_to_search);
        }

        // temporary variables
        student_t *temp;
        db_iter_t *it = db_iter_init(self);

        // iterate through the database
        while ((temp = db_iter_next(it))) {

            list_of_grades_iter_t *grades_it = list_of_grades_iter_init(
                    temp->list_of_grades);

            // if user input matches the last name of a student
            if (!strcasecmp(temp->last_name, name_to_search)) {
                printf("Found student: %s %s\n", temp->first_name,
                       temp->last_name);
                printf("Student grade: %.2f%% (%c)", temp->final_grade,
                       *get_letter_grade(temp->final_grade));
                found = 1;
            }

            // free variables
            if (grades_it) {
                free(grades_it);
                grades_it = NULL;
            }

        }

        // if student was not found
        if (!found) {
            printf("Student: %s is not in database", name_to_search);
        }
        printf("\n");


        printf("Search more students? (0/1): ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }

        // free variables
        free(name_to_search);
        name_to_search = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;

    }

}


/*
 * Searches the database with the user-provided letter grades.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void search_by_grade(database_t *self) {

    int loop_flag = 1;

    while (loop_flag) {

        char *letter_grade = malloc(1 * sizeof(char));
        int found = 0;

        // get letter grade to search
        printf("---------- Search by Grade ----------\nEnter grade: ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%c", letter_grade);
        }

        // temporary variables
        student_t *temp;
        db_iter_t *it = db_iter_init(self);

        // iterate through the database
        while ((temp = db_iter_next(it))) {

            // if user input matches the letter grade of a student
            if (*get_letter_grade(temp->final_grade) == *letter_grade) {

                printf("Found student: %s %s\n", temp->first_name,
                       temp->last_name);
                printf("Student data: %.2f\n", temp->final_grade);
                found = 1;

            }

        }

        // if letter grade was not found
        if (!found) {
            printf("No students with a final_grade of %c in database",
                   *letter_grade);
        }
        printf("\n");

        printf("Search more students? (0/1): ");
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }

        // free variables
        free(letter_grade);
        letter_grade = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;
    }

}


/*
 * Add students to the database.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void add_data(database_t *self) {

    int loop_flag = 1;

    while (loop_flag) {

        char *first_name = malloc(MAXSTUDENTNAME / 2 * sizeof(char));
        char *last_name = malloc(MAXSTUDENTNAME / 2 * sizeof(char));
        list_of_grades_t *list_of_grades = list_of_grades_init();

        int inner_loop_flag = 1;

        printf("---------- Add Students ----------\n");

        printf("Enter name: ");
        if (fgets(user_line_student_name, MAXSTUDENTNAME, stdin) != NULL) {
            sscanf(user_line_student_name, "%s %[^\n]", first_name, last_name);
        }

        while (inner_loop_flag) {

            char *assn_name = malloc(MAXASSNNAME * sizeof(char));
            unsigned int assn_type;
            float grade, weight;

            // prompt user for assignment type
            printf("Enter type of assignment.\n0 = quiz, 1 = test: ");
            if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_choice, "%d", &assn_type);
            }

            // prompt user for assignment name
            if (!assn_type) {

                printf("Enter quiz name: ");

            } else {

                printf("Enter test name: ");

            }
            if (fgets(user_line_grade_name, MAXASSNNAME, stdin) != NULL) {
                sscanf(user_line_grade_name, "%[^\n]", assn_name);
            }

            // prompt user for assignment grade
            printf("Enter grade: ");
            if (fgets(user_grade, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_grade, "%f", &grade);
            }

            // prompt user for assignment weight
            printf("Enter weight: ");
            if (fgets(user_grade, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_grade, "%f", &weight);
            }

            // initialize a grade_t node with user inputted data and push to
            // the list_of_grades_t list
            list_of_grades_push(list_of_grades,
                                new_grade(assn_type, &assn_name, grade, weight));

            printf("Assignment: %s added to student.\n"
                           "Add more assignments? (0/1): ", assn_name);
            if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
                sscanf(user_choice, "%d", &inner_loop_flag);
            }

        }

        // push student name, their list_of_grades_t list and their computed
        // final grade to the database
        db_push(self, new_student(&first_name, &last_name, list_of_grades,
                                  calculate_grade
                                          (list_of_grades)));

        printf("Student: %s added to database.\nAdd more students? (0/1): ",
               first_name);
        if (fgets(user_choice, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_choice, "%d", &loop_flag);
        }
        printf("\n");

    }

    UNSORTED = 1;

}


/*
 * Remove students from the database.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void remove_data(database_t *self) {

    int loop_flag = 1;

    while (loop_flag) {

        int found = 0;

        char *name_to_remove = malloc(MAXSTUDENTNAME * sizeof(char));

        // prompt user for student last name
        printf("---------- Remove Students ----------\nEnter last name: ");
        if (fgets(user_line_student_name, MAXSTUDENTNAME, stdin) != NULL) {
            sscanf(user_line_student_name, "%[^\n]", name_to_remove);
        }

        // temporary variables
        student_t *temp;
        db_iter_t *it = db_iter_init(self);

        // iterate through the database
        while ((temp = db_iter_next(it))) {

            // if user input matches the last name of a student
            if (!strcasecmp(temp->last_name, name_to_remove)) {
                printf("Removing student: %s %s ... ", temp->first_name,
                       temp->last_name);
                db_remove(self, temp);
                printf("Removed.");
                found = 1;
            }
        }

        if (!found) {
            printf("Student: %s is not in database", name_to_remove);
        }
        printf("\n");

        printf("\nRemove more students? (0/1): ");
        if (fgets(user_grade, MAXINTINPUT, stdin) != NULL) {
            sscanf(user_grade, "%d", &loop_flag);
        }

        // free variables
        free(name_to_remove);
        name_to_remove = NULL;
        free(temp);
        temp = NULL;
        free(it);
        it = NULL;

    }

}


/*
 * Calls the database_t destructor and frees all dynamically allocated variables
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void close_db(database_t *database) {

    // temporary variables
    student_t *temp;
    db_iter_t *it = db_iter_init(database);

    // iterate through the database
    while ((temp = db_iter_next(it))) {

        // free each name strings
        free(temp->first_name);
        temp->first_name = NULL;
        free(temp->last_name);
        temp->last_name = NULL;

        // invoke the list_of_grades_t destructor on all nodes
        destroy_list_of_grades(temp->list_of_grades);

    }

    // free temporary variables and call database_t destructor
    free(temp);
    temp = NULL;
    free(it);
    it = NULL;
    db_destory(database);

}


/*
 * Reads in the provide input file and initializes the database by populating
 * its data.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *      file_path: path to input file
 *
 * output:
 *      success status
 */
int init_db(database_t *self, char *file_path) {

    FILE *file_ptr = fopen(file_path, "r");

    if (file_ptr) {

        // get the buffer size
        fseek(file_ptr, 0, SEEK_END); // go to end of file
        size_t size = ftell(file_ptr); // get the size in bytes

        // set position of stream to the beginning
        rewind(file_ptr);

        // allocate the buffer with the size of the file + 1 for the NULL
        // terminator
        char *buffer = malloc((size + 1) * sizeof(char));

        // read the file into the buffer
        fread(buffer, size, 1, file_ptr);

        // NULL terminate the buffer
        buffer[size] = '\0';

        int student_id = 0;

        // allocate an array of strings to store student information read
        // from the input file
        char **students = malloc(STUDENTSINFILE * sizeof(char *));

        // allocate each string with sufficient space
        for (int i = 0; i < STUDENTSINFILE; i++) {
            students[i] = malloc(
                    (size / STUDENTSINFILE + MAXSTUDENTNAME)
                            * sizeof(*students[i])
            );
        }

        // tokenize the buffer at every newline character
        char *file_buf_tokens = strtok(buffer, "\n");

        while (file_buf_tokens != NULL) {

            // remove all instances of carriage return characters
            remove_cr(file_buf_tokens);

            if (strlen(file_buf_tokens) > 1) {

                // replace the last character with a newline
                students[student_id][strlen(students[student_id])] = '\n';
                // concatenate each line of the file to a unique index
                strcat(students[student_id], file_buf_tokens);

            } else {
                student_id++;
            }

            file_buf_tokens = strtok(NULL, "\n");

        }

        int not_student_name = 0;

        for (int i = 0; i < STUDENTSINFILE; i++) {

            // tokenize each students string
            char *student_tokens = strtok(students[i], "\n");

            // allocate 25 characters for first and last names
            char *first_name = malloc(MAXSTUDENTNAME / 2 * sizeof(char));
            char *last_name = malloc(MAXSTUDENTNAME / 2 * sizeof(char));

            list_of_grades_t *list_of_grades = list_of_grades_init();

            while (student_tokens != NULL) {

                // if the indexer is at the student_name index
                if (!not_student_name) {

                    sscanf(student_tokens, "%s %[^\n]", first_name, last_name);

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

                // increment indexer
                not_student_name++;

            }

            db_push(self, new_student(&first_name, &last_name, list_of_grades,
                                      calculate_grade(list_of_grades)));

            not_student_name = 0;

        }

        // free variables
        if (buffer) {
            free(buffer);
            buffer = NULL;
        }

        for (int i = 0; i < STUDENTSINFILE; i++) {
            free(students[i]);
            students[i] = NULL;
        }
        free(students);

        fclose(file_ptr);

        return EXIT_SUCCESS;

    }

    return EXIT_FAILURE;

}
