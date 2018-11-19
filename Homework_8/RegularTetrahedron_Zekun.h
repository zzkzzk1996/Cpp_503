//
// Created by Zekun Zhang on 10/30/18.
//

#ifndef HOMEWORK_8_REGULARTETRAHEDRON_ZEKUN_H
#define HOMEWORK_8_REGULARTETRAHEDRON_ZEKUN_H

#include "ThreeDimensionalShape_Zekun.h"

class RegularTetrahedron : public ThreeDimensionalShape {
public:
    RegularTetrahedron();
    ~RegularTetrahedron();

    double getEdge() const;
    void setEdge(double edge);

    double getArea() const;
    double getVolume() const;
    void print() const;

private:
    double edge;
};


#endif //HOMEWORK_8_REGULARTETRAHEDRON_ZEKUN_H
