#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define __NR_slmbx_init     333
#define __NR_slmbx_shutdown 334
#define __NR_slmbx_create   335
#define __NR_slmbx_destroy  336
#define __NR_slmbx_count    337
#define __NR_slmbx_send     338
#define __NR_slmbx_recv     339
#define __NR_slmbx_length   340

long slmbx_init_syscall(unsigned int ptrs, unsigned int prob) {

    return syscall(__NR_slmbx_init, ptrs, prob);

}

long slmbx_shutdown_syscall(void) {

    return syscall(__NR_slmbx_shutdown);

}

long slmbx_create_syscall(unsigned int id, int protected) {

    return syscall(__NR_slmbx_create, id, protected);

}

long slmbx_destroy_syscall(unsigned int id) {

    return syscall(__NR_slmbx_destroy, id);

}

long slmbx_count_syscall(unsigned int id) {

    return syscall(__NR_slmbx_count, id);

}

long slmbx_send_syscall(unsigned int id, const unsigned char *msg, unsigned int len) {

    return syscall(__NR_slmbx_send, id, msg, len);

}

long slmbx_recv_syscall(unsigned int id, unsigned char *msg, unsigned int len) {

    return syscall(__NR_slmbx_recv, id, msg, len);

}

long slmbx_length_syscall(unsigned int id) {

    return syscall(__NR_slmbx_length, id);

}


int main(int argc, char *argv[]) {

    unsigned int ptrs, prob;
    ptrs = 16;
    prob = 2;

    printf("init: %ld\n", slmbx_init_syscall(ptrs, prob));

    unsigned char *robot_buffer = (unsigned char *) "i ♥ you";
    unsigned char *human_buffer = (unsigned char *) "i love you";
    unsigned char *buf = malloc(sizeof(char));
    unsigned char *buf1 = NULL;

    unsigned int id = 4;
    unsigned int send_size = 7;
    unsigned int recv_size = 5;

    // printf("create: %ld\n", slmbx_create_syscall(id, 1));
    // printf("send1: %ld\n", slmbx_send_syscall(id, human_buffer, send_size));
    // printf("send2: %ld\n", slmbx_send_syscall(id, robot_buffer, send_size));

    // printf("len1: %ld ", slmbx_length_syscall(id));
    // printf("rec1: %ld ", slmbx_recv_syscall(id, buf, recv_size));
    // printf("msg1: %s\n", buf);

    // printf("len2: %ld ", slmbx_length_syscall(id));
    // printf("rec2: %ld ", slmbx_recv_syscall(id, buf1, recv_size));
    // printf("msg2: %s\n", buf1);

    printf("destroy: %ld\n", slmbx_shutdown_syscall());

    free(buf);
    free(buf1);

    return 0;

}
