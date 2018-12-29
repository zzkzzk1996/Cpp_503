//Zekun Zhang       Oct.8.2018
//Use recursion and backtracking method to finish a puzzle jump

#include <iostream>

using std::cout;
using std::cin;
using std::endl;


#include <vector>

using std::vector;


//prototypes
int Input(vector< int > &);
void Print(const vector< int > &,int);
bool SolvePuzzle(vector< int > &,int,int);
bool RightPos(vector< int > &,int,int);
bool LeftPos(vector< int > &,int,int);

int main()
{
    //use puzzle to contain input
    vector< int > puzzle;
    int n=Input(puzzle);
    //judge whether the puzzle sovled or not
    if(SolvePuzzle(puzzle,n,0))
    {
        cout<<"Solved"<<endl;
    }
    else
    {
        cout<<"Can't be solved"<<endl;
    }
    return 0;
}

//input module
int Input(vector< int > &integer)
{
    //use 'temp' to contain input then give the value to 'integer'
    int temp;
    int count=0;
    cout<<"Please input your puzzle, input number should be positive and if you input '0', input program finished"<<endl;

    //make sure the first input is positive
    cin>>temp;
    while(temp<0)
    {
        cout << "Wrong input, input should be positive:" << endl;
        cin >> temp;
    }

    //while you input a 0, which means input operation finished
    while(temp!=0)
    {
        integer.push_back(temp);
        count++;
        cin>>temp;

        //make sure every input is positive
        while(temp<0)
        {
            cout << "Wrong input, input should be positive:" << endl;
            cin >> temp;
        }

    }
    integer.push_back(0);
    count++;

    //input the first(start) number
    int start;
    cout << "Please input a number as the start of the puzzle:" << endl;
    cout<<"And your input should from 1 to "<<count<<endl;
    cin >> start;

    //judge whether the start is in the range
    while(start<=0||start>count)
    {
        cout << "Wrong input, input should be positive and in the range " << endl;
        cin >> start;
    }
    //insert 'start' to the first position
    integer.insert(integer.begin(),start);
    count++;
    Print(integer,count);
    return count;
}

//print module
void Print(const vector< int > &array,int n)
{
    cout<<"Your puzzle line is:"<<endl;

    for (int i = 0;i<n;i++)
    {
        cout<<" "<<array[i];
    }
    cout<<endl;
}

bool SolvePuzzle(vector< int > &puzzle,int n,int i)
{
    //define a vector to contain the copies of the puzzle to finish backtracking
    vector< int > temp;
    //if the peg move to the last, program return true and finish recursion
    if(i==n-1)
    {
        return true;
    }
    else
    {
        //if it can move to right, do the operation and begin recursion until can't move and then backtrack
        if (RightPos(puzzle, n, i))
        {
            int i_new;
            i_new = i + puzzle[i];
            temp=puzzle;
            puzzle[i]=-1;
            if(SolvePuzzle(puzzle, n, i_new))
            {
                return true;
            }
        }
        //give back the copies of values
        puzzle=temp;
        //if it can move to left, do the operation and begin recursion until can't move and then backtrack
        if (LeftPos(puzzle, n, i))
        {
            int i_new;
            i_new = i - puzzle[i];
            temp=puzzle;
            puzzle[i]=-1;
            if(SolvePuzzle(puzzle, n, i_new))
            {
                return true;
            }
        }
        //give back the copies of values
        puzzle=temp;
        return false;
    }
}

//test to move right
bool RightPos(vector< int > &puzzle,int n,int i)
{
    i+=puzzle[i];
    if(puzzle[i]==-1)
    {
        return false;
    }
    if(i<=0||i>=n)
    {
        return false;
    }
    return true;
}

//test to move left
bool LeftPos(vector< int > &puzzle,int n,int i)
{

    i=i-puzzle[i];
    if(puzzle[i]==-1)
    {
        return false;
    }
    if(i<=0||i>=n)
    {
        return false;
    }
    return true;
}