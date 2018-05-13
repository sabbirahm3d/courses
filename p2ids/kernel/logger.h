
//
// Created by sabbir on 5/8/18.
//

#ifndef LOGGER_H
#define LOGGER_H

#include <unistd.h>

int sys_ids_log(char **argv);

int spawn_child(char **);

int do_trace(pid_t);

int wait_for_syscall(pid_t);

void launch_proc(char **cmd, char* file_name);

#endif // LOGGER_H
