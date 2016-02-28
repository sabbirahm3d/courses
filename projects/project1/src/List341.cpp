#ifndef LIST341_CPP
#define LIST341_CPP

#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Exceptions341.h"
#include "Node341.h"
#include "List341.h"

using namespace std;


template <class datatype>
List341<datatype>::List341() {
    
    m_head = m_tail = NULL;
    m_size = 0;

}


template <class datatype>
List341<datatype>::~List341() {

    Node341<datatype>* cursor = m_head;

    while (cursor != NULL) {
        Node341<datatype>* next = cursor->next;
        delete cursor;
        cursor = next;
    }

    m_head = m_tail = NULL;

}

#endif