//
// Created by Zekun Zhang on 11/21/18.
//

#include "StockAccount_Zekun.h"

//constructor
StockAccount::StockAccount() {}

//destructor
StockAccount::~StockAccount() {

}

//Download data from file to portfolio
void StockAccount::download_portfolio() {
    Filer filer;
    string line, name;
    int num = 0;
    ifstream ifs;

    ifs.open(STOCK, ios_base::in);
    if (ifs.is_open() && !ifs.fail()) {
        while(getline(ifs, line))
        {
            name = filer.Getdata(line, "name");
            num = stoi(filer.Getdata(line, "price"));
            Node *node = new Node(name, num);
            list.Add(node);
        }

    } else {
        cout << " Error : File Can't Open " << endl;

    }
}

//update data from portfolio to file
void StockAccount::update_portfolio() {
    Filer filer;
    ofstream ofs;
    string name, num;
    ofs.open(STOCK, ofstream::trunc | ofstream::out);
    // using this check to prevent causing bug by clean function
    if (ofs.is_open() && !ofs.fail()) {

        Node *current = list.getFirst()->getNext();
        while( current != list.getLast() )
        {
            name = current->getStocksymbol();
            num = to_string(current->getSharenumber());
            ofs << name << '\t' << num << '\n';
            current = current->getNext();
        }
        ofs.close();
    } else {
        cout << " Error : File Can't Initialize " << endl;
    }
}

//Check share price
string StockAccount::check_price(string keyword) const {
    Filer filer;
    string checker;
    int x = rand() % 2 + 1;

    if (x == 1) {
        checker = filer.SearchName(RESULT_1, keyword);
    } else if (x == 2) {
        checker = filer.SearchName(RESULT_2, keyword);
    }
    return checker;
}

//Display the price of a stock
void StockAccount::display_price(string keyword) const {
    Filer filer;
    string displayer;
    displayer = check_price(keyword);

    if (!displayer.empty()) {
        cout << left << setw(8) << "Symbol" << "Price per share" << endl;
        cout << left << setw(8) << keyword << fixed << setprecision(2) << displayer << endl;

//        if (!filer.Changeprice(TEMP_SHARE, keyword, displayer)) {
//            filer.Add(TEMP_SHARE, keyword + "\t" + displayer);
//        }
    }
}

//Display the current portfolio
void StockAccount::display_portfolio() {

    Strategy_Setup sort;
    //setting sorting method
    Strategy_Setup strategy;
    int choice = 0;
    cout << " Enter : Exit(0), Bubble(1), Selection(2) " << endl;
    cin >> choice;
    cin.clear();
    cin.ignore(1024, '\n');
    while (choice < 0 | choice > 2) {
        cout << " Invalid Input " << endl;
        cin >> choice;
        cin.clear();
        cin.ignore(1024, '\n');
    }
    strategy.setSort(choice);
    sort = strategy;
    sort.Do_sort(list);

    double total = 0.0;
    cout << "Cash balance = $" << fixed << setprecision(2) <<  getBalance() << endl;
    cout << left << setw(15) << "CompanySymbol"
         << left << setw(8) << "Number"
         << left << setw(15) << "PricePerShare" << "TotalValue" << endl;

    total = list.printList();
    cout << "Total portfolio value: $" << fixed << setprecision(2) <<  total + getBalance() << endl;
}

//Buy shares
void StockAccount::buy_share(string name, int num, double pricewilling, BankAccount &bankaccount) {
    Filer filer;
    const char* file;
    int x = rand() % 2 + 1;

    if (x == 1) {
        file = RESULT_1;
    } else if (x == 2) {
        file = RESULT_2;
    }
    //get the price from the temporary share price file
    double pricepershare = 0.0;
    if(filer.SearchName(file, name) != "")
    {
        pricepershare = stod(filer.SearchName(file, name));
    } else
    {
        cout << " Transaction Failed : can't found the stock " << endl;
        return;
    }

    //check whether the price is higher than the expected value
    if(pricepershare > pricewilling)
    {
        cout << " Transaction Failed : the price is higher than you want to pay " << endl;
        return;
    }

    //check whether user got enough balance to buy the stock
    double cost = num * pricepershare * 1.0;
    double balance = getBalance();
    if(cost > balance)
    {
        cout << " Transaction Failed : the balance is insufficient " << endl;
        return;
    }

    //buy the share
    //change balance
    setBalance(balance - cost);
    //add share to the portfolio and modify the history
    change_share(name, num, pricepershare, "Buy");
    //add balance history to bankaccount
    bankaccount.addhistory(cost, "BuyStock");
    //add history to stock account
    add_history(name, num, pricepershare, cost, "Buy");

    cout << " You have purchased " << num << " shares of " << name << " at $"
         << fixed << setprecision(2) << pricepershare << " each for a total of $"
         << fixed << setprecision(2) << cost << endl;

}

//Sell shares
void StockAccount::sell_share(string name, int numberwilling, double pricewilling, BankAccount &bankaccount) {
    Filer filer;

    const char* file;
    int x = rand() % 2 + 1;

    if (x == 1) {
        file = RESULT_1;
    } else if (x == 2) {
        file = RESULT_2;
    }

    Node *share = list.Find(name);
    //check if the user has the stock
    if(share == nullptr)
    {
        cout << " Transaction Failed : can't found the stock in your account " << endl;
        return;
    }

    //check whether user got enough shares to sell
    int number = share->getSharenumber();
    if(number < numberwilling)
    {
        cout << " Transaction Failed : the shares are insufficient " << endl;
        return;
    }

    //get the price from the temporary share price file
    double pricepershare = 0.0;
    if(filer.SearchName(file, name) != "")
    {
        pricepershare = stod(filer.SearchName(file, name));
    } else
    {
        cout << " Please check the price first " << endl;
        return;
    }

    //check whether the price is higher than the expected value
    if(pricepershare < pricewilling)
    {
        cout << " Transaction Failed : the price is lower than you want to sell " << endl;
        return;
    }

    //sell the share
    double earn = numberwilling * pricepershare * 1.0;
    double balance = getBalance();
    //remove share from the portfolio and modify the history
    change_share(name, numberwilling, pricepershare, "Sell");
    //change balance
    setBalance(balance + earn);
    //add balance history to bankaccount
    bankaccount.addhistory(earn, "SellStock");
    //add history to stock account
    add_history(name, numberwilling, pricepershare, earn, "Sell");

    cout << " You have sold " << numberwilling << " shares of " << name << " at $"
         << fixed << setprecision(2) << pricepershare << " each for a total of $"
         << fixed << setprecision(2) << earn << endl;

}

////got some problem that if I buy the same stock with different price, what to do
//Add or remove shares to the current portfolio
void StockAccount::change_share(string name, int num, double price, string type) {
    Node *node = list.Find(name);
    //check the type of operation
    if(type == "Buy")
    {
        //check if the stock has existed and if there's no previous same stock, new a node
        if (node == nullptr) {
            node = new Node(name, num);
            node->setPrice(price);
            list.Add(node);
        }
        else
        {
            node->setSharenumber(node->getSharenumber() + num);
        }
    }
    else if(type == "Sell")
    {
        //after deal finishing, if there's no same stock, remove the node
        if(node->getSharenumber() == num)
        {
            list.Remove(name);
        }
        else
        {
            node->setSharenumber(node->getSharenumber() - num);
        }
    }

}

//Add transaction history
void StockAccount::add_history(string name, int num, double price, double value, string type) {
    Timer timer;
    Filer filer;
    stringstream line;
    string time = timer.Gettime();
    line << left << setw(16) << type << left << setw(16) << name << left << setw(16) << to_string(num) << left
         << setw(16) << converter(price)
         << left << setw(16) << converter(value) << left << setw(16) << time;
    filer.Add(STOCK_HISTORY, line.str());
}

//Print stock transaction history
void StockAccount::printhistory() const {
    Filer filer;
    cout << left << setw(16) << "Event" << left << setw(16) << "CompSymbol"
         << left << setw(16) << "Number" << left << setw(16) << "PricePerShare" << left << setw(16)
         << left << setw(16) << "TotalValue" << "Time" << endl;
    filer.Getall(STOCK_HISTORY);
}

//Convert double to string and set precision
string StockAccount::converter(double convertee) const {
    stringstream convert;
    convert << fixed << setprecision(2) << convertee;
    return convert.str();
}

void StockAccount::total_portfolio() {
    Filer filer;
    Timer timer;
    string time = timer.Gettime();
    string date = timer.Getdate();
    Node *current = list.getFirst()->getNext();
    double totalvalue = 0.0;
    while (current != list.getLast()) {
        current->searchprice();

        totalvalue += list.getValue(current);
        current = current->getNext();
    }
    double total = totalvalue + getBalance();
    stringstream line;
    line << converter(total) << '\t' << time << '\t' << date;
    filer.Add(PORTFOLIO, line.str());
}






