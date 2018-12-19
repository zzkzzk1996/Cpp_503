
/*

    Final Project - 16:332:503:02 F18

    Author : Zekun Zhang

    Email : zekunzhang.1996@gmail.com

    Time : 2018/11/21

    Project : Account Management System

    IDE: CLion 2018.3.1

 */

#include "Account_Zekun.h"
#include "StockAccount_Zekun.h"
#include "BankAccount_Zekun.h"
#include "Linkedlist_Zekun.h"
#include "Filer_Zekun.h"
#include "Timer_Zekun.h"

#include <iostream>
#include <string>

using namespace std;

//main menu
void Show_main_menu();
//stock account menu
void Show_stock_menu();
//bank account menu
void Show_bank_menu();

//operation for stock account
void Stock_account();
//operation for bank account
void Bank_account();
////operation for setting
//void Setting();
//operation for exit
void Exit();

//positive check
template < typename TYPE >
TYPE input();

//create objects as user accounts
StockAccount stockaccount;
BankAccount bankaccount;
Account *account;
//object for file operation
Filer filer;

int main() {

    int choice = 0;
    //when the program starts, read the balance from the file
    account->Initial();
    cout << endl << "Welcome to the Account Management System." << endl;
    while (choice != 3)
    {
        Show_main_menu();
        cin >> choice;
        cin.clear();
        cin.ignore(1024, '\n');

        //all the functions need to be chosen
        switch (choice)
        {
            //Stock Portfolio Account
            case 1:
            {
                //initialize the temporary shares prices
//                if(!filer.Check(TEMP_SHARE))
//                {
//                    filer.Initial(TEMP_SHARE);
//                }
                //initialize the double linked list
                stockaccount.download_portfolio();
                Stock_account();
                break;
            }

            //Bank Account
            case 2:
            {
                Bank_account();
                break;
            }

//            //Settings (Choose Strategy)
//            case 3:
//            {
//                Setting();
//                break;
//            }

            //Exit and go to update part
            case 3:
            {
                Exit();
                break;
            }

            default:
            {
                cout << " Wrong Input " << endl;
                break;
            }
        }
    }

    //system pause used for visual studio
    //system("pause");
    return 0;
}

//operation for stock account
void Stock_account()
{
    //stock name
    string name;
    //stock numbers
    int num;
    //stock price
    double price;

    int choice = 0;
    cout << endl << "Stock Portfolio Account" << endl;
    while (choice != 7)
    {
        Show_stock_menu();
        cin >> choice;
        cin.clear();
        cin.ignore(1024, '\n');
        //all the functions need to be chosen
        switch (choice)
        {
            //Display the price for a stock symbol
            case 1:
            {
                cout << " Please enter the stock symbol : " << endl;
                getline(cin, name);
                stockaccount.display_price(name);
                break;
            }

            //Display the current portfolio
            case 2:
            {
                Strategy_Setup sort;

                stockaccount.display_portfolio();
                break;
            }

            //Buy shares
            case 3:
            {
                cout << " Please enter the stock symbol you wish to purchase : " << endl;
                getline(cin, name);
                cout << " Please enter the number of shares : " << endl;
                num = input<int>();
                cout << " Please enter the maximum amount you are willing to pay per share : " << endl;
                price = input<double>();
                stockaccount.buy_share(name, num, price, bankaccount);
                break;
            }

            //Sell shares
            case 4:
            {
                cout << " Please enter the stock symbol you wish to sell : " << endl;
                getline(cin, name);
                cout << "  Please enter the number of shares : " << endl;
                num = input<int>();
                cout << " Please enter the minimum amount you are willing to sell per share : " << endl;
                price = input<double>();
                stockaccount.sell_share(name, num, price, bankaccount);
                break;
            }

            //View a graph for the portfolio value
            case 5:
            {
                //stockaccount.printGraph();
                break;
            }

            //View transaction history
            case 6:
            {
                stockaccount.printhistory();
                break;
            }

            //Return to previous menu and initialize the temporary shares prices
            case 7:
            {
                stockaccount.update_portfolio();
                //filer.Initial(TEMP_SHARE);
                break;
            }

            default:
            {
                cout << " Wrong Input " << endl;
                break;
            }
        }
    }
}

//operation for bank account
void Bank_account()
{
    int choice = 0;
    double money;
    cout << endl << "Bank Account" << endl;
    while (choice != 5)
    {
        Show_bank_menu();
        cin >> choice;
        cin.clear();
        cin.ignore(1024, '\n');

        //all the functions need to be chosen
        switch (choice)
        {
            //View account balance
            case 1:
            {
                bankaccount.display_balance();
                break;
            }

            //Deposit money
            case 2:
            {
                cout << " Please select the amount you wish to deposit : " << endl;
                money = input<double>();
                bankaccount.deposit(money);
                break;
            }

            //Withdraw money
            case 3:
            {
                cout << " Please select the amount you wish to withdraw : " << endl;
                money = input<double>();
                bankaccount.withdraw(money);
                break;
            }

            //Print out history
            case 4:
            {
                bankaccount.printhistory();
                break;
            }

            //Return to previous menu
            case 5:
            {
                break;
            }

            default:
            {
                cout << " Wrong Input " << endl;
                break;
            }
        }
    }
}

////operation for setting
//void Setting()
//{
//    //setting sorting method
//    Strategy_Setup strategy;
//    int choice = 0;
//    cout << " Enter : Exit(0), Bubble(1), Selection(2) " << endl;
//    cin >> choice;
//    strategy.setSort(choice);
//}

//operation for exit
void Exit()
{
    stockaccount.total_portfolio();
    cout << endl << " Have a nice day ! " << endl;
}

//main menu
void Show_main_menu()
{
    cout << " Please select an account to access : " << endl;
    cout << " 1. Stock Portfolio Account " << endl;
    cout << " 2. Bank Account " << endl;
    //cout << " 3. Settings (Choose Strategy) " << endl;
    cout << " 3. Exit " << endl;
    cout << endl << " Option : ";
}

//stock account menu
void Show_stock_menu()
{
    cout << " Please select an option : " << endl;
    cout << " 1. Display the price for a stock symbol " << endl;
    cout << " 2. Display the current portfolio " << endl;
    cout << " 3. Buy shares " << endl;
    cout << " 4. Sell shares " << endl;
    cout << " 5. View a graph for the portfolio value " << endl;
    cout << " 6. View transaction history " << endl;
    cout << " 7. Return to previous menu " << endl;
    cout << endl << "Option : ";
}

//bank account menu
void Show_bank_menu()
{
    cout << " Please select an option : " << endl;
    cout << " 1. View account balance " << endl;
    cout << " 2. Deposit money " << endl;
    cout << " 3. Withdraw money " << endl;
    cout << " 4. Print out history " << endl;
    cout << " 5. Return to previous menu " << endl;
    cout << endl << " Option : ";
}

//perform input operation and make sure to be positive
template< typename TYPE >
TYPE input() {
    TYPE input;
    cin >> input;
    cin.clear();
    cin.ignore(1024, '\n');
    while (input <= 0) {
        cout << " Invalid Input : Input needs to be positive " << endl;
        cin >> input;
        cin.clear();
        cin.ignore(1024, '\n');
    }
    return input;
}
