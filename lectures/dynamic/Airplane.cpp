/*
 * Airplane.cpp
 *
 *  Created on: Jul 15, 2014
 *      Author: sumCTY1
 */

#include "Airplane.h"

int Duration::getHours() const { return hours; }
void Duration::setHours(int hours) { this->hours = hours; }
int Duration::getMinutes() const { return minutes;}
void Duration::setMinutes(int minutes) { this->minutes = minutes; }

// custom methods
void Duration::setHoursAndMinutes(int h, int m)
{
	setHours(h);
	setMinutes(m);
}

// default constructor
Airplane::Airplane()
{
	setCrew(0);
	setDestination("");
	setFlightName("");
	setFlightNumber("");
	setGate("");
	setOrigin("");
	setPassengers(0);
	setTravelTime(Duration{0,0});
}

Airplane::Airplane(int crew, int passengers, string des, string org)
{
	this->Crew = crew;
	this->Passengers = passengers;
	this->Destination = des;
	this->Origin = org;
}

int Airplane::getCrew() const { return Crew; }
void Airplane::setCrew(int crew) { Crew = crew; }
string Airplane::getDestination() const { return Destination; }
void Airplane::setDestination(string destination) { Destination = destination; }

string Airplane::getFlightName() const
{
	return FlightName;
}

void Airplane::setFlightName(string flightName)
{
	FlightName = flightName;
}

string Airplane::getFlightNumber() const
{
	return FlightNumber;
}

void Airplane::setFlightNumber(string flightNumber)
{
	FlightNumber = flightNumber;
}

string Airplane::getGate() const
{
	return Gate;
}

void Airplane::setGate(string gate)
{
	Gate = gate;
}

string Airplane::getOrigin() const
{
	return Origin;
}

void Airplane::setOrigin(string origin)
{
	Origin = origin;
}

int Airplane::getPassengers() const
{
	return Passengers;
}

void Airplane::setPassengers(int passengers)
{
	Passengers = passengers;
}

const Duration& Airplane::getTravelTime() const
{
	return TravelTime;
}

void Airplane::setTravelTime(const Duration& travelTime)
{
	TravelTime = travelTime;
}

