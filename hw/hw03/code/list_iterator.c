
//
// iterator.c
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#include "list.h"

/*
 * Allocate a new list_iterator_t. NULL on failure.
 * Accepts a direction, which may be LIST_HEAD or LIST_TAIL.
 */

list_iterator_t *
list_iterator_new(linked_list *list, list_direction_t direction) {
    node *node = direction == LIST_HEAD
            ? list->head
            : list->tail;
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
