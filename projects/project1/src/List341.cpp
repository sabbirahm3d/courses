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
    
    head = NULL;

}


template <class datatype>
List341<datatype>::~List341() {

    Node341<datatype>* tmp;

    while(head) {
        tmp = head;
        head = head->next;
        delete tmp;
    }

}


template <class datatype>
int List341<datatype>::Size() const {

    Node341<datatype> *q = head;
    int m_size = 0;

    while (q != NULL) {
        q = q->next;
        m_size++;
    }
    
    return m_size;

}


template <class datatype>
bool List341<datatype>::Empty() const {

    if (head == NULL) {
        return true;
    }

    else {
        return false;
    }

}


template <class datatype>
bool List341<datatype>::Pop() {

    if (tail == NULL)
        return false;

    Node341<datatype> *tmp = tail;
    tail = tail->prev;

    if(tail != NULL)
        tail->next = NULL;

    delete tmp;

}


template <class datatype>
bool List341<datatype>::Push(datatype value) {

    Node341<datatype>* temp = new Node341<datatype>();

    temp->data = value;
    temp->next = NULL;

    if (head == NULL) {
        temp->prev = NULL;
        head = temp;
    }

    if (tail != NULL)
        tail->next = temp;

    tail = temp;

}
 
/*
 * Insertion at the beginning
 */
// template <class datatype>
// void List341<datatype>::add_begin(datatype value) {
//     if (head == NULL)
//     {
//         cout<<"First Push the list."<<endl;
//         return;
//     }
//     Node341<datatype>* temp = new Node341<datatype>();
//     temp->prev = NULL;
//     temp->data = value;
//     temp->next = head;
//     head->prev = temp;
//     head = temp;
//     cout<<"Element Inserted"<<endl;
// }
 
/*
 * Insertion of element at a particular position
 */
// template <class datatype>
// void List341<datatype>::add_after(datatype value, datatype pos)
// {
//     if (head == NULL)
//     {
//         cout<<"First Push the list."<<endl;
//         return;
//     }
//     Node341<datatype> *tmp = new Node341<datatype>();
//     Node341<datatype> *q = new Node341<datatype>();
//     datatype i;
//     q = head;
//     for (i = 0;i < pos - 1; i++)
//     {
//         q = q->next;
//         if (q == NULL)
//         {
//             cout<<"There are less than ";
//             cout<<pos<<" elements."<<endl;
//             return;
//         }
//     }
//     // tmp = new(Node341);
//     tmp->data = value;
//     if (q->next == NULL)
//     {
//         q->next = tmp;
//         tmp->next = NULL;
//         tmp->prev = q;      
//     }
//     else
//     {
//         tmp->next = q->next;
//         tmp->next->prev = tmp;
//         q->next = tmp;
//         tmp->prev = q;
//     }
//     cout<<"Element Inserted"<<endl;
// }
 
/*
 * Deletion of element from the list
 */
template <class datatype>
bool List341<datatype>::Clear() {

    if (head == NULL){
        return false;
    }

    else {

        Node341<datatype> *cursor = head;
        
        /* Traverse the list and delete the node one by one from the head */
        while (cursor != NULL) {
            /* take out the head node */
            head = head->next;
            delete cursor;
            /* update the head node */
            cursor = head;
        }
        /* Reset the head and tail node */
        head = NULL;

        return true;
    }

}
 
/*
 * Display elements of Doubly Link List
 */
template <class datatype>
void List341<datatype>::display_dlist()
{
    Node341<datatype> *q = new Node341<datatype>();
    if (head == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = head;
    cout<<"The Doubly Link List is :"<<endl;
    while (q != NULL)
    {
        cout<<q->data<<" <-> ";
        q = q->next;
    }
    cout<<"NULL"<<endl;
}
 
/*
 * Number of elements in Doubly Link List
 */
 
/*
 * Reverse Doubly Link List
 */
// template <class datatype>
// void List341<datatype>::reverse()
// {
//     Node341<datatype> *p1 = new Node341<datatype>();
//     Node341<datatype> *p2 = new Node341<datatype>();
//     p1 = head;
//     p2 = p1->next;
//     p1->next = NULL;
//     p1->prev = p2;
//     while (p2 != NULL)
//     {
//         p2->prev = p2->next;
//         p2->next = p1;
//         p1 = p2;
//         p2 = p2->prev; 
//     }
//     head = p1;
//     cout<<"List Reversed"<<endl; 
// }

#endif