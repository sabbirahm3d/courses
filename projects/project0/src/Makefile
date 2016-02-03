all: driver.o Country.o
		g++ -Wall driver.o Country.o -o output.out

Lecturer.o : Country.cpp
		g++ -Wall -c Country.cpp

driver.o: driver.cpp
		g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
		rm -rf *.o
		rm -f *.out
		rm -f *~ *.h.gch *#

# to test for memory leaks
val:
		valgrind ./output

# compile an executible
run:
		./output.out