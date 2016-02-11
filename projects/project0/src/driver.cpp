#include "Country.h"
#include "Continent.h"


void ReadFromFiles(string, string);

// vector< string > &split(const string &s, char delim, vector< string > &elems);

// vector< string > split(const string &s, char delim);


int main() {

	string file1 = "data/CountriesContinents.txt";
	string file2 = "data/2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1, file2);

	return 0;

}


void ReadFromFiles(string file1, string file2) {

	ifstream countriesFile(file1.c_str(), ios_base::in);
	ifstream statistics(file2.c_str(), ios_base::in);

	vector<string>* africa = new vector<string>;
	vector<string>* asia = new vector<string>;
	vector<string>* europe = new vector<string>;
	vector<string>* northAmerica = new vector<string>;
	vector<string>* oceania = new vector<string>;
	vector<string>* southAmerica = new vector<string>;

	vector<string>* continents = new vector<string>;
	vector<Continent>* world = new vector<Continent>;

	// Countries
	if (countriesFile.is_open()) {

		string continent, excess, country;
		int numCountries;


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			africa->push_back(country);
		}


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			asia->push_back(country);
		}


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			europe->push_back(country);
		}


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			northAmerica->push_back(country);
		}


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			oceania->push_back(country);
		}


		countriesFile >> continent >> excess >> numCountries;
		continents->push_back(continent);

		for (int i = 0; i <= (numCountries); i++){
			getline(countriesFile, country);
			southAmerica->push_back(country);
		}

	}

	else {
		cerr << "Unable to open file \'" << file1 << "\'";
		exit(1);
	}

	string heading, line;
	string name, population, litRate, eduGDP, priCompTot, priCompMale,
		priCompFem, youthLitRateFem, youthLitRateMale;


	// Statistics
	if (statistics.is_open()) {

		getline(statistics, heading); // isolate the heading from stats

		// Create instances of Continent objects 
		Continent* africaObj = new Continent();
		Continent* asiaObj = new Continent();
		Continent* europeObj = new Continent();
		Continent* northAmericaObj = new Continent();
		Continent* oceaniaObj = new Continent();
		Continent* southAmericaObj = new Continent();

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

			Country countryObj(name, newPopulation, newLitRate, newEduGDP, 
				newPriCompTot, newPriCompMale, newPriCompFem, 
				newYouthLitRateFem, newYouthLitRateMale); // for testing

			vector<string>::iterator it;

			it = find(africa->begin(), africa->end(), countryObj.GetName());
			if (it != africa->end()){
				africaObj->AddCountry(countryObj);
			}

			it = find(asia->begin(), asia->end(), countryObj.GetName());
			if (it != asia->end()){
				asiaObj->AddCountry(countryObj);
			}

			it = find(europe->begin(), europe->end(), countryObj.GetName());
			if (it != europe->end()){
				europeObj->AddCountry(countryObj);
			}

			it = find(northAmerica->begin(), northAmerica->end(), countryObj.GetName());
			if (it != northAmerica->end()){
				northAmericaObj->AddCountry(countryObj);
			}

			it = find(oceania->begin(), oceania->end(), countryObj.GetName());
			if (it != oceania->end()){
				oceaniaObj->AddCountry(countryObj);
			}

			it = find(southAmerica->begin(), southAmerica->end(), countryObj.GetName());
			if (it != southAmerica->end()){
				southAmericaObj->AddCountry(countryObj);
			}

		}

		africaObj->Init();
		asiaObj->Init();
		europeObj->Init();
		northAmericaObj->Init();
		oceaniaObj->Init();
		southAmericaObj->Init();


		world->push_back(*africaObj);
		world->push_back(*asiaObj);
		world->push_back(*europeObj);
		world->push_back(*northAmericaObj);
		world->push_back(*oceaniaObj);
		world->push_back(*southAmericaObj);

		vector<Continent>::iterator it;
		int counter = 0;

		for ( it = world->begin(); it != world->end(); ++it ){
			cout << continents->at(counter) << endl;
			cout << *it << endl;
			counter++;
		}

		// Delete continent objects after use
		delete africaObj;
		africaObj = NULL;

		delete asiaObj;
		asiaObj = NULL;

		delete europeObj;
		europeObj = NULL;

		delete northAmericaObj;
		northAmericaObj = NULL;

		delete oceaniaObj;
		oceaniaObj = NULL;

		delete southAmericaObj;
		southAmericaObj = NULL;

		delete continents;
		continents = NULL;

		delete world;
		world = NULL;

	}

	else {
		cerr << "Unable to open file \'" << file2 << "\'";
		exit(1);
	}

	// Delete vectors of countries after use
	delete africa;
	africa = NULL;

	delete asia;
	asia = NULL;

	delete europe;
	europe = NULL;

	delete northAmerica;
	northAmerica = NULL;

	delete oceania;
	oceania = NULL;

	delete southAmerica;
	southAmerica = NULL;

	countriesFile.close();
	statistics.close();

}

/*
vector<string> &split(const string &s, char delim, vector< string > &elems) {

	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;

}


vector<string> split(const string &s, char delim) {

	vector< string > elems;
	split(s, delim, elems);
	return elems;

}
*/