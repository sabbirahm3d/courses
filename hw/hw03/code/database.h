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

#define MAXSTUDENTNAME 50
#define MAXASSNNAME 20
#define MAXINTINPUT 5
#define STUDENTSINFILE 2


// -------------------------- STRUCTS --------------------------

// student_t struct
typedef struct student_node {

    struct student_node *prev;
    struct student_node *next;  // pointer to next
    char *name;  // student name
    float final_grade;  // student final grade
    list_of_grades_t *list_of_grades;  // list_of_grades_t linked list

} student_t;

// database_t struct
typedef struct {

    student_t *head;
    student_t *tail;
    size_t len;

} database_t;

// db_iter-t struct
typedef struct {

    student_t *next;

} db_iter_t;


// -------------------------- FUNCTION PROTOTYPES --------------------------

student_t *new_student(char **, list_of_grades_t *, float);

database_t *db_init();

db_iter_t *db_iter_init(database_t *);

student_t *db_iter_next(db_iter_t *);

void db_push(database_t *, student_t *);

void db_remove(database_t *, student_t *);

void db_destory(database_t *);

void swap_students(student_t *, student_t *);

void slice_str(const char *, char *, size_t, size_t);

int cmp_last_name(char *, char *);

void db_sort(database_t *);

#endif /* DATABASE_H */
