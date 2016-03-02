CPPFLAGS = -Wall -ansi -g

all: Driver.o
	g++ $(CPPFLAGS) Driver.o -o Driver.out

TicTacNode.o: TicTacNode.cpp TicTacNode.h
	g++ $(CPPFLAGS) -c Node341.cpp Node341.h

TicTacTree.o: TicTacTree.cpp TicTacTree.h
	g++ $(CPPFLAGS) -c TicTacTree.cpp TicTacTree.h

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