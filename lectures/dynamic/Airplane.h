/*
 * Airplane.h
 *
 *  Created on: Jul 15, 2014
 *      Author: sumCTY1
 */

#include <string>
#include <iostream>
using namespace std;

#ifndef AIRPLANE_H_
#define AIRPLANE_H_

struct Duration
{
	int hours;
	int minutes;

	int getHours() const;
	void setHours(int hours);
	int getMinutes() const;
	void setMinutes(int minutes);

	// custom methods
	void setHoursAndMinutes(int h, int m);

	// any overload have to be "friends"
	friend ostream &operator << (ostream &os, const Duration &x)
	{
		os << x.hours << ":" << x.minutes << endl;	return os;
	}
};




class Airplane
{
public:
	// friends

	// constructors
	Airplane();
	Airplane(int crew, int passengers, string des, string org);

	// setters and getters
	int getCrew() const;
	void setCrew(int crew);
	string getDestination() const;
	void setDestination(string destination);
	string getFlightName() const;
	void setFlightName(string flightName);
	string getFlightNumber() const;
	void setFlightNumber(string flightNumber);
	string getGate() const;
	void setGate(string gate);
	string getOrigin() const;
	void setOrigin(string origin);
	int getPassengers() const;
	void setPassengers(int passengers);
	const Duration& getTravelTime() const;
	void setTravelTime(const Duration& travelTime);

	// any overload have to be "friends"
	friend ostream &operator << (ostream &os, const Airplane &x)
	{
		os << "<----------------->" << endl;
		os << "crew->" << x.Crew << endl;
		os << "passenger->" << x.Passengers << endl;
		os << "origin->" << x.Origin << endl;
		os << "destination->" << x.Destination << endl;

		return os;
	}

private:
	string FlightName;
	int Passengers;
	int Crew;
	string FlightNumber;
	string Destination;
	string Origin;
	string Gate;
	Duration TravelTime;

};

#endif /* AIRPLANE_H_ */

