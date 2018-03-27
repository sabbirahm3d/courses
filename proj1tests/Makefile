# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -std=gnu11

# define the C header files
DEPS = slmbxsyscall.h

# define the C source files
SRCS = basic.c nullptrs.c

# define the C object files
OBJS = ${SRCS:.c=.o}

# define the executable file
EXE = ${SRCS:.c=.out}

.PHONY: build
build: ${EXE}
	@echo "\033[0;32mPrograms compiled successfully\033[0m"

basic.out: basic.o
	${CC} -o $@ $^ ${CFLAGS}

nullptrs.out: nullptrs.o
	${CC} -o $@ $^ ${CFLAGS}

%.o: %.c ${DEPS}
	${CC} -c -o $@ $< ${CFLAGS}


.PHONY: val
val:
    # check memory leaks
	@valgrind ./${EXE}


.PHONY: clean
clean:
	# clean out cache, temporary files and executables
	@find . \( -name "*.o" -o -name "*.out" \) -type f -delete
