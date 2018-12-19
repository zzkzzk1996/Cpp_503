//
// Created by Zekun Zhang on 11/28/18.
//

#include "Timer_Zekun.h"

Timer::Timer() {

}

Timer::~Timer() {

}

//get the local date for bank transaction time tag
string Timer::Getdate() const {
    string date;
    const time_t t =time(NULL);
    tm* now = localtime(&t);
    string year = Convertor(now->tm_year + 1900), mon = Convertor(now->tm_mon + 1), day = Convertor(now->tm_mday);
    date = year + "/" + mon + "/" + day;
    return date;
}

//get the local time for stock transaction time tag
string Timer::Gettime() const {
    string timer;
    const time_t t =time(NULL);
    tm* now = localtime(&t);
    string hour = Convertor(now->tm_hour), min = Convertor(now->tm_min), sec = Convertor(now->tm_sec);
    timer = hour + ":" + min + ":" + sec;
    return timer;
}

//convert time in int to string
string Timer::Convertor(int val) const {
    string res;
    //keep the time format
    if (val < 10 && val >= 0) {
        res = "0" + to_string(val);
    } else {
        res = to_string(val);
    }
    return res;
}