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


/* IsFloat()
 * Preconditions: Parameter must be a string.
   Postconditions: Returns the float version of the string. */

float IsFloat(string);


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


/* IsFloat()
 * Helper function, to minimize lines of code (multiple if-else conditions).
   Parameters are variables extracted from the input file. If the variable
   is not a float, i.e. "N/A", -1 is assigned. If the variable is a float, it
   returns the float-version of it. */

float IsFloat(string inputFloat) {

    if ( atof(inputFloat.c_str()) == 0 ) {
        return -1;
    }

    else {
        return atof(inputFloat.c_str());
    }

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
        int countSwitch = 0;

        // Read through the entire file
        while ( !countriesFile.eof() ) {

            // Assigns continent name, excess dummy data ('--' or '---') and
            // the number of countries as specified in the input file.
            countriesFile >> continent >> excess >> numCountries;

            // The continent name is then appended to a temporary vector.
            continents->push_back(continent);

            // All the remaining numCountries amount of lines are then stored
            // in vectors of countries corresponding to their continent.
            for (int i = 0; i <= numCountries; i++) {

                getline(countriesFile, country);

                // A switch statement is used since the same looping technique
                // would be used for all 6 continent vectors
                switch(countSwitch) {

                    case 0: {
                        africa->push_back(country);
                        break;
                    }

                    case 1: {
                        asia->push_back(country);
                        break;
                    }

                    case 2: {
                        europe->push_back(country);
                        break;
                    }

                    case 3: {
                        northAmerica->push_back(country);
                        break;
                    }

                    case 4: {
                        oceania->push_back(country);
                        break;
                    }

                    case 5: {
                        southAmerica->push_back(country);
                        break;
                    }

                    default: {
                        cerr << "Invalid format in file." << endl;
                    }

                }
            }

            // Iterate to switch to the next for-loop to begin storing data
            // for the next continent.
            countSwitch++;
        }

        // Overwrite the dummy line with an empty string
        excess = "";

    }


    // Exits the program if the input file does not exist, or the path
    // specified is invalid.
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

        // isolate the heading from statistics
        getline(statistics, line);

        // overwrite the dummy line with an empty string
        line = "";

        // Allocate pointers of instances of new Continent objects
        Continent* africaObj = new Continent();
        Continent* asiaObj = new Continent();
        Continent* europeObj = new Continent();
        Continent* northAmericaObj = new Continent();
        Continent* oceaniaObj = new Continent();
        Continent* southAmericaObj = new Continent();

        // Read through the rest of the file, assigning each variables
        while (statistics >> name >> population >> litRate >> eduGDP >>
            priCompTot >> priCompMale >> priCompFem >> youthLitRateFem >>
            youthLitRateMale) {

            long newPopulation;
            float newLitRate, newEduGDP, newPriCompFem, newPriCompMale, 
                newPriCompTot, newYouthLitRateFem, newYouthLitRateMale;

            // Convert population into long
            newPopulation = atol(population.c_str());

            // Convert the rest of the variables to floats
            newLitRate = IsFloat(litRate);
            newEduGDP = IsFloat(eduGDP);
            newPriCompFem = IsFloat(priCompFem);
            newPriCompMale = IsFloat(priCompMale);
            newPriCompTot = IsFloat(priCompTot);
            newYouthLitRateMale = IsFloat(youthLitRateMale);
            newYouthLitRateFem = IsFloat(youthLitRateFem);

            // Create Country objects with the variables extracted
            Country countryObj(name, newPopulation, newLitRate, newEduGDP, 
                newPriCompTot, newPriCompMale, newPriCompFem, 
                newYouthLitRateFem, newYouthLitRateMale);

            // Create a temporary iterator to iterate through the vectors of
            // countries
            vector<string>::iterator it;

            // The iterator is used with Find() to search for the country
            // within the 6 continent vectors of countries 
            it = Find(africa->begin(), africa->end(), countryObj.GetName());
            if (it != africa->end()) {

                // If the country is found, it is passed in to its respective
                // Continent object
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

        // Append all the Continent objects into a vector
        world->push_back(*africaObj);
        world->push_back(*asiaObj);
        world->push_back(*europeObj);
        world->push_back(*northAmericaObj);
        world->push_back(*oceaniaObj);
        world->push_back(*southAmericaObj);


        // A temporary iterator and counter to display the final output
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


    // Exits the program if the input file does not exist, or the path
    // specified is invalid.
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