#include "util.h"
#include "rand.h"
#include "msgsl.h"

#include <stdio.h>


int main() {

    int arr[] = {3, 6, 9, 2, 11, 1, 4, 100, 98, 1000001}, i;
    msg_sl *list;
    list = (msg_sl *) malloc(sizeof(msg_sl));
    init_msg_sl(list);

    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        insert_msg_sl(list, arr[i], arr[i]);
    }
    dump_msg_sl(list);

    printf("Search:--------------------\n");
    int keys[] = {3, 4, 7, 10, 111};

    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        msg_sl_node *x = search_msg_sl(list, keys[i]);
        if (x) {
            printf("id = %d, data = %d\n", keys[i], x->data);
        } else {
            printf("id = %d, not found\n", keys[i]);
        }
    }

    printf("Search:--------------------\n");
    remove_msg_sl(list, 3);
    remove_msg_sl(list, 9);
    dump_msg_sl(list);
    destroy_msg_sl(list);

    return 0;

}
