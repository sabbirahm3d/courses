#include "Country.h"
#include "Continent.h"

#include <map>
#include <typeinfo>


void ReadFromFiles(string, string);

vector< string > &split(const string &s, char delim, vector< string > &elems);

vector< string > split(const string &s, char delim);


int NUM_CONTINENTS = 6;

int main() {

	string file1 = "data/CountriesContinents.txt";
	string file2 = "data/2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1, file2);

	return 0;

}


void ReadFromFiles(string file1, string file2) {

	ifstream countriesFile(file1.c_str(), ios_base::in);
	ifstream statistics(file2.c_str(), ios_base::in);
	vector<string> africa, asia, europe, northAmerica, oceania, southAmerica;

	// Countries
	if (countriesFile.is_open()) {

		cout << "Reading from \'" << file1 << "\'" << endl << endl;

		string continent, excess, country;
		int numCountries;


		countriesFile >> continent >> excess >> numCountries;

		cout << endl << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			africa.push_back(country);
			cout << africa[i] << endl;
		}


		countriesFile >> continent >> excess >> numCountries;

		cout << endl << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			asia.push_back(country);
			cout << asia[i] << endl;
		}


		countriesFile >> continent >> excess >> numCountries;

		cout << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			europe.push_back(country);
			cout << europe[i] << endl;
		}


		countriesFile >> continent >> excess >> numCountries;

		cout << endl << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			northAmerica.push_back(country);
			cout << northAmerica[i] << endl;
		}


		countriesFile >> continent >> excess >> numCountries;

		cout << endl << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			oceania.push_back(country);
			cout << oceania[i] << endl;
		}


		countriesFile >> continent >> excess >> numCountries;

		cout << endl << numCountries << endl;

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			southAmerica.push_back(country);
			cout << southAmerica[i] << endl;
		}


		// vector<string>::iterator it;

		// it = find(asia.begin(), asia.end(), "Bangladesh");
		// if (it != asia.end())
		// 	cout << "Element found in myvector: " << *it << '\n';
		// else
		// 	cout << "Element not found in myvector\n";

	}

	else {
		cerr << "Unable to open file \'" << file1 << "\'";
		exit(1);
	}


	string name, population, litRate, eduGDP, priCompTot, priCompMale,
		priCompFem, youthLitRateFem, youthLitRateMale;

	string heading, line;

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

			Country ex(name, newPopulation, newLitRate, newEduGDP, 
				newPriCompTot, newPriCompMale, newPriCompFem, 
				newYouthLitRateFem, newYouthLitRateMale); // for testing

			// yo = *ex;

			// Continent jkjkj(ex);

			// cout << ex.GetPriCompFem() << endl; // for testing

		}

	}

	else {
		cerr << "Unable to open file \'" << file2 << "\'";
		exit(1);
	}

	countriesFile.close();
	statistics.close();

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