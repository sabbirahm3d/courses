//
// Created by sabbir on 3/15/18.
//

#include "rand.h"
#include "msgsl.h"


msg_sl *init_msg_sl(msg_sl *list) {

    int i;
    msg_sl_node *header = (msg_sl_node *) malloc(sizeof(msg_sl_node));

    seed_random(rand());
    list->head = header;
    header->id = INT_MAX;
    header->next = (msg_sl_node **) malloc(sizeof(msg_sl_node *) *
                                                   (SKIPLIST_MAX_LEVEL + 1));

    for (i = 0; i <= SKIPLIST_MAX_LEVEL; i++) {
        header->next[i] = list->head;
    }

    list->level = 1;

    return list;

}


static int rand_level() {

    int level = 1;
    generate_random_int();

    while ((rand() < RAND_MAX / 2) && (level < SKIPLIST_MAX_LEVEL)) {
        level++;
    }

    printf("level %d\n", level);
    return level;
}


int insert_msg_sl(msg_sl *list, int key, msg_q *data) {

    msg_sl_node *update[SKIPLIST_MAX_LEVEL + 1];
    msg_sl_node *x = list->head;
    int level;

    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->id < key) {
            x = x->next[i];
        }
        update[i] = x;
    }
    x = x->next[1];

    if (key == x->id) {

        x->data = data;
        return 0;

    } else {

        level = rand_level();
        if (level > list->level) {
            for (int i = list->level + 1; i <= level; i++) {
                update[i] = list->head;
            }
            list->level = level;
        }

        x = (msg_sl_node *) malloc(sizeof(msg_sl_node));
        x->id = key;
        x->data = data;
        x->next = (msg_sl_node **) malloc(sizeof(msg_sl_node *) *
                                                  (level + 1));

        for (int i = 1; i <= level; i++) {
            x->next[i] = update[i]->next[i];
            update[i]->next[i] = x;
        }

    }

    return 0;

}


msg_sl_node *search_msg_sl(msg_sl *list, int key) {

    msg_sl_node *x = list->head;

    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->id < key)
            x = x->next[i];
    }
    if (x->next[1]->id == key) {

        return x->next[1];

    } else {

        return NULL;

    }

    return NULL;

}


void free_msg_sl_node(msg_sl_node *msg_sl_node_obj) {

    if (msg_sl_node_obj) {

        free(msg_sl_node_obj->next);
        msg_sl_node_obj->next = NULL;

        destroy_msg_q(msg_sl_node_obj->data);

        free(msg_sl_node_obj);
        msg_sl_node_obj = NULL;

    }

}


int remove_msg_sl(msg_sl *list, int key) {

    msg_sl_node *update[SKIPLIST_MAX_LEVEL + 1];
    msg_sl_node *x = list->head;
    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->id < key)
            x = x->next[i];
        update[i] = x;
    }

    x = x->next[1];

    if (x->id == key) {

        for (int i = 1; i <= list->level; i++) {
            if (update[i]->next[i] != x)
                break;
            update[i]->next[i] = x->next[i];
        }

        free_msg_sl_node(x);

        while (list->level > 1 &&
                list->head->next[list->level] == list->head) {
            list->level--;
        }
        return 0;

    }

    return 1;

}

void destroy_msg_sl(msg_sl *list) {

    msg_sl_node *current_node = list->head->next[1];
    while (current_node != list->head) {

        msg_sl_node *next_node = current_node->next[1];

        free(current_node->next);
        current_node->next = NULL;

        free(current_node);

        current_node = next_node;

    }

    free(current_node->next);
    current_node->next = NULL;

    free(current_node);
    current_node = NULL;

    free(list);
    list = NULL;

}

void dump_msg_sl(msg_sl *list) {

    msg_sl_node *x = list->head;
    while (x && x->next[1] != list->head) {
        printf("%d[%d]->", x->next[1]->id, x->next[1]->data);
        x = x->next[1];
    }
    printf("NIL\n");

}
