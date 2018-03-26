#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>

#define __NR_hello 333

long hello_syscall(void) {

    return syscall(__NR_hello);

}

int main(int argc, char *argv[]) {

    hello_syscall();
    return 0;

}
