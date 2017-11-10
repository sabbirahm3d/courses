/*
 * list_of_grades.c
 *
 *
 *
 * */

#include <stdlib.h>
#include "database.h"

/*
 * Initialize an assignment node.
 * inputs:
 *      assn_type: type of assignment - 0 for quiz, 1 for test
 *      name: name of quiz / test
 *      grade: grade of quiz / test
 *      weight: weight of quiz / test
 *
 * output:
 *      NULL if memory could not be allocated for a new quiz_t node, else a
 *      new quiz_t node with the specified attributes
 * */
grade_t *new_assn(
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
 * Allocate a new Database. NULL on failure.
 */

List_of_Grades *list_of_grades_init() {

    List_of_Grades *self;

    if (!(self = malloc(sizeof(Database))))
        return NULL;
    self->head = NULL;
    self->tail = NULL;
//    self->free = NULL;
    self->len = 0;

    return self;

}


/*
 * Return the next Student or NULL when no more
 * nodes remain in the list.
 */

grade_t *list_of_grades_iterator_next(list_of_grades_it_t *self) {

    grade_t *curr = self->next;
    if (curr) {
        self->next = curr->next;
    }
    return curr;

}

grade_t *assn_push(List_of_Grades *self, grade_t *node) {

    if (!node) {
        return NULL;
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

    ++self->len;
    return node;

}


/*
 * Free the list.
 */

void destroy_list_of_grades(List_of_Grades *self) {

    size_t len = self->len;
    grade_t *next;
    grade_t *curr = self->head;

    while (len--) {
        next = curr->next;
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
