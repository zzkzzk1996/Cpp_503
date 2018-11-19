//
// Created by Zekun Zhang on 11/5/18.
//

#ifndef HOMEWORK_9_OVERNIGHTPACKAGE_ZEKUN_H
#define HOMEWORK_9_OVERNIGHTPACKAGE_ZEKUN_H


#include "package_Zekun.h"

class OvernightPackage : public package {
public:
    OvernightPackage(char*, char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0, double = 0.0);
    virtual ~OvernightPackage();

    double getFlatpo2() const;
    void setFlatpo2(double flatpo2);

    virtual double calculateCost() const;
    virtual void print_cost() const;

private:
    double flatpo2;

};


#endif //HOMEWORK_9_OVERNIGHTPACKAGE_ZEKUN_H
