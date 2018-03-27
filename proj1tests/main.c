#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
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

long slmbx_send_syscall(unsigned int id, const unsigned char *msg,
                    unsigned int len) {

    return syscall(__NR_slmbx_send, id, msg, len);

}

long slmbx_recv_syscall(unsigned int id, unsigned char *msg,
                    unsigned int len) {

    return syscall(__NR_slmbx_recv, id, msg, len);

}

long slmbx_length_syscall(unsigned int id) {

    return syscall(__NR_slmbx_length, id);

}


int main() {

    unsigned int ptrs =16;
    unsigned int prob = 2;

    unsigned char *robot_buffer = (unsigned char *) "i ♥ you";
    unsigned char *human_buffer = (unsigned char *) "i love you";
    unsigned char *good_buf = malloc(sizeof(char));
    unsigned char *null_buf = NULL;

    unsigned int id = 4;
    unsigned int send_size = 10;
    unsigned int recv_size = 8;

    slmbx_init_syscall(ptrs, prob);
    printf("Initialize system (%d ptrs, %d prob) \t\terrno: %d\n",
        ptrs, prob, errno);
    printf("---------------------------------------------------------\n");

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);

    slmbx_create_syscall(id, 1);
    printf("Create a mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);

    slmbx_send_syscall(id, robot_buffer, send_size);
    printf("Send %d bytes of '%s' to mbx (id: %d) \terrno: %d\n",
        send_size, robot_buffer, id, errno);

    slmbx_send_syscall(id, human_buffer, send_size);
    printf("Send %d bytes of '%s' to mbx (id: %d) \terrno: %d\n",
        send_size, human_buffer, id, errno);
    printf("---------------------------------------------------------\n");

    slmbx_length_syscall(id);
    printf("Length of first message in mbx (id: %d) \t\terrno: %d\n",
        id, errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);

    slmbx_recv_syscall(id, good_buf, recv_size);
    printf("Receive %d bytes of %s in mbx (id: %d) \t\terrno: %d\n",
        recv_size, good_buf, id, errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);
    printf("---------------------------------------------------------\n");

    slmbx_length_syscall(id);
    printf("Length of first message in mbx (id: %d) \t\terrno: %d\n",
        id, errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);

    slmbx_recv_syscall(id, good_buf, recv_size);
    printf("Receive %d bytes of %s in mbx (id: %d) \t\terrno: %d\n",
        recv_size, good_buf, id, errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);
    printf("---------------------------------------------------------\n");

    slmbx_length_syscall(id);
    printf("Length of first message in mbx (id: %d) \t\terrno: %d\n",
        id, errno);

    slmbx_recv_syscall(id, good_buf, recv_size);
    printf("Receive %d bytes of %s in mbx (id: %d) \t\terrno: %d\n",
        recv_size, good_buf, id, errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);
    printf("---------------------------------------------------------\n");

    slmbx_shutdown_syscall();
    printf("Destroy system \t\t\t\t\terrno: %d\n", errno);

    slmbx_count_syscall(id);
    printf("Size of mbx (id: %d) \t\t\t\terrno: %d\n", id, errno);

    // free up testing buffers
    free(good_buf);
    free(null_buf);

    return 0;

}
