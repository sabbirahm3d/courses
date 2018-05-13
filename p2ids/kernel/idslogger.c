#include <linux/errno.h>
#include <linux/unistd.h>
#include "../../arch/x86/entry/common.h"

#include "idslogger.h"

asmlinkage long sys_ids_log(unsigned long *syscall_nr) {

    // if pointer is valid
    if (syscall_nr) {

        *syscall_nr = SYSCALL_NR;
        return 0;

    }

    return -EFAULT;

}
