/*
 * list_of_grades.h
 *
 * This file contains the prototypes for the functions and declarations of
 * structs used for the list_of_grades linked lists.
 *
 * */

#ifndef CODE_LIST_OF_GRADES_H
#define CODE_LIST_OF_GRADES_H

#include "grade_t.h"

// -------------------------- FUNCTIONS --------------------------

grade_t *new_assn(unsigned int, char **, float, float);

List_of_Grades *list_of_grades_init();

grade_t *list_of_grades_iterator_next(list_of_grades_it_t *);

grade_t *assn_push(List_of_Grades *, grade_t *);

list_of_grades_it_t *list_of_grades_iterator_new(List_of_Grades *);

void destroy_list_of_grades(List_of_Grades *);

#endif //CODE_LIST_OF_GRADES_H
