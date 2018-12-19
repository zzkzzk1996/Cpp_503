//
// Created by Zekun Zhang on 11/28/18.
//

#ifndef FINAL_PROJECT_TIMER_ZEKUN_H
#define FINAL_PROJECT_TIMER_ZEKUN_H

#include "Filer_Zekun.h"
#include <ctime>
#include <iostream>

using namespace std;

class Timer {
public:
    //constructor & destructor
    Timer();
    virtual ~Timer();
    //get local date & time for transaction part
    string Getdate() const;
    string Gettime() const;

private:
    //convert int to string
    string Convertor(int) const;
};


#endif //FINAL_PROJECT_TIMER_ZEKUN_H
