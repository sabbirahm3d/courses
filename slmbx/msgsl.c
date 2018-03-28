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

    msg_sl_node *cursor
    cursor = list->head;
    int i;

    for (i = list->level; i >= 1; i--) {

        while (cursor->next[i]->id < id) {
            cursor = cursor->next[i];
        }

    }

    if (cursor->next[1]->id == id) {

        return cursor->next[1];

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

    printk("passed: id: %u uid: %d\n", id, uid);

    msg_sl_node *update[MAXLVL + 1];
    msg_sl_node *cursor;
    cursor = list->head;

    int i;

    for (i = list->level; i >= 1; i--) {
        while (cursor->next[i]->id < id){
            cursor = cursor->next[i];
        }
        update[i] = cursor;
    }

    cursor = cursor->next[1];
    printk("passed: id: %u uid: %d\n", id, uid);
    printk("cursor: id: %u uid: %d\n", cursor->id, uid);

    if (cursor->id == id && cursor->uid == uid) {

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

        printk("in remove_msg_sl, worked\n");

        return 0;

    }

    printk("didn't work\n");
    dump_msg_sl(list);

    return 1;

}

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


void dump_msg_sl(msg_sl *list) {

    msg_sl_node *cursor;
    cursor = list->head;

    while (cursor && cursor->next[1] != list->head) {

        printk("{id: %d, lvl: %d, msg: [", cursor->next[1]->id,
               cursor->next[1]->uid);
        dump_msg_q(cursor->next[1]->msg_queue);
        printk("]} -> \n");
        cursor = cursor->next[1];

    }

    printk("{NULL}\n");

}

