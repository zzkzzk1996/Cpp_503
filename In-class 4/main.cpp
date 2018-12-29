//Zekun Zhang       Oct.6.2018
//Recursive method countBinStr

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

//function prototypes
int CountBinStr(int);
int InputN();

//use ans to contain the result number in each recursion
int ans;

int main()
{
    int n=InputN();
    int result=CountBinStr(n);
    cout<<"The result is:"<<result<<endl;
    return 0;
}

//the input module
int InputN()
{
    int n;
    cout << "Please input n as the length of the binary string:" << endl;
    cin >> n;

    //use while loop to check the input
    while(n<=0)
    {
        cout << "Wrong input, 'n' should be non-negative:" << endl;
        cin >> n;
    }
    return n;
}

//Use Recursion method to finish the calculation
int CountBinStr(int n)
{
    //if the recursion n is smaller than 1, 'return 1' is for the calculation can be finished
    if(n<1)
    {
        return 1;
    }

    //when n is equal to 1, there is '0' and '1', so we should return 2
    if(n==1)
    {
        return 2;
    }

    //the recursion method
    return ans=CountBinStr(n-1)+CountBinStr(n-2);
}
