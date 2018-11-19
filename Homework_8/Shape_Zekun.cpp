//
// Created by Zekun Zhang on 10/30/18.
//
#include <iostream>
#include "Shape_Zekun.h"
using std::cout;
using std::endl;

Shape::Shape()
{
    x = y = z = 0;
}

Shape::~Shape()
{

}

int Shape::getX() const {
    return x;
}

void Shape::setX(int x) {
    Shape::x = x;
}

int Shape::getY() const {
    return y;
}

void Shape::setY(int y) {
    Shape::y = y;
}

int Shape::getZ() const {
    return z;
}

void Shape::setZ(int z) {
    Shape::z = z;
}
