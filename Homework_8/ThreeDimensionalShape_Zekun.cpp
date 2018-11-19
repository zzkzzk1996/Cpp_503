//
// Created by Zekun Zhang on 10/30/18.
//
#include <iostream>
#include "ThreeDimensionalShape_Zekun.h"
using std::cout;
using std::endl;

ThreeDimensionalShape::ThreeDimensionalShape() {}

ThreeDimensionalShape::~ThreeDimensionalShape() {

}

void ThreeDimensionalShape::print_3D() const {
    cout << "(" << Shape::getX() << "," << Shape::getY() << "," << Shape::getZ() <<")";
}
