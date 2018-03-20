#include "mbx.h"
//#include <string.h>

#include <stdio.h>
#include <stdlib.h>

int main() {

    unsigned char *byte_buffer = (unsigned char *) "i ♥ u";
    unsigned char *human_buffer = (unsigned char *) "i love you";
    unsigned char *buf = malloc(sizeof(char));

    printf("init: %ld\n", slmbx_init(16, 2));
    printf("create1: %ld\n", slmbx_create(4, 1));
    printf("send1: %ld\n", slmbx_send(4, human_buffer, 10));
    printf("send2: %ld\n", slmbx_send(4, byte_buffer, 10));

    printf("len: %ld\n", slmbx_length(4));
    printf("rec1: %ld ", slmbx_recv(4, buf, 5));
    printf("msg: %s\n", buf);

    printf("len: %ld\n", slmbx_length(4));
    printf("rec1: %ld ", slmbx_recv(4, buf, 5));
    printf("msg: %s\n", buf);

    free(buf);
    printf("destroy: %ld\n", slmbx_shutdown());

    return 0;

}
