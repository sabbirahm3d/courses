#include <linux/kernel.h>
#include <linux/errno.h>
#include <linux/time.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <linux/signal.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include "../../arch/x86/entry/common.h"

#include "logger.h"

asmlinkage long sys_ids_log(unsigned long *syscall_nr) {

    // if pointer is valid
    if (syscall_nr) {

        *syscall_nr = SYSCALL_NR;
        return 0;

    }

    return -EFAULT;

}
