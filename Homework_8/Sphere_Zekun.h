//
// Created by Zekun Zhang on 10/30/18.
//

#ifndef HOMEWORK_8_SPHERE_ZEKUN_H
#define HOMEWORK_8_SPHERE_ZEKUN_H

#include "ThreeDimensionalShape_Zekun.h"

class Sphere : public ThreeDimensionalShape{
public:
    Sphere();
    ~Sphere();

    double getRadius() const;
    void setRadius(double radius);

    double getArea() const;
    double getVolume() const;
    void print() const;

private:
    double radius;
};


#endif //HOMEWORK_8_SPHERE_ZEKUN_H
