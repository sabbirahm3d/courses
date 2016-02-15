/* File:    Driver.cpp
 * Project: CMSC 341: Project 0, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/13/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu

 * The driver program for Project 0, this file reads through two input files to
 * map 6 continents to their corresponding countries, and adds statistics to
 * them to convert into Country objects. The Country objects are then appended
 * to their corresponding Continent object, and then used to find the total
 * population, the country with the highest population, literacy rate and
 * expendature on education for each continents.
 */


#include "Country.h"
#include "Continent.h"


/* ******************** Declaration of functions ******************** */

/* ReadFromFiles()
 * Preconditions: Parameters must be valid paths to the input files.
 * Postconditions: Checks if paths are valid, and then implements the driver
   program as specified by the Project 0 description. */

void ReadFromFiles(string, string);


/* Find()
 * Preconditions: Parameters are custom iterators, and custom objects.
   Postconditions: Returns the custom object, if found. */

template <class iteratorT, class stringT>
iteratorT Find(iteratorT, iteratorT, const stringT&);


/* Find()
 * Preconditions: Parameters are either pointers to vectors of strings or 
 * custom objects.
 * Postconditions: Deletes the object and its pointer. */

template <typename pointerT>
void Destroy(pointerT);


/* ******************** Implementation of functions ******************** */


/* main()
 * Driver function. Calls ReadFromFiles() after passing in the paths to the
   input files. */

int main() {

	string file1 = "CountriesContinents.txt";
	string file2 = "2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1, file2);

	return 0;

}


/* Find()
 * Helper template. Parameters are pointers to custom iterators, so the types
   are not declared. Searches through vectors of Country objects for a Country
   object with specific attributes, and returns the object if found. */

template <class iteratorT, class stringT>
iteratorT Find(iteratorT first, iteratorT last, const stringT& countryName) {

	while (first != last) {

		if (*first == countryName) {
			return first;
		}
		++first; // narrows down the area to search by iterations
	}

	return last;

}


/* Destroy()
 * Helper template. Parameters are pointers to vectors of strings, custom
   objects, or vectors of custom objects. Deletes the object passed in to free
   heap memory. */

template <typename pointerT>
void Destroy(pointerT object) { 

	delete object;
	object = NULL;

} 

/* ReadFromFiles()
 * Parameters are paths to the input files. Creates instances of the 2 classes
   and appends statistical data to them, and calls the overloaded output
   operator to display the result. */

void ReadFromFiles(string file1, string file2) {

	// Reads the 2 input files
	ifstream countriesFile(file1.c_str(), ios_base::in);
	ifstream statistics(file2.c_str(), ios_base::in);

	// Allocates new pointers for vectors of strings to contain countries
	// for each continents, to contain the names of continents, and vectors
	// of Continent objects to hold the final output.
	vector<string>* africa = new vector<string>;
	vector<string>* asia = new vector<string>;
	vector<string>* europe = new vector<string>;
	vector<string>* northAmerica = new vector<string>;
	vector<string>* oceania = new vector<string>;
	vector<string>* southAmerica = new vector<string>;

	vector<string>* continents = new vector<string>;
	vector<Continent>* world = new vector<Continent>;

	// CountriesContinents.txt
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

			it = Find(africa->begin(), africa->end(), countryObj.GetName());
			if (it != africa->end()) {
				africaObj->AddCountry(countryObj);
			}

			it = Find(asia->begin(), asia->end(), countryObj.GetName());
			if (it != asia->end()) {
				asiaObj->AddCountry(countryObj);
			}

			it = Find(europe->begin(), europe->end(), countryObj.GetName());
			if (it != europe->end()) {
				europeObj->AddCountry(countryObj);
			}

			it = Find(northAmerica->begin(), northAmerica->end(),
				countryObj.GetName());
			if (it != northAmerica->end()) {
				northAmericaObj->AddCountry(countryObj);
			}

			it = Find(oceania->begin(), oceania->end(),
				countryObj.GetName());
			if (it != oceania->end()) {
				oceaniaObj->AddCountry(countryObj);
			}

			it = Find(southAmerica->begin(), southAmerica->end(),
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