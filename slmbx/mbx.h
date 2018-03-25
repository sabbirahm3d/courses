#ifndef MBX_H
#define MBX_H

#ifdef DEBUG
#define DEBUG_UID 1
#else
#define DEBUG_UID 0
#endif

#include <stdlib.h>
#include <linux/unistd.h>
#include <linux/errno.h>
#include <linux/kernel.h>


asmlinkage long slmbx_init(unsigned int, unsigned int);

asmlinkage long slmbx_shutdown(void);

asmlinkage long slmbx_create(unsigned int, int);

asmlinkage long slmbx_destroy(unsigned int);

asmlinkage long slmbx_count(unsigned int);

asmlinkage long slmbx_send(unsigned int, const unsigned char *, unsigned int);

asmlinkage long slmbx_recv(unsigned int, unsigned char *, unsigned int);

asmlinkage long slmbx_length(unsigned int);

#endif
