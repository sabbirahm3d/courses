//
// Created by sabbir on 11/9/17.
//

#ifndef CODE_GRADE_T_H
#define CODE_GRADE_T_H


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
enum assn_type {QUIZ, TEST};


// grade_t struct
typedef struct Grade {

    // type of assignment: 0 for quiz, 1 for test. Used to keep track of the
    // current node type
    enum assn_type assn_t;
    struct Grade *next;  // pointer to next
    struct Grade *prev;

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

} List_of_Grades;


// list_of_grades iterator struct
typedef struct {

    grade_t *next;

} list_of_grades_it_t;



#endif //CODE_GRADE_T_H
