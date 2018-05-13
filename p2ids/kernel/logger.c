#include <linux/kernel.h>
#include <linux/time.h>
#include <linux/cred.h>
#include <linux/slab.h>
#include <linux/signal.h>
#include <linux/unistd.h>
#include <linux/syscalls.h>
#include "../../arch/x86/entry/common.h"

#include "logger.h"


asmlinkage long sys_ids_log(void) {

    printk("%ld ", SYSCALL_NR);

    return 0;

}
