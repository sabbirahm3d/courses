#include <stdlib.h>
#include "msgq.h"

msg_q_node *create_msg_q_node(unsigned char *data) {

    msg_q_node *temp = (msg_q_node *) malloc(sizeof(msg_q_node));
    temp->data = data;
    temp->next = NULL;

    return temp;

}


msg_q *init_msg_q(msg_q *msg_queue) {

    msg_queue->head = msg_queue->tail = NULL;
    msg_queue->size = 0;

    return msg_queue;

}


void enqueue_msg_q(msg_q *msg_queue, unsigned char *data) {

    msg_q_node *temp = create_msg_q_node(data);
    msg_queue->size++;

    // If msg_queue is empty, then new msg_sl_node is head and tail both
    if (!msg_queue->tail) {
        msg_queue->head = msg_queue->tail = temp;
        return;
    }

    // Add the new msg_sl_node at the end of msg_queue and change tail
    msg_queue->tail->next = temp;
    msg_queue->tail = temp;

}


// Function to remove a msg_queue from given queue q
msg_q_node *dequeue_msg_q(msg_q *msg_queue) {

    // If msg_queue is empty, return NULL.
    if (!msg_queue->head) {

        return NULL;

    }

    // Store previous head and move head one msg_sl_node ahead
    msg_q_node *temp = msg_queue->head;
    msg_queue->head = msg_queue->head->next;

    // If head becomes NULL, then change tail also as NULL
    if (!msg_queue->head) {
        msg_queue->tail = NULL;
    }

    msg_queue->size--;
    return temp;

}

unsigned int count_msg_q(msg_q *msg_queue) {

    return msg_queue->size;

}


void destroy_msg_q(msg_q *msg_queue) {

    msg_q_node *temp = msg_queue->head;

    while (temp) {

        msg_queue->head = msg_queue->head->next;

        // If head becomes NULL, then change tail also as NULL
        if (!msg_queue->head) {
            msg_queue->tail = NULL;
        }

        free(temp->data);
        temp->data = NULL;
        free(temp);
        temp = msg_queue->head;

    }

    free(msg_queue);
    msg_queue = NULL;

}


/*
// Function to remove a msg_queue from given queue q
void dump_msg_q(msg_q *msg_queue) {

    msg_q_node *temp = msg_queue->head;

    while (temp) {

        printf("%s -> ", temp->data);
        temp = temp->next;

    }

    printf("NULL");

    free(temp);
    temp = NULL;

}
*/
