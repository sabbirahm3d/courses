/*
 * proc.h
 *
 * Header file to hold global variables and prototypes for functions related
 * to shell processes in sabbash.
 *
 * */

#ifndef PROC_H
#define PROC_H


/* *********** FUNCTION PROTOTYPES *********** */

void print_help();

int parse_cmd(char **, int*);

void change_dir(char **);

void launch_proc(char **);


#endif // PROC_H
