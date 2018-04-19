/*
 * proc.c
 *
 * Implementation of functions related to shell processes in sabbash.
 *
 * */

#include "proc.h"
#include "util.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/*
 * Prints information on sabbash, including features and limitations
 *
 * */
void print_help() {

    char *help_msg =
            "===============================================================\n"
                    "--------------------------- sabbash ---------------------------\n"
                    "------------------ Super Awesome Better BASH ------------------\n"
                    "===============================================================\n"
                    "-------------------------- By Sabbir --------------------------\n"
                    "===============================================================\n"
                    "\nMost basic commands are supported\n"
                    "Features to be added soon:\n"
                    "1. Piping\n"
                    "2. Background processes\n"
                    "3. Chaining commands\n"
                    "4. Scripting\n"
                    "5. Killing and suspending processes\n"
                    "6. Handling other special characters and escaping\n"
                    "7. And more...\n";

    printf("%s", help_msg);

}


/*
 * Parses the user inputted commands
 *
 * inputs:
 *
 *      char **cmd      : array of command arguments provided by user
 *      int *exit_code  : pointer to exit argument
 *
 * output:
 *
 *      0 to exit program successfully, 1 to keep program alive
 *
 * */
int parse_cmd(char **cmd, int *exit_code) {

    if (!strcmp(cmd[0], "exit")) {  // quit shell

        if (!cmd[1]) {

            *exit_code = 0;
            return 0;


        } else if ((*exit_code = atoi(cmd[1])) && !cmd[2]) {

            return 0;

        } else {

            printf("Invalid arguments provided to exit\n");

        }


    } else if (!strcmp(cmd[0], "cd") || !strcmp(cmd[0], "chdir")) {  // change
        // directory

        change_dir(cmd);

    } else if (!strcmp(cmd[0], "echo")) {  // echo

        if (cmd[2]) {

            char *full_arg = malloc(sizeof(char));
            strcpy(full_arg, cmd[1]);
            for (int i = 2; cmd[i]; i++) {

                strcat(full_arg, " ");
                strcat(full_arg, cmd[i]);

            }

            printf("%s\n", unescape(full_arg));

        } else {

            printf("%s\n", unescape(cmd[1]));

        }

    } else if (!strcmp(cmd[0], "que?")) {  // print information on the shell

        print_help();


    } else {

        // if none of the above commands
        launch_proc(cmd);

    }

    return 1;

}

/*
 * Launches processes from commands provided
 *
 * inputs:
 *
 *      char **cmd  : array of command arguments provided by user
 *
 * */
void launch_proc(char **cmd) {

    int pid = fork();

    if (pid == -1) {

        printf("Child process could not be created\n");
        return;

    } else if (!pid) {  // child process

        // end the process for invalid commands
        if (execvp(cmd[0], cmd) == -1) {
            printf("sabbash: command not found: %s\n", cmd[0]);
            kill(getpid(), SIGTERM);
        }

    }

    // wait for child to finish
    waitpid(pid, NULL, 0);

}

/*
 * Change directory to path provided
 *
 * inputs:
 *
 *      char **path : path string provided in the user's command
 *
 * */
void change_dir(char **path) {

    // change directory to home if no arguments or "~" were provided
    if (path[1] == NULL || !strcmp(path[1], "~")) {

        chdir(getenv("HOME"));

    } else {

        // attempt to change directory to path provided, and prompt if invalid
        if (chdir(path[1]) == -1) {
            printf("cd: no such file or directory: %s\n", path[1]);
        }

    }

}
