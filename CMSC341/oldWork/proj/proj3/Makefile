CPPFLAGS = -ansi -Wall
proj3 : Vertex.o Matrix.o Graph.o Edge.o proj3.o
	g++ Vertex.o Graph.o Matrix.o Edge.o proj3.o -o proj3

Graph.o : Graph.cpp Graph.h
	g++ -c Graph.cpp

Matrix.o: Matrix.cpp Matrix.h
	g++ -c Matrix.cpp

Vertex.o : Vertex.cpp Vertex.h
	g++ -c Vertex.cpp

Edge.o : Edge.cpp Edge.h
	g++ -c Edge.cpp

proj3.o: proj3.cpp Vertex.h Graph.h Matrix.h Edge.h
	g++ -c proj3.cpp
