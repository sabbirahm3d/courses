// File: lab5.cpp
//
// Demonstrates use of the Dog class.
// Compile together with Dog.cpp
//

#include <iostream>
#include "Dog.h"

using namespace std;

int main() {
    // CREATE TWO OBJECTS OF THE "Dog" CLASS BY DECLARING VARIABLES
    // "dog1" AND "dog2" OF THAT CLASS TYPE:
    Dog dog1;
    Dog dog2;

    // PRINT THE INITIAL FIELD VALUES FOR THE dog1:
    cout << "dog1's original data:\n";
    cout << "  name is: " << dog1.GetName() << endl;
    cout << "  age in 2014 is: " << dog1.GetAge(2014) << endl;
    cout << "  owner is: " << dog1.GetOwner() << endl;

    // MODIFY dog1 AND dog2, BY USING THE APPROPRIATE Dog CLASS METHODS,
    // TO SET THE "owner" FIELD TO SOMETHING NEW, THEN FETCH THE FIELDS
    // BACK OUT AND PRINT
    cout << "Give the dogs to new owners:\n";
    dog1.SetOwner("fgh"); // set new owner for dog1
    cout << "dog1's new owner is: " << dog1.GetOwner() << endl;
    dog2.SetOwner("bob"); // set new owner for dog2
    cout << "dog2's new owner is: " << dog2.GetOwner() << endl;

    // INTERACT WITH YOUR DOGS TO AFFECT THEIR HAPPINESS RATINGS,
    // BY USING THE Scold() AND Reward() METHODS
    cout << "Scold and reward a dog several times:\n";

    // Fetch current happiness value and print it out
    cout << "dog1 starts out " << dog1.GetHappiness() << endl;
    /*
    // Now, scold dog1 once, then reward it twice, printing out the
    // happiness level after each change:
    dog1.Scold();  // scold the dog
    cout << "Scolded dog1: dog is now " << dog1.Scold() << endl;
    dog1.Reward();  // reward the dog
    cout << "Rewarded dog1: dog is now " << dog1.Reward() << endl;
    dog1.Reward();  // reward the dog
    cout << "Rewarded dog1: dog is now " << dog1.Reward() << endl;
    */

    // FINALLY, GET THE DOGS TO TALK TO YOU
    cout << "Asking dog1 to speak:\n";
    dog1.Talk();

    return 0;

}
