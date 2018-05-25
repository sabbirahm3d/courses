# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -Wno-pointer-sign -std=gnu11

# define the C header files
DEPS = slmbxsyscall.h customerrno.h

# define the C source files
SRCS = basic.c nullrecvbuf.c nullsendbuf.c stresscreate.c stresssend.c

# define the C object files
OBJS = ${SRCS:.c=.o}

# define the executable files
EXE = ${SRCS:.c=.out}

# define the default executable
TEST ?= basic.out

.PHONY: build
build: ${EXE}
	@echo "\033[0;32mPrograms compiled successfully\033[0m"

basic.out: basic.o
	${CC} -o $@ $^ ${CFLAGS}

nullrecvbuf.out: nullrecvbuf.o
	${CC} -o $@ $^ ${CFLAGS}

nullsendbuf.out: nullsendbuf.o
	${CC} -o $@ $^ ${CFLAGS}

stresscreate.out: stresscreate.o
	${CC} -o $@ $^ ${CFLAGS}

stresssend.out: stresssend.o
	${CC} -o $@ $^ ${CFLAGS}

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}


.PHONY: run
run:
	@./${TEST}


.PHONY: val
val:
    # check memory leaks
	@valgrind ./${TEST}


.PHONY: clean
clean:
	# clean out cache, temporary files and executables
	@find . \( -name "*.o" -o -name "*.out" \) -type f -delete
