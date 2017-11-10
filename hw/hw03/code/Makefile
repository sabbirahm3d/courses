# define the C compiler to use
CC = gcc

# define any compile-time flags
CFLAGS = -Wall -std=gnu99 -Os

# define the C source files
SRCS = main.c database.c list_of_grades.c

# define the C object files 
OBJS = ${SRCS:.c=.o}

# define the executable file 
EXE = linkedlist


.PHONY: run
run:
	@./${EXE} ${INPUT}


.PHONY: build
build: ${EXE}
	@echo  Simple compiler named mycc has been compiled

${EXE}: ${OBJS} 
	${CC} ${CFLAGS}-o ${EXE} ${OBJS}

.c.o:
	${CC} ${CFLAGS} -c $<  -o $@


.PHONY: val
val:
	@valgrind ./${EXE} ${INPUT}


.PHONY: clean
clean:
	# clean out cache and temporary files
	@find . \( -name "*.o" -o -name ${EXE} \) -type f -delete


.PHONY: depend
depend: ${SRCS}
	makedepend ${INCLUDES} $^

# DO NOT DELETE THIS LINE -- make depend needs it
