#include <iostream>
#include <float.h>
int main() {
    using namespace std;
    double n, max, min;             //Use n as a variable to contain input number
    min=DBL_MAX;                    //Give min a initial value which is the maximum value of double respectively
    max=DBL_MIN;                    //Give max a initial value which is the minimum value of double respectively
    cout<<"Please input your five numbers(after each number you input please key-in 'return'):"<<endl;
    for(int i=1;i<=5;i++)           //Use a 'for' loop to input five number stream
    {
        cin>>n;
        if(min>n&&n>max)    //This comparision for the first number input gives the first valid values to min and max
            min=max=n;
        else if(n>max)      //If the input is bigger than max, give its value to max
            max=n;
        else if(n<min)      //If the input is smaller than min, give its value to min
            min=n;
    }
    cout<<"The maximum number is:"<<max<<endl;  //The maximum number output
    cout<<"The minimum number is:"<<min<<endl;  //The minimum number output
    return 0;
}
