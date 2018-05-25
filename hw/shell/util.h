/*
 * util.h
 *
 * Header file to hold global variables and prototypes for helper functions.
 *
 * */

#ifndef UTIL_H
#define UTIL_H

#include <stdio.h>

/* *********** FUNCTION PROTOTYPES *********** */

void read_stdin(char *, size_t *);

/* Unescape a given string, transforming all escape sequences and quoted strings
   as appropriate.
   Note: You are responsible for freeing the string returned by this function */
char *unescape(const char *);

#endif // UTIL_H
