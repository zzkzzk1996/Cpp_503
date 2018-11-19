//
// Created by Zekun Zhang on 11/15/18.
//

#include "Node_Zekun.h"


void Node::setItemName(const string &itemName) {
    Node::itemName = itemName;
}

void Node::setItemNo(int itemNo) {
    Node::itemNo = itemNo;
}

const string &Node::getItemName() const {
    return itemName;
}

int Node::getItemNo() const {
    return itemNo;
}

Node::~Node() {

}