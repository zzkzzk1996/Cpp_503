//
// Created by Zekun Zhang on 10/30/18.
//

#ifndef HOMEWORK_8_TRIANGLE_ZEKUN_H
#define HOMEWORK_8_TRIANGLE_ZEKUN_H

#include "TwoDimensionalShape_Zekun.h"

class Triangle : public TwoDimensionalShape{
public:
    Triangle();
    ~Triangle();

    double getEdge() const;
    void setEdge(double edge);

    double getArea() const;
    void print() const;

private:
    double edge;
};


#endif //HOMEWORK_8_TRIANGLE_ZEKUN_H
