#include <iostream>
#include <algorithm>
#include <deque>
#include <numeric>
#include <iterator>
using namespace std;

void outputhalf(int x);
bool greater6(int x);
int main() {
    deque < int > mydequezekun;

    //1.Insert the numbers 3, 4, 6, 2, 9, 1, 5, 0, 7, 8 by inserting the numbers in that
    //order, one at a time, to the end of the deque.
    mydequezekun.push_back(3);
    mydequezekun.push_back(4);
    mydequezekun.push_back(6);
    mydequezekun.push_back(2);
    mydequezekun.push_back(9);
    mydequezekun.push_back(1);
    mydequezekun.push_back(5);
    mydequezekun.push_back(0);
    mydequezekun.push_back(7);
    mydequezekun.push_back(8);

    //2. Use STL algorithms to remove the value of 7 from the deque
    mydequezekun.erase(remove(mydequezekun.begin(), mydequezekun.end(), 7), mydequezekun.end());

    //3. Use STL algorithms to replace values greater than 6 in the deque with 10.
    replace_if(mydequezekun.begin(), mydequezekun.end(), greater6, 10);

    /*4.Use STL algorithms to return the sum of all the elements in the deque and
      print out the sum. Then insert that sum to be a new element at the beginning of
      the deque.
     */
    int sum = accumulate(mydequezekun.begin(), mydequezekun.end(), 0);
    cout << "The sum of the numbers 0 to 9 after removing 7 and replacing values greater than 6 with 10 is: "
    << sum << endl;
    mydequezekun.push_front(sum);

    //5.Use STL algorithms to count the number of elements in the deque that are greater than 6 and print out the count.
    int count = count_if(mydequezekun.begin(), mydequezekun.end(), greater6);
    cout << "Now the number of elements greater than 6 is: " << count << endl;

    //6. Use STL algorithms to output the half (integer division) of every element in the deque.
    cout << "The half of every element in the deque is: ";
    for_each(mydequezekun.begin(), mydequezekun.end(), outputhalf);
    cout << endl;

    //7. Use STL algorithms to sort the deque
    sort(mydequezekun.begin(), mydequezekun.end());

    //8. Use the STL algorithms to find the location of 6 in the deque and print out the location.
    deque < int > ::iterator finder;
    finder = find(mydequezekun.begin(), mydequezekun.end(), 6);
    if(finder != mydequezekun.end())
    {
        int location = (finder - mydequezekun.begin());
        cout << "After sorting, the location of 6 is at index: " << location << endl;
    }
    else
    {
        cout << " '6' Not Found " << endl;
    }

    /*9. Use the ostream_iterator and the copy algorithm to print out the deque
     * elements with a comma in between the numbers. The last element can also
     * have a comma after it.
     */
    ostream_iterator < int > output (cout, ", ");
    cout << "The items in the deque are: ";
    copy(mydequezekun.begin(), mydequezekun.end(), output);
    cout << endl;

    system("pause");

    return 0;
}

//print half function
void outputhalf(int x)
{
    cout << x / 2 << " ";
}

//determine whether arguement is greater than 6
bool greater6(int x)
{
    return x > 6;
}