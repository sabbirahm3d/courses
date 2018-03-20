#include "mbx.h"
//#include <string.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned char *buffer = malloc(sizeof(char));

    printf("init: %ld\n", slmbx_init(16, 4));
    printf("create1: %ld\n", slmbx_create(4, 1));
    printf("create2: %ld\n", slmbx_create(4, 1));
    printf("send1: %ld\n", slmbx_send(4, "success1", 10));
    printf("rec1: %ld\n", slmbx_recv(4, buffer, 2));
    printf("msg: %s\n", buffer);
    free(buffer);
//    printf("send2: %ld\n", slmbx_send(4, "success2", 10));
//    printf("send3: %ld\n", slmbx_send(3, "success3", 10));
    printf("count1: %ld\n", slmbx_count(4));
    printf("count2: %ld\n", slmbx_count(3));
    printf("destroy: %ld\n", slmbx_shutdown());
    printf("init: %ld\n", slmbx_init(16, 8));
    printf("destroy: %ld\n", slmbx_shutdown());

    return 0;

}
