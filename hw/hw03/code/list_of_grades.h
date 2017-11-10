/*
 * list_of_grades.h
 *
 * This file contains the prototypes for the functions and declarations of
 * structs used for the list_of_grades linked lists.
 *
 * */

#ifndef LIST_OF_GRADES_H
#define LIST_OF_GRADES_H

#include "grade_t.h"

// -------------------------- FUNCTION PROTOTYPES --------------------------

grade_t *new_grade(unsigned int, char **, float, float);

list_of_grades_t *list_of_grades_init();

list_of_grades_iter_t *list_of_grades_iter_init(list_of_grades_t *);

grade_t *list_of_grades_iter_next(list_of_grades_iter_t *);

void list_of_grades_push(list_of_grades_t *, grade_t *);

void destroy_list_of_grades(list_of_grades_t *);

#endif // LIST_OF_GRADES_H
