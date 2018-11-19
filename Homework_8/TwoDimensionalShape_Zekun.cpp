//
// Created by Zekun Zhang on 10/30/18.
//
#include <iostream>
#include "TwoDimensionalShape_Zekun.h"
using std::cout;
using std::endl;

TwoDimensionalShape::TwoDimensionalShape() {}

TwoDimensionalShape::~TwoDimensionalShape() {

}

void TwoDimensionalShape::print_2D() const {
    cout << "(" << Shape::getX() << "," << Shape::getY() <<")";
}
