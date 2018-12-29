//Zekun Zhang Sept.15.2018
#include <iostream>
//Using for structure to print diamond shape

int main()
{
    using namespace std;

    //Usr input module
    int numb,renumb;

    //Ask users to key in a maximum number of spaces in each line
    cout<<"Please input a maximum number of spaces in each line:"<<endl;
    //Put the number in variable 'numb'
    cin>>numb;

    //Check whether the input number is an odd number
    while(numb%2==0)
    {
        cout << "Please input an odd number:" << endl;
        //Put the new number in variable 'renumb'
        cin >> renumb;
        numb=renumb;
    }


    //Shape print module
    //Print the upper part of the diamond
    //Define the number of upper lines as 'n'
    int n=(numb+3)/2;

    //Use the 'for' loop to control the number of line
    for(int i=1;i<=n;i++)
    {
        //Use the 'for' loop to control the spaces before first '*'
        for(int j=0;j<n-i;j++)
            cout << " ";
        cout << "*";

        //The first line is special, so we need to skip
        if(i==1)
        {
            cout << endl;
            continue;
        }

        //Use the 'for' loop to control the spaces after first '*'
        for(int k=0;k<2*i-3;k++)
            cout<<" ";
        cout<<"*"<<endl;
    }

    //Print the lower part of the diamond
    //Use the 'for' loop to control the number of line
    for(int i=1;i<=n-1;i++)
    {
        //Use the 'for' loop to control the spaces before first '*'
        for(int j=0;j<i;j++)
            cout<<" ";
        cout<<"*";

        //The last line is special, so we need to break to end the program
        if(i==n-1)
        {
            cout<<endl;
            break;
        }

        //Use the 'for' loop to control the spaces after first '*'
        for(int k=0;k<(-2)*i+numb;k++)
            cout<<" ";
        cout<<"*"<<endl;
    }

    //Use this line to hold the result figure
    cin.get();

    return 0;
}
