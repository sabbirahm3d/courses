#ifndef APARTMENT_H
#define APARTMENT_H

#include "Residence.h"
#include "House.h"

using namespace std;

class Apartment : public House {

 public:

  Apartment(int story, bool hasWasher);
  virtual double PropertyValue() const;
  virtual int GetStory() const;

  friend ostream& operator<<(ostream& mout, const Apartment& apartment);

 private:

  int m_story;

};

#endif
