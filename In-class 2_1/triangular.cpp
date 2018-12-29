//Zekun Zhang Sept.15.2018
#include <iostream>
//Using for structure to print triangular shape

int main()
{
    using namespace std;

    int n,i,j;

    //Ask users to key in the number of the lines
    cout<<"How many lines do you want in the triangular shape? Please input:"<<endl;
    //Put the number in variable 'n'
    cin>>n;

    for(i=1;i<=n;i++)
    {
        for(j=1;j<=i;j++)
            cout<<"*";
        cout<<endl;
    }

    //Use this line to hold the result figure
    cin.get();

    return 0;
}