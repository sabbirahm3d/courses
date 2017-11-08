
//
// list.h
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef DATABASE_H
#define DATABASE_H


//typedef union Grade grade_t;
/*
 * Database Student struct.
 */

typedef struct quiz_node {

    char *name;
    float grade;
    float weight;

} quiz_t;

typedef struct test_node {

    char *name;
    float grade;
    float weight;

} test_t;

// Indicates the type of data stored in the union
enum assn_type {QUIZ, TEST};

typedef struct Grade {

    enum assn_type assn_t;
    struct Grade *next;

    union {
        quiz_t quiz;
        test_t test;
    };

} grade_t;

/*
 * Database struct.
 */

typedef struct list_of_grades {

    grade_t *head;
    grade_t *tail;
    size_t len;

} List_of_Grades;


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

    void (*free)(void *val);

} Database;

/*
 * Database iterator struct.
 */

typedef struct {

    Student *next;

} list_iterator_t;

typedef struct {

    grade_t *next;

} list_of_grades_it_t;

list_of_grades_it_t *list_of_grades_iterator_new(List_of_Grades *list);

grade_t *list_of_grades_iterator_next(list_of_grades_it_t *self);
// Node prototypes.

Student *new_student(char **, List_of_Grades *, float);

grade_t *new_assn(unsigned int, char **, float, float);
// Database prototypes.

Database *db_init();

List_of_Grades *list_of_grades_init();

Student *db_push(Database *, Student *);

grade_t *assn_push(List_of_Grades *, grade_t *);

void slice_str(const char *, char *, size_t, size_t);

int cmp_last_name(char *, char *);

void sort_students(Database *);

void db_remove(Database *, Student *);

void destroy_db(Database *);

void destroy_list_of_grades(List_of_Grades *);
// Database iterator prototypes.

list_iterator_t *list_iterator_new(Database *);

Student *list_iterator_next(list_iterator_t *);

void list_iterator_destroy(list_iterator_t *);

#endif /* DATABASE_H */
