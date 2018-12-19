//
// Created by Zekun Zhang on 11/25/18.
//

#ifndef FINAL_PROJECT_SORT_ZEKUN_H
#define FINAL_PROJECT_SORT_ZEKUN_H

#include "StockAccount_Zekun.h"
#include <iostream>
/*
    using two methods to implement sort class, which is called Strategy Pattern
 */

class Sort {

public:
    Sort();
    virtual ~Sort();
    void Format(Linkedlist &list);
private:
    virtual void sort(Linkedlist &list) = 0;
};

class Sortbubble : public Sort {
private:
    virtual void sort(Linkedlist &list);
};

class Sortselection : public Sort {
private:
    virtual void sort(Linkedlist &list);
};

//this class works for setup strategy for sorting
class Strategy_Setup {

public:
    //enum the strategy type for future using as int
    enum Strategy_Type
    {
        Dummy, Bubble, Selection
    };
    //Constructor & Destructor for pointer 'strategy_sort'
    Strategy_Setup(){
        Strategy_sort = NULL;
    };

    //set sort strategy
    void setSort(int type);
    //do sort using selected strategy
    void Do_sort(Linkedlist &list);

private:
    Sort *Strategy_sort;

};




#endif //FINAL_PROJECT_SORT_ZEKUN_H
