#include <errno.h>
#include <stdio.h>
#include <unistd.h>

#include "customerrno.h"
#include "slmbxsyscall.h"

int main() {

    unsigned int ptrs = 16;
    unsigned int prob = 2;

    int MAXID = 1000;
    int failed = 0;

    printf("Initialize system (%d ptrs, %d prob)", ptrs, prob);
    if (slmbx_init_syscall(ptrs, prob) == -1) {
        printf("\t\terrno: %d (%s)", errno, str_errno(errno));
    }
    printf("\n");
    printf("---------------------------------------------------------\n");

    printf("Create %d mailboxes... ", MAXID);
    for (int i = 1; i < MAXID; i++) {
        if (slmbx_create_syscall(i, 1) == -1) {
            printf("FAILED! \t\t\terrno: %d (%s)\n", errno, str_errno(errno));
            failed = 1;
            break;
        }
    }

    if (!failed) {

        printf("SUCCESS!\n");
        failed = 0;

        printf("Delete all %d mailboxes... ", MAXID);
        for (int i = 1; i < MAXID; i++) {
            if (slmbx_destroy_syscall(i) == -1) {
                printf("FAILED! \t\t\terrno: %d (%s)\n", errno, str_errno(errno));
                failed = 1;
                break;
            }
        }

    }

    if (!failed) {
        printf("SUCCESS!\n");
    }

    printf("---------------------------------------------------------\n");

    printf("Destroy system");
    if (slmbx_shutdown_syscall() == -1) {
        printf("\t\t\t\t\terrno: %d (%s)", errno, str_errno(errno));
    }
    printf("\n");

    return 0;

}
