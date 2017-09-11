#include "Residence.h"
#include <iostream>

using namespace std;

Residence::Residence() {
  /* nothing */
}

Residence::Residence(int numRooms, int numWalls, bool hasWasher) {

  if ((numRooms > 0) && (numWalls > 0)) {
    m_numRooms = numRooms;
    m_numWalls = numWalls;
    m_hasWasher = hasWasher;
  }

}

double Residence::PropertyValue() const {

  double propertyVal;

  propertyVal = (10000 * m_numRooms);

  return propertyVal;

}

int Residence::NumWindows() const {

  int numWindows;

  numWindows = (2 * m_numWalls);

  return numWindows;

}

bool Residence::HasWasher() const {

  if (m_hasWasher == true)
    return true;
  else
    return false;

}

ostream& operator<<(ostream& out, const Residence& residence) {

  out << "Number of rooms: " << residence.m_numRooms << endl
      << "Number of walls: " << residence.m_numWalls << endl
      << "Washer: " << (residence.m_hasWasher == true ? "True" : "False")
      << endl << "Number of windows: " << residence.NumWindows() << endl
      << "Property value: " << residence.PropertyValue() << endl;

  return out;

}
