
#include <stdio.h>
#include <string.h>
#include "list.h"

int main(void) {


    linked_list *langs = list_new();

    double ptr = 9;
    char *n = "Ana";
    double ptr1 = 12.9;
    char *n1 = "Sabbir";
    double ptr2 = 19;
    char *n2 = "Us";

    list_rpush(langs, create_node(&n, &ptr));
    list_rpush(langs, create_node(&n1, &ptr1));
    list_rpush(langs, create_node(&n2, &ptr2));

    node *temp;
    list_iterator_t *it = list_iterator_new(langs, LIST_HEAD);
    while ((temp = list_iterator_next(it))) {
        printf("%s: %f\n", temp->name, *temp->grade);
    }

    node *found = list_find(langs, n);
    printf("found %s: %f\n", found->name, *found->grade);

    list_iterator_destroy(it);
    list_destroy(langs);


    return 0;

}
