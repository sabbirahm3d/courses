CPPFLAGS = -ansi -Wall

proj4 : WalkGraph.o WalkVertex.o WalkEdge.o Intersection.o PoliceStation.o SafeHouse.o proj4.o
	g++ WalkGraph.o WalkVertex.o WalkEdge.o Intersection.o PoliceStation.o SafeHouse.o proj4.o -o proj4

WalkGraph.o : WalkGraph.cpp WalkGraph.h
	g++ -c WalkGraph.cpp

WalkVertex.o : WalkVertex.cpp WalkVertex.h
	g++ -c WalkVertex.cpp

WalkEdge.o : WalkEdge.cpp WalkEdge.h
	g++ -c WalkEdge.cpp

Intersection.o : Intersection.cpp Intersection.h
	g++ -c Intersection.cpp

PoliceStation.o : PoliceStation.cpp PoliceStation.h
	g++ -c PoliceStation.cpp

SafeHouse.o : SafeHouse.cpp SafeHouse.h
	g++ -c SafeHouse.cpp

proj4.o: proj4.cpp WalkGraph.h WalkVertex.h WalkEdge.h
	g++ -c proj4.cpp
