CPPFLAGS = -ansi -Wall

proj2 : proj2.o CipherMessage.o Date.o
	g++ proj2.o CipherMessage.o Date.o -o proj2

CipherMessage.o : CipherMessage.cpp CipherMessage.h Date.h
	g++ -c CipherMessage.cpp

Date.o : Date.cpp Date.h
	g++ -c Date.cpp