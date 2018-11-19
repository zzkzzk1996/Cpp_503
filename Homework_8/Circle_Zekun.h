//
// Created by Zekun Zhang on 10/30/18.
//

#ifndef HOMEWORK_8_CIRCLE_ZEKUN_H
#define HOMEWORK_8_CIRCLE_ZEKUN_H

#include "TwoDimensionalShape_Zekun.h"

class Circle : public TwoDimensionalShape{
public:
    Circle();
    ~Circle();

    double getRadius() const;
    void setRadius(double radius);

    double getArea() const;
    void print() const;

private:
    double radius;
};


#endif //HOMEWORK_8_CIRCLE_ZEKUN_H
