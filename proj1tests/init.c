#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define __NR_slmbx_init 333

long slmbx_init_syscall(unsigned int ptrs, unsigned int prob) {

    return syscall(__NR_slmbx_init, ptrs, prob);

}


int main() {

    unsigned int ptrs, prob;
    ptrs = 16;
    prob = 2;

    printf("init: %ld\n", slmbx_init_syscall(ptrs, prob));

    return 0;

}
