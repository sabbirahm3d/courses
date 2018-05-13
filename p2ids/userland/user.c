#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#define __NR_ids_log 333

long ids_log_syscall(void) {
    return syscall(__NR_ids_log);
}

int main(int argc, char *argv[]) {
    ids_log_syscall();
    return 0;
}