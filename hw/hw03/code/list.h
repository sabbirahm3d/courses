
//
// list.h
//
// Copyright (c) 2010 TJ Holowaychuk <tj@vision-media.ca>
//

#ifndef LIST_H
#define LIST_H

#include <stdlib.h>

/*
 * linked_list iterator direction.
 */

//typedef enum {
//    LIST_HEAD, LIST_TAIL
//} list_direction_t;

/*
 * linked_list node struct.
 */

typedef struct list_node {

    struct list_node *prev;
    struct list_node *next;
    char *name;
    char *grade;
    float list_of_grades;

} node;


/*
 * linked_list struct.
 */

typedef struct {

    node *head;
    node *tail;
    size_t len;

    void (*free)(void *val);

    int (*match)(void *a, void *b);

} linked_list;

//typedef union list_of_grades {
//    linked_list
//};

/*
 * linked_list iterator struct.
 */

typedef struct {

    node *next;
//    list_direction_t direction;

} list_iterator_t;

// Node prototypes.

node *create_node(char **, float, char *);

// linked_list prototypes.

linked_list *list_new();

node *list_push(linked_list *, node *);

//node *list_lpush(linked_list *self, node *node);
//
//node *list_find(linked_list *self, char *);
//
//node *list_get(linked_list *self, int index);
//
//node *list_rpop(linked_list *self);
//
//node *list_lpop(linked_list *self);

void list_remove(linked_list *, node *);

void list_destroy(linked_list *);

// linked_list iterator prototypes.

list_iterator_t *list_iterator_new(linked_list *);

//list_iterator_t *list_iterator_new_from_node(node *);

node *list_iterator_next(list_iterator_t *);

void list_iterator_destroy(list_iterator_t *);

#endif /* LIST_H */
