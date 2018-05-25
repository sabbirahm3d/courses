/*
 * Sabbir Ahmed
 * CMSC 421: Project 1
 *
 * Prototypes and structs used in the implementation of a simple queue.
 *
 * */

#ifndef MSGQ_H
#define MSGQ_H

// queue node
typedef struct msg_q_node_t {

    unsigned char *data;
    struct msg_q_node_t *next;

} msg_q_node;


// queue container
typedef struct msg_q_t {

    msg_q_node *head;
    msg_q_node *tail;
    unsigned int size;

} msg_q;

// queue methods
msg_q_node *create_msg_q_node(unsigned char *);

msg_q *init_msg_q(msg_q *);

void enqueue_msg_q(msg_q *, unsigned char *);

msg_q_node *dequeue_msg_q(msg_q *);

void destroy_msg_q(msg_q *);

#endif // MSGQ_H
