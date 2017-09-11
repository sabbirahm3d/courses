CPPFLAGS = -Wall -ansi -g

all: Driver.o TicTacNode.o TicTacToe.o TicTacTrie.o
	g++ $(CPPFLAGS) TicTacNode.o TicTacToe.o TicTacTrie.o Driver.o -o Driver.out

Driver.o: Driver.cpp
	g++ $(CPPFLAGS) -c Driver.cpp

TicTacNode.o: TicTacNode.cpp TicTacNode.h
	g++ $(CPPFLAGS) -c TicTacNode.cpp TicTacNode.h

TicTacToe.o: TicTacToe.cpp TicTacToe.h
	g++ $(CPPFLAGS) -c TicTacToe.cpp TicTacToe.h

TicTacTrie.o: TicTacTrie.cpp TicTacTrie.h
	g++ $(CPPFLAGS) -c TicTacTrie.cpp TicTacTrie.h

# to test for memory leaks
val:
	valgrind ./Driver.out $(FILE)

# -f removes any error messages if the file is not present
clean:
	rm -rf *~ *.h.gch *# *.out *.o
	clear
	ls

# compile an executable
run:
	./Driver.out $(FILE)

yo:
	make clean
	make
	clear