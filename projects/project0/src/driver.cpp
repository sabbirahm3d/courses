#include <iostream>
#include <vector>
#include <fstream>
#include <locale>

using namespace std;

#include "Country.h"
#include "Continent.h"


void ReadFromFiles(string);

int main(){

	string file1 = "data/CountriesContinents.txt";
	string file2 = "data/2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1);

	Country Park("Aruba", 102921, -1, 6.036870003, 94.72277832, 97.84075928, 91.66667175, 99.32309723, 98.96572876);

	cout << Park.GetName() << endl;

	return 0;

}

void ReadFromFiles(string file1){

	string line;
	string continent;
	locale loc;
	ifstream countries( file1.c_str() );

	if ( countries.is_open() ){
		while ( getline(countries, line) ){
			cout << line << endl;
			if ( isupper(line, loc) ){
				cout << "ay" << line;
			}
		}

		countries.close();
	}

	else {
		cerr << "Unable to open file";
		// exit(1);
	}

}