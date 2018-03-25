
#include "mbx.h"

#include <stdio.h>

int main() {

    unsigned char *robot_buffer = (unsigned char *) "i ♥ you";
    unsigned char *human_buffer = (unsigned char *) "i love you";
    unsigned char *buf = malloc(sizeof(char));
    unsigned char *buf1 = NULL;

    printf("char size %u\n", u_strlen(robot_buffer));

    unsigned int id = 4;
    unsigned int msg_size = 999999;

    printf("init: %ld\n", slmbx_init(16, 2));
    printf("create1: %ld\n", slmbx_create(id, 1));
    printf("create1: %ld\n", slmbx_create(id - 1, 1));
    printf("send1: %ld\n", slmbx_send(id, human_buffer, 999));
    printf("send2: %ld\n", slmbx_send(id, robot_buffer, 7));

    printf("len1: %ld ", slmbx_length(id));
    printf("rec1: %ld ", slmbx_recv(id, buf, msg_size));
    printf("msg1: %s\n", buf);

    printf("len2: %ld ", slmbx_length(id));
    printf("rec2: %ld ", slmbx_recv(id, buf1, msg_size));
    printf("msg2: %s\n", buf1);

    printf("destroy: %ld\n", slmbx_shutdown());
    free(buf);
    free(buf1);

    return 0;

}
