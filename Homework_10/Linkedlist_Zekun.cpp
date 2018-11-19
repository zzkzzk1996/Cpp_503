//
// Created by Zekun Zhang on 11/15/18.
//

#include "Linkedlist_Zekun.h"
#include <iostream>
#include <iomanip>
using std::cout;
using std::setw;
using std::left;
using std::endl;

Linkedlist::Linkedlist() : first(0), last(0), mySize(0)
{

}

Linkedlist::~Linkedlist()
{
    mySize = size();
    if( mySize != 0 )
    {
        Node *current = first;
        Node *temp;

        while( current != 0 )
        {
            temp = current;
            current = current->next;
            delete temp;
        }
    }
}

void Linkedlist::addToStart(Node *newp)
{
    mySize = size();
    if(mySize == 0)
    {
        first = last = newp;
    }
    else
    {
        newp->next = first;
        first = newp;
    }
}

void Linkedlist::addToEnd(Node *newp)
{

    mySize = size();
    if(mySize == 0)
    {
        first = last = newp;
    }
    else
    {
        last->next = newp;
        last = newp;
    }
}

bool Linkedlist::removeFromStart()
{
    mySize = size();
    if(mySize == 0)
    {
        return false;
    }
    else
    {
        Node *temp = first;
        if(first == last)
        {
            first = last = 0;
        }
        else
        {
            first = first->next;
            delete temp;
        }
        return true;
    }
}

bool Linkedlist::removeFromEnd()
{
    mySize = size();
    if(mySize == 0)
    {
        return false;
    }
    else
    {
        Node *temp = last;
        if(first == last)
        {
            first = last = 0;
        }
        else
        {
            Node *current = first;
            while ( current->next != last )
            {
                current = current->next;
            }
            last = current;
            current->next = 0;
        }
        delete temp;
        return true;
    }
}

void Linkedlist::removeNodeFromListnumber(int num)
{
    mySize = size();
    if( mySize == 0)
    {
        cout << "Item Not Found\n";
        return;
    }

    Node *current = first;
    if(last == first)
    {
        if(current->getItemNo() == num)
        {
            Node *temp = first;
            first = last = 0;
            cout << "Remove Successfully\n";
            delete temp;
            return;
        }
        else
        {
            cout << "Item Not Found\n";
            return;
        }
    }

    while ( current != 0 )
    {

        if( current->next != 0 && current->next->getItemNo() == num)
        {
            Node *temp = current->next;
            current = current->next->next;
            cout << "Remove Successfully\n";
            delete temp;
            return;
        }
        else if( current->next == 0 && current->next->getItemNo() == num)
        {
            Node *temp = last;
            last = current;
            current->next = 0;
            delete temp;
            cout << "Remove Successfully\n";
            return;
        }
        current = current->next;
    }
    cout << "Item Not Found\n";
}

void Linkedlist::removeNodeFromListname(string name)
{
    mySize = size();
    if( mySize == 0)
    {
        cout << "Item Not Found\n";
        return;
    }

    Node *current = first;
    if(last == first)
    {
        if(current->getItemName() == name)
        {
            Node *temp = first;
            first = last = 0;
            cout << "Remove Successfully\n";
            delete temp;
            return;
        }
        else
        {
            cout << "Item Not Found\n";
            return;
        }
    }

    while ( current != 0 )
    {

        if( current->next != 0 && current->next->getItemName() == name)
        {
            Node *temp = current->next;
            current = current->next->next;
            cout << "Remove Successfully\n";
            delete temp;
            return;
        }
        else if( current->next == 0 && current->next->getItemName() == name)
        {
            Node *temp = last;
            last = current;
            current->next = 0;
            delete temp;
            cout << "Remove Successfully\n";
            return;
        }
        current = current->next;
    }
    cout << "Item Not Found\n";
}

void Linkedlist::printList() const
{
    cout << "\nList\n";
    cout << left << setw( 20 ) << "Item No" << "Item Name\n";
    Node *current = first;
    while ( current != 0 )
    {
        cout << left << setw( 20 ) << current->getItemNo() << current->getItemName() << endl;
        current = current->next;
    }
}

int Linkedlist::size() const
{
    int index = 0;
    Node *current = first;
    while (current != 0)
    {
        index++;
        current = current->next;
    }
    return index;

}