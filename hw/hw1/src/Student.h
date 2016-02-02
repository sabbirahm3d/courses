#ifndef STUDENT_H
#define STUDENT_H

#include <string>
#include <iostream>

using namespace std;

class STUDENT
{
public:
	
	STUDENT() { Fname = "null"; Lname = "null"; score = 0; }
	STUDENT(string fname, string lname, int pts)
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
	const STUDENT &operator = (const STUDENT &source);
	bool operator != (const STUDENT &source) { return !(score == source.score); }
	bool operator == (const STUDENT &source) 
	{ return (score == source.score) && (Fname == source.Fname) && (Lname == source.Lname); }

	bool operator < (const STUDENT &source) const { return score < source.score; }
	friend bool compare(const STUDENT &e1, const STUDENT &e2) { return e1.score < e2.score; } 
      // COMPARE has to be a friend

	// CUSTOM overloaded streams
	friend ostream &operator << (ostream &out, const STUDENT &x);
	friend istream &operator >> (istream &in, STUDENT &x);
};

#endif
