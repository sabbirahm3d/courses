//
// Created by sabbir on 5/8/18.
//

#ifndef MINIPTRACE_H
#define MINIPTRACE_H

/* Type of the REQUEST argument to `ptrace.'  */
enum ptrace_req {
    /* Indicate that the process making this request should be traced.
       All signals received by this process can be intercepted by its
       parent, and its parent can use the other `ptrace' requests.  */
            PTRACE_TRACEME = 0,

    /* Return the word in the process's user area at offset ADDR.  */
            PTRACE_PEEKUSER = 3,

    /* Continue and stop at the next (return from) syscall.  */
            PTRACE_SYSCALL = 24,

    /* Set ptrace filter options.  */
            PTRACE_SETOPTIONS = 0x4200,

};


/* Options set using PTRACE_SETOPTIONS.  */
enum __ptrace_setoptions {
    PTRACE_O_TRACESYSGOOD = 0x00000001,
};


/* Perform process tracing functions.  REQUEST is one of the values
   above, and determines the action to be taken.
   For all requests except PTRACE_TRACEME, PID specifies the process to be
   traced.

   PID and the other arguments described above for the various requests should
   appear (those that are used for the particular request) as:
     pid_t PID, void *ADDR, int DATA, void *ADDR2
   after REQUEST.  */
extern long int ptrace(enum ptrace_req req, pid_t pid, void *addr, void *data);

extern pid_t fork(void);

extern long int kill(pid_t pid, int sig);

extern long waitpid(pid_t pid, ...);

#endif // MINIPTRACE_H