//
// Created by Zekun Zhang on 11/25/18.
//

#include "Filer_Zekun.h"

Filer::Filer() {

}

Filer::~Filer() {

}


//initialize the balance
void Filer::Initial_balance() {
    ofstream ofs;
    ofs.open(BALANCE, ofstream::trunc | ofstream::out);
    // using this check to prevent causing bug by clean function
    if (ofs.is_open() && !ofs.fail()) {
        ofs << "10000.00";
        ofs.close();
    } else {
        cout << " Error : Balance Can't Be Initialized " << endl;
    }

}

//initialize file
void Filer::Initial(const char *file_name) {
    ofstream ofs;
    ofs.open(file_name, ofstream::trunc);
    // using this check to prevent causing bug by clean function
    if (ofs.is_open() && !ofs.fail()) {
        ofs.close();
    } else {
        cout << " Error : File Can't Initialize " << endl;
    }
}

// check if the file is initialized
bool Filer::Check(const char *file_name) const {
    ifstream ifs;
    ifs.open(file_name, ios_base::in);
    //if there's nothing return true, which means this file has been initialized
    if (ifs.get() == EOF) {
        ifs.close();
        return true;
    } else {
        ifs.close();
        return false;
    }
}

//add elements to the last line, which is used for editing the history transaction
void Filer::Add(const char *file_name, string line) {
    ofstream ofs;
    ofs.open(file_name, ofs.app);
    if (ofs.is_open() && !ofs.fail()) {
        ofs << line << '\n';
        ofs.close();
    } else {
        cout << " Error : File Can't Open " << endl;
    }
}

//get the last line of the file, which is used for getting the balance from the cash balance file
string Filer::Getlast(const char *file_name) const {
    string line;
    ifstream ifs;
    ifs.open(file_name, ios_base::in);
    if (ifs.is_open() && !ifs.fail()) {
        getline(ifs, line);
        ifs.close();
    } else {
        cout << " Error : File Can't Open " << endl;
    }
    return line;
}

//get all data, which is used for printing transaction
void Filer::Getall(const char *file_name) const {
    string line;
    ifstream ifs;
    ifs.open(file_name, ios_base::in);
    if (ifs.is_open() && !ifs.fail()) {
        while (getline(ifs, line)) {
            cout << line << endl;
        }
        ifs.close();
    } else {
        cout << " Error : File Can't Open " << endl;
    }
}

//Search the file to find out that file has the very stock
string Filer::SearchName(const char *file_name, string keyword) const {
    string line;
    string word;
    ifstream ifs;
    ifs.open(file_name, ios_base::in);
    if (ifs.is_open() && !ifs.fail()) {
        while (getline(ifs, line)) {
            if (Getdata(line, "name") == keyword) {
                word = Getdata(line, "price");
                ifs.close();
                return word;
            }
        }
        cout << " Can't Find The Stock Symbol " << endl;
        ifs.close();
        return "";
    } else {
        cout << " Error : File Can't Open " << endl;
        return "";
    }

}

//get data from one line
string Filer::Getdata(string line, string datatype) const {
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

//change price for the temporary share pricing file
//bool Filer::Changeprice(const char *file_name, string keyword, string price) {
//    string line;
//    ifstream ifs;
//    string tempStr;
//    bool res = false;
//
//    ifs.open(file_name, ios_base::in);
//    if (ifs.is_open() && !ifs.fail()) {
//        while (getline(ifs, line)) {
//            if (Getdata(line, "name") == keyword) {
//                line = keyword + "\t" + price;
//                res = true;
//            }
//            tempStr += line + '\n';
//        }
//        ifs.close();
//    }
//
//    ofstream ofs;
//    ofs.open(file_name, ofstream::trunc);
//    ofs << tempStr;
//    ofs.close();
//
//    return res;
//}

//import data from file to the double linked list
//Linkedlist& Filer::Getstock() const {
//    string line, name;
//    int num = 0;
//    ifstream ifs;
//    Linkedlist list;
//    ifs.open(STOCK, ios_base::in);
//    if (ifs.is_open() && !ifs.fail()) {
//        while(getline(ifs, line))
//        {
//            name = Getdata(line, "name");
//            num = stoi(Getdata(line, "price"));
//            Node *node = new Node(name, num);
//            list.Add(node);
//        }
//
//    } else {
//        cout << " Error : File Can't Open " << endl;
//
//    }
//    return list;
//}
//
//store data from the double linked list to the file
//void Filer::Storestock(Linkedlist &list) const {
//    ofstream ofs;
//    int index = 1;
//    string name, num;
//    ofs.open(STOCK, ofstream::trunc);
//    // using this check to prevent causing bug by clean function
//    if (ofs.is_open() && !ofs.fail()) {
//
//        Node *current = list.Findposition(index);
//        while( current != nullptr)
//        {
//            name = current->getStocksymbol();
//            num = to_string(current->getSharenumber());
//            ofs << name << '\t' << num << '\n';
//            index++;
//            current = list.Findposition(index);
//        }
//        ofs.close();
//    } else {
//        cout << " Error : File Can't Initialize " << endl;
//    }
//}
