//
// Created by Zekun Zhang on 11/21/18.
//

#ifndef FINAL_PROJECT_BANKACCOUNT_ZEKUN_H
#define FINAL_PROJECT_BANKACCOUNT_ZEKUN_H

#include "Account_Zekun.h"

#include <iostream>

class BankAccount : public Account {
public:
    //constructor & dectructor
    BankAccount();
    virtual ~BankAccount();
    //Convert double to string and set precision
    string converter(double) const;
    //display account balance
    void display_balance() const;
    //operation for adding balance
    void deposit(double money);
    //operation for withdraw
    void withdraw(double money);
    //add deposit or withdraw history to the file
    void addhistory(double money, string type);
    //print bank transaction history
    /* virtual */void printhistory() const;


};


#endif //FINAL_PROJECT_BANKACCOUNT_ZEKUN_H
