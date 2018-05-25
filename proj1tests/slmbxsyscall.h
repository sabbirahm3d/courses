#ifndef SLMBXSYSCALL_H
#define SLMBXSYSCALL_H

#define __NR_slmbx_init     333
#define __NR_slmbx_shutdown 334
#define __NR_slmbx_create   335
#define __NR_slmbx_destroy  336
#define __NR_slmbx_count    337
#define __NR_slmbx_send     338
#define __NR_slmbx_recv     339
#define __NR_slmbx_length   340

#include <sys/syscall.h>

long slmbx_init_syscall(unsigned int ptrs, unsigned int prob) {

    return syscall(__NR_slmbx_init, ptrs, prob);

}

long slmbx_shutdown_syscall(void) {

    return syscall(__NR_slmbx_shutdown);

}

long slmbx_create_syscall(unsigned int id, int protected) {

    return syscall(__NR_slmbx_create, id, protected);

}

long slmbx_destroy_syscall(unsigned int id) {

    return syscall(__NR_slmbx_destroy, id);

}

long slmbx_count_syscall(unsigned int id) {

    return syscall(__NR_slmbx_count, id);

}

long slmbx_send_syscall(unsigned int id, const unsigned char *msg,
                    unsigned int len) {

    return syscall(__NR_slmbx_send, id, msg, len);

}

long slmbx_recv_syscall(unsigned int id, unsigned char *msg,
                    unsigned int len) {

    return syscall(__NR_slmbx_recv, id, msg, len);

}

long slmbx_length_syscall(unsigned int id) {

    return syscall(__NR_slmbx_length, id);

}

#endif //MSGSL_H
