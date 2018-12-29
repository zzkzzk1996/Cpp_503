//Zekun Zhang       Oct.7.2018
//Use recursion method to print the square of n

#include <iostream>

using std::cout;
using std::cin;
using std::endl;

//use sqrt to calculate the square of n
#include <cmath>
using std::pow;

//prototypes
int InputN();
void Square(int);

int main()
{
    int n=InputN();
    cout<<"On input "<<n<<", it should print ";
    Square(n);
    return 0;
}

//the input module
int InputN()
{
    int n;
    cout << "Please input n:" << endl;
    cin >> n;

    //use while loop to check the input
    while(n<=0)
    {
        cout << "Wrong input, 'n' should be positive:" << endl;
        cin >> n;
    }
    return n;
}

//Use Recursion method to finish the calculation and do the print
void Square(int n)
{
    //when n is equal to 1, print 1 and return the recursion
    if(n==1)
    {
        cout<<"1";
        return;
    }
    //if n is even, go the next function first
    if(n%2==0)
    {
        Square(n-1);
        cout<<","<<pow(n, 2);
    }
    //if n is odd, do print and go to the next function
    else
    {
        cout<<pow(n, 2)<<",";
        Square(n-1);
    }

}