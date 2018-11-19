//
// Created by Zekun Zhang on 11/5/18.
//

#ifndef HOMEWORK_9_TWODAYPACKAGE_ZEKUN_H
#define HOMEWORK_9_TWODAYPACKAGE_ZEKUN_H


#include "package_Zekun.h"

class TwoDayPackage : public package {
public:
    TwoDayPackage(char*, char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0, double = 0.0);
    virtual ~TwoDayPackage();

    double getFlatpo1() const;
    void setFlatpo1(double flatpo1);

    virtual double calculateCost() const;
    virtual void print_cost() const;

private:
    double flatpo1;
};


#endif //HOMEWORK_9_TWODAYPACKAGE_ZEKUN_H
