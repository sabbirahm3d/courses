/*
 * main.c
 *
 * Main script of sabbash. This file controls the processes and functionality
 * of the shell.
 *
 * The implementation on the initialization of the shell was extracted from:
 * http://www.gnu.org/software/libc/manual/html_node/Initializing-the-Shell.html
 *
 * */


#include "config.h"
#include "proc.h"
#include "util.h"

#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

#define ANSI_COLOR_GREY_BG "\x1b[48;5;241m"
#define ANSI_COLOR_WHITE "\x1b[37m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_RESET "\x1b[0m"

/*
 * Initialize the shell and all its signal handlers
 *
 * output:
 *
 *      0 if successful, 1 otherwise
 *
 * */
int shell_init() {

    // check if shell is running interactively
    if (isatty(STDIN_FILENO)) {

        // loop until we are in the foreground
        while (tcgetpgrp(STDIN_FILENO) != (shell_pgid = getpgrp())) {
            kill(shell_pgid, SIGTTIN);
        }

        // ignore interactive and job-control signals
        signal(SIGINT, SIG_IGN);
        signal(SIGQUIT, SIG_IGN);
        signal(SIGTSTP, SIG_IGN);
        signal(SIGTTIN, SIG_IGN);
        signal(SIGTTOU, SIG_IGN);
        signal(SIGCHLD, SIG_IGN);

        if (setpgid(shell_pgid, shell_pgid) < 0) {

            printf("Couldn't put the shell in its own process group\n");
            return 1;

        }

        // grab control of the terminal
        tcsetpgrp(STDIN_FILENO, shell_pgid);

        // save default terminal attributes for shell
        tcgetattr(STDIN_FILENO, &shell_tmodes);

        return 0;

    } else {

        printf("Could not make the shell interactive\n");
        return 1;

    }

}

/*
 * Main function of the program
 *
 * */
int main(int argc, char *argv[]) {

    char *line; // buffer for the user input
    char **cmd_tokens; // array for the different tokens in the command
    char *cur_dir = (char *) calloc(1024, sizeof(char));  // cwd string

    size_t len_cmd = 0;
    int num_tokens;
    int alive = 1;

    // if shell was not initialized successfully, exit program
    if (shell_init()) {
        return -1;
    }

    int exit_code;

    // main loop where the user input will be read and the prompt will be
    // printed
    while (alive) {

        printf(ANSI_COLOR_GREY_BG ANSI_COLOR_WHITE " %s"
                       ANSI_COLOR_RESET ANSI_COLOR_GREEN " $ "
                       ANSI_COLOR_RESET, getcwd(cur_dir, 1024));

        line = realloc(NULL, 0);

        // read line from user
        read_stdin(line, &len_cmd);

        // allocate enough space for the array to hold the command tokens
        cmd_tokens = malloc(len_cmd * sizeof(*cmd_tokens));

        // keep looping until a command is inputted
        if (!(*cmd_tokens = strtok(line, " \n\t"))) {
            continue;
        }

        // read all the tokens of the input
        num_tokens = 1;
        while ((cmd_tokens[num_tokens] = strtok(NULL, " \n\t"))) {
            num_tokens++;
        }

        // escape each token after command
        for (int i = 1; i < num_tokens; i++) {
            cmd_tokens[i] = unescape(cmd_tokens[i]);
        }

        alive = parse_cmd(cmd_tokens, &exit_code);

    }

    // free pointers
    free(line);
    line = NULL;

    free(cmd_tokens);
    cmd_tokens = NULL;

    return exit_code;  // exit code provided by user

}
