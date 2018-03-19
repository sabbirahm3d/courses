//
// Created by sabbir on 3/15/18.
//

#ifndef SLDS_H
#define SLDS_H

#include "msgq.h"
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>


typedef struct msg_sl_node_t {

    int id;
    msg_q *msg_queue;
    struct msg_sl_node_t **next;

} msg_sl_node;

typedef struct msg_sl_t {

    int level;
    msg_sl_node *head;

} msg_sl;


msg_sl *init_msg_sl(msg_sl *, unsigned int, unsigned int);

int rand_level();

int insert_msg_sl(msg_sl *, int, msg_q *);

msg_sl_node *search_msg_sl(msg_sl *, int);

void free_msg_sl_node(msg_sl_node *);

int remove_msg_sl(msg_sl *, int);

void destroy_msg_sl(msg_sl *);

void dump_msg_sl(msg_sl *);

#endif //SLDS_H
