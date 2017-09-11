/* File:    Driver.cpp
 * Project: CMSC 341: Project 1, Spring 2016
 * Author:  Sabbir Ahmed
 * Date:    2/27/16
 * Section: 02
 * E-mail:  sabbir1@umbc.edu
 *
 * Driver file for Project 1. The program integrates the test Driver file
 * provided to test all the methods mentioned in the project description,
 * and also provides the option to dynamically create and test the various
 * methods of the classes
 */

#include "List341.h"
#include "Stack341.h"
#include "Queue341.h"


/* ******************** Declaration of functions ******************** */

/* StackMenu()
 * Preconditions: None
 * Postconditions: Allows the user to dynamically test out Stack341 methods */

void StackMenu();


/* QueueMenu()
 * Preconditions: None
 * Postconditions: Allows the user to dynamically test out Queue341 methods */

void QueueMenu();


/* SampleMenu()
 * Preconditions: None
 * Postconditions: Allows the user to call the sample driver program */

void SampleMenu();


int main() {

    int choice;
    bool flag = true;

    while (flag) {

        cout << endl << "----------------------------" << endl;
        cout << "1. Create a Stack341 object" << endl;
        cout << "2. Create a Queue341 object" << endl;
        cout << "3. Use the sample driver provided" << endl;
        cout << "4. Done testing, you deserve an A!" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        // User inputs their options
        switch(choice) {

            case 1:
                StackMenu();
                break;


            case 2:
                QueueMenu();
                break;

            case 3:
                SampleMenu();
                break;

            case 4:
                cout << "Program terminated." << endl;
                flag = false;
                break;

            default:
                cout << "Wrong choice" << endl;

        }

    }

    return 0;

}


/* StackMenu()
   Interactively handles a Stack341 object */

void StackMenu() {

    int choice;
    bool flag = true;
    string element;
    Stack341<string>* testList = new Stack341<string>;


    while (flag) {

        cout << endl << "----------------------------" << endl;
        cout << endl << "Create a Stack341" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Empty" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Size"<< endl;
        cout << "6. Top" << endl;
        cout << "7. Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;


        // User inputs their options
        switch ( choice ) {

        case 1:

            cout << "Enter the element: ";
            cin >> element;

            if ( testList->Push(element) ) {
                cout << "Pushed " << element << " into list." << endl;
            }

            else {
                cout << "Failed to push." << endl;
            }

            cout << endl;
            break;

        case 2:

            if ( !testList->Pop() ) {
                cout << "List is empty." << endl;
            }

            cout << endl;
            break;

        case 3:

            if (testList->Empty()) {
                cout << "List is empty." << endl;
            }

            else {
                cout << "List is not empty." << endl;
            }

            cout << endl;
            break;

        case 4:

            if (testList->Clear()){
                cout << "List cleared." << endl;
            }

            else {
                cout << "List empty, nothing to clear." << endl;
            }

            cout << endl;
            break;

        case 5:
            cout << testList->Size() << endl;
            break;    

        case 6:
            cout << testList->Top() << endl;
            break;

        case 7:
            if ( !testList->Empty() ) {
                cout << "You forgot to clear the list!" << endl;
                cout << "I'll clear it for you!" << endl;
                testList->Clear();
            }

            flag = false;
            break;

        default:
            cout << "Wrong choice" << endl;

        }
    }

    delete testList;
    testList = NULL;


}


/* QueueMenu()
   Interactively handles a Queue341 object */

void QueueMenu() {


    int choice;
    bool flag = true;
    string element;
    Queue341<string>* testList = new Queue341<string>;


    while (flag) {

        cout << endl << "----------------------------" << endl;
        cout << endl << "Create a Stack341" << endl;
        cout << "1. Push" << endl;
        cout << "2. Pop" << endl;
        cout << "3. Empty" << endl;
        cout << "4. Clear" << endl;
        cout << "5. Size"<< endl;
        cout << "6. Front" << endl;
        cout << "7. Back" << endl;
        cout << "8. Quit" << endl;
        cout << "Enter your choice : ";
        cin >> choice;

        switch ( choice ) {

        case 1:

            cout << "Enter the element: ";
            cin >> element;

            if ( testList->Push(element) ) {
                cout << "Pushed " << element << " into list." << endl;
            }

            else {
                cout << "Failed to push." << endl;
            }

            cout << endl;
            break;

        case 2:

            if ( !testList->Pop() ) {
                cout << "List is empty." << endl;
            }

            cout << endl;
            break;

        case 3:

            if (testList->Empty()) {
                cout << "List is empty." << endl;
            }

            else {
                cout << "List is not empty." << endl;
            }

            cout << endl;
            break;

        case 4:

            if (testList->Clear()){
                cout << "List cleared." << endl;
            }

            else {
                cout << "List empty, nothing to clear." << endl;
            }

            cout << endl;
            break;

        case 5:
            cout << testList->Size() << endl;
            break;    

        case 6:
            cout << testList->Front() << endl;
            break;

        case 7:
            cout << testList->Back() << endl;
            break;

        case 8:

            if ( !testList->Empty() ) {
                cout << "You forgot to clear the list!" << endl;
                cout << "I'll clear it for you!" << endl;
                testList->Clear();
            }

            flag = false;
            break;

        default:
            cout << "Wrong choice" << endl;

        }
    }

    delete testList;
    testList = NULL;

}


/* SampleMenu()
   Calls the modified sample driver program provided by the project 
   description */

void SampleMenu() {

    Stack341<int> *myDynStack = new Stack341<int>(); // dynamic Stack341
    Stack341<int> myStack; // static Stack341

    Queue341<double> *myDynQueue = new Queue341<double>(); // dynamic Queue341
    Queue341<double> myQueue; // static Queue341

    cout << endl;

    try {

        for (int i = 1; i < 101; i++){
            myDynStack->Push(i);
            myStack.Push(i);
        }

        cout << "Dynamic stack size: " << myDynStack->Size() << endl;
        cout << "Dynamic stack top = " << myDynStack->Top() << endl;
        cout << "Dynamic stack pop = " << myDynStack->Pop() << endl;
        cout << "Dynamic stack cleared = " << myDynStack->Clear() << endl;

        cout << "Static stack size: " << myStack.Size() << endl;
        cout << "Static stack top: " << myStack.Top() << endl;
        cout << "Static stack pop: " << myStack.Pop() << endl;
        cout << "Static stack cleared = " << myStack.Clear() << endl;
    
    }

    catch (Exceptions341 &E){
        cout << "Exception: " << E.GetMessage() << endl;

    }

    cout << "-----------------------------" << endl << endl;

    try {

        for (double i = 1; i < 101; i++){
            myDynQueue->Push(i);
            myQueue.Push(i);
        }

        cout << "Dynamic queue size: " << myDynQueue->Size() << endl;
        cout << "Dynamic queue front = " << myDynQueue->Front() << endl;
        cout << "Dynamic queue back = " << myDynQueue->Back() << endl;
        cout << "Dynamic queue pop = " << myDynQueue->Pop() << endl;
        cout << "Dynamic queue cleared = " << myDynQueue->Clear() << endl;

        cout << "Static queue size: " << myQueue.Size() << endl;
        cout << "Static queue front: " << myQueue.Front() << endl;
        cout << "Static queue back: " << myQueue.Back() << endl;
        cout << "Static queue pop: " << myQueue.Pop() << endl;
        cout << "Static queue cleared = " << myQueue.Clear() << endl;
    
    }

    catch (Exceptions341 &E){
        cout << "Exception: " << E.GetMessage() << endl;

    }
    
    delete myDynStack;
    delete myDynQueue;

}