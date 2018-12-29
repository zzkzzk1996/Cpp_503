//
// Created by Zekun Zhang on 10/20/18.
//
#include <iostream>
#include "Polynomial_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

//constructor
Polynomial::Polynomial() {

    for ( int i = 0; i < 13; i++ )
    {
        coef[ i ] = 0;
    }


}// end IntegerSet constructor

// set 3 global objects to do the return work. because there will be a memory release problem if we return a new created object
Polynomial polyx;
Polynomial polyy;
Polynomial polyz;

//input a polynomial
void Polynomial::Input(){

    int terms, coefficient,exponent;
    cout<<"\nEnter the number of polynomial terms:";
    cin>>terms;

    for(int i = 0; i < terms; i++)
    {
        cout << "Enter coefficient and exponent :";
        cin >> coefficient;
        cin >> exponent;

        //if input is not valid, loop again until a valid input
        if(validDegree(exponent))
        {
            this->coef[exponent] += coefficient;
        }
        else
        {
            i--;
            cout<<"Invalid degree input. The greatest degree is 6.\n";
        }
    }

}

//set function
void Polynomial::setCoef(const double poly[]) {

    for(int i = 0; i < 13; i++)
    {
        coef[i] = poly[i];
    }

}

//operator <<
ostream &operator<<( ostream &PrintPoly, const Polynomial &poly)
{

    for (int i = 0, j = 0; i < 13; i++)
    {
        if(poly.coef[i] != 0)
        {
            //use variable j to print '+'
            if (j != 0)
            {
                PrintPoly << " + ";
            }

            PrintPoly << poly.coef[i] << "x^" << i;
            j++;
        }

    }

    return PrintPoly;
}

//operator + using friend function
Polynomial &operator+(const Polynomial &poly1, const Polynomial &poly2)
{
    for(int i = 0; i < 13; i++)
    {
        polyx.coef[i] = poly1.coef[i] + poly2.coef[i];
    }

    return polyx;
}

//operator - using friend function
Polynomial &operator-(const Polynomial &poly1, const Polynomial &poly2)
{
    for(int i = 0; i < 13; i++)
    {
        polyy.coef[i] = poly1.coef[i] - poly2.coef[i];
    }

    return polyy;
}

//operator * using friend function
Polynomial &operator*(const Polynomial &poly1, const Polynomial &poly2)
{
    for(int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            polyz.coef[i + j] += poly1.coef[i] * poly2.coef[j];
        }
    }

    return polyz;
}

//operator =
Polynomial &Polynomial::operator=(const Polynomial &poly) {
     for(int i = 0; i < 13; i++)
     {
         coef[i] = poly.coef[i];
     }
     return *this;
}

//operator += using member function
Polynomial &Polynomial::operator+=(const Polynomial &poly1)
{
    for(int i = 0; i < 13; i++)
    {
        coef[i] = coef[i] + poly1.coef[i];
    }
    return *this;
}

//operator -= using member function
Polynomial &Polynomial::operator-=(const Polynomial &poly1)
{
    for(int i = 0; i < 13; i++)
    {
        coef[i] = coef[i] - poly1.coef[i];
    }
    return *this;
}

//operator *= using member function
Polynomial &Polynomial::operator*=(const Polynomial &poly1)
{
    Polynomial poly;
    for(int i = 0; i < 13; i++)
    {
        for (int j = 0; j < 13; j++)
        {
            poly.coef[i + j] += coef[i] * poly1.coef[j];
        }
    }
    *this = poly;

    return *this;
}

//get function
const double *Polynomial::getCoef() const
{
    return coef;
}

//destructor
Polynomial::~Polynomial() {

}


