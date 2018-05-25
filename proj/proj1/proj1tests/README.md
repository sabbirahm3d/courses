# Project 1: System Call Test Drivers

This directory contains several drivers for testing the `slmbx` system calls.

## Included files
- `slmbxsyscall.h` contains the wrappers for the system calls
- `customerrno.h` contains the string messages of the errnos used
- `Makefile` has been provided for building all the executables.<br>The following is a list of useful targets for testing:
    - `make` builds all the executables provided in the `SRCS` array
    - `make run TEST=<test.out>` runs the `test.out` test executable. Default: `basic.out`
    - `make val TEST=<test.out>` runs valgrind on the `test.out` test executable. Default: `basic.out`
    - `make clean` clears all temporary objects and executables

## Tests
Each one of the tests provided consist of both correct and incorrect usage of the system calls.
- `basic.c` tests at least one call to all the system calls with a single user
- `nullrecvbuf.c` tests reception of messages with invalid buffers
- `nullsendbuf.c` tests transmission of messages with invalid buffers
- `stresscreate.c` stress tests the `slmbx_create` and `slmbx_destroy` system calls
- `stresssend.c` stress tests the `slmbx_send` and `slmbx_recv` system calls
