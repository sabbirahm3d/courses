
//
// list.h
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef DATABASE_H
#define DATABASE_H


typedef union Grade grade_t;
/*
 * Database Student struct.
 */

typedef struct quiz_node {

    char *name;
    char *grade;
    int weight;
    grade_t *list_of_grades;

} quiz_t;

typedef struct test_node {

    char *name;
    char *grade;
    int weight;
    grade_t *list_of_grades;

} test_t;

union Grade {
    quiz_t quiz;
    test_t test;
};


typedef struct student_node {

    struct student_node *prev;
    struct student_node *next;
    char *name;
    char *grade;
//    grade_t *list_of_grades;
    float list_of_grades;

} Student;


/*
 * Database struct.
 */

typedef struct {

    Student *head;
    Student *tail;
    size_t len;

    void (*free)(void *val);

    int (*match)(void *a, void *b);

} Database;

/*
 * Database iterator struct.
 */

typedef struct {

    Student *next;

} list_iterator_t;

// Node prototypes.

Student *new_student(char **, float, char *);

// Database prototypes.

Database *list_new();

Student *list_push(Database *, Student *);

void slice_str(const char *, char *, size_t, size_t);

int cmp_last_name(char *, char *);

void sort_students(Database *);

void list_remove(Database *, Student *);

void list_destroy(Database *);

// Database iterator prototypes.

list_iterator_t *list_iterator_new(Database *);

Student *list_iterator_next(list_iterator_t *);

void list_iterator_destroy(list_iterator_t *);

#endif /* DATABASE_H */
