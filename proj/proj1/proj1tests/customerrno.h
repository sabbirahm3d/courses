#ifndef CUSTOMERRNO_H
#define CUSTOMERRNO_H

#include <errno.h>

const char* str_errno(int _errno) {

    switch (_errno) {

        case EINVAL : return "invalid value passed";
        case ENODEV : return "mailbox system not initialized";
        case EEXIST : return "mailbox already exists";
        case ENOENT : return "mailbox does not exist";
        case EPERM : return "permission denied";
        case EFAULT : return "bad pointer passed";
        case ESRCH : return "no messages in mailbox";
        case ENOMEM : return "memory allocation failure";
        default : return "other";

    }

}

#endif //CUSTOMERRNO_H
