#include "Apartment.h"
#include "House.h"
using namespace std;

Apartment::Apartment(int story, bool hasWasher) : House(4, 4, hasWasher), m_story(story) { 
  /* nothing */
}

double Apartment::PropertyValue() const {

  double propertyVal;

  propertyVal = (m_numRooms * 10000);

  if (m_hasWasher == true) {
    propertyVal += 100;
  }

  return propertyVal;

}

int Apartment::GetStory() const {

  return m_story;

}

ostream& operator <<(ostream & mout, const Apartment& apartment) {
 

  mout << "Number of Rooms: " << apartment.m_numRooms<< endl
       << "Number of Walls: " << apartment.m_numWalls << endl
       << "Washer: " << (apartment.HasWasher() == true ? "True" : "False")
       << endl
       << "Number of Windows: " << apartment.NumWindows() << endl
       << "Property Value: " << apartment.PropertyValue() << endl
       << "Story: " << apartment.GetStory() << endl;
  return mout;
}
