#include "List341.cpp"

int main() {

    int choice;
    double element;
    List341<double>* testList = new List341<double>;

    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;
        cout<<"1. Push"<<endl;
        cout<<"2. Empty"<<endl;
        // cout<<"3.Add after position"<<endl;
        cout<<"4. Clear"<<endl;
        cout<<"5. Display"<<endl;
        cout<<"6. Size"<<endl;
        // cout<<"7.Reverse"<<endl;
        cout<<"8. Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            testList->Push(element);
            cout<<endl;
            break;

        case 2:

            if (testList->Empty()) {
                cout << "List is empty." << endl;
            }

            else {
                cout << "List is not empty." << endl;
            }

            cout<<endl;
            break;
        // case 3:
        //     cout<<"Enter the element: ";
        //     cin>>element;
        //     cout<<"Insert Element after postion: ";
        //     cin>>position;
        //     testList.add_after(element, position);
        //     cout<<endl;
        //     break;
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
            testList->display_dlist();
            cout<<endl;
            break;

        case 6:
            cout << testList->Size() << endl;
            break;    
        // case 7:
        //     if (start == NULL)
        //     {
        //         cout<<"List empty,nothing to reverse"<<endl;
        //         break;
        //     }
        //     testList.reverse();
        //     cout<<endl;
        //     break;
        case 8:
            // delete testList;
            // testList = NULL;
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}