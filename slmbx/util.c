//
// Created by sabbir on 3/11/18.
//

/*
 * Initializes the mailbox system, setting up the initial state of the skip
 * list. The ptrs parameter specifies the maximum number of pointers any node
 * in the list will be allowed to have. The prob parameter specifies the
 * inverse of the probability that a node will be promoted to having an
 * additional pointer in it (that is to say that if the function is called with
 * prob = 2 , then the probability that the node will have 2 pointers is 1 / 2
 * and the probability that it will have 3 pointers is 1 / 4 , and so on). The
 * only valid values for the prob parameter are 2, 4, 8, and 16 — any other
 * value should result in an error being returned. Additionally, the ptrs
 * parameter must be non-zero — a zero value should result in an error being
 * returned. Returns 0 on success. Only the root user (the user with a uid of
 * 0) should be allowed to call this function.
 *
 * */
long slmbx_init(unsigned int ptrs, unsigned int prob){

};

/*
 * Shuts down the mailbox system, deleting all existing mailboxes and any
 * messages contained therein. Returns 0 on success. Only the root user should
 * be allowed to call this function.
 *
 * */
long slmbx_shutdown(void){

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
long slmbx_create(unsigned int id, int protected){

};

/*
 * Deletes the mailbox identified by id if it exists and the user has
 * permission to do so. If the mailbox has any messages stored in it, these
 * messages should be deleted. Returns 0 on success or an appropriate error
 * code on failure.
 *
 * */
long slmbx_destroy(unsigned int id){

};



/*
 * Returns the number of messages in the mailbox identified by id if it exists
 * and the user has permission to access it. Returns an appropriate error code
 * on failure.
 *
 * */
long slmbx_count(unsigned int id){

};

/*
 * Sends a new message to the mailbox identified by id if it exists and the
 * user has access to it. The message shall be read from the user-space pointer
 * msg and shall be len bytes long. Returns 0 on success or an appropriate
 * error code on failure.
 *
 * */
long slmbx_send(unsigned int id, const unsigned char *msg, unsigned int len){

};

/*
 * Reads the first message that is in the mailbox identified by id if it exists
 * and the user has access to it, storing either the entire length of the
 * message or len bytes to the user-space pointer msg , whichever is less. The
 * entire message is then removed from the mailbox (even if len was less than
 * the total length of the message). Returns the number of bytes copied to the
 * user space pointer on success or an appropriate error code on failure.
 *
 * */
long slmbx_recv(unsigned int id, unsigned char *msg, unsigned int len){

};


/*
 * Retrieves the length (in bytes) of the first message pending in the mailbox
 * identified by id , if it exists and the user has access to it. Returns the
 * number of bytes in the first pending message in the mailbox on success, or
 * an appropriate error code on failure.
 *
 * */
long slmbx_length(unsigned int id){

};
