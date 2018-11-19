//
// Created by Zekun Zhang on 11/5/18.
//
#include <iostream>
#include "TwoDayPackage_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

//constructor
TwoDayPackage::TwoDayPackage(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost, double f)
: package(n1, a1, c1, z1, n2, a2, c2, z2, w, cost)
{
    setFlatpo1(f);
}

//destructor
TwoDayPackage::~TwoDayPackage() {

}

double TwoDayPackage::getFlatpo1() const {
    return flatpo1;
}

void TwoDayPackage::setFlatpo1(double flatpo1) {
    TwoDayPackage::flatpo1 = flatpo1 >= 0.0 ? flatpo1 : 0.0;
}

// calculate the two day deliver cost of the package
double TwoDayPackage::calculateCost() const {
    return package::calculateCost() + getWeight() * getFlatpo1();
}

//print cost info for package
void TwoDayPackage::print_cost() const {
    cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
    cout << "Type of delivery : Two Day Delivery" << endl;
    cout << "Cost of Package : $" << calculateCost() << endl;
}