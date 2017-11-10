/*
 * list_of_grades.h
 *
 * This file contains the prototypes for the functions and declarations of
 * structs used for the list_of_grades linked lists.
 *
 * */

#ifndef LIST_OF_GRADES_H
#define LIST_OF_GRADES_H


// -------------------------- STRUCTS --------------------------

// quiz_t struct
typedef struct {

    char *name;  // quiz name
    float grade;  // quiz grade
    float weight;  // quiz weight

} quiz_t;


// test_t struct
typedef struct {

    char *name;  // test name
    float grade;  // test grade
    float weight;  // test weight

} test_t;


// indicates the type of data stored in the grade_t union
enum grade_enum {QUIZ, TEST};


// grade_t struct
typedef struct grade_node {

    // type of assignment: 0 for quiz, 1 for test. Used to keep track of the
    // current node type
    enum grade_enum assn_t;
    struct grade_node *next;  // pointer to next
    struct grade_node *prev;

    // union quiz_t and test_t
    union {
        quiz_t quiz;
        test_t test;
    };

} grade_t;


// list_of_grades linked list struct
typedef struct list_of_grades {

    grade_t *head;
    grade_t *tail;
    size_t len;

} list_of_grades_t;


// list_of_grades iterator struct
typedef struct {

    grade_t *next;

} list_of_grades_iter_t;


// -------------------------- FUNCTION PROTOTYPES --------------------------

grade_t *new_grade(unsigned int, char **, float, float);

list_of_grades_t *list_of_grades_init();

list_of_grades_iter_t *list_of_grades_iter_init(list_of_grades_t *);

grade_t *list_of_grades_iter_next(list_of_grades_iter_t *);

void list_of_grades_push(list_of_grades_t *, grade_t *);

void destroy_list_of_grades(list_of_grades_t *);

#endif // LIST_OF_GRADES_H
