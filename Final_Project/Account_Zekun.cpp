//
// Created by Zekun Zhang on 11/21/18.
//

#include "Account_Zekun.h"

Account::Account() {
}

Account::~Account() {
}

//get previous balance from the balance file
double Account::getBalance() const {
    Filer filer;
    double balance;
    balance = stod(filer.Getlast(BALANCE));
    return balance;
}

//set new balance to the balance file
void Account::setBalance(double balance) {
     Filer filer;
     filer.Initial(BALANCE);
     filer.Add(BALANCE, to_string(balance));
}

void Account::History() const {
    printhistory();
}

void Account::Initial() {
    Filer filer;
    //debug
    //filer.Initial_balance();
    if (filer.Check(BALANCE))
    {
        filer.Initial_balance();
    }
}