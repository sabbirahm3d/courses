
//
// list.c
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#include "list.h"

/*
 * Allocates a new node. NULL on failure.
 */


node *create_node(char **data, float grade) {

    node *self;
    if (!(self = malloc(sizeof(node))))
        return NULL;
    self->prev = NULL;
    self->next = NULL;
    self->name = *data;
    self->grade = grade;

    return self;

}

/*
 * Allocate a new list_iterator_t. NULL on failure.
 * Accepts a direction, which may be LIST_HEAD or LIST_TAIL.
 */

list_iterator_t *
list_iterator_new(linked_list *list, list_direction_t direction) {

    node *node = direction == LIST_HEAD ? list->head : list->tail;
    return list_iterator_new_from_node(node, direction);

}

/*
 * Allocate a new list_iterator_t with the given start
 * node. NULL on failure.
 */

list_iterator_t *
list_iterator_new_from_node(node *node, list_direction_t direction) {

    list_iterator_t *self;
    if (!(self = malloc(sizeof(list_iterator_t))))
        return NULL;
    self->next = node;
    self->direction = direction;
    return self;

}

/*
 * Return the next node or NULL when no more
 * nodes remain in the list.
 */

node *list_iterator_next(list_iterator_t *self) {
    node *curr = self->next;
    if (curr) {
        self->next = self->direction == LIST_HEAD
                ? curr->next
                : curr->prev;
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
 * Allocate a new linked_list. NULL on failure.
 */

linked_list *list_new() {

    linked_list *self;

    if (!(self = malloc(sizeof(linked_list))))
        return NULL;
    self->head = NULL;
    self->tail = NULL;
    self->free = NULL;
    self->match = NULL;
    self->len = 0;

    return self;

}

/*
 * Free the list.
 */

void list_destroy(linked_list *self) {
    size_t len = self->len;
    node *next;
    node *curr = self->head;

    while (len--) {
        next = curr->next;
        if (self->free) self->free(curr->name);
        free(curr);
        curr = next;
    }

    free(self);
}

/*
 * Append the given node to the list
 * and return the node, NULL on failure.
 */

node *list_push(linked_list *self, node *node) {
    if (!node) return NULL;

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
 * Return / detach the last node in the list, or NULL.
 */

node *list_rpop(linked_list *self) {
    if (!self->len) return NULL;

    node *node = self->tail;

    if (--self->len) {
        (self->tail = node->prev)->next = NULL;
    } else {
        self->tail = self->head = NULL;
    }

    node->next = node->prev = NULL;
    return node;
}

/*
 * Return / detach the first node in the list, or NULL.
 */

node *list_lpop(linked_list *self) {
    if (!self->len) return NULL;

    node *node = self->head;

    if (--self->len) {
        (self->head = node->next)->prev = NULL;
    } else {
        self->head = self->tail = NULL;
    }

    node->next = node->prev = NULL;
    return node;
}

/*
 * Prepend the given node to the list
 * and return the node, NULL on failure.
 */

node *list_lpush(linked_list *self, node *node) {
    if (!node) return NULL;

    if (self->len) {
        node->next = self->head;
        node->prev = NULL;
        self->head->prev = node;
        self->head = node;
    } else {
        self->head = self->tail = node;
        node->prev = node->next = NULL;
    }

    ++self->len;
    return node;
}

/*
 * Return the node associated to name or NULL.
 */

node *list_find(linked_list *self, char *name) {
    list_iterator_t *it = list_iterator_new(self, LIST_HEAD);
    node *node;

    while ((node = list_iterator_next(it))) {

        if (self->match) {
            if (self->match(name, node->name)) {
                list_iterator_destroy(it);
                return node;
            }

        } else {

            if (name == node->name) {
                list_iterator_destroy(it);
                return node;
            }

        }

    }

    list_iterator_destroy(it);
    return NULL;
}

/*
 * Return the node at the given index or NULL.
 */

node *list_get(linked_list *self, int index) {
    list_direction_t direction = LIST_HEAD;

    if (index < 0) {
        direction = LIST_TAIL;
        index = ~index;
    }

    if ((unsigned) index < self->len) {
        list_iterator_t *it = list_iterator_new(self, direction);
        node *node = list_iterator_next(it);
        while (index--) node = list_iterator_next(it);
        list_iterator_destroy(it);
        return node;
    }

    return NULL;
}

/*
 * Remove the given node from the list, freeing it and it's value.
 */

void list_remove(linked_list *self, node *node) {
    node->prev ? (node->prev->next = node->next) : (self->head = node->next);

    node->next ? (node->next->prev = node->prev) : (self->tail = node->prev);

    if (self->free) self->free(node->name);

    free(node->name);
    free(node);
    --self->len;
}
