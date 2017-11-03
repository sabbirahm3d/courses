
//
// list.c
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#include <stdlib.h>
#include <string.h>
#include "database.h"

/*
 * Allocates a new Student. NULL on failure.
 */


Student *
new_student(char **name, List_of_Grades *list_of_grades, float final_grade) {

    Student *self;
    if (!(self = malloc(sizeof(Student))))
        return NULL;
    self->prev = NULL;
    self->next = NULL;
    self->name = *name;
    self->final_grade = final_grade;
    self->list_of_grades = list_of_grades;

    return self;

}


grade_t *new_assn(unsigned int assn_type, char **name, float grade, float
weight) {

    grade_t *self;
    if (!(self = malloc(sizeof(grade_t))))
        return NULL;

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
 * Allocate a new list_iterator_t. NULL on failure.
 * Accepts a direction, which may be LIST_HEAD or LIST_TAIL.
 */

list_iterator_t *list_iterator_new(Database *list) {

    list_iterator_t *self;
    if (!(self = malloc(sizeof(list_iterator_t))))
        return NULL;
    self->next = list->head;
    return self;

}


/*
 * Return the next Student or NULL when no more
 * nodes remain in the list.
 */

Student *list_iterator_next(list_iterator_t *self) {
    Student *curr = self->next;
    if (curr) {
        self->next = curr->next;
    }
    return curr;
}

/*
 * Allocate a new list_iterator_t. NULL on failure.
 * Accepts a direction, which may be LIST_HEAD or LIST_TAIL.
 */

list_of_grades_it_t *list_of_grades_iterator_new(List_of_Grades *list) {

    list_of_grades_it_t *self;
    if (!(self = malloc(sizeof(list_iterator_t))))
        return NULL;
    self->next = list->head;
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

/*
 * Free the list iterator.
 */

void list_iterator_destroy(list_iterator_t *self) {
    free(self);
    self = NULL;
}


/*
 * Allocate a new Database. NULL on failure.
 */

Database *db_init() {

    Database *self;

    if (!(self = malloc(sizeof(Database))))
        return NULL;
    self->head = NULL;
    self->tail = NULL;
    self->free = NULL;
    self->len = 0;

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
    self->free = NULL;
    self->len = 0;

    return self;

}

/*
 * Free the list.
 */

void destroy_db(Database *self) {

    size_t len = self->len;
    Student *next;
    Student *curr = self->head;

    while (len--) {
        next = curr->next;
//        db_remove(self, next);
//        if (self->free) self->free(curr->name);
        free(curr);
        curr = next;
    }

    free(self);

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
//        if (self->free) self->free(curr->name);
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


void slice_str(const char *str, char *buffer, size_t start, size_t end) {
    size_t j = 0;
    for (size_t i = start; i <= end; ++i) {
        buffer[j++] = str[i];
    }
    buffer[j] = 0;
}


int cmp_last_name(char *node1, char *node2) {

    size_t len1 = strlen(node1);
    size_t len2 = strlen(node2);
    char buffer1[len1 + 1];
    char buffer2[len2 + 1];
    char *start1 = strchr(node1, ' ');
    char *start2 = strchr(node2, ' ');

    slice_str(node1, buffer1, start1 - node1 + 1, len1);
    slice_str(node2, buffer2, start2 - node2 + 1, len2);

    return strcmp(buffer1, buffer2);
}

/*
 * Append the given Student to the list
 * and return the Student, NULL on failure.
 */

void sort_students(Database *self) {

    for (int i = 0; i < self->len; i++) {

        Student *current = self->head;
        Student *next = current->next;
        Student *previous = NULL;

        while (next) {

            if (cmp_last_name(current->name, next->name) > 0) {

                if (current == self->head) {
                    self->head = next;
                } else {
                    previous->next = next;
                }

                current->next = next->next;
                next->next = current;

                previous = next;
                next = current->next;

            } else {

                previous = current;
                current = current->next;
                next = current->next;

            }

        }

    }

}


Student *db_push(Database *self, Student *node) {

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
 * Remove the given Student from the list, freeing it and it's value.
 */

void db_remove(Database *self, Student *node) {

    node->prev ? (node->prev->next = node->next) : (self->head = node->next);

    node->next ? (node->next->prev = node->prev) : (self->tail = node->prev);

//    if (self->free) self->free(node->name);

    free(node->name);
    free(node);

    destroy_list_of_grades(node->list_of_grades);
    --self->len;

}
