CPPFLAGS = -Wall -ansi

all: driver.o Country.o Continent.o
	g++ $(CPPFLAGS) driver.o Country.o Continent.o -o driver.out

Country.o: Country.cpp
	g++ $(CPPFLAGS) -c Country.cpp

Continent.o: Continent.cpp
	g++ $(CPPFLAGS) -c Continent.cpp

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