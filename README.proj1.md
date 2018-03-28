# Project 1: Mailbox System

This project implemented a mailbox system using a skiplist of queues data
structure. A total of 8 system calls 

asmlinkage long slmbx_init(unsigned int, unsigned int);

asmlinkage long slmbx_shutdown(void);

asmlinkage long slmbx_create(unsigned int, int);

asmlinkage long slmbx_destroy(unsigned int);

asmlinkage long slmbx_count(unsigned int);

asmlinkage long slmbx_send(unsigned int, const unsigned char *, unsigned int);

asmlinkage long slmbx_recv(unsigned int, unsigned char *, unsigned int);

asmlinkage long slmbx_length(unsigned int);

