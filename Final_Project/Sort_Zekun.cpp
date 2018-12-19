//
// Created by Zekun Zhang on 11/25/18.
//


#include "Sort_Zekun.h"

Sort::Sort() {}

Sort::~Sort() {

}

void Sort::Format(Linkedlist &list) {
    sort(list);
}

void Sortbubble::sort(Linkedlist &list) {
    cout << " Bubble Sort " << endl;
    //Linkedlist list = stocklist.list;
    for(int i = 1; i < list.getLength(); i++)
    {
        list.iteratorwithcompare(1);
    }
}

void Sortselection::sort(Linkedlist &list) {
    cout << " Selection Sort " << endl;
    //Linkedlist list = stocklist.list;
    for(int i = 1; i < list.getLength(); i++)
    {
        int maxptr = 0;
        maxptr = list.iteratorForMaxValue(i);
        //value of maxptr is equal to the input position means that there no smaller value than the first one
        if (maxptr > i) {
            list.Swap(i, maxptr);
        }
    }

}

void Strategy_Setup::setSort(int type) {
    delete Strategy_sort;
    if(type == Bubble)
    {
        Strategy_sort = new Sortbubble();
    }
    else if(type == Selection)
    {
        Strategy_sort = new Sortselection();
    }
    else
    {
        //set bubble strategy as a default sorting method
        Strategy_sort = new Sortbubble();
    }
}

void Strategy_Setup::Do_sort(Linkedlist &list) {
    Strategy_sort->Format(list);
}