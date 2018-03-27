//
// Created by sabbir on 3/15/18.
//

#ifndef MSGQ_H
#define MSGQ_H

// A msg_sl_node to store a queue entry
typedef struct msg_q_node_t {
    unsigned char *data;
    struct msg_q_node_t *next;
} msg_q_node;


// The queue, head stores the head msg_sl_node and tail stores the last
// msg_sl_node
typedef struct msg_q_t {

    msg_q_node *head;
    msg_q_node *tail;
    unsigned int size;

} msg_q;


msg_q_node *create_msg_q_node(unsigned char *);

msg_q *init_msg_q(msg_q *);

void enqueue_msg_q(msg_q *, unsigned char *);

msg_q_node *dequeue_msg_q(msg_q *);

unsigned int count_msg_q(msg_q *);

void destroy_msg_q(msg_q *);

// void dump_msg_q(msg_q *);

#endif // MSGQ_H
