//
// Created by Zekun Zhang on 10/30/18.
//

#include <iostream>
#include "Sphere_Zekun.h"
using std::cout;
using std::endl;

Sphere::Sphere() {
    radius = 0.0;
}

Sphere::~Sphere() {

}

double Sphere::getRadius() const {
    return radius;
}

void Sphere::setRadius(double radius) {
    Sphere::radius = (radius < 0.0 ? 0.0 : radius);
}

double Sphere::getArea() const {
    return 4.0 * 3.14159 * getRadius() * getRadius();
}

double Sphere::getVolume() const {
    return 4.0 / 3.0 * 3.14159 * getRadius() * getRadius() * getRadius();
}

void Sphere::print() const {
    cout << "\nThe sphere with radius " << getRadius() << " that is located at ";
    ThreeDimensionalShape::print_3D();
    cout << " has:" << endl;
    cout << "Surface area of " << getArea() << endl;
    cout << "Volume of " << getVolume() << endl;
}