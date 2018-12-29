//Zekun Zhang           Oct.20.2018
//

#include <iostream>

//Polynomial class definition
#include "Polynomial_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

int main() {

    Polynomial poly1;
    Polynomial poly2;
    Polynomial poly3;
    Polynomial poly4;
    Polynomial poly5;
    Polynomial poly6;
    Polynomial poly7;
    Polynomial poly8;

//input polynomials
    poly1.Input();
    poly2.Input();

    cout << "\nFirst Polynomial is  : ";
    cout << poly1 << endl;

    cout << "Second Polynomial is : ";
    cout << poly2 << endl;

    //use set and get to do the copy works
    poly6.setCoef(poly1.getCoef());
    poly7.setCoef(poly1.getCoef());
    poly8.setCoef(poly1.getCoef());

    poly3 = poly1 + poly2;
    cout << "\nAdding polynomial yields : ";
    cout << poly3 << endl;

    poly6 += poly2;
    cout << "+= the polynomial yields : ";
    cout << poly6 << endl;

    poly4 = poly1 - poly2;
    cout << "\nSubtracting the polynomial yield : ";
    cout << poly4 << endl;

    poly7 -= poly2;
    cout << "-= the polynomial yields : ";
    cout << poly7 << endl;

    poly5 = poly1 * poly2;
    cout << "\nMultiplying the polynomials yields : ";
    cout << poly5 << endl;

    poly8 *= poly2;
    cout << "*= the polynomial yields : ";
    cout << poly8 << endl;

    return 0;
}