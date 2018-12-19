//
// Created by Zekun Zhang on 11/24/18.
//

#ifndef FINAL_PROJECT_NODE_ZEKUN_H
#define FINAL_PROJECT_NODE_ZEKUN_H

#define RESULT_1 "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Result_1.txt"
#define RESULT_2 "/Users/zekunzhang/CLionProjects/Final_Project/Filer/Result_2.txt"
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>
using namespace std;

class Node {

    friend class Linkedlist;
    friend class Sortbubble;
    friend class Sortselection;
    friend class Strategy_Setup;
public:
    //constructor
    Node(string stock, int num)
            :stocksymbol(stock), sharenumber(num)
    {
        this->next = NULL;
        this->pre = NULL;
    }

    const string &getStocksymbol() const {
        return stocksymbol;
    }

    void setStocksymbol(const string &stocksymbol) {
        Node::stocksymbol = stocksymbol;
    }

    int getSharenumber() const {
        return sharenumber;
    }

    void setSharenumber(int sharenumber) {
        Node::sharenumber = sharenumber;
    }


    //Get price from the file
    double getPrice() const {
        return price;
    }

    void setPrice(double price) {
        Node::price = price;
    }

    //destructor
    virtual ~Node() {

    }

    //search price and set price
    void searchprice()
    {
        string file;
        double price = 0.0;
        int x = rand() % 2 + 1;

        if (x == 1) {
            file = RESULT_1;
        } else if (x == 2) {
            file = RESULT_2;
        }
        string line;
        string word = "";
        ifstream ifs;
        ifs.open(file, ios_base::in);
        if (ifs.is_open() && !ifs.fail()) {
            while (getline(ifs, line)) {
                if (Getdata(line, "name") == this->getStocksymbol()) {
                    word = Getdata(line, "price");
                    ifs.close();
                    break;
                }
            }
            if (!word.empty()) {
                price = stod(word);
                this->setPrice(price);
            } else {
                this->setPrice(price);
                cout << " Can't Find The Stock Symbol " << endl;
                ifs.close();
            }

        } else {
            cout << " Error : File Can't Open " << endl;
        }
    }

    string Getdata(string line, string datatype) const {
        // change string data type to int
        int data = 0;
        if (datatype == "name") {
            data = 1;
        } else if (datatype == "price") {
            data = 2;
        } else {
            cout << " Error : Wrong Data Type " << endl;
            return "";
        }

        stringstream ss(line);
        string dataword;
        int num = 0;
        // find the num-th data which uses '\t' seperated
        while (num != data && getline(ss, dataword, '\t')) {
            num++;
        }
        return dataword;
    }

    Node *getNext() const {
        return next;
    }

private:
    //the stock symbol and number of shares which the node stores
    string stocksymbol;
    int sharenumber;
    double price;
    //two pointers, one for the next, and the other for the previous
    Node* next;
    Node* pre;
};


#endif //FINAL_PROJECT_NODE_ZEKUN_H