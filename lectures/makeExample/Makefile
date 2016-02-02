all: driver.o Lecturer.o
		g++ -Wall driver.o Lecturer.o -o output.out

Lecturer.o : Lecturer.cpp
		g++ -Wall -c Lecturer.cpp

driver.o: driver.cpp
		g++ -Wall -c driver.cpp

# -f removes any error messages if the file is not present
clean:
		rm -rf *.o
		rm -f *.out
		rm -f *~ *.h.gch *#

val:  # to test for memory leaks
		valgrind ./output

run:
		./output.out