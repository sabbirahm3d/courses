CPPFLAGS = -Wall -ansi

all: Driver.o Node341.o List341.o Stack341.o
	g++ $(CPPFLAGS) Node341.o List341.o Stack341.o Driver.o -o Driver.out

# Exceptions341.o: Exceptions341.cpp
# 	g++ $(CPPFLAGS) -c Country.cpp

Node341.o: Node341.cpp Node341.h
	g++ $(CPPFLAGS) -c Node341.cpp Node341.h

List341.o: List341.cpp List341.h
	g++ $(CPPFLAGS) -c List341.cpp List341.h

Stack341.o: Stack341.cpp Stack341.h
	g++ $(CPPFLAGS) -c Stack341.cpp Stack341.h

Queue341.o: Queue341.cpp Queue341.h
	g++ $(CPPFLAGS) -c Queue341.cpp Queue341.h

# to test for memory leaks
val:
	valgrind ./Driver.out --leak-check=full

# -f removes any error messages if the file is not present
clean:
	rm -rf *~ *.h.gch *# *.out *.o
	clear
	ls

# compile an executable
run:
	./Driver.out