//
// Created by Zekun Zhang on 10/20/18.
//

#ifndef POLYNOMIAL_ZEKUN_H
#define POLYNOMIAL_ZEKUN_H

#include <iostream>

using std::ostream;
class Polynomial {

    //define friend functions to finish the following operations
    friend ostream &operator<<( ostream &, const Polynomial &);
    friend Polynomial &operator+(const Polynomial &, const Polynomial &);
    friend Polynomial &operator-(const Polynomial &, const Polynomial &);
    friend Polynomial &operator*(const Polynomial &, const Polynomial &);

public:
    Polynomial();//constructor

    ~Polynomial();//destructor

    void Input();//input the polynomial

    //define member functions to finish the following operations
    Polynomial& operator=(const Polynomial &);
    Polynomial &operator+=(const Polynomial &);
    Polynomial &operator-=(const Polynomial &);
    Polynomial &operator*=(const Polynomial &);

    //get function
    const double *getCoef() const;

    //set function
    void setCoef(const double[]);

private:
    //when doing the multiplication, two 6 degree polynomials would give a 12 degree polynomial out
    double coef[13];

    // determines a valid number of terms to the polynomial (greatest degree will be 6)
    int validDegree( int x) const
    {
        return ( x >= 0 && x <= 6 );
    } // end function validDegree

};


#endif //POLYNOMIAL_ZEKUN_H
