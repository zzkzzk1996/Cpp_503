//
// Created by Zekun Zhang on 11/5/18.
//
#include <iostream>
#include "package_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

//constructor
package::package(char* n1, char* a1, char* c1, char* z1, char* n2, char* a2, char* c2, char* z2, double w, double cost)
: name1(n1), address1(a1), city1(c1), zip1(z1), name2(n2), address2(a2), city2(c2), zip2(z2), weight(w), costpo(cost)
{

}

//destructor
package::~package() {

}

// calculate the standard cost of the package
double package::calculateCost() const
{
    return getWeight() * getCostpo();
}

//print address info for package
void package::print() const {
    cout << "\nSender : " << endl;
    cout << getName1() << endl;
    cout << getAddress1() << endl;
    cout << getCity1() << " , " << getZip1() << endl;

    cout << "\nRecipient : " << endl;
    cout << getName2() << endl;
    cout << getAddress2() << endl;
    cout << getCity2() << " , " << getZip2() << endl;
}

//print cost info for package
void package::print_cost() const {
    cout << "\nWeight of package : " << getWeight() << " ounces" << endl;
    cout << "Type of delivery : Regular Delivery" << endl;
    cout << "Cost of Package : $" << calculateCost() << endl;
}

double package::getWeight() const {
    return weight;
}

//make sure the weight is non-negative
void package::setWeight(double weight) {
    package::weight = weight >= 0.0 ? weight : 0.0;
}

double package::getCostpo() const {
    return costpo;
}

//make sure the cost per ounce is non-negative
void package::setCostpo(double costpo) {
    package::costpo = costpo >= 0.0 ? costpo : 0.0;
}

char *package::getName1() const {
    return name1;
}

void package::setName1(char *name1) {
    package::name1 = name1;
}

char *package::getAddress1() const {
    return address1;
}

void package::setAddress1(char *address1) {
    package::address1 = address1;
}

char *package::getCity1() const {
    return city1;
}

void package::setCity1(char *city1) {
    package::city1 = city1;
}

char *package::getZip1() const {
    return zip1;
}

void package::setZip1(char *zip1) {
    package::zip1 = zip1;
}

char *package::getName2() const {
    return name2;
}

void package::setName2(char *name2) {
    package::name2 = name2;
}

char *package::getAddress2() const {
    return address2;
}

void package::setAddress2(char *address2) {
    package::address2 = address2;
}

char *package::getCity2() const {
    return city2;
}

void package::setCity2(char *city2) {
    package::city2 = city2;
}

char *package::getZip2() const {
    return zip2;
}

void package::setZip2(char *zip2) {
    package::zip2 = zip2;
}




