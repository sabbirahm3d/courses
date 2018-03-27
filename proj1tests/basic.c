#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/kernel.h>

#include "slmbxsyscall.h"

int main() {

    unsigned int ptrs = 16;
    unsigned int prob = 2;

    unsigned char *robot_buffer = (unsigned char *) "i ♥ you";
    unsigned char *human_buffer = (unsigned char *) "i love you";
    unsigned char *buf = malloc(sizeof(char));

    unsigned int id = 4;
    unsigned int send_size = 10;
    unsigned int recv_size = 8;

    int count;
    int length;

    printf("Initialize system (%d ptrs, %d prob)", ptrs, prob);
    if (slmbx_init_syscall(ptrs, prob) == -1) {
        printf("\t\terrno: %d", errno);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");

    printf("Create a mbx (id: %d)", id);
    if (slmbx_create_syscall(id, 1) == -1) {
        printf("\t\t\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Send %d bytes of '%s' to mbx (id: %d)", send_size,
        robot_buffer, id);
    if (slmbx_send_syscall(id, human_buffer, send_size) == -1) {
        printf(" \terrno: %d", errno);
    }
    printf("\n");

    printf("Send %d bytes of '%s' to mbx (id: %d)", send_size,
        human_buffer, id);
    if (slmbx_send_syscall(id, human_buffer, send_size) == -1) {
        printf(" \terrno: %d", errno);
    }
    printf("\n");

    printf("---------------------------------------------------------\n");

    printf("Length of first message in mbx (id: %d)", id);
    length = slmbx_length_syscall(id);
    if (length == -1) {
        printf("\t\terrno: %d", errno);
    } else {
        printf(": %d", length);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");

    printf("Receive %d bytes of %s in mbx (id: %d)", recv_size, buf, id);
    if (slmbx_recv_syscall(id, buf, recv_size) == -1) {
        printf("\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Length of first message in mbx (id: %d)", id);
    length = slmbx_length_syscall(id);
    if (length == -1) {
        printf("\t\terrno: %d", errno);
    } else {
        printf(": %d", length);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");

    printf("Receive %d bytes of %s in mbx (id: %d)", recv_size, buf, id);
    if (slmbx_recv_syscall(id, buf, recv_size) == -1) {
        printf("\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    // free up testing buffers
    free(buf);

    printf("Length of first message in mbx (id: %d)", id);
    length = slmbx_length_syscall(id);
    if (length == -1) {
        printf("\t\terrno: %d", errno);
    } else {
        printf(": %d", length);
    }
    printf("\n");

    printf("Receive %d bytes of %s in mbx (id: %d)", recv_size, buf, id);
    if (slmbx_recv_syscall(id, buf, recv_size) == -1) {
        printf("\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Destroy system");
    if (slmbx_shutdown_syscall() == -1) {
        printf("\t\t\t\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf(": %d", count);
    }
    printf("\n");

    return 0;

}
