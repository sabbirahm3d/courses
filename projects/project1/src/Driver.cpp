#include "List341.cpp"


/*
 * Main: Conatins Menu
 */
int main()
{
    int choice, element, position;
    List341 dl;
    while (1)
    {
        cout<<endl<<"----------------------------"<<endl;
        cout<<endl<<"Operations on Doubly linked list"<<endl;
        cout<<endl<<"----------------------------"<<endl;         
        cout<<"1.Create Node"<<endl;
        cout<<"2.Add at begining"<<endl;
        cout<<"3.Add after position"<<endl;
        cout<<"4.Delete"<<endl;
        cout<<"5.Display"<<endl;
        cout<<"6.Size"<<endl;
        cout<<"7.Reverse"<<endl;
        cout<<"8.Quit"<<endl;
        cout<<"Enter your choice : ";
        cin>>choice;
        switch ( choice )
        {
        case 1:
            cout<<"Enter the element: ";
            cin>>element;
            dl.create_list(element);
            cout<<endl;
            break;
        case 2:
            cout<<"Enter the element: ";
            cin>>element;
            dl.add_begin(element);
            cout<<endl;
            break;
        case 3:
            cout<<"Enter the element: ";
            cin>>element;
            cout<<"Insert Element after postion: ";
            cin>>position;
            dl.add_after(element, position);
            cout<<endl;
            break;
        case 4:
            if (start == NULL)
            {                      
                cout<<"List empty,nothing to delete"<<endl;   
                break;
            }
            cout<<"Enter the element for deletion: ";
            cin>>element;
            dl.delete_element(element);
            cout<<endl;
            break;
        case 5:
            dl.display_dlist();
            cout<<endl;
            break;
        case 6:
            cout << dl.Size() << endl;
            break;    
        case 7:
            if (start == NULL)
            {
                cout<<"List empty,nothing to reverse"<<endl;
                break;
            }
            dl.reverse();
            cout<<endl;
            break;
        case 8:
            exit(1);
        default:
            cout<<"Wrong choice"<<endl;
        }
    }
    return 0;
}