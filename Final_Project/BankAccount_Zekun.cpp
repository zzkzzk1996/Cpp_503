//
// Created by Zekun Zhang on 11/21/18.
//

#include "BankAccount_Zekun.h"

//constructor
BankAccount::BankAccount() {}

//destructor
BankAccount::~BankAccount() {

}

//display account balance
void BankAccount::display_balance() const {
    cout << "You have $" << fixed << setprecision(2) <<  getBalance() <<  " in your bank account." << endl;
}

//operation for adding balance
void BankAccount::deposit(double money) {
    double balance = getBalance();
    setBalance(money + balance);
    addhistory(money, "Deposit");
    display_balance();
}

//operation for withdraw
void BankAccount::withdraw(double money) {
    double balance = getBalance();
    //check if there's enough money
    if(balance - money < 0)
    {
        cout << " Withdraw Failed : there's no sufficient money " << endl;
        return;
    } else
    {
        setBalance(balance - money);
        addhistory(money, "Withdraw");
        display_balance();
    }
}

//add deposit or withdraw history to the file
void BankAccount::addhistory(double money, string type) {
    Timer timer;
    Filer filer;
    stringstream line;
    string date = timer.Getdate();
    line << left << setw(16) << type << left << setw(16) << "$" + converter(money)
         << left << setw(16) << date << "$" + converter(getBalance());
    filer.Add(BANK_HISTORY, line.str());
}

//print bank transaction history
void BankAccount::printhistory() const {
    Filer filer;
    cout << left << setw(16) << "Event" << left << setw(16) << "Amount"
         << left << setw(16) << "Date" << "Balance" << endl;
    filer.Getall(BANK_HISTORY);
    cout << endl;
}

//Convert double to string and set precision
string BankAccount::converter(double convertee) const {
    stringstream convert;
    convert << fixed << setprecision(2) << convertee;
    return convert.str();
}
