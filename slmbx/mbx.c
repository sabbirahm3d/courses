//
// Created by sabbir on 3/11/18.
//

#include <linux/kernel.h>
#include <linux/slab.h>
#include <linux/errno.h>
#include <linux/unistd.h>
#include "msgsl.h"
#include "utilstr.h"
#include "mbx.h"

msg_sl *MAILBOXSL;
int UID;


/*
 * Initializes the mailbox system, setting up the initial state of the skip
 * list. The ptrs parameter specifies the maximum number of pointers any
 * msg_sl_node in the list will be allowed to have. The prob parameter
 * specifies the inverse of the probability that a msg_sl_node will be
 * promoted to having an additional pointer in it (that is to say that if the
 * function is called with prob = 2 , then the probability that the
 * msg_sl_node will have 2 pointers is 1 / 2 and the probability that it will
 * have 4 pointers is 1 / 4 , and so on). The only valid values for the prob
 * parameter are 2, 4, 8, and 16 - any other value should result in an error
 * being returned. Additionally, the ptrs parameter must be non-zero - a zero
 * msg_queue should result in an error being returned. Returns 0 on success.
 * Only the root user (the user with a uid of 0) should be allowed to call
 * this function.
 *
 * */
asmlinkage long slmbx_init(unsigned int ptrs, unsigned int prob) {

    if (DEBUG_UID) {

        // simulate user UID as root for full functionality
        UID = 0;

    } else {

        UID = getuid();

    }

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        destroy_msg_sl(MAILBOXSL);

    }

    // if root
    if (!UID) {

        // if probability is 2, 4, 8 or 16 and the number of pointers is
        // non-zero
        if (ptrs && (prob == 2 || prob == 4 || prob == 8 || prob == 16)) {

            MAILBOXSL = kmalloc(sizeof(msg_sl), GFP_KERNEL);

            // memory allocation failure
            if (!MAILBOXSL) {

                return -ENOMEM;

            }

            init_msg_sl(MAILBOXSL, ptrs, prob);

            return 0;

        } else {

            return -EINVAL;

        }

    } else {

        return -EPERM;

    }

};

/*
 * Shuts down the mailbox system, deleting all existing mailboxes and any
 * messages contained therein. Returns 0 on success. Only the root user should
 * be allowed to call this function.
 *
 * */
asmlinkage long slmbx_shutdown(void) {


    if (!UID) {

        // if the mailbox system was initialized
        if (MAILBOXSL) {

            destroy_msg_sl(MAILBOXSL);
            MAILBOXSL = '\0';

            return 0;

        } else {

            return -ENODEV;

        }

    } else {

        return -EPERM;

    }

};


/*
 * Creates a new mailbox with the given id if it does not already exist (no
 * duplicates are allowed). If the protected parameter is non-zero, the created
 * mailbox will only be accessible to processes owned by the same user that
 * owns the process that creates the mailbox (that is to say that if user bob
 * runs a program to create the mailbox, only other programs run by bob should
 * be able to send messages to or read messages from that mailbox if the
 * protected parameter is non-zero). Returns 0 on success or an appropriate
 * error on failure. If an id of 0 or (2^32 - 1) is passed, this is considered
 * an invalid ID and an appropriate error should be returned.
 *
 * */
asmlinkage long slmbx_create(unsigned int id, int protected) {

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        int protected_uid = (protected ? UID : -1);

        if (!id || id >= MAXID) {

            return -EINVAL;

        } else {

            // if not found
            if (!search_msg_sl(MAILBOXSL, id)) {

                insert_msg_sl(MAILBOXSL, id, protected_uid);

                return 0;

            } else {

                return -EEXIST;

            }

        }

    } else {

        return -ENODEV;

    }

};

/*
 * Deletes the mailbox identified by id if it exists and the user has
 * permission to do so. If the mailbox has any messages stored in it, these
 * messages should be deleted. Returns 0 on success or an appropriate error
 * code on failure.
 *
 * */
asmlinkage long slmbx_destroy(unsigned int id) {

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        return remove_msg_sl(MAILBOXSL, id, UID) ? -EPERM : 0;

    } else {

        return -ENODEV;

    }

};


/*
 * Returns the number of messages in the mailbox identified by id if it exists
 * and the user has permission to access it. Returns an appropriate error code
 * on failure.
 *
 * */
asmlinkage long slmbx_count(unsigned int id) {

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        msg_sl_node *found_mbx = search_msg_sl(MAILBOXSL, id);

        if (found_mbx) {

            if (found_mbx->uid == UID || found_mbx->uid == -1) {

                return found_mbx->msg_queue->size;

            } else {

                return -EPERM;

            }

        } else {

            return -ENOENT;

        }

    } else {

        return -ENODEV;

    }

};


/*
 * Sends a new message to the mailbox identified by id if it exists and the
 * user has access to it. The message shall be read from the user-space pointer
 * msg and shall be len bytes asmlinkage long. Returns 0 on success or an appropriate
 * error code on failure.
 *
 * */
asmlinkage long slmbx_send(unsigned int id, const unsigned char *msg, unsigned int len) {

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        msg_sl_node *found_mbx = search_msg_sl(MAILBOXSL, id);

        if (found_mbx) {

            if (found_mbx->uid == UID || found_mbx->uid == -1) {

                // if buffer is a valid pointer
                if (msg) {

                    unsigned int buf_size = len;
                    unsigned char *buffer = kmalloc(
                        sizeof(unsigned char), GFP_KERNEL);

                    // memory allocation failure
                    if (!buffer) {

                        return -ENOMEM;

                    }

                    if (len > u_bytelen(msg)) {
                        buf_size = u_bytelen(msg);
                    }

                    u_strcpy(buffer, msg);
                    buffer[buf_size] = '\0';

                    enqueue_msg_q(found_mbx->msg_queue, buffer);

                    return 0;

                } else {

                    // bad pointer
                    return -EFAULT;

                }

            } else {

                // permission denied
                return -EPERM;

            }


        } else {

            return -ENONET;

        }

    } else {

        return -ENODEV;

    }

};


/*
 * Reads the first message that is in the mailbox identified by id if it exists
 * and the user has access to it, storing either the entire length of the
 * message or len bytes to the user-space pointer msg, whichever is less.
 * The entire message is then removed from the mailbox (even if len was less
 * than the total length of the message). Returns the number of bytes copied
 * to the user space pointer on success or an appropriate error code on failure.
 *
 * */
asmlinkage long slmbx_recv(unsigned int id, unsigned char *msg, unsigned int len) {

    // if the mailbox system was initialized
    if (MAILBOXSL) {

        // look for mailbox with the unique ID
        msg_sl_node *found_mbx = search_msg_sl(MAILBOXSL, id);

        // if mailbox exists
        if (found_mbx) {

            // if mailbox UID matches with the current user process, or global
            if (found_mbx->uid == UID || found_mbx->uid == -1) {

                // if mailbox has messages
                if (found_mbx->msg_queue->size) {

                    // if buffer is a valid pointer
                    if (msg) {

                        msg_q_node *msg_node = dequeue_msg_q(
                                found_mbx->msg_queue);
                        unsigned int buf_size = len;
                        unsigned char *buffer = msg_node->data;

                        if (len > u_bytelen(buffer)) {
                            buf_size = u_bytelen(buffer);
                        }

                        u_strcpy(msg, buffer);
                        msg[buf_size] = '\0';

                        kfree(buffer);
                        kfree(msg_node);

                        return 0;

                    } else {

                        // bad pointer
                        return -EFAULT;

                    }

                } else {

                    // mailbox is empty
                    return -ESRCH;

                }

            } else {

                // permission denied
                return -EPERM;

            }


        } else {

            // mailbox does not exist
            return -ENONET;

        }

    } else {

        // mailbox system was never initialized
        return -ENODEV;

    }

};


/*
 * Retrieves the length (in bytes) of the first message pending in the mailbox
 * identified by id, if it exists and the user has access to it. Returns the
 * number of bytes in the first pending message in the mailbox on success, or
 * an appropriate error code on failure.
 *
 * */
asmlinkage long slmbx_length(unsigned int id) {

    if (MAILBOXSL) {

        msg_sl_node *found_mbx = search_msg_sl(MAILBOXSL, id);

        if (found_mbx) {

            if (found_mbx->uid == UID || found_mbx->uid == -1) {

                if (found_mbx->msg_queue->size) {

                    return u_bytelen(found_mbx->msg_queue->head->data);

                } else {

                    // mailbox is empty
                    return -ESRCH;

                }

            } else {

                // permission denied
                return -EPERM;

            }

        } else {

            // mailbox does not exist
            return -ENONET;

        }

    } else {

        // mailbox system was never initialized
        return -ENODEV;

    }

};
