#include <errno.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <linux/kernel.h>

#include "slmbxsyscall.h"

int main() {

    unsigned int ptrs = 16;
    unsigned int prob = 2;

    unsigned char *send_buf = (unsigned char *) "i ♥ you";
    unsigned char *recv_buf = malloc(sizeof(char));

    int MAXID = 1000;
    unsigned int send_size = MAXID;
    int failed = 0;
    int id = 1;
    int count;

    printf("Initialize system (%d ptrs, %d prob)", ptrs, prob);
    if (slmbx_init_syscall(ptrs, prob) == -1) {
        printf("\t\terrno: %d", errno);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Create a mbx (id: %d)", id);
    if (slmbx_create_syscall(id, 1) == -1) {
        printf("\t\t\t\terrno: %d", errno);
    }
    printf("\n");

    printf("Send %d messages... ", MAXID);
    for (int i = 0; i < MAXID; i++) {
        if (slmbx_send_syscall(id, send_buf, send_size) == -1) {
            printf("FAILED! \t\t\terrno: %d\n", errno);
            failed = 1;
            break;
        }
    }

    if (!failed) {

        printf("SUCCESS!\n");
        failed = 1;
        printf("Receive the %d messages... ", MAXID);
        for (int i = 0; i < MAXID; i++) {
            if (slmbx_recv_syscall(id, recv_buf, send_size) == -1) {
                printf("FAILED! \t\t\terrno: %d\n", errno);
                failed = 1;
                break;
            }
        }

    }

    if (!failed) {
        printf("SUCCESS!\n");
    }

    printf("Size of mbx (id: %d)", id);
    count = slmbx_count_syscall(id);
    if (count == -1) {
        printf("\t\t\t\terrno: %d", errno);
    } else {
        printf("\t\t\t\tcount: %d", count);
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Destroy system");
    if (slmbx_shutdown_syscall() == -1) {
        printf("\t\t\t\t\terrno: %d", errno);
    }
    printf("\n");

    return 0;

}
