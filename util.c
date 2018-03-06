/*
 * util.c
 *
 * Implementation of helper functions in sabbash.
 *
 * */

#include "util.h"

#include <stdlib.h>
#include <string.h>

/*
 * Function to properly allocate space for the buffer to read standard inputs
 *
 * inputs:
 *
 *      char *buf   : the buffer read from stdin
 *      size_t *len : pointer to length of the stdin input
 *
 * */
void read_stdin(char *buf, size_t *len) {

    size_t size = 0;
    size_t last = 0;

    while (!feof(stdin) && buf[last] != '\n') {

        // defined as "the optimal read size for this platform"
        size += BUFSIZ;

        // reallocate more space for the buffer
        buf = realloc(buf, size);

        fgets(buf + last, size, stdin);

        // keep track of buffer length
        *len = strlen(buf);
        last = *len - 1;

    }

}
