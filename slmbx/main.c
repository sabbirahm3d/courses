#include "mbx.h"

#include <stdio.h>

int main() {

    printf("init: %ld\n", slmbx_init(16, 4));
    printf("create1: %ld\n", slmbx_create(4, 1));
    printf("create2: %ld\n", slmbx_create(4, 1));
    printf("send1: %ld\n", slmbx_send(4, "success1", 10));
    printf("send2: %ld\n", slmbx_send(4, "success2", 10));
    printf("send3: %ld\n", slmbx_send(3, "success3", 10));
    printf("count1: %ld\n", slmbx_count(4));
    printf("count2: %ld\n", slmbx_count(3));
    printf("destroy: %ld\n", slmbx_shutdown());

    return 0;

}
