#include "Stack341.cpp"
#include <string>

int main() {

    int choice;
    string element;
    Stack341<string>* testList = new Stack341<string>;

    while (1) {
        cout<< endl << "----------------------------" << endl;
        cout<<"1. Push" << endl;
        cout<<"2. Pop" << endl;
        cout<<"3. Empty" << endl;
        cout<<"4. Clear" <<endl;
        cout<<"5. Size"<<endl;
        cout<<"6. Print list" <<endl;
        cout<<"7. Back" <<endl;
        cout<<"8. Quit" <<endl;
        cout<<"Enter your choice : ";
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

            cout<<endl;
            break;

        case 4:

            if (testList->Clear()){
                cout << "List cleared." << endl;
            }

            else {
                cout << "List empty, nothing to clear." << endl;
            }

            cout<<endl;
            break;

        case 5:
            cout << testList->Size() << endl;
            break;    

        case 6:
            testList->Print();
            cout<<endl;
            break;

        case 7:
            cout << testList->Top() << endl;
            break;

        case 8:
            delete testList;
            exit(1);

        default:
            cout<<"Wrong choice"<<endl;

        }
    }

    return 0;

}