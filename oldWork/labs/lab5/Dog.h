// File: Dog.h
//
// Modified class definition from Lab 3.
// Added #ifndef ...  macros, default constructor, 
// GetName accessor.

#ifndef DOG_H
#define DOG_H

#include <string>

using namespace std;

class Dog {
public:
    // Default constructor--used to initialize all new Dogs.
    // we'll learn about these later!
    Dog();

    // Returns the name of the owner
    string GetOwner();

    // Gives the Dog a new owner
    void SetOwner(const string &owner);

    // Returns the name of the dog
    string GetName();

    // Gives the Dog a new name
    void SetName(const string &name);

    // Returns year the Dog was born
    int GetBirthYear();

    // Gives the Dog a new year of birth
    void SetBirthYear(int birthYear);

    // Abuse the dog
    void Scold();

    // Pat the dog
    void Reward();

    // Returns the age of the dog at a given year
    int GetAge(int current_year);

    // See how the dog is feeling
    string GetHappiness();

    // Prompt the dog to talk to you
    void Talk();

private:
    string m_name;	// Name of Dog
    int m_birthYear;	// Year dog was born
    string m_owner;	// Name of owner
    int m_happiness;	// Happiness rating from Scold() and Reward()

};

#endif 
