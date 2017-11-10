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
 * Database Student struct.
 *
 */


typedef struct student_node {

    struct student_node *prev;
    struct student_node *next;
    char *name;
    float final_grade;
    List_of_Grades *list_of_grades;

} Student;


typedef struct {

    Student *head;
    Student *tail;
    size_t len;

//    void (*free)(void *val);

} Database;

/*
 * Database iterator struct.
 */

typedef struct {

    Student *next;

} list_iterator_t;


// Node prototypes.

Student *new_student(char **, List_of_Grades *, float);

// -------------------------- FUNCTIONS --------------------------
void bubbleSort(Database *);
void swap(Student *a, Student *b);

Database *db_init();

Student *db_push(Database *, Student *);

void slice_str(const char *, char *, size_t, size_t);

int cmp_last_name(char *, char *);

void sort_students(Database *);

void db_remove(Database *, Student *);

void destroy_db(Database *);

// Database iterator prototypes.

list_iterator_t *list_iterator_new(Database *);

Student *list_iterator_next(list_iterator_t *);

void list_iterator_destroy(list_iterator_t *);

#endif /* DATABASE_H */