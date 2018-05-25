/*
 * config.h
 *
 * Header file to hold global variables and prototypes for functions related
 * to the main functionality of the shell
 *
 * */

#ifndef CONFIG_H
#define CONFIG_H

#include <termios.h>

/* *********** STATIC VARIABLES *********** */

static pid_t shell_pgid;
static struct termios shell_tmodes;

#endif // CONFIG_H
