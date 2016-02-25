#ifndef PLAYER_H
#define PLAYER_H

#include <string>
#include <iostream>

using namespace std;

class PLAYER {

public:
	
	PLAYER() { Fname = "null"; Lname = "null"; score = 0; }
	PLAYER(string fname, string lname, int pts)
               { Fname = fname; Lname = lname; score = pts; }
	string Fname;
	string Lname;
	size_t score;

	// mutators
	void setFname(string x) { Fname = x; } // use inline when possible, no source!
	void setLname(string x) { Lname = x; }
	void setScore(size_t x) { score = x; }
	
	// accessors
	string getFname() { return Fname; }
	string getLname() { return Lname; }
	size_t getScore() { return score; }

	// CUSTOM overloaded operators

        // COMPARE has to be a friend
	friend bool operator< (const PLAYER &x1, const PLAYER &x2){

		return x1.score < x2.score;

	}

	// CUSTOM overloaded streams
	friend ostream &operator << (ostream &out, const PLAYER &x){
	
		// out << x.getFname() << endl; --> will not work
		out << x.Fname << " " << x.Lname << ", with a score of " << x.score << endl;
		return out;
	};

};

#endif
