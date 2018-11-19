//
// Created by Zekun Zhang on 10/30/18.
//
#include <iostream>
#include <cmath>
#include "Triangle_Zekun.h"
using std::cout;
using std::endl;

Triangle::Triangle() {
    edge = 0.0;
}

Triangle::~Triangle() {

}

double Triangle::getEdge() const {
    return edge;
}

void Triangle::setEdge(double edge) {
    Triangle::edge = (edge < 0.0 ? 0.0 : edge);
}

double Triangle::getArea() const {
    return sqrt(3.0) / 4.0 * getEdge() * getEdge();
}

void Triangle::print() const {
    cout << "\nThe triangle with edge length " << getEdge() << " that is located at ";
    TwoDimensionalShape::print_2D();
    cout << " has:" << endl;
    cout << "An area of " << getArea() << endl;
}