//
// Created by Zekun Zhang on 11/24/18.
//

#include "Linkedlist_Zekun.h"
#include <iostream>
#include <iomanip>
using namespace std;
//constructor
Linkedlist::Linkedlist()
{
    length = 0;
    //create new empty 'first' and 'last'
    first = new Node( "", 0 );
    last = new Node( "", 0 );
    first->pre = NULL;
    first->next = last;
    last->pre = first;
    last->next = NULL;
}

//destructor
Linkedlist::~Linkedlist()
{
    if( length != 0 )
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

//get length
int Linkedlist::getLength() const {
    return length;
}

//add a new node before the last node
void Linkedlist::Add(Node *node){

    node->next = last;
    last->pre->next = node;
    node->pre = last->pre;
    last->pre = node;

    length++;
}

//find a node by the stock symbol
Node * Linkedlist::Find(string stocksymbol) const {

    Node *current = first->next;

    while ( current != last )
    {
        if( current->getStocksymbol() == stocksymbol)
        {
            return current;
        }
        current = current->next;
    }
    //if there's no aim pointer return nullptr;
    return nullptr;
}

//remove the pointer by the stock symbol
void Linkedlist::Remove(string stocksymbol) {

    //find aim pointer first
    Node *node = Find(stocksymbol);

    if( node != nullptr )
    {
        node->next->pre = node->pre;
        node->pre->next = node->next;
        delete(node);
        length--;
    }
    else
    {
        cout << " Error : Stock Not Found " << endl;
    }

}

//find position for the swap operation
Node * Linkedlist::Findposition(int position) const {
    if( getLength() >= position )
    {
        Node *temp = first->next;
        int count = 1;
        while ( count != position)
        {
            temp = temp->next;
            count++;
        }
        return temp;
    }
    else
    {
        //cout << " Error : Invalid Position " << endl;
        return nullptr;
    }
}

//do swap operation for sorting
void Linkedlist::Swap(int position1, int position2) const {
    //first find two position
    Node * node1 = Findposition(position1);
    Node * node2 = Findposition(position2);
    if( node1 == nullptr || node2 == nullptr)
    {
        cout << " Error : Invalid Swap " << endl;
        return;
    }
    else
    {
        //check if two nodes are neighbors
        if(node1->next == node2)
        {
            node1->pre->next = node2;
            node2->pre = node1->pre;
            node2->next->pre = node1;
            node1->next = node2->next;
            node2->next = node1;
            node1->pre = node2;
        }
        else if(node1->pre == node2)
        {
            node2->pre->next = node1;
            node1->pre = node2->pre;
            node1->next->pre = node2;
            node2->next = node1->next;
            node1->next = node2;
            node2->pre = node1;
        }
        else
        {
            //not neighbors swap them using a temporary ptr
            Node * temp = new Node ( "", 0 );
            temp->pre = node1->pre;
            temp->next = node1->next;
            node1->pre->next = node2;
            node1->next->pre = node2;
            node1->pre = node2->pre;
            node1->next = node2->next;
            node2->pre->next = node1;
            node2->next->pre = node1;
            node2->pre = temp->pre;
            node2->next = temp->next;
            delete(temp);
        }
    }

}

//for Selection sort : from certain postion iteration the list and find the smallest to return its position
int Linkedlist::iteratorForMaxValue(int position){
    int res = 0;
    double Max = DBL_MIN;
    int pos = 1;
    Node *current = first->next;

    //move the node to the input position
    while (pos < position)
    {
        current = current->next;
        pos++;
    }
    //iterate the going-on values
    double total;
    while (current != last)
    {
        current->searchprice();
        total = current->getSharenumber() * current->getPrice();
        if(Max < total)
        {
            Max = total;
            res = pos;
        }
        current = current->next;
        pos++;
    }
    return res;
}

//for Bubble sort : from certain position iteration the list and compare the nearest two nodes
void Linkedlist::iteratorwithcompare(int position) {

    int pos = 1;
    Node *current = first->next;
    //move the node to the input position
    while (pos < position)
    {
        current = current->next;
        pos++;
    }
    //iterate the going-on values
    double total1, total2;
    //search & setprice
    current->searchprice();
    while (current->next != last)
    {
        //search & setprice
        current->next->searchprice();
        total1 = current->getSharenumber() * current->getPrice();
        total2 = current->next->getSharenumber() * current->next->getPrice();
        //if the first total value is smaller than the second, swap
        if(total1 < total2)
        {
            Swap(pos, pos + 1);
        }
        pos++;
        current = Findposition(pos);
    }
}

//figure out the total value for each stock
double Linkedlist::getValue(Node *node) const {
    return node->getPrice() * node->getSharenumber();
}

//print list for portfolio and return the total value for all the stocks
double Linkedlist::printList() const {
    Node *current = first->next;
    double totalvalue = 0.0;
    while (current != last) {
        current->searchprice();
        cout << left << setw(15) << current->getStocksymbol()
             << left << setw(8) << current->getSharenumber()
             << left << setw(15) << fixed << setprecision(2) << current->getPrice()
             << fixed << setprecision(2) << getValue(current) << endl;
        totalvalue += getValue(current);
        current = current->next;
    }
    return totalvalue;
}

Node *Linkedlist::getFirst() const {
    return first;
}

Node *Linkedlist::getLast() const {
    return last;
}


