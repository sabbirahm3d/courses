//#include <linux/time.h>
//#include <linux/cred.h>
//#include <kernel/signal.h>
//#include <linux/slab.h>
//#include <linux/signal.h>

//#include <sys/wait.h>
//#include <stdlib.h>
#include <stdio.h>

#include "local_logger.h"
#include "local_miniptrace.h"

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

int main() {

    char **args = malloc(sizeof(char));
    //char **args = kmalloc(sizeof(char));

    *args = "ls";

    sys_ids_log(args);

    free(args);

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

    ptrace(PTRACE_TRACEME, 0, 0, 0);
    kill(getpid(), SIGSTOP);

    return execvp(argv[0], argv);

}

int do_trace(pid_t child) {

    int status, syscall_num;
    long addr_sz = sizeof(long) * 15;
    waitpid(child, &status, 0);
    ptrace(PTRACE_SETOPTIONS, child, 0, (void *) PTRACE_O_TRACESYSGOOD);

    while (1) {

        if (wait_for_syscall(child)) {
            break;
        }

        syscall_num = ptrace(PTRACE_PEEKUSER, child, (void *) addr_sz, 0);
        printf("%d %d\n", child, syscall_num);

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
