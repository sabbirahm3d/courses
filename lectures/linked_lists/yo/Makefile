FLAGS = -Wall

all: Driver.o LinkedList.o
	g++ $(FLAGS) Driver.o LinkedList.o -o Output.out

LinkedList.o: LinkedList.cpp
	g++ $(FLAGS) LinkedList.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Output.out

# to test for memory leaks
val:
	valgrind ./Output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
