#include <cstdlib>
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <algorithm> // for copy
#include <iterator> // for ostream_iterator

using namespace std;

#include "Country.h"
#include "Continent.h"


void ReadFromFiles(string, string);
vector<string> &split(const string &s, char delim, vector<string> &elems);
vector<string> split(const string &s, char delim);


int main(){

	string file1 = "data/CountriesContinents.txt";
	string file2 = "data/2013WorldBankEducationCensusData.txt";

	ReadFromFiles(file1, file2);

	return 0;

}


void ReadFromFiles(string file1, string file2){

	string heading, line;
	string name, population, litRate, educationGDPSpent, \
		primaryCompletionFemale, primaryCompletionMale, primaryCompletionTotal, \
		youthLitRateFem, youthLitRateMale;

	string country;
	vector<string> africa;
	vector<string> asia;
	vector<string> europe;
	vector<string> oceania;
	vector<string> northAmerica;
	vector<string> southAmerica;

	ifstream countries( file1.c_str(), ios_base::in );
	ifstream statistics( file2.c_str(), ios_base::in );


	// Statistics
	if ( statistics.is_open() ){

		cout << "Reading from \'" << file2 << "\'" << endl << endl;

		getline(statistics, heading); // isolate the heading from stats

		vector<string> x = split(heading, '\t'); // testing

		// copy( x.begin(), x.end(), ostream_iterator<string>(cout, "\n") ); //for testing

		// for (int i; i < x.size(); i++){

		// 	cout << x[i] << "lolol" << endl;

		// }


		statistics >> country >> population >> litRate >> educationGDPSpent >>
		primaryCompletionFemale >> primaryCompletionMale >> primaryCompletionTotal >>
		youthLitRateFem >> youthLitRateMale;

		while (statistics >> country >> population >> litRate >> educationGDPSpent >>
		primaryCompletionFemale >> primaryCompletionMale >> primaryCompletionTotal >>
		youthLitRateFem >> youthLitRateMale){
			cout << country << population << litRate << educationGDPSpent <<
			primaryCompletionFemale << primaryCompletionMale << primaryCompletionTotal <<
			youthLitRateFem << youthLitRateMale << endl;
		}

		statistics.close();
	}

	else {
		cerr << "Unable to open file";
		exit(1);
	}


	string numbers = "0123456789";

	// Countries
	if ( countries.is_open() ){

		cout << "Reading from \'" << file1 << "\'" << endl << endl;

		while ( getline(countries, country) ){

		    // size_t found = country.find_first_of(numbers.c_str());


			if (string::npos != country.find_first_of(numbers.c_str())) {
				// string cont, excess, num;
				// countries >> cont >> excess >> num;

				size_t pos = country.find("--");
				// vector<char&> nums;
				// nums.push_back(country.substr(pos+3));
				cout << country.substr(pos+3) << endl;

			}

		}

	}

	else {
		cerr << "Unable to open file";
		exit(1);
	}


}


vector<string> &split(const string &s, char delim, vector<string> &elems) {
	stringstream ss(s);
	string item;
	while (getline(ss, item, delim)) {
		elems.push_back(item);
	}
	return elems;
}


vector<string> split(const string &s, char delim) {
	vector<string> elems;
	split(s, delim, elems);
	return elems;
}