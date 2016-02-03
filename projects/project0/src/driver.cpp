#include <iostream>
#include <string>
using namespace std;

#include "Country.h"


int main(){

	Country Park("Aruba", 102921, -1, 6.036870003, 94.72277832, 97.84075928, 91.66667175, 99.32309723, 98.96572876);

	cout << Park.GetName() << endl;

	return 0;

}