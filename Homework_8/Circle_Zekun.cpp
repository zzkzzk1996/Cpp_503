//
// Created by Zekun Zhang on 10/30/18.
//

#include <iostream>
#include "Circle_Zekun.h"
using std::cout;
using std::endl;

Circle::Circle() {
    radius = 0.0;
}

Circle::~Circle() {

}

double Circle::getRadius() const {
    return radius;
}

void Circle::setRadius(double radius) {
    Circle::radius = (radius < 0.0 ? 0.0 : radius);
}

double Circle::getArea() const {
    return 3.14159 * getRadius() * getRadius();
}

void Circle::print() const {
    cout << "\nThe circle with radius " << getRadius() << " that is located at ";
    TwoDimensionalShape::print_2D();
    cout << " has:" << endl;
    cout << "An area of " << getArea() << endl;
}
