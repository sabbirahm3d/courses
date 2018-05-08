#include <sys/wait.h>
#include <unistd.h>

#include <stdlib.h>
#include <stdio.h>

#include "miniptrace.h"

int do_child(char **argv);

int do_trace(pid_t child);

int wait_for_syscall(pid_t child);

int main(int argc, char **argv) {

    if (argc < 2) {
        fprintf(stderr, "Usage: %s prog args\n", argv[0]);
        exit(1);
    }

    int i = 1;
    while (argv[i]) {

        fprintf(stderr, "%s ", argv[i]);
        i++;

    }
    fprintf(stderr, "\n");

    pid_t child = fork();
    if (!child) {
        return do_child(argv + 1);
    } else {
        return do_trace(child);
    }
}

int do_child(char **argv) {

    ptrace(PTRACE_TRACEME);
    kill(getpid(), SIGSTOP);

    return execvp(argv[0], argv);

}

int do_trace(pid_t child) {

    int status, syscall;
    waitpid(child, &status, 0);
    ptrace(PTRACE_SETOPTIONS, child, 0, PTRACE_O_TRACESYSGOOD);

    while (1) {

        if (wait_for_syscall(child)) {
            break;
        }

        syscall = ptrace(PTRACE_PEEKUSER, child, sizeof(long) * 15);
        fprintf(stdout, "%d %d\n", child, syscall);

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
