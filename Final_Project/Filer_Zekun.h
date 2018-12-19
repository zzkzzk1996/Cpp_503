//
// Created by Zekun Zhang on 11/25/18.
//

#ifndef FINAL_PROJECT_FILER_H
#define FINAL_PROJECT_FILER_H

#include "Linkedlist_Zekun.h"
#include <fstream>
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

//define macros for the long director of files

#define RESULT_1 "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Result_1.txt"
#define RESULT_2 "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Result_2.txt"
//#define TEMP_SHARE "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Temp_share.txt"
#define BALANCE "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Balance.txt"
#define STOCK_HISTORY "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Stock_transaction_history.txt"
#define BANK_HISTORY "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Bank_transaction_history.txt"
#define STOCK "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Stock.txt"
#define PORTFOLIO "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Portfolio.txt"

class Filer {
public:
    //constructor and destructor
    Filer();

    virtual ~Filer();

    //initialize the balance
    void Initial_balance();

    //initialize file as a temporary share pricing file
    void Initial(const char *file_name);

    // check if the file is initialized
    bool Check(const char *file_name) const;

    //add new elements to the last line
    void Add(const char *file_name, string line);

    //get data for the last line
    string Getlast(const char *file_name) const;

    //get all data, which is used for printing transaction
    void Getall(const char *file_name) const;

    //Search the file to find out that file has the very stock
    string SearchName(const char *file_name, string keyword) const;

    //from the line get stock name and stock price
    string Getdata(string line, string datatype) const;

    //change price for the temporary share pricing file
//    bool Changeprice(const char *file_name, string keyword, string price);

//    import data from file to the double linked list
//    Linkedlist& Getstock() const;
//
//    store data from the double linked list to the file
//    void Storestock(Linkedlist &list) const;

};


#endif //FINAL_PROJECT_FILER_H
