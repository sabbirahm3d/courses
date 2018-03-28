//
// Created by sabbir on 3/15/18.
//

#include <linux/kernel.h>
#include <linux/random.h>
#include <linux/slab.h>
#include "msgsl.h"

static unsigned int MAXID = 4294967295;
static unsigned int next_random = 9001;
static unsigned int MULTIPLIER = 1103515245;
static unsigned int INCREMENT = 12345;
unsigned int MAXLVL;
unsigned int PROB;


static unsigned int generate_random_int(void) {

    next_random = next_random * MULTIPLIER + INCREMENT;
    return (next_random / 65536) % 32768;

}

static void seed_random(unsigned int seed) {

    next_random = seed;

}

static void ceil_log(unsigned int opand, unsigned int base) {

    unsigned int level = 0;
    unsigned int total = 1;

    while (total < opand) {
        total = total * base;
        level++;
    }

    MAXLVL = level;
    PROB = base;

}


unsigned int rand_level(void) {

    unsigned int level = 1;

    while ((generate_random_int() < 32767 / PROB) && (level < MAXLVL)) {
        level++;
    }

    return level;
}


msg_sl *init_msg_sl(msg_sl *list, unsigned int opand, unsigned int base) {

    msg_sl_node *header;
    header = kmalloc(sizeof(msg_sl_node), GFP_KERNEL);

    ceil_log(opand, base);

    unsigned int rand;
    get_random_bytes(&rand, sizeof(rand));

    seed_random(rand);

    list->head = header;
    header->id = MAXID;
    header->next = kmalloc(sizeof(msg_sl_node *) * (MAXLVL + 1), GFP_KERNEL);

    int i;

    for (i = 0; i <= MAXLVL; i++) {
        header->next[i] = list->head;
    }

    list->level = 1;

    return list;

}


int insert_msg_sl(msg_sl *list, unsigned int id, int uid) {

    msg_q *msg_queue;
    msg_queue = kmalloc(sizeof(msg_q), GFP_KERNEL);
    init_msg_q(msg_queue);

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *head;
    head = list->head;

    int i;

    for (i = list->level; i >= 1; i--) {

        while (head->next[i]->id < id) {
            head = head->next[i];
        }
        update[i] = head;

    }

    head = head->next[1];

    if (id == head->id) {

        head->msg_queue = msg_queue;
        head->uid = uid;

    } else {

        int level = rand_level();

        if (level > list->level) {
            for (i = list->level + 1; i <= level; i++) {
                update[i] = list->head;
            }

            list->level = level;

        }

        head = kmalloc(sizeof(msg_sl_node), GFP_KERNEL);
        head->id = id;
        head->msg_queue = msg_queue;
        head->uid = uid;
        head->next = kmalloc(sizeof(msg_sl_node *) * (level + 1), GFP_KERNEL);

        for (i = 1; i <= level; i++) {
            head->next[i] = update[i]->next[i];
            update[i]->next[i] = head;
        }

    }

    return 0;

}


msg_sl_node *search_msg_sl(msg_sl *list, unsigned int id) {

    msg_sl_node *x = list->head;
    int i;

    for (i = list->level; i >= 1; i--) {

        while (x->next[i]->id < id) {
            x = x->next[i];
        }

    }

    if (x->next[1]->id == id) {

        return x->next[1];

    }

    return NULL;

}


void free_msg_sl_node(msg_sl_node *msg_sl_node_obj) {

    if (msg_sl_node_obj) {

        kfree(msg_sl_node_obj->next);
        msg_sl_node_obj->next = NULL;

        destroy_msg_q(msg_sl_node_obj->msg_queue);

        kfree(msg_sl_node_obj);
        msg_sl_node_obj = NULL;

    }

}


int remove_msg_sl(msg_sl *list, unsigned int id, int uid) {

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *x = list->head;
    int i;

    for (i = list->level; i >= 1; i--) {
        while (x->next[i]->id < id)
            x = x->next[i];
        update[i] = x;
    }

    x = x->next[1];

    if (x->id == id && x->next[1]->uid == uid) {

        for (i = 1; i <= list->level; i++) {
            if (update[i]->next[i] != x)
                break;
            update[i]->next[i] = x->next[i];
        }

        free_msg_sl_node(x);

        while (list->level > 1 &&
                list->head->next[list->level] == list->head) {
            list->level--;
        }

        printk("in remove_msg_sl, worked\n");

        return 0;

    }

    return 1;

}

void destroy_msg_sl(msg_sl *list) {

    msg_sl_node *cur_node;
    cur_node = list->head->next[1];

    while (cur_node != list->head) {

        msg_sl_node *next_node = cur_node->next[1];

        destroy_msg_q(cur_node->msg_queue);

        kfree(cur_node->next);
        cur_node->next = NULL;

        kfree(cur_node);
        cur_node = next_node;

    }

    kfree(cur_node->next);
    cur_node->next = NULL;

    kfree(cur_node);
    cur_node = NULL;

    kfree(list);
    list = NULL;

}

/*
void dump_msg_sl(msg_sl *list) {

    msg_sl_node *temp = list->head;
    while (temp && temp->next[1] != list->head) {
        printf("{id: %d, lvl: %d, msg: [", temp->next[1]->id,
               temp->next[1]->uid);
        dump_msg_q(temp->next[1]->msg_queue);
        printf("]} -> \n");
        temp = temp->next[1];
    }
    printf("{NULL}\n");

}
*/
