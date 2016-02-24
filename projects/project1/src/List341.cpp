/*
 * C++ Program to Implement Doubly Linked List 
 */
#include <iostream>
#include <cstdio>
#include <cstdlib>
#include "Exceptions341.h"

using namespace std;


// class node {

// public:

//     int data;
//     node *next;
//     node *prev;

// };

template <class T>
class node {

public:

    T data;
    node *next;
    node *prev;

};

node<int>* start = new node<int>;

/*
 Class Declaration 
 */
class List341 {
public:
    void create_list(int value);
    void add_begin(int value);
    void add_after(int value, int position);
    void delete_element(int value);
    void search_element(int value);
    void display_dlist();
    // void 
    virtual int Size() const;
    void reverse();
    List341()
    {
        start = NULL;  
    }

private:


};

/*
 * Create Double Link List
 */
void List341::create_list(int value)
{
    node<int> *s;
    // temp = new(node);
    node<int>* temp = new node<int>();
    temp->data = value;
    temp->next = NULL;
    if (start == NULL)
    {
        temp->prev = NULL;
        start = temp;
    }
    else
    {
        s = start;
        while (s->next != NULL)
            s = s->next;
        s->next = temp;
        temp->prev = s;
    }
}
 
/*
 * Insertion at the beginning
 */
void List341::add_begin(int value)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node<int>* temp = new node<int>();
    // temp = new(node);
    temp->prev = NULL;
    temp->data = value;
    temp->next = start;
    start->prev = temp;
    start = temp;
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Insertion of element at a particular position
 */
void List341::add_after(int value, int pos)
{
    if (start == NULL)
    {
        cout<<"First Create the list."<<endl;
        return;
    }
    node<int> *tmp = new node<int>();
    node<int> *q = new node<int>();
    int i;
    q = start;
    for (i = 0;i < pos - 1;i++)
    {
        q = q->next;
        if (q == NULL)
        {
            cout<<"There are less than ";
            cout<<pos<<" elements."<<endl;
            return;
        }
    }
    // tmp = new(node);
    tmp->data = value;
    if (q->next == NULL)
    {
        q->next = tmp;
        tmp->next = NULL;
        tmp->prev = q;      
    }
    else
    {
        tmp->next = q->next;
        tmp->next->prev = tmp;
        q->next = tmp;
        tmp->prev = q;
    }
    cout<<"Element Inserted"<<endl;
}
 
/*
 * Deletion of element from the list
 */
void List341::delete_element(int value)
{
    // node *tmp, *q;
    node<int> *tmp = new node<int>();
    node<int> *q = new node<int>();
     /*first element deletion*/
    if (start->data == value)
    {
        tmp = start;
        start = start->next;  
        start->prev = NULL;
        cout<<"Element Deleted"<<endl;
        free(tmp);
        return;
    }
    q = start;
    while (q->next->next != NULL)
    {   
        /*Element deleted in between*/
        if (q->next->data == value)  
        {
            tmp = q->next;
            q->next = tmp->next;
            tmp->next->prev = q;
            cout<<"Element Deleted"<<endl;
            free(tmp);
            return;
        }
        q = q->next;
    }
     /*last element deleted*/
    if (q->next->data == value)    
    {   
        tmp = q->next;
        free(tmp);
        q->next = NULL;
        cout<<"Element Deleted"<<endl;
        return;
    }
    cout<<"Element "<<value<<" not found"<<endl;
}
 
/*
 * Display elements of Doubly Link List
 */
void List341::display_dlist()
{
    node<int> *q = new node<int>();
    if (start == NULL)
    {
        cout<<"List empty,nothing to display"<<endl;
        return;
    }
    q = start;
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
int List341::Size() const {

    node<int> *q = start;
    int cnt = 0;
    while (q != NULL)
    {
        q = q->next;
        cnt++;
    }
    
    return cnt;

}
 
/*
 * Reverse Doubly Link List
 */
void List341::reverse()
{
    node<int> *p1 = new node<int>();
    node<int> *p2 = new node<int>();
    p1 = start;
    p2 = p1->next;
    p1->next = NULL;
    p1->prev = p2;
    while (p2 != NULL)
    {
        p2->prev = p2->next;
        p2->next = p1;
        p1 = p2;
        p2 = p2->prev; 
    }
    start = p1;
    cout<<"List Reversed"<<endl; 
}