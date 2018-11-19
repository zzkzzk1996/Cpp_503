
//Zekun Zhang           Nov.15.2018

#include <iostream>
#include <string>
#include "Linkedlist_Zekun.h"
using std::cout;
using std::cin;
using std::endl;
using std::string;

void instruction();
void input(string&, int&);

int main() {

    int choice;
    string name;
    int number;
    Linkedlist list;
    do{
        Node *a = new Node(name, number);
        instruction();
        cin >> choice;
        switch (choice)
        {
            case 1:
            {
                input(name, number);
                a->setItemName(name);
                a->setItemNo(number);
                list.addToStart(a);
                list.printList();
                break;
            }

            case 2:
            {
                input(name, number);
                a->setItemName(name);
                a->setItemNo(number);
                list.addToEnd(a);
                list.printList();
                break;
            }

            case 3:
            {
                if(list.removeFromStart())
                {
                    cout << "Remove Successfully\n";
                    list.printList();
                }
                else
                {
                    cout << "Empty\n";
                }
                break;
            }

            case 4:
            {
                if(list.removeFromEnd())
                {
                    cout << "Remove Successfully\n";
                    list.printList();
                }
                else
                {
                    cout << "Empty\n";
                }
                break;
            }

            case 5:
            {
                cout << "Please input the item number you want to remove" << endl;
                cin >> number;
                list.removeNodeFromListnumber(number);
                list.printList();
                break;
            }

            case 6:
            {
                cout << "Please input the item name you want to remove" << endl;
                cin >> name;
                list.removeNodeFromListname(name);
                list.printList();
                break;
            }

            case 7:
            {
                list.printList();
                break;
            }
            case 8:
            {
                break;
            }

            default:
                cout << "Wront Input\n";
        }
    }while (choice != 8);
    cout << "Program killed" << endl;
    return 0;
}

// display instructions to users
void instruction()
{
    cout << "\n\nWelcome to the shopping list program" << endl;
    cout << "Please choose an option : " << endl;
    cout << "1. Add a new node at the beginning" << endl;
    cout << "2. Add a new node at the end" << endl;
    cout << "3. Remove the beginning node" << endl;
    cout << "4. Remove the end node" << endl;
    cout << "5. Remove a node from the list by entering an item number" << endl;
    cout << "6. Remove a node from the list by entering an item name" << endl;
    cout << "7. Print out the list" << endl;
    cout << "8. Quit the program" << endl;
}

void input(string &name, int &number)
{
    cout << "Please enter product number to insert at beginning\n";
    cin >> number;
    cout << "Please enter the name for the product\n";
    cin >> name;
}