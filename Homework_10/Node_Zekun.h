//
// Created by Zekun Zhang on 11/15/18.
//

#ifndef HOMEWORK_10_NODE_ZEKUN_H
#define HOMEWORK_10_NODE_ZEKUN_H

#include <string>
using std::string;

class Node {
    friend class Linkedlist;
public:
    Node(string& name, int no)
            :itemName(name), itemNo(no)
    {
        this->next= NULL;
    }

    const string &getItemName() const;

    int getItemNo() const;

    void setItemName(const string &itemName);

    void setItemNo(int itemNo);

    virtual ~Node();

private:

    string itemName;
    int itemNo;
    Node *next;
};


#endif //HOMEWORK_10_NODE_ZEKUN_H
