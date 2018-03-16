#include <stdlib.h>
#include <stdio.h>
#include "slqueue.h"

msg *create_node(char *data) {

    msg *temp = (msg *) malloc(sizeof(msg));
    temp->data = data;
    temp->next = NULL;
    return temp;

}


msg_queue *init_queue() {

    msg_queue *q = (msg_queue *) malloc(sizeof(msg_queue));
    q->head = q->tail = NULL;
    return q;

}


void enqueue(msg_queue *queue, char *data) {

    msg *temp = create_node(data);

    // If queue is empty, then new node is head and tail both
    if (queue->tail == NULL) {
        queue->head = queue->tail = temp;
        return;
    }

    // Add the new node at the end of queue and change tail
    queue->tail->next = temp;
    queue->tail = temp;

}


// Function to remove a data from given queue q
msg *dequeue(msg_queue *queue) {

    // If queue is empty, return NULL.
    if (queue->head == NULL) {
        return NULL;
    }

    // Store previous head and move head one node ahead
    msg *temp = queue->head;
    queue->head = queue->head->next;

    // If head becomes NULL, then change tail also as NULL
    if (queue->head == NULL) {
        queue->tail = NULL;
    }
    return temp;

}


void destroy_queue(msg_queue *queue) {

    msg *temp = queue->head;

    while (temp != NULL) {

        queue->head = queue->head->next;

        // If head becomes NULL, then change tail also as NULL
        if (queue->head == NULL) {
            queue->tail = NULL;
        }

        free(temp->data);
        free(temp);
        temp = queue->head;

    }

    free(queue);

}
