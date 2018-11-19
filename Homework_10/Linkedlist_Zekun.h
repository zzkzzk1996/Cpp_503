//
// Created by Zekun Zhang on 11/15/18.
//

#ifndef HOMEWORK_10_LINKEDLIST_ZEKUN_H
#define HOMEWORK_10_LINKEDLIST_ZEKUN_H

#include <string>
#include "Node_Zekun.h"
using std::string;

class Linkedlist {

public:
    Linkedlist();
    virtual ~Linkedlist();

    int size() const;
    void addToStart(Node *);
    void addToEnd(Node *);
    void printList() const;
    bool removeFromStart();
    bool removeFromEnd();
    void removeNodeFromListnumber(int);
    void removeNodeFromListname(string);

private:
    Node *first;
    Node *last;
    int mySize;

};


#endif //HOMEWORK_10_LINKEDLIST_ZEKUN_H
