//============================================================================
// Name        : Airplane.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Airplane.h"


int main() {
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!

	Duration temp = {100, 100};
	cout << temp << endl;


	cout << temp.getHours() << endl;

	// Airplane Rudra;
	// cout << Rudra.getPassengers() << endl;

	// Airplane Dylan(10, 40, "North Korea", "Albany");
	// cout << Dylan << endl;

	// Dylan.setDestination("Aruba");
	// cout << Dylan << endl;


	Airplane* ConAir = new Airplane(10, 40, "East Germany", "West Germany");
	cout << *ConAir << endl;

	delete ConAir;
	ConAir = NULL;

	return 0;
}
