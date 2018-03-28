/*
 * Sabbir Ahmed
 * CMSC 421: Project 1
 *
 * Implementation of a skiplist of queues. Most of the implementation were
 * derived from the algorithm detailed in the paper:
 *
 * "Skip Lists: A Probabilistic Alternative to Balanced Trees"
 * (ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf)
 *
 * */

// kernel headers
#include <linux/kernel.h>
#include <linux/random.h>
#include <linux/slab.h>

// local headers
#include "msgsl.h"

// variables for the linear congruential generator
const unsigned int MULTIPLIER = 1103515245;
const unsigned int INCREMENT = 12345;

unsigned int MAXLVL;  // maximum level of lanes in the skiplist
unsigned int PROB;  // probability of a promotion of a skiplist node
static unsigned int next_random = 9001; // seed for the generated random number

/*
 * Linear congruential generator to generate the random numbers
 *
 * */
static unsigned int generate_random_int(void) {

    // 32-bit linear congruential generator parameters
    next_random = next_random * MULTIPLIER + INCREMENT;
    return (next_random / 65536) % 32768;

}

/*
 * Seed the generated random number
 *
 * */
static void seed_random(unsigned int seed) {

    next_random = seed;

}

/*
 * Generates the ceil[log_{base}(opand)] without any floating point
 * operations. This function is required to determine the probability of
 * promoting the nodes and the maximum number of levels (L(n)).
 *
 * Computation of L(n) = log_(1/p)(n) is provided in the original paper here:
 * ftp://ftp.cs.umd.edu/pub/skipLists/skiplists.pdf
 *
 * */
static void ceil_log(unsigned int opand, unsigned int base) {

    unsigned int level = 0;
    unsigned int total = 1;

    // keep increasing the power of the base until it is greater than or
    // equal to the operand
    while (total < opand) {
        total = total * base;
        level++;
    }

    MAXLVL = level;
    PROB = base;

}

/*
 * Generate a random level to promote the current node
 *
 * */
unsigned int rand_level(void) {

    unsigned int level = 1;

    while ((generate_random_int() < 32767 / PROB) && (level < MAXLVL)) {
        level++;
    }

    return level;
}


/*
 * Initialize the skiplist
 *
 * */
msg_sl *init_msg_sl(msg_sl *list, unsigned int opand, unsigned int base) {

    // generate the probability and maximum level
    ceil_log(opand, base);

    // seed the random number generator
    unsigned int rand;
    get_random_bytes(&rand, sizeof(rand));
    seed_random(rand);

    msg_sl_node *head;
    head = kmalloc(sizeof(msg_sl_node), GFP_KERNEL);

    list->head = head;
    head->id = 4294967295;
    head->next = kmalloc(sizeof(msg_sl_node *) * (MAXLVL + 1), GFP_KERNEL);

    int i;
    for (i = 0; i <= MAXLVL; i++) {
        head->next[i] = list->head;
    }

    list->level = 1;

    return list;

}

/*
 * Insert a node into the skiplist with its provided ID and UID
 *
 * */
int insert_msg_sl(msg_sl *list, unsigned int id, int uid) {

    // initialize a queue to be stored in the node
    msg_q *msg_queue;
    msg_queue = kmalloc(sizeof(msg_q), GFP_KERNEL);
    init_msg_q(msg_queue);

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *cursor;
    cursor = list->head;

    // move cursor until after the previous declared IDs
    int i;
    for (i = list->level; i >= 1; i--) {

        while (cursor->next[i]->id < id) {
            cursor = cursor->next[i];
        }
        update[i] = cursor;

    }

    cursor = cursor->next[1];

    // insert node once the position is found
    if (id == cursor->id) {

        cursor->msg_queue = msg_queue;
        cursor->uid = uid;

    } else {

        int level = rand_level();

        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->head;
            }

            list->level = level;

        }

        cursor = kmalloc(sizeof(msg_sl_node), GFP_KERNEL);
        cursor->id = id;
        cursor->msg_queue = msg_queue;
        cursor->uid = uid;
        cursor->next = kmalloc(sizeof(msg_sl_node *) * (level + 1), GFP_KERNEL);

        for (i = 1; i <= level; i++) {
            cursor->next[i] = update[i]->next[i];
            update[i]->next[i] = cursor;
        }

    }

    return 0;

}

/*
 * Search the skiplist for a node specified by its ID
 *
 * */
msg_sl_node *search_msg_sl(msg_sl *list, unsigned int id) {

    msg_sl_node *cursor;
    cursor = list->head;

    // loop through the different levels of lanes until found
    int i;
    for (i = list->level; i >= 1; i--) {

        while (cursor->next[i]->id < id) {
            cursor = cursor->next[i];
        }

    }

    // if found
    if (cursor->next[1]->id == id) {

        return cursor->next[1];

    }

    return NULL;

}


/*
 * Frees up a skiplist node
 *
 * */
void free_msg_sl_node(msg_sl_node *node) {

    if (node) {

        // free up the pointer after the node
        kfree(node->next);
        node->next = NULL;

        // destroy the queue in the node
        destroy_msg_q(node->msg_queue);

        // free up the node
        kfree(node);
        node = NULL;

    }

}


/*
 * Remove a skiplist node specified by its ID and UID
 *
 * */
int remove_msg_sl(msg_sl *list, unsigned int id, int uid) {

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *cursor;
    cursor = list->head;

    // search through the skiplist
    int i;
    for (i = list->level; i >= 1; i--) {
        while (cursor->next[i]->id < id) {
            cursor = cursor->next[i];
        }
        update[i] = cursor;
    }

    cursor = cursor->next[1];

    // if the ID matches and the UID matches or is unprotected (-1)
    if ((cursor->id == id) && (cursor->uid == uid || cursor->uid == -1)) {

        // move the nodes after the current node
        for (i = 1; i <= list->level; i++) {
            if (update[i]->next[i] != cursor) {
                break;
            }
            update[i]->next[i] = cursor->next[i];
        }

        free_msg_sl_node(cursor);

        while (list->level > 1 &&
                list->head->next[list->level] == list->head) {
            list->level--;
        }

        return 0;

    }

    // if not found and removed
    return 1;

}

/*
 * Destroy the skiplist
 *
 * */
void destroy_msg_sl(msg_sl *list) {

    msg_sl_node *cursor;
    cursor = list->head->next[1];

    while (cursor != list->head) {

        msg_sl_node *next_node = cursor->next[1];

        destroy_msg_q(cursor->msg_queue);

        kfree(cursor->next);
        cursor->next = NULL;

        kfree(cursor);
        cursor = next_node;

    }

    kfree(cursor->next);
    cursor->next = NULL;

    kfree(cursor);
    cursor = NULL;

    kfree(list);
    list = NULL;

}
