/*
 * list_of_grades.c
 *
 * This file contains the implementation of grade_t nodes and list_of_grades_t
 * linked lists constructors, methods and its corresponding iterators.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include "database.h"


// -------------------------- CONSTRUCTORS --------------------------

/*
 * Initialize a grade_t node.
 *
 * inputs:
 *      grade_enum: type of assignment - 0 for quiz, 1 for test
 *      name: name of quiz / test
 *      grade: grade of quiz / test
 *      weight: weight of quiz / test
 *
 * output:
 *      NULL if memory could not be allocated for a new quiz_t node, else a
 *      new quiz_t node with the specified attributes
 * */
grade_t *new_grade(
        unsigned int assn_type, char **name, float grade, float weight) {

    grade_t *self;
    if (!(self = malloc(sizeof(grade_t)))) {
        return NULL;
    }

    // 0 for quiz, 1 for test
    self->assn_t = assn_type;

    if (!assn_type) {

        self->quiz.name = *name;
        self->quiz.grade = grade;
        self->quiz.weight = weight;

    } else {

        self->test.name = *name;
        self->test.grade = grade;
        self->test.weight = weight;

    }

    return self;

}


/*
 * Allocate a new list_of_grades_t linked list.
 *
 * inputs:
 *      none
 *
 * output:
 *      new list_of_grades_t linked list
 */
list_of_grades_t *list_of_grades_init() {

    list_of_grades_t *self;

    if (!(self = malloc(sizeof(list_of_grades_t)))){
        return NULL;
    }
    self->head = NULL;
    self->tail = NULL;
    self->len = 0;

    return self;

}


/*
 * Allocate a new list_of_grades_iter_t.
 * 
 * inputs:
 *      list: list_of_grades_t linked list
 *
 * output:
 *      new list_of_grades_iter_t iterator
 */
list_of_grades_iter_t *list_of_grades_iter_init(list_of_grades_t *list) {

    list_of_grades_iter_t *self;
    if (!(self = malloc(sizeof(db_iter_t))))
        return NULL;
    self->next = list->head;
    return self;

}


// -------------------------- STRUCT METHODS --------------------------

/*
 * Return the next grade_t or NULL when no more nodes remain in the list.
 *
 * inputs:
 *      self: pointer to the initialized list_of_grades_t
 *
 * output:
 *      pointer to the next node in the iterator
 */
grade_t *list_of_grades_iter_next(list_of_grades_iter_t *self) {

    grade_t *curr = self->next;
    if (curr) {
        self->next = curr->next;
    }
    return curr;

}

/*
 * Append new grade_t nodes to the list_of_grades_t linked list.
 *
 * inputs:
 *      self: pointer to the initialized list_of_grades_t
 *      node: pointer to the new node to be pushed
 *
 * output:
 *      none
 */

void list_of_grades_push(list_of_grades_t *self, grade_t *node) {

    if (!node) {
        printf("Invalid node.\n");
    }

    if (self->len) {

        node->prev = self->tail;
        node->next = NULL;
        self->tail->next = node;
        self->tail = node;

    } else {

        self->head = self->tail = node;
        node->prev = node->next = NULL;

    }

    ++(self->len);

}


/*
 * Destructor for the list_of_grades_t linked list.
 *
 * inputs:
 *      self: pointer to the initialized list_of_grades_t
 *
 * output:
 *      none
 */
void destroy_list_of_grades(list_of_grades_t *self) {

    size_t len = self->len;
    grade_t *next;
    grade_t *curr = self->head;

    // keep decrementing the size
    while (len--) {
        next = curr->next;

        // free the quiz / test name depending on its type
        if (!curr->assn_t) {
            free(curr->quiz.name);
        } else {
            free(curr->test.name);

        }

        free(curr);
        curr = next;
    }

    free(self);

}
