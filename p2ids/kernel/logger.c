#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>
#include <wait.h>
#include <time.h>

#include <linux/kernel.h>
#include <sys/syscall.h>
#include <string.h>

#include "logger.h"

#define __NR_ids_log 333

long ids_log_syscall(unsigned long *syscall_nr) {

    return syscall(__NR_ids_log, syscall_nr);

}

int main(int argc, char *argv[]) {

    // array for the different tokens in the command
    char **cmd_tokens = malloc(argc * sizeof(*cmd_tokens));

    for (int i = 1; argv[i]; i++) {
        cmd_tokens[i] = argv[i];
    }

    char *file_name = malloc(sizeof(char));
    strcpy(file_name, "../idsdata/");
    strcat(file_name, argv[1]);
    strcat(file_name, ".log");

    launch_proc(cmd_tokens, file_name);

}


void launch_proc(char **cmd, char *file_name) {

    FILE *log_file = fopen(file_name, "w");

    if (!log_file) {
        printf("Error opening file\n");
        exit(1);
    }

    unsigned long syscall_nr;
    ids_log_syscall(&syscall_nr);

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

    fprintf(log_file, "%d %ld %ld\n", pid, syscall_nr, (unsigned long) time(NULL));

    // wait for child to finish
    waitpid(pid, NULL, 0);

    fclose(log_file);

}


int wait_for_syscall(pid_t child) {

    int status;

    while (1) {

        waitpid(child, &status, 0);
        if (WIFSTOPPED(status) && WSTOPSIG(status) & 0x80) {
            return 0;
        }
        if (WIFEXITED(status)) {
            return 1;
        }
    }

}
