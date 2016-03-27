#ifndef LECTURER_H
#define LECTURER_H

#include <string>
#include <iostream>
using namespace std;

class Lecturer {

	private:

		// set up data members for first, last, age and salary

		string firstName;
		string lastName;
		int age;
		int salary;

	public:

		Lecturer(string fName, string lName, int old, int little) {

			setAge(old);
			setFirstName(fName);
			setlastName(lName);
			setSalary(little);

		}

		// set up getter(s) prototypes here

		string GetfName(){

			return firstName;

		}

		string GetlName(){

			return lastName;

		}

		int GetAge(){

			return age;

		}

		int Getsalary(){

			return salary;

		}

		// set up setter(s) prototypes here

		void setFirstName(string param){

			firstName = param;

		}

		void setlastName(string param){

			lastName = param;

		}

		void setAge(int param){

			age = param;

		}

		void setSalary(int param){

			salary = param;

		}
};

#endif
