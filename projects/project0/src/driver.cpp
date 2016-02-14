#include "Country.h"
#include "Continent.h"


// Declaration of functions
void ReadFromFiles(string, string);


template <class iteratorT, class stringT>
iteratorT find(iteratorT first, iteratorT last, const stringT& countryName) {

	while (first != last) {
		if (*first == countryName) {
			return first;
		}

		++first;
	}

	return last;

}


// Template for deleting heap blocks of any data types
template <typename pointerT>
void Destroy(pointerT object) { 

	delete object;
	object = NULL;

} 


int main() {

	string file1 = "CountriesContinents.txt";
	string file2 = "2013WorldBankEducationCensusData.txt";

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
		cerr << "Unable to open file \'" << file1 << "\'." << endl
		<< "Please make sure \'" << file1 << 
		"\' exists in the same directory as this file." << endl;
		exit(1);
	}

	string line;
	string name, population, litRate, eduGDP, priCompTot, priCompMale,
		priCompFem, youthLitRateFem, youthLitRateMale;


	// Statistics
	if (statistics.is_open()) {

		getline(statistics, line); // isolate the heading from stats

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
			if ( atof(litRate.c_str()) == 0 ){
				newLitRate = -1;
			}

			else {
				newLitRate = atof(litRate.c_str());
			}

			// Convert eduGDP into float
			if ( atof(eduGDP.c_str()) == 0 ) {
				newEduGDP = -1;
			}

			else {
				newEduGDP = atof(eduGDP.c_str());
			}

			// Convert priCompFem into float
			if ( atof(priCompFem.c_str()) == 0 ){
				newPriCompFem = -1;
			}

			else {
				newPriCompFem = atof(priCompFem.c_str());
			}

			// Convert priCompMale into float
			if ( atof(priCompTot.c_str()) == 0 ){
				newPriCompTot = -1;
			}

			else {
				newPriCompTot = atof(priCompTot.c_str());
			}

			// Convert priCompTot into float
			if ( atof(priCompMale.c_str()) == 0 ){
				newPriCompMale = -1;
			}

			else {
				newPriCompMale = atof(priCompMale.c_str());
			}

			// Convert youthLitRateFem into float
			if ( atof(youthLitRateFem.c_str()) == 0 ){
				newYouthLitRateFem = -1;
			}

			else {
				newYouthLitRateFem = atof(youthLitRateFem.c_str());
			}

			// Convert youthLitRateMale into float
			if ( atof(youthLitRateMale.c_str()) == 0 ){
				newYouthLitRateMale = -1;
			}

			else {
				newYouthLitRateMale = atof(youthLitRateMale.c_str());
			}


			Country countryObj(name, newPopulation, newLitRate, newEduGDP, 
				newPriCompTot, newPriCompMale, newPriCompFem, 
				newYouthLitRateFem, newYouthLitRateMale);

			vector<string>::iterator it;

			it = find(africa->begin(), africa->end(), countryObj.GetName());
			if (it != africa->end()) {
				africaObj->AddCountry(countryObj);
			}

			it = find(asia->begin(), asia->end(), countryObj.GetName());
			if (it != asia->end()) {
				asiaObj->AddCountry(countryObj);
			}

			it = find(europe->begin(), europe->end(), countryObj.GetName());
			if (it != europe->end()) {
				europeObj->AddCountry(countryObj);
			}

			it = find(northAmerica->begin(), northAmerica->end(),
				countryObj.GetName());
			if (it != northAmerica->end()) {
				northAmericaObj->AddCountry(countryObj);
			}

			it = find(oceania->begin(), oceania->end(),
				countryObj.GetName());
			if (it != oceania->end()) {
				oceaniaObj->AddCountry(countryObj);
			}

			it = find(southAmerica->begin(), southAmerica->end(),
				countryObj.GetName());
			if (it != southAmerica->end()) {
				southAmericaObj->AddCountry(countryObj);
			}

		}

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
		Destroy(africaObj);
		Destroy(asiaObj);
		Destroy(europeObj);
		Destroy(northAmericaObj);
		Destroy(oceaniaObj);
		Destroy(southAmericaObj);

		// Delete the helper vectors
		Destroy(continents);
		Destroy(world);

	}

	else {
		cerr << "Unable to open file \'" << file2 << "\'." << endl
		<< "Please make sure \'" << file2 << 
		"\' exists in the same directory as this file." << endl;
		exit(1);
	}

	// Delete vectors of countries after use
	Destroy(africa);
	Destroy(asia);
	Destroy(europe);
	Destroy(northAmerica);
	Destroy(oceania);
	Destroy(southAmerica);

	countriesFile.close();
	statistics.close();

}