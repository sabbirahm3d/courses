/*
 * list_of_grades.h
 *
 * This file contains the prototypes for the functions and declarations of
 * structs used for the list_of_grades linked lists.
 *
 * */

#ifndef DATABASE_H
#define DATABASE_H

#include "list_of_grades.h"

/*
 * database_t student_t struct.
 *
 */


typedef struct student_node {

    struct student_node *prev;
    struct student_node *next;
    char *name;
    float final_grade;
    list_of_grades_t *list_of_grades;

} student_t;


typedef struct {

    student_t *head;
    student_t *tail;
    size_t len;

//    void (*free)(void *val);

} database_t;

/*
 * database_t iterator struct.
 */

typedef struct {

    student_t *next;

} db_iter_t;


// Node prototypes.

student_t *new_student(char **, list_of_grades_t *, float);

// -------------------------- FUNCTIONS --------------------------

void swap_students(student_t *, student_t *);

database_t *db_init();

void db_push(database_t *, student_t *);

void slice_str(const char *, char *, size_t, size_t);

int cmp_last_name(char *, char *);

void db_sort(database_t *);

void db_remove(database_t *, student_t *);

void db_destory(database_t *);

// database_t iterator prototypes.

db_iter_t *db_iter_init(database_t *);

student_t *db_iter_next(db_iter_t *);

#endif /* DATABASE_H */