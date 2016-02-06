#include "Country.h"
#include "Continent.h"

void ReadFromFiles(string, string);

vector< string > &split(const string &s, char delim, vector< string > &elems);

vector< string > split(const string &s, char delim);


int main() {

	string file1 = "data/CountriesContinents.txt";
	string file2 = "data/2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1, file2);

	return 0;

}


void ReadFromFiles(string file1, string file2) {

	ifstream countries(file1.c_str(), ios_base::in);
	ifstream statistics(file2.c_str(), ios_base::in);

	string numbers = "0123456789";
	string countryLine;
	string test[20];

	// Countries
	if (countries.is_open()) {

		cout << "Reading from \'" << file1 << "\'" << endl << endl;

		// string big, excess;
		// int numCountries;

		int count = 0;
		while (getline(countries, countryLine)) {

			if ( string::npos != countryLine.find_first_of(numbers.c_str()) ) {

				vector< string > continents = split(countryLine, ' ');
				for (vector<string>::iterator i = continents.begin(); i != continents.end(); i++){

					if ( *i != "--" && *i != "---" ){
						test[count] = *i;
						cout << "Printing " << count << " " << test[count] << endl;
						count++;
					}

				}

			}

		}

		// for (int j = 0; j <= 6; j++){
		// 	cout << test[j] << endl;

		// }

		countries.close();
	}

	else {
		cerr << "Unable to open file \'" << file1 << "\'";
		exit(1);
	}


	string name, population, litRate, eduGDP, priCompTot, priCompMale,
		priCompFem, youthLitRateFem, youthLitRateMale;

	string heading, line;

	vector< string > africa, asia, europe, oceania, northAmerica, southAmerica;

	// Statistics
	if (statistics.is_open()) {

		cout << endl << "Reading from \'" << file2 << "\'" << endl << endl;

		getline(statistics, heading); // isolate the heading from stats

		while (statistics >> name >> population >> litRate >> eduGDP >> 
			priCompTot >> priCompMale >> priCompFem >> youthLitRateFem >> 
			youthLitRateMale) {

			long newPopulation;
			float newLitRate, newEduGDP, newPriCompFem, newPriCompMale, 
				newPriCompTot, newYouthLitRateFem, newYouthLitRateMale;

			// Convert population into long
			newPopulation = atol(population.c_str());

			// Convert litRate into float
			if ( atof(litRate.c_str()) == 0 ){ newLitRate = -1; }

			else { newLitRate = atof(litRate.c_str()); }

			// Convert eduGDP into float
			if ( atof(eduGDP.c_str()) == 0 ){ newEduGDP = -1; }

			else { newEduGDP = atof(eduGDP.c_str()); }

			// Convert priCompFem into float
			if ( atof(priCompFem.c_str()) == 0 ){ newPriCompFem = -1; }

			else { newPriCompFem = atof(priCompFem.c_str()); }

			// Convert priCompMale into float
			if ( atof(priCompTot.c_str()) == 0 ){ newPriCompTot = -1; }

			else { newPriCompTot = atof(priCompTot.c_str()); }

			// Convert priCompTot into float
			if ( atof(priCompMale.c_str()) == 0 ){ newPriCompMale = -1; }

			else { newPriCompMale = atof(priCompMale.c_str()); }

			// Convert youthLitRateFem into float
			if ( atof(youthLitRateFem.c_str()) == 0 ){ newYouthLitRateFem = -1; }

			else { newYouthLitRateFem = atof(youthLitRateFem.c_str()); }

			// Convert youthLitRateMale into float
			if ( atof(youthLitRateMale.c_str()) == 0 ){ newYouthLitRateMale = -1; }

			else { newYouthLitRateMale = atof(youthLitRateMale.c_str()); }

			Country ex(name, newPopulation, newLitRate,
					 newEduGDP, newPriCompTot,  
					 newPriCompMale, newPriCompFem, 
					 newYouthLitRateFem, newYouthLitRateMale); // for testing

			// cout << ex.GetPriCompFem() << endl; // for testing

		}

		statistics.close();
	}

	else {
		cerr << "Unable to open file \'" << file2 << "\'";
		exit(1);
	}

}


vector< string > &split(const string &s, char delim, vector< string > &elems) {

	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;

}


vector< string > split(const string &s, char delim) {

	vector< string > elems;
	split(s, delim, elems);
	return elems;

}