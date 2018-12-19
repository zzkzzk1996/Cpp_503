//
// Created by Zekun Zhang on 11/24/18.
//

#ifndef FINAL_PROJECT_LINKEDLIST_ZEKUN_H
#define FINAL_PROJECT_LINKEDLIST_ZEKUN_H

#include "Node_Zekun.h"
#include <iostream>
#include <iomanip>
#include <cfloat>
using namespace std;
class Linkedlist {

public:

    //constructor and destructor
    Linkedlist();
    virtual ~Linkedlist();
    int getLength() const;
    void Add(Node *);
    Node* Find(string) const;
    void Remove(string);
    Node* Findposition(int) const;
    void Swap(int, int) const;
    double printList() const;
    //figure out the total value for each stock
    double getValue(Node *) const;
    //for Selection sort : iterate the list
    int iteratorForMaxValue(int position);
    //for Bubble sort : compare and iterate the list
    void iteratorwithcompare(int position);

    Node *getFirst() const;

    Node *getLast() const;

private:

    Node *first;
    Node *last;
    int length;

};


#endif //FINAL_PROJECT_LINKEDLIST_ZEKUN_H
