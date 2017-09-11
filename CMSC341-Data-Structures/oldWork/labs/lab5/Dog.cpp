// File: Dog.cpp
//
// Implementation of Dog class.
//

#include <iostream>
#include "Dog.h"

// ------------- Constructors ----------------------

// Default constructor--used to initialize all new Dogs.
// we'll learn about these later!
//
Dog::Dog() 
{
    cout << "Creating a Dog...\n";
    m_owner = "nobody:-(";
    m_name = "no-name";
    m_birthYear = 2001;
    m_happiness = 1;  // Start out as just "ok"
}


// ------------- Accessors -------------------------
//
// These do what you think.

string Dog::GetOwner() {
    return m_owner;
}

void Dog::SetOwner(const string &owner) {
    m_owner = owner;
}

string Dog::GetName() {
    return m_name;
}

void Dog::SetName(const string &name) {
    m_name = name;
}

int Dog::GetBirthYear() {
    return m_birthYear;
}

void Dog::SetBirthYear(int birthYear) {
    m_birthYear = birthYear;
}

void Dog::Scold() {
    m_happiness--;
}

void Dog::Reward() {
    m_happiness++;
}
// ------ Service/Facilitator Methods --------------

int Dog::GetAge(int currentYear) {
    return currentYear - m_birthYear;
}

string Dog::GetHappiness() {
    if(m_happiness > 1) {
        return "happy";
    }

    else if(m_happiness < 1) {
        return "sad";
    }
    
    else {
        return "ok";
    }
}
        
void Dog::Talk() {
    cout << "woof" << endl;
}
