//
// Created by Zekun Zhang on 10/30/18.
//
#include <iostream>
#include <cmath>
#include "RegularTetrahedron_Zekun.h"
using std::cout;
using std::endl;

RegularTetrahedron::RegularTetrahedron() {
    edge = 0.0;
}

RegularTetrahedron::~RegularTetrahedron() {

}

double RegularTetrahedron::getEdge() const {
    return edge;
}

void RegularTetrahedron::setEdge(double edge) {
    RegularTetrahedron::edge = (edge < 0.0 ? 0.0 : edge);
}

double RegularTetrahedron::getArea() const {
    return sqrt(3.0) * getEdge() * getEdge();
}

double RegularTetrahedron::getVolume() const {
    return sqrt(2.0) / 12.0 * getEdge() * getEdge() * getEdge();
}

void RegularTetrahedron::print() const {
    cout << "\nThe regular tetrahedron with edge length " << getEdge() << " that is located at ";
    ThreeDimensionalShape::print_3D();
    cout << " has:" << endl;
    cout << "Surface area of " << getArea() << endl;
    cout << "Volume of " << getVolume() << endl;
}