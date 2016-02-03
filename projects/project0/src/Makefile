all: driver.o Country.o Continent.o
	g++ -Wall driver.o Country.o Continent.o -o driver.out

Country.o: Country.cpp
	g++ -Wall -c Country.cpp

Continent.o: Continent.cpp
	g++ -Wall -c Continent.cpp

driver.o: driver.cpp
	g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
	rm -rf *.o
	rm -f *.out
	rm -f *~ *.h.gch *#

# compile an executable
run:
	./driver.out