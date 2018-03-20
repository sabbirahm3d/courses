//
// Created by sabbir on 3/15/18.
//

#include "extmath.h"
#include "msgsl.h"


unsigned int rand_level() {

    unsigned int level = 1;

    while ((generate_random_int() < 32767 / PROB) && (level < MAXLVL)) {
        level++;
    }

//    printf("max %d level %d %d\n", MAXLVL, level, next_random);
    return level;
}


msg_sl *init_msg_sl(msg_sl *list, unsigned int opand, unsigned int base) {

    msg_sl_node *header = malloc(sizeof(msg_sl_node));

    ceil_log(opand, base);
    seed_random(rand());

    list->head = header;
    header->id = MAXID;
    header->next = malloc(sizeof(msg_sl_node *) * (MAXLVL + 1));

    for (int i = 0; i <= MAXLVL; i++) {
        header->next[i] = list->head;
    }

    list->level = 1;

    return list;

}


int insert_msg_sl(msg_sl *list, unsigned int id, int uid) {

    msg_q *msg_queue = malloc(sizeof(msg_q));
    init_msg_q(msg_queue);

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *head = list->head;

    for (int i = list->level; i >= 1; i--) {

        while (head->next[i]->id < id) {
            head = head->next[i];
        }
        update[i] = head;

    }

    head = head->next[1];

    if (id == head->id) {

        head->msg_queue = msg_queue;
        head->uid = uid;
        return 0;

    } else {

        int level = rand_level();

        if (level > list->level) {
            for (int i = list->level + 1; i <= level; i++) {
                update[i] = list->head;
            }

            list->level = level;

        }

        head = malloc(sizeof(msg_sl_node));
        head->id = id;
        head->msg_queue = msg_queue;
        head->uid = uid;
        head->next = malloc(sizeof(msg_sl_node *) * (level + 1));

        for (int i = 1; i <= level; i++) {
            head->next[i] = update[i]->next[i];
            update[i]->next[i] = head;
        }

    }

    return 0;

}


msg_sl_node *search_msg_sl(msg_sl *list, unsigned int id) {

    msg_sl_node *x = list->head;

    for (int i = list->level; i >= 1; i--) {

        while (x->next[i]->id < id) {
            x = x->next[i];
        }

    }

    if (x->next[1]->id == id) {

        return x->next[1];

    }

    return NULL;

}


void free_msg_sl_node(msg_sl_node *msg_sl_node_obj) {

    if (msg_sl_node_obj) {

        free(msg_sl_node_obj->next);
        msg_sl_node_obj->next = NULL;

        destroy_msg_q(msg_sl_node_obj->msg_queue);

        free(msg_sl_node_obj);
        msg_sl_node_obj = NULL;

    }

}


int remove_msg_sl(msg_sl *list, unsigned int id, int uid) {

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *x = list->head;
    for (int i = list->level; i >= 1; i--) {
        while (x->next[i]->id < id)
            x = x->next[i];
        update[i] = x;
    }

    x = x->next[1];

    if (x->id == id && x->next[1]->uid == uid) {

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

    msg_sl_node *current = list->head->next[1];
    while (current != list->head) {

        msg_sl_node *next_node = current->next[1];

        destroy_msg_q(current->msg_queue);

        free(current->next);
        current->next = NULL;

        free(current);
        current = next_node;

    }

    free(current->next);
    current->next = NULL;

    free(current);
    current = NULL;

    free(list);
    list = NULL;

}

void dump_msg_sl(msg_sl *list) {

    msg_sl_node *temp = list->head;
    while (temp && temp->next[1] != list->head) {
        printf("{id: %d, lvl: %d, msg: [", temp->next[1]->id,
               temp->next[1]->uid);
        dump_msg_q(temp->next[1]->msg_queue);
        printf("]} -> \n");
        temp = temp->next[1];
    }
    printf("{NULL}\n");

}
