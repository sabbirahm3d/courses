//
// Created by sabbir on 3/15/18.
//

#ifndef SLQUEUE_H
#define SLQUEUE_H


// A linked list (LL) msg_sl_node to store a queue entry
typedef struct msg_q_node_t {
    char *data;
    struct msg_q_node_t *next;
} msg_q_node;


// The queue, head stores the head msg_sl_node of LL and tail stores ths
// last msg_sl_node of LL
typedef struct msg_q_t {
    msg_q_node *head;
    msg_q_node *tail;
} msg_q;


msg_q_node *create_msg_q_node(char *);

msg_q *init_msg_q();

void push_msg_q(msg_q *, char *);

msg_q_node *pop_msg_q(msg_q *);

void destroy_msg_q(msg_q *);


#endif // SLQUEUE_H
