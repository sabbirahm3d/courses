CPPFLAGS = -ansi -Wall

residence_driver : House.o Residence.o residence_driver.o Tent.o Apartment.o
	g++ House.o Tent.o Apartment.o Residence.o residence_driver.o -o residence_driver

residence_driver.o : residence_driver.cpp House.h Residence.h Tent.h Apartment.o
	g++ -c residence_driver.cpp

Residence.o : Residence.cpp Residence.h
	g++ -c Residence.cpp

House.o : House.cpp House.h
	g++ -c House.cpp

Tent.o : Tent.cpp Tent.h
	g++ -c Tent.cpp

Apartment.o : Apartment.cpp Apartment.h
	g++ -c Apartment.cpp