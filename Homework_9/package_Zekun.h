//
// Created by Zekun Zhang on 11/5/18.
//

#ifndef HOMEWORK_9_PACKAGE_ZEKUN_H
#define HOMEWORK_9_PACKAGE_ZEKUN_H

#include <string>

class package {
public:
    package( char*, char*, char*, char*, char*, char*, char*, char*, double = 0.0, double = 0.0);
    virtual ~package();
    virtual double calculateCost() const;
    void print() const;
    virtual void print_cost() const;

    double getWeight() const;
    void setWeight(double weight);

    double getCostpo() const;
    void setCostpo(double costpo);

    char *getName1() const;
    void setName1(char *name1);

    char *getAddress1() const;
    void setAddress1(char *address1);

    char *getCity1() const;
    void setCity1(char *city1);

    char *getZip1() const;
    void setZip1(char *zip1);

    char *getName2() const;
    void setName2(char *name2);

    char *getAddress2() const;
    void setAddress2(char *address2);

    char *getCity2() const;
    void setCity2(char *city2);

    char *getZip2() const;
    void setZip2(char *zip2);

private:
    char *name1;
    char *address1;
    char *city1;
    char *zip1;
    char *name2;
    char *address2;
    char *city2;
    char *zip2;
    double weight;
    double costpo;

};


#endif //HOMEWORK_9_PACKAGE_ZEKUN_H
