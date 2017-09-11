/* 
 * STUDENTS DO NOT MODIFY THIS FILE
 *
 * WalkVertex is an ABSTRACT CLASS: it is only used as a base class for
 * the Intersection, SafeHouse, and PoliceStation classes.  It is not 
 * possible to instantiate a WalkVertex object.
 *
 */

#ifndef WALKVERTEX_H
#define WALKVERTEX_H

#include <string>
#include <iostream>

using namespace std;

/* walk_status_t - status messages returned by Status() function
   CONTINUE - continue the walk
   SUCCESS - walk completed successfully (escaped)
   FAILURE - walked completed with FAILURE (caught)                      */

enum walk_status_t { CONTINUE, SUCCESS, FAILURE };

class WalkVertex {

 public:

  /* WalkVertex() - default constructor
     Preconditions: none
     Postconditions: creates a WalkVertex object with unique integer ID 
     and description "(none)".                                           */

  WalkVertex();

  /* WalkVertex() - non-default constructor
     Preconditions: none
     Postconditions: creates a WalkVertex object with unique integer ID 
     and caller-provided description.                                    */

  WalkVertex(string description);
  
  /* ToString() - returns string representation
     Preconditions: none
     Postconditions: returns a string representation of the object       */

  virtual string ToString() const = 0;

  /* Hello() - get walk status for current location
     Preconditions: none
     Postconditions: returns walk_status_t indicating whether walk has
     succeeded, failed, or should continue.                              */

  virtual walk_status_t Status() const = 0;

  /* GetID() - returns the ID of the WalkVertex object.
     Preconditions: none
     Postconditions: returns the integer ID of the WalkVertex object.    */

  int GetID() const;

 protected:

  string m_description;  // Description of vertex
  int m_id;              // Unique ID of vertex

 private:

  static int s_idCtr;    // Counter to generate unique IDs
  static int NextID();   // Helper function; gets next valid ID

};

#endif
