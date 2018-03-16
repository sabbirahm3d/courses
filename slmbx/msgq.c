#include <stdlib.h>
#include <stdio.h>
#include "msgq.h"

msg_q_node *create_msg_q_node(char *data) {

    msg_q_node *temp = (msg_q_node *) malloc(sizeof(msg_q_node));
    temp->data = data;
    temp->next = NULL;
    return temp;

}


msg_q *init_msg_q(msg_q *msg_queue) {

    msg_queue->head = msg_queue->tail = NULL;
    return msg_queue;

}


void enqueue_msg_q(msg_q *msg_queue, char *data) {

    msg_q_node *temp = create_msg_q_node(data);

    // If msg_queue is empty, then new msg_sl_node is head and tail both
    if (msg_queue->tail == NULL) {
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
    if (msg_queue->head == NULL) {
        return NULL;
    }

    // Store previous head and move head one msg_sl_node ahead
    msg_q_node *temp = msg_queue->head;
    msg_queue->head = msg_queue->head->next;

    // If head becomes NULL, then change tail also as NULL
    if (msg_queue->head == NULL) {
        msg_queue->tail = NULL;
    }
    return temp;

}

// Function to remove a msg_queue from given queue q
void dump_msg_q(msg_q *msg_queue) {

    msg_q_node *temp = msg_queue->head;

    while (temp != NULL) {

        printf("%s -> ", temp->data);
        temp = temp->next;

    }

    printf("NULL");

    free(temp);
    temp = NULL;

}


void destroy_msg_q(msg_q *msg_queue) {

    msg_q_node *temp = msg_queue->head;

    while (temp != NULL) {

        msg_queue->head = msg_queue->head->next;

        // If head becomes NULL, then change tail also as NULL
        if (msg_queue->head == NULL) {
            msg_queue->tail = NULL;
        }

//        free(temp->data);
        free(temp);
        temp = msg_queue->head;

    }

    free(msg_queue);
    msg_queue = NULL;

}

//int main() {
//
//    msg_q *msg_q_obj = malloc(sizeof(msg_q));
//    init_msg_q(msg_q_obj);
//
//    enqueue_msg_q(msg_q_obj, "test0");
//    enqueue_msg_q(msg_q_obj, "test1");
//
//    msg_q_node* test = dequeue_msg_q(msg_q_obj);
//    free(test);
//
//    enqueue_msg_q(msg_q_obj, "test2");
//    enqueue_msg_q(msg_q_obj, "test3");
//
//    dump_msg_q(msg_q_obj);
//
//    destroy_msg_q(msg_q_obj);
//
//    return 0;
//
//}
