//Zekun Zhang Sept.20.2018
//Monte Carlo method simulation of pi

#include <iostream>
//contains prototypes for function srand and rand
#include <cstdlib>
//contains prototypes for function time
#include <time.h>
//contains operation for file
#include <fstream>
//define the real value of pi, so when the result is close to this value, stop the iteration
#define real_pi 3.14159

int main()
{
    using namespace std;

    int iteration;
    //use variable 'dot' to contain the number of dots which are inside
    int dot=0;
    double pi;

    //ask the user to input the number of the iteration
    cout<<"Please input your expected number of the iteration"<<"\n"
    <<"Caution: if the estimate result is close to the known value, the program would stop"<<endl;

    cin>>iteration;

    //seed random number generator
    srand(static_cast<unsigned int>(time(0)));


    //open a csv file named'data.csv'
    ofstream out("data.csv");
    //print the title for the following outputs
    out<<"X"<<","<<"Y"<<endl;

    //use this 'for' loop to control the amounts of random values of x and y
    //double 'i' is for the calculation of pi and actually 'i' is always an integer
    for(double i=1;i<=iteration;i++)
    {
        //variables 'x' and 'y' are the coordinates for the dot
        double x= static_cast<double>(rand())/RAND_MAX;
        double y= static_cast<double>(rand())/RAND_MAX;

        //judge whether the dot is inside the arc
        if(x*x+y*y<=1.0)
            ++dot;

        //print the values of x and y for each different value on the 'csv' file
        out<<x<<","<<y<<endl;

        //calculate the value of pi
        pi=4*dot/i;

        //if the estimate result is close to the known value, stop the iteration
        if(pi<=real_pi+0.0001&&pi>=real_pi-0.0001)
        {
            break;
        }

        //if the print is over, close the file
        if(i==iteration)
        {
            out.close();
        }

    }

    //if the print breaks, close the file
    if(out.is_open())
    {
        out.close();
    }

    //output the value of pi
    cout<<"PI="<<pi<<endl;

    return 0;
}