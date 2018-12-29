//Zekun Zhang   Sept.22.2018
//tally up the number of votes each candidate received and pronounce a winner.

#include <iostream>
//contains operation for maximum number comparison
#include <algorithm>
//contains operation for some maths function
#include <cmath>
int main() {

    using namespace std;

    //only have five candidates, so the size of array is constant
    const int size=5;
    //double 'i' is used for judging if the input is an integer,finally double will be converted to int
    double i;
    //use array 'c' to contain the numbers of votes
    int c[size]={0};
    //use array 'v' to find out whether there are two or more maximum numbers
    int v[size]={0};
    //only 20 students can vote
    int votes=20;

    //the 'for' loop inputs the numbers of votes to array 'c'
    for(int j=1;j<=votes;j++)
    {
        cout<<"Please choose one of the candidates and input 1~5 represents for the five candidates"<<endl;
        cout<<"You are the "<<j<<"th student who votes for the candidates"<<endl;
        cin>>i;

        //use three 'if' statements to judge if there is any wrong input
        //judge if 'i' is a number
        if(cin.good()==0)
        {
            cout<<"it's not a number"<<endl;
            j--;
            cin.clear();
            cin.ignore();
            continue;
        }

        //judge if 'i' is among 1 to 5
        if(i<1||i>5)
        {
            cout<<"it's not from 1 to 5"<<endl;
            j--;
            continue;
        }

        //judge if 'i' is an integer
        if(abs(round(i)-i)>0.000000000000001)
        {
            cout<<"it's not an integer"<<endl;
            j--;
            continue;
        }

        //convert the double 'i' to int 'i_new'
        int i_new=static_cast<int>(i);

        //use array to count the votes
        c[i_new-1]++;
    }

    //the 'for' loop generates the reversed array 'v'
    //array 'v' is used to judge if there are two or more maximum numbers of votes
    for(int m=0,n=size-1-m;m<size;m++,n--)
    {
        v[m]=c[n];
    }

    //because the function 'max_element' only output the first maximum number
    //use the function 'distance' to judge if there are two or more maximum numbers of votes
    if(distance(begin(v),max_element(v,v+5))+distance(begin(c),max_element(c,c+5))<4)
    {
        cout << "There's no winner." << endl;
    }
    else
    {
        //pronounce the winner and the number of votes
        cout << "The maximum number of votes is " << *max_element(c, c + 5) << " and the "
        << distance(begin(c), max_element(c, c + 5)) + 1
        << "th one candidates wins" << endl;
    }
    return 0;

}


