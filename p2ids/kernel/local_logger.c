#include <stdio.h>
#include <unistd.h>
#include <linux/kernel.h>
#include <sys/syscall.h>
#define __NR_ids_log 333

long ids_log_syscall(void) {
    return syscall(__NR_ids_log);
}

#include "local_logger.h"
// #include "local_miniptrace.h"

# define WIFSTOPPED(status)    __WIFSTOPPED (__WAIT_INT (status))
# define WSTOPSIG(status)    __WSTOPSIG (__WAIT_INT (status))
#define    __WIFSTOPPED(status)    (((status) & 0xff) == 0x7f)
/* If WIFSTOPPED(STATUS), the signal that stopped the child.  */
#define    __WSTOPSIG(status)    __WEXITSTATUS(status)
/* If WIFEXITED(STATUS), the low-order 8 bits of the status.  */
#define    __WEXITSTATUS(status)    (((status) & 0xff00) >> 8)

# define WIFEXITED(status)    __WIFEXITED (__WAIT_INT (status))
/* Nonzero if STATUS indicates normal termination.  */
#define    __WIFEXITED(status)    (__WTERMSIG(status) == 0)
/* If WIFSIGNALED(STATUS), the terminating signal.  */
#define    __WTERMSIG(status)    ((status) & 0x7f)
#   define __WAIT_INT(status) \
  (__extension__ (((union { __typeof(status) __in; int __i; }) \
           { .__in = (status) }).__i))

/* Allocate SIZE bytes of memory.  */
extern void *malloc(size_t __size);
/* Allocate NMEMB elements of SIZE bytes each, all initialized to 0.  */

/* Free a block allocated by `malloc', `realloc' or `calloc'.  */
extern void free(void *__ptr);


#define SIGSTOP 19
#define SIGTERM 15

int main() {

    char **args = malloc(sizeof(char));

    *args = "ls";

    launch_proc(args);

    free(args);

}

void launch_proc(char **cmd) {

    unsigned long syscall_nr;
    long ret = ids_log_syscall(&syscall_nr);

    int pid = fork();

    if (pid == -1) {

        printf("Child process could not be created\n");
        return;

    } else if (!pid) {  // child process

        // end the process for invalid commands
        if (execvp(cmd[0], cmd) == -1) {
            printf("Command not found: %s\n", cmd[0]);
            kill(getpid(), SIGTERM);
        }

    }

    printf("%d %ld %ld\n", pid, syscall_nr, ret);
    // wait for child to finish
    waitpid(pid, NULL, 0);

}


int sys_ids_log(char **argv) {

    int i;
    for (i = 0; argv[i]; i++) {

        printf("%s ", argv[i]);

    }
    printf("\n");

    pid_t child = fork();
    if (!child) {
        return do_child(argv);
    } else {
        return do_trace(child);
    }

}




int do_child(char **argv) {

    return execvp(argv[0], argv);

}

int do_trace(pid_t child) {

    int status, syscall_num;
    long addr_sz = sizeof(long) * 15;
    waitpid(child, &status, 0);
    ids_log_syscall();

    while (1) {

        if (wait_for_syscall(child)) {
            break;
        }

        ids_log_syscall();

        if (wait_for_syscall(child)) {
            break;
        }

    }

    return 0;

}

int wait_for_syscall(pid_t child) {

    int status;

    while (1) {
        ids_log_syscall();
        // ptrace(PTRACE_SYSCALL, child, 0, 0);
        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80) {
            return 0;
        }
        if (WIFEXITED(status)) {
            return 1;
        }
    }

}
