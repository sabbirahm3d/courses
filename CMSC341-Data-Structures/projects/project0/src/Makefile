CPPFLAGS = -Wall -ansi

all: Driver.o Country.o Continent.o
	g++ $(CPPFLAGS) Driver.o Country.o Continent.o -o Driver.out

Country.o: Country.cpp
	g++ $(CPPFLAGS) -c Country.cpp

Continent.o: Continent.cpp
	g++ $(CPPFLAGS) -c Continent.cpp

Driver.o: Driver.cpp
	g++ $(CPPFLAGS) -c Driver.cpp

# to test for memory leaks
val:
	valgrind ./Driver.out

# -f removes any error messages if the file is not present
clean:
	rm -rf *~ *.h.gch *# *.out *.o

# compile an executable
run:
	./Driver.out