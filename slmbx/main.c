#include "util.h"
#include "rand.h"
#include "slds.h"

#include <stdio.h>


int main() {

    int arr[] = {3, 6, 9, 2, 11, 1, 4, 100, 98, 1000001}, i;
    skiplist *list;
    list = (skiplist *) malloc(sizeof(skiplist));
    skiplist_init(list);

    printf("Insert:--------------------\n");
    for (i = 0; i < sizeof(arr) / sizeof(arr[0]); i++) {
        skiplist_insert(list, arr[i], arr[i]*rand());
    }
    skiplist_dump(list);

    printf("Search:--------------------\n");
    int keys[] = {3, 4, 7, 10, 111};

    for (i = 0; i < sizeof(keys) / sizeof(keys[0]); i++) {
        node *x = skiplist_search(list, keys[i]);
        if (x) {
            printf("id = %d, data = %d\n", keys[i], x->data);
        } else {
            printf("id = %d, not found\n", keys[i]);
        }
    }

    printf("Search:--------------------\n");
    skiplist_delete(list, 3);
    skiplist_delete(list, 9);
    skiplist_dump(list);
    skiplist_free(list);

    return 0;

}
