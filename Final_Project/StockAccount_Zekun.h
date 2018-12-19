//
// Created by Zekun Zhang on 11/21/18.
//

#ifndef FINAL_PROJECT_STOCKACCOUNT_ZEKUN_H
#define FINAL_PROJECT_STOCKACCOUNT_ZEKUN_H

#include "Account_Zekun.h"
#include "BankAccount_Zekun.h"
#include "Linkedlist_Zekun.h"
#include "Sort_Zekun.h"
#include <iostream>
#include <string>
#include <cstdlib>
#include <iomanip>
#include <sstream>

using namespace std;

class StockAccount : public Account{
    friend class Strategy_Setup;
    friend class Sortbubble;
    friend class Sortselection;
public:
    //constructor & destructor
    StockAccount();
    virtual ~StockAccount();

    //Convert double to string and set precision
    string converter(double) const;
    //Check share
    string check_price(string keyword) const;
    //Display the price of a stock
    void display_price(string keyword) const;
    //Display the current portfolio
    void display_portfolio();
    //Buy shares
    void buy_share(string name, int num, double pricewilling, BankAccount& bankaccount);
    //Sell shares
    void sell_share(string name, int numwilling, double pricewilling, BankAccount& bankaccount);
    //Add shares to the transaction
    void change_share(string name, int num, double price, string type);
    //add transaction history
    void add_history(string name, int num, double price, double value, string type);
    //download data from file to portfolio
    void download_portfolio();
    //update data from portfolio to file
    void update_portfolio();
    //print stock transaction history
    /* virtual */void printhistory() const;
    void total_portfolio();
    //print the graph by MATLAB
    void printGraph();
    //converter for time
    double convertertime(string) const;
private:
    Linkedlist list;

};


#endif //FINAL_PROJECT_STOCKACCOUNT_ZEKUN_H
