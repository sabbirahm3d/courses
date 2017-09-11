/* 
 * STUDENTS DO NOT MODIFY THIS FILE
 *
 * WalkVertex is an ABSTRACT CLASS: it is only used as a base class for
 * the Intersection, SafeHouse, and PoliceStation classes.  It is not 
 * possible to instantiate a WalkVertex object.
 *
 */

#include <string>
#include "WalkVertex.h"

using namespace std;

int WalkVertex::s_idCtr = 0;

WalkVertex::WalkVertex() 
  : m_description("(none)"), m_id(NextID())
{ /* empty constructor body */ }

WalkVertex::WalkVertex(string description) 
  : m_description(description), m_id(NextID()) 
{ /* empty constructor body */ }

int WalkVertex::GetID() const {

  return m_id;

}

int WalkVertex::NextID() {

  return s_idCtr++;

}
