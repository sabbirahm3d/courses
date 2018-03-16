//
// Created by sabbir on 3/15/18.
//

#ifndef SLQUEUE_H
#define SLQUEUE_H


// A linked list (LL) node to store a queue entry
typedef struct msg_node_t {
    char *data;
    struct msg_node_t *next;
} msg;


// The queue, head stores the head node of LL and tail stores ths
// last node of LL
typedef struct msg_queue_t {
    msg *head;
    msg *tail;
} msg_queue;


msg *create_node(char *);

msg_queue *init_queue();

void enqueue(msg_queue *, char *);

msg *dequeue(msg_queue *);

void destroy_queue(msg_queue *);


#endif // SLQUEUE_H
