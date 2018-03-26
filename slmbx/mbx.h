#ifndef MBX_H
#define MBX_H

#ifdef DEBUG
#define DEBUG_UID 1
#else
#define DEBUG_UID 0
#endif

#include <linux/unistd.h>
#include <linux/errno.h>
#include <linux/kernel.h>


long slmbx_init(unsigned int, unsigned int);

long slmbx_shutdown(void);

long slmbx_create(unsigned int, int);

long slmbx_destroy(unsigned int);

long slmbx_count(unsigned int);

long slmbx_send(unsigned int, const unsigned char *, unsigned int);

long slmbx_recv(unsigned int, unsigned char *, unsigned int);

long slmbx_length(unsigned int);

#endif
