
// Created by Zekun Zhang on 10/20/18.
//
// IntegerSet.h
// Header file for class IntegerSet

#ifndef INTEGERSET_H
#define INTEGERSET_H

class IntegerSet
{
public:
    IntegerSet( ); // constructor

    IntegerSet UnionOfSets(IntegerSet);

    IntegerSet IntersectionOfSets(IntegerSet);

    void inputSet(); // read values from user

    void printSet() const;

private:
    int set[ 101 ]; // range of 0 - 100

// determines a valid entry to the set

    int validEntry( int x) const
    {
        return ( x >= 0 && x <= 100 );
    } // end function validEntry
};



#endif //INTEGERSET_H
