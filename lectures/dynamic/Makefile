CPPFLAGS = -Wall -ansi

all: driver.o Airplane.o
	g++ $(CPPFLAGS) driver.o Airplane.o -o driver.out

Airplane.o: Airplane.cpp
	g++ $(CPPFLAGS) -c Airplane.cpp

driver.o: driver.cpp
	g++ $(CPPFLAGS) -c driver.cpp

# to test for memory leaks
val:
	valgrind ./driver.out

# -f removes any error messages if the file is not present
clean:
	rm -rf *~ *.h.gch *# *.out *.o

# compile an executable
run:
	./driver.out