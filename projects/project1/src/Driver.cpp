// #include "Stack341.cpp"
// #include "Queue341.cpp"


// void StackMenu();
// void QueueMenu();


// int main() {

//     int choice;
//     bool flag = true;

//     while (flag) {

//         cout << endl << "----------------------------" << endl;
//         cout << "1. Create a Stack341 object" << endl;
//         cout << "2. Create a Queue341 object" << endl;
//         cout << "3. Done testing, you deserve an A!" << endl;
//         cout << "Enter your choice : ";
//         cin >> choice;

//         switch(choice) {

//             case 1:

//                 StackMenu();
//                 break;


//             case 2:

//                 QueueMenu();
//                 break;

//             case 3:

//                 cout << "Program terminated." << endl;
//                 flag = false;
//                 break;

//             default:
//                 cout << "Wrong choice" << endl;

//         }

//     }


//     return 0;

// }


// void StackMenu() {


//     int choice;
//     bool flag = true;
//     string element;
//     Stack341<string>* testList = new Stack341<string>;


//     while (flag) {

//         cout << endl << "----------------------------" << endl;
//         cout << endl << "Create a Stack341" << endl;
//         cout << "1. Push" << endl;
//         cout << "2. Pop" << endl;
//         cout << "3. Empty" << endl;
//         cout << "4. Clear" << endl;
//         cout << "5. Size"<< endl;
//         cout << "6. Top" << endl;
//         cout << "7. Quit" << endl;
//         cout << "Enter your choice : ";
//         cin >> choice;

//         switch ( choice ) {

//         case 1:

//             cout << "Enter the element: ";
//             cin >> element;

//             if ( testList->Push(element) ) {
//                 cout << "Pushed " << element << " into list." << endl;
//             }

//             else {
//                 cout << "Failed to push." << endl;
//             }

//             cout << endl;
//             break;

//         case 2:

//             if ( !testList->Pop() ) {
//                 cout << "List is empty." << endl;
//             }

//             cout << endl;
//             break;

//         case 3:

//             if (testList->Empty()) {
//                 cout << "List is empty." << endl;
//             }

//             else {
//                 cout << "List is not empty." << endl;
//             }

//             cout << endl;
//             break;

//         case 4:

//             if (testList->Clear()){
//                 cout << "List cleared." << endl;
//             }

//             else {
//                 cout << "List empty, nothing to clear." << endl;
//             }

//             cout << endl;
//             break;

//         case 5:
//             cout << testList->Size() << endl;
//             break;    

//         case 6:
//             cout << testList->Top() << endl;
//             break;

//         case 7:

//             if ( !testList->Empty() ) {
//                 cout << "You forgot to clear the list!" << endl;
//                 cout << "I'll clear it for you!" << endl;
//                 testList->Clear();
//             }

//             flag = false;
//             break;

//         default:
//             cout << "Wrong choice" << endl;

//         }
//     }

//     delete testList;
//     testList = NULL;


// }

// void QueueMenu() {


//     int choice;
//     bool flag = true;
//     string element;
//     Queue341<string>* testList = new Queue341<string>;


//     while (flag) {

//         cout << endl << "----------------------------" << endl;
//         cout << endl << "Create a Stack341" << endl;
//         cout << "1. Push" << endl;
//         cout << "2. Pop" << endl;
//         cout << "3. Empty" << endl;
//         cout << "4. Clear" << endl;
//         cout << "5. Size"<< endl;
//         cout << "6. Front" << endl;
//         cout << "7. Back" << endl;
//         cout << "8. Quit" << endl;
//         cout << "Enter your choice : ";
//         cin >> choice;

//         switch ( choice ) {

//         case 1:

//             cout << "Enter the element: ";
//             cin >> element;

//             if ( testList->Push(element) ) {
//                 cout << "Pushed " << element << " into list." << endl;
//             }

//             else {
//                 cout << "Failed to push." << endl;
//             }

//             cout << endl;
//             break;

//         case 2:

//             if ( !testList->Pop() ) {
//                 cout << "List is empty." << endl;
//             }

//             cout << endl;
//             break;

//         case 3:

//             if (testList->Empty()) {
//                 cout << "List is empty." << endl;
//             }

//             else {
//                 cout << "List is not empty." << endl;
//             }

//             cout << endl;
//             break;

//         case 4:

//             if (testList->Clear()){
//                 cout << "List cleared." << endl;
//             }

//             else {
//                 cout << "List empty, nothing to clear." << endl;
//             }

//             cout << endl;
//             break;

//         case 5:
//             cout << testList->Size() << endl;
//             break;    

//         case 6:
//             cout << testList->Front() << endl;
//             break;

//         case 7:
//             cout << testList->Back() << endl;
//             break;

//         case 8:

//             if ( !testList->Empty() ) {
//                 cout << "You forgot to clear the list!" << endl;
//                 cout << "I'll clear it for you!" << endl;
//                 testList->Clear();
//             }

//             flag = false;
//             break;

//         default:
//             cout << "Wrong choice" << endl;

//         }
//     }

//     delete testList;
//     testList = NULL;

// }

/**************************************************************
 * File:    Driver.cpp
 * Project: CMSC 341 - Project 1
 * Author : Frank Zastawnik
 * Date   : 12-February-2016
 * Section: 
 * E-mail:  frankz2@umbc.edu
 *
 * Sample driver file for project 1.
 *
 *************************************************************/

#include "List341.h"
#include "Stack341.h"
#include "Queue341.h"

int main(int argc, char *argv[]) {

    // Stack341<int> *myStack = new Stack341<int>();
    Stack341<int> *myDynQueue = new Stack341<int>();
    Stack341<int> myQueue;
    

    try {
        for (int i = 1; i < 101; i++){
            // myStack->Push(i);
            myDynQueue->Push(i);
            myQueue.Push(i);
        }
    cout << "Dynamic queue size: " << myDynQueue->Size() << endl;
    cout << "Dynamic queue back = " << myDynQueue->Top() << endl;
    cout << "Dynamic queue cleared = " << myDynQueue->Clear() << endl;

    cout << "Queue size: " << myQueue.Size() << endl;
    cout << "Queue front: " << myQueue.Top() << endl;
    cout << "Queue cleared = " << myQueue.Clear() << endl;
    
    }
    catch (Exceptions341 &E){
        cout << "Exception: " << E.GetMessage() << endl;
    }
    
    // delete myStack;
    delete myDynQueue;
}