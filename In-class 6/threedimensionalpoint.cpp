//
// Created by Zekun Zhang on 11/3/18.
//

#include "threedimensionalpoint.h"

ThreeDimensionalPoint::ThreeDimensionalPoint(){
    setx(0);
    sety(0);
    setz(0);
}

ThreeDimensionalPoint::ThreeDimensionalPoint(int xin, int yin, int zin){
    //please implement this constructor to set the x, y and z values to the input parameter values
    setx(xin);
    sety(yin);
    setz(zin);
}

int ThreeDimensionalPoint::getz(){
    //please implement this function to get the z value
    return z;
}

void ThreeDimensionalPoint::setz(int zin){
    //please implement this function to set z value
    z = zin;
}

void ThreeDimensionalPoint::addPoints(ThreeDimensionalPoint pointin){
    //please implement this function to add the x,y and z values of point1 to values of the calling instance of the object
    (*this).setx((this->getx()) + pointin.getx());
    (*this).sety((this->gety()) + pointin.gety());
    (*this).setz((this->getz()) + pointin.getz());

}