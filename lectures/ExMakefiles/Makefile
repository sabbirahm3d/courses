CPPFLAGS = -ansi -Wall -g

Driver.out: Driver.o
	g++ $(CPPFLAGS) Driver.o -o Driver.out

Driver.o: Driver.cpp
	g++ $(CPPFLAGS) -c Driver.cpp

clean:
	rm -f *.o *.out *~ *.gch

# checking for memory leaks
val:
	valgrind ./Driver.out $(COUNT)

# each item with a $ is a variable NAME
run:
	./Driver.out $(COUNT)