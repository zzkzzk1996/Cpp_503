//
// Created by Zekun Zhang on 11/21/18.
//

#ifndef FINAL_PROJECT_ACCOUNT_ZEKUN_H
#define FINAL_PROJECT_ACCOUNT_ZEKUN_H

#include "Filer_Zekun.h"
#include "Timer_Zekun.h"

class Account {

public:
    //constructor and destructor
    Account();
    virtual ~Account();

    // Using Template for print transaction history
    void History() const;

    //check if the balance is initialized every time the program starts
    void Initial();
    ////upload

protected:
    void setBalance(double balance);
    double getBalance() const;

private:
    virtual void printhistory() const = 0;

};


#endif //FINAL_PROJECT_ACCOUNT_ZEKUN_H
