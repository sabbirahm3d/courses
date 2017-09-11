#ifndef TENT_H
#define TENT_H

#include "Residence.h"

using namespace std;

class Tent : public Residence {

 public:

  Tent();

 private:

  virtual double PropertyValue() const;
  virtual int NumWindows() const;

};

#endif
