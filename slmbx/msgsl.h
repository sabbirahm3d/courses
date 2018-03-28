//
// Created by sabbir on 3/15/18.
//

#ifndef MSGSL_H
#define MSGSL_H

#include "msgq.h"

typedef struct msg_sl_node_t {

    unsigned int id;
    int uid;
    msg_q *msg_queue;
    struct msg_sl_node_t **next;

} msg_sl_node;

typedef struct msg_sl_t {

    int level;
    msg_sl_node *head;

} msg_sl;


static unsigned int generate_random_int(void);

static void seed_random(unsigned int);

static void ceil_log(unsigned int, unsigned int);

unsigned int rand_level(void);


msg_sl *init_msg_sl(msg_sl *, unsigned int, unsigned int);

int insert_msg_sl(msg_sl *, unsigned int, int);

msg_sl_node *search_msg_sl(msg_sl *, unsigned int);

void free_msg_sl_node(msg_sl_node *);

int remove_msg_sl(msg_sl *, unsigned int, int);

void destroy_msg_sl(msg_sl *);

void dump_msg_sl(msg_sl *);

#endif //MSGSL_H
