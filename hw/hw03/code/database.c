/*
 * database.c
 *
 * This file contains the implementation of student_t nodes and database_t
 * linked lists constructors, methods and its corresponding iterators.
 *
 * */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "database.h"


// -------------------------- CONSTRUCTORS --------------------------

/*
 * Initialize a student_t node.
 *
 * inputs:
 *      first_name: first name of student
 *      last_name: last name of student
 *      list_of_grades: pointer to filled list_of_grades_t linked list
 *      final_grade: final letter grade of student
 *
 * output:
 *      NULL if memory could not be allocated for a new student_t node, else a
 *      new student_t node with the specified attributes
 */
student_t *new_student(
        char **first_name, char **last_name, list_of_grades_t *list_of_grades,
        float final_grade) {

    student_t *self;
    if (!(self = malloc(sizeof(student_t)))) {
        return NULL;
    }

    self->prev = NULL;
    self->next = NULL;
    self->first_name = *first_name;
    self->last_name = *last_name;
    self->final_grade = final_grade;
    self->list_of_grades = list_of_grades;

    return self;

}


/*
 * Allocate a new database_t linked list.
 *
 * inputs:
 *      none
 *
 * output:
 *      new database_t linked list
 */
database_t *db_init() {

    database_t *self;

    if (!(self = malloc(sizeof(database_t)))) {
        return NULL;
    }

    self->head = NULL;
    self->tail = NULL;
    self->len = 0;

    return self;

}


/*
 * Allocate a new db_iter_t.
 * 
 * inputs:
 *      list: database_t linked list
 *
 * output:
 *      new db_iter_t iterator
 */
db_iter_t *db_iter_init(database_t *list) {

    db_iter_t *self;
    if (!(self = malloc(sizeof(db_iter_t))))
        return NULL;
    self->next = list->head;
    return self;

}


// -------------------------- STRUCT METHODS --------------------------

/*
 * Return the next student_t or NULL when no more nodes remain in the list.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      pointer to the next node in the iterator
 */
student_t *db_iter_next(db_iter_t *self) {

    student_t *curr = self->next;

    if (curr) {
        self->next = curr->next;
    }

    return curr;

}


/*
 * Append new student_t nodes to the database_t linked list.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *      node: pointer to the new node to be pushed
 *
 * output:
 *      none
 */
void db_push(database_t *self, student_t *node) {

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
 * Swaps the data between two student_t nodes.
 *
 * inputs:
 *      student1: pointer to a student_t node
 *      student2: pointer to a student_t node
 *
 * output:
 *      none
 */
void swap_students(student_t *student1, student_t *student2) {

    // store individual attributes to temporary variables before swapping
    char *temp_first_name = student1->first_name;
    char *temp_last_name = student1->last_name;
    float temp_final_grade = student1->final_grade;
    list_of_grades_t *temp_list_of_grades = student1->list_of_grades;

    // swap each attributes
    student1->first_name = student2->first_name;
    student2->first_name = temp_first_name;

    student1->last_name = student2->last_name;
    student2->last_name = temp_last_name;

    student1->final_grade = student2->final_grade;
    student2->final_grade = temp_final_grade;

    student1->list_of_grades = student2->list_of_grades;
    student2->list_of_grades = temp_list_of_grades;

}


/*
 * Sorts the database by student last names.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void db_sort(database_t *self) {

    // if list is empty, do nothing
    if (!self->len) {
        return;
    }

    int swapped;
    student_t *cur;
    student_t *tail = NULL;

    // uses bubble sort to swap nodes until fully sorted
    do {

        swapped = 0;
        cur = self->head;

        while (cur->next != tail) {

            if (strcasecmp(cur->last_name, cur->next->last_name) > 0) {
                swap_students(cur, cur->next);
                swapped = 1;
            }

            cur = cur->next;

        }

        tail = cur;

    } while (swapped);

}


/*
 * Remove the specified student_t node from the database_t linked list.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *      node: node to remove from list
 *
 * output:
 *      none
 */
void db_remove(database_t *self, student_t *node) {

    node->prev ? (node->prev->next = node->next) : (self->head = node->next);

    node->next ? (node->next->prev = node->prev) : (self->tail = node->prev);

    free(node->first_name);
    free(node->last_name);
    node->first_name = NULL;

    // call the node's list_of_grades_t destructor
    destroy_list_of_grades(node->list_of_grades);
    free(node);
    --(self->len);

}


/*
 * Destructor the database_t linked list.
 *
 * inputs:
 *      self: pointer to the initialized database_t
 *
 * output:
 *      none
 */
void db_destory(database_t *self) {

    size_t len = self->len;
    student_t *next;
    student_t *curr = self->head;

    while (len--) {
        next = curr->next;
        free(curr);
        curr = next;
    }

    free(self);

}
