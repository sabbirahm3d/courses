//
// Created by sabbir on 5/8/18.
//

#ifndef LOGGER_H
#define LOGGER_H

//#include <unistd.h>

int sys_ids_log(char **);

int do_child(char **);

int do_trace(pid_t);

int wait_for_syscall(pid_t);

#endif // LOGGER_H
