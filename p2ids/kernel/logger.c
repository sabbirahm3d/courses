#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <linux/signal.h>
#include <linux/unistd.h>

//#include <sys/wait.h>
//#include <stdlib.h>
//#include <stdio.h>
//
#include "logger.h"
#include "miniptrace.h"

//int main() {
//
//    char **args = kmalloc(sizeof(char));
//    //char **args = kmalloc(sizeof(char));
//
//    *args = "pwd";
//
//    sys_ids_log(args);
//
//    kfree(args);
//
//}


int sys_ids_log(char **argv) {

    int i;
    for (i = 0; argv[i]; i++) {

        printk("%s ", argv[i]);

    }
    printk("\n");

    struct timespec ts;
//    getnstimeofday(&ts);

    printk("TIME: %.2lu:%.2lu:%.2lu:%.6lu \r\n",
           (ts.tv_sec / 3600) % (24),
           (ts.tv_sec / 60) % (60),
           ts.tv_sec % 60,
           ts.tv_nsec / 1000);

    pid_t child = fork();
    if (!child) {
        return do_child(argv);
    } else {
        return do_trace(child);
    }

}


int do_child(char **argv) {

    ptrace(PTRACE_TRACEME, 0, 0, 0);
    kill(current->pid, SIGSTOP);
    //kill(getpid(), SIGSTOP);

    return execvp(argv[0], argv);

}

int do_trace(pid_t child) {

    int status, syscall;
    long addr_sz = sizeof(long) * 15;
    waitpid(child, &status, 0);
    ptrace(PTRACE_SETOPTIONS, child, 0, (void *) PTRACE_O_TRACESYSGOOD);

    while (1) {

        if (wait_for_syscall(child)) {
            break;
        }

        syscall = ptrace(PTRACE_PEEKUSER, child, (void *) addr_sz, 0);
        printk("%d %d\n", child, syscall);

        if (wait_for_syscall(child)) {
            break;
        }

    }

    return 0;

}

int wait_for_syscall(pid_t child) {

    int status;

    while (1) {
        ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80) {
            return 0;
        }
        if (WIFEXITED(status)) {
            return 1;
        }
    }

}
