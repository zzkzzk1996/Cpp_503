//
// Created by Zekun Zhang on 11/3/18.
//

#ifndef IN_CLASS_6_THREEDIMENSIONALPOINT_H
#define IN_CLASS_6_THREEDIMENSIONALPOINT_H


#include "point.h"

class ThreeDimensionalPoint:public Point{
private:
    int z;
public:
    ThreeDimensionalPoint();
    ThreeDimensionalPoint(int, int, int);
    int getz();
    void setz(int);
    void addPoints(ThreeDimensionalPoint);
};


#endif //IN_CLASS_6_THREEDIMENSIONALPOINT_H
