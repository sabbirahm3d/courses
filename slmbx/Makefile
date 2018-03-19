# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -std=gnu11

# define the C source files
SRCS = main.c msgq.c msgsl.c mbx.c

# define the C object files
OBJS = ${SRCS:.c=.o}

# define the executable file
EXE = slmbx.o

.PHONY: build
build: ${EXE}
	@echo "Program compiled successfully"

${EXE}: ${OBJS}
	${CC} ${CFLAGS} -o ${EXE} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $< -o $@


.PHONY: val
val:
    # check memory leaks
	@valgrind --leak-check=full ./${EXE}


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name "*.o" -o -name ${EXE} \) -type f -delete
