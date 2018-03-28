/*
 * Sabbir Ahmed
 * CMSC 421: Project 1
 *
 * Implementation of a simple queue.
 *
 * */

// kernel headers
#include <linux/slab.h>

// local headers
#include "msgq.h"

/*
 * Initialize a node for the queue
 *
 * */
msg_q_node *create_msg_q_node(unsigned char *data) {

    msg_q_node *temp;
    temp = (msg_q_node *) kmalloc(sizeof(msg_q_node), GFP_KERNEL);
    temp->data = data;
    temp->next = NULL;

    return temp;

}

/*
 * Initialize a queue
 *
 * */
msg_q *init_msg_q(msg_q *msg_queue) {

    msg_queue->head = msg_queue->tail = NULL;
    msg_queue->size = 0;

    return msg_queue;

}

/*
 * Push new node to the back of the queue
 *
 * */
void enqueue_msg_q(msg_q *msg_queue, unsigned char *data) {

    msg_q_node *temp;
    temp = create_msg_q_node(data);
    msg_queue->size++;

    // if empty, the new node is now both the head and tail
    if (!msg_queue->tail) {
        msg_queue->head = msg_queue->tail = temp;
        return;
    }

    // add the new node at the end of queue and change tail
    msg_queue->tail->next = temp;
    msg_queue->tail = temp;

}

/*
 * Remove and return the first node from the queue
 *
 * */
msg_q_node *dequeue_msg_q(msg_q *msg_queue) {

    // if empty, return NULL
    if (!msg_queue->head) {

        return NULL;

    }

    // store previous head and move head one node ahead
    msg_q_node *temp;
    temp = msg_queue->head;
    msg_queue->head = msg_queue->head->next;

    // if head becomes NULL, then change tail to NULL
    if (!msg_queue->head) {

        msg_queue->tail = NULL;

    }

    // decrement queue size
    msg_queue->size--;

    return temp;

}


/*
 * Destroy the queue
 *
 * */
void destroy_msg_q(msg_q *msg_queue) {

    msg_q_node *temp;
    temp = msg_queue->head;

    // traverse through the queue until all nodes are freed
    while (temp) {

        msg_queue->head = msg_queue->head->next;

        // If head becomes NULL, then change tail also as NULL
        if (!msg_queue->head) {
            msg_queue->tail = NULL;
        }

        kfree(temp->data);
        temp->data = NULL;
        kfree(temp);
        temp = msg_queue->head;

    }

    kfree(msg_queue);
    msg_queue = NULL;

}
