#ifndef MBX_H
#define MBX_H

#include <string.h>

unsigned char *u_strcpy(unsigned char *, const unsigned char *);

size_t u_strlen(const unsigned char *);

long slmbx_init(unsigned int, unsigned int);

long slmbx_shutdown(void);

long slmbx_create(unsigned int, int);

long slmbx_destroy(unsigned int);

long slmbx_count(unsigned int);

long slmbx_send(unsigned int, const unsigned char *, unsigned int);

long slmbx_recv(unsigned int, unsigned char *, unsigned int);

long slmbx_length(unsigned int);

#endif
