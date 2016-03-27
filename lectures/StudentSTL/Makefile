FLAGS = -Wall

all: Driver.o Player.o
	g++ $(FLAGS) Driver.o Player.o -o Output.out

Player.o: Player.cpp
	g++ $(FLAGS) Player.cpp -c

Driver.o: Driver.cpp
	g++ $(FLAGS) Driver.cpp -c

run:
	./Output.out

clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#
