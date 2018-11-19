//
// Created by Zekun Zhang on 11/5/18.
//
#include <iostream>
#include "OvernightPackage_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

//constructor
OvernightPackage::OvernightPackage(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost, double f)
: package(n1, a1, c1, z1, n2, a2, c2, z2, w, cost)
{
    setFlatpo2(f);
}

//destructor
OvernightPackage::~OvernightPackage() {

}

double OvernightPackage::getFlatpo2() const {
    return flatpo2;
}

void OvernightPackage::setFlatpo2(double flatpo2) {
    OvernightPackage::flatpo2 = flatpo2 >= 0.0 ? flatpo2 : 0.0;
}

// calculate the overnight deliver cost of the package
double OvernightPackage::calculateCost() const {
    return package::calculateCost() + getWeight() * getFlatpo2();
}

//print cost info for package
void OvernightPackage::print_cost() const {
    cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
    cout << "Type of delivery : Overnight Delivery" << endl;
    cout << "Cost of Package : $" << calculateCost() << endl;
}