//
// Created by Zekun Zhang on 10/13/18.
//

#include <iostream>
#include "Booklist_Zekun.h"

using std::cout;
using std::endl;
using std::cin;


Booklist::Booklist()
{
    memset(booklist,0, sizeof(booklist));
    numbers = position = 0;
    Sorted = false;
}


void Booklist::Print()
{
    cout<<"Your list is now:"<<endl;
    for(int i=0;i<numbers;i++)
    {
        cout<<i+1<<". "<<*(booklist+i)<<endl;
    }
}

bool Booklist::Judge_Full()
{
    if(numbers==20)
    {
        cout<<"The booklist is full"<<endl;
        return true;
    }
    else
    {
        return false;
    }
}

bool Booklist::Judge_Empty()
{
    if(numbers==0)
    {
        cout<<"The booklist is empty"<<endl;
        return true;
    }

    else
    {
        return false;
    }
}

//input the value of position
int Booklist::Input_Position_Insert()
{
    //make sure the position is in the range of the list
    cout<<"the position range is: "<<"1~"<<numbers+1<<endl;
    cout<<"At what position:"<<endl;
    cin>>position;
    while(position<=0||position>numbers+1)
    {
        cout<<"Not in the range"<<endl;
        cin>>position;
    }
    return position;
}

//input the value of position
int Booklist::Input_Position_Delete()
{
    //make sure the position is in the range of the list
    cout<<"the position range is: "<<"1~"<<numbers<<endl;
    cout<<"At what position:"<<endl;
    cin>>position;
    while(position<=0||position>numbers)
    {
        cout<<"Not in the range"<<endl;
        cin>>position;
    }
    return position;
}

void Booklist::Insert(int new_book)
{
    numbers++;
    *(booklist+numbers-1)=new_book;
}

void Booklist::Insert_pos(int new_book,int position)
{
    numbers++;
    for(int i=numbers-1;i>=position;i--)
    {
        *(booklist+i)=*(booklist+i-1);
    }
    *(booklist+position-1)=new_book;
}

int Booklist::Find_linear(int book)
{
    //can't find return -1 or return i
    for(int i=0;i<numbers;i++)
    {
        if(*(booklist+i)==book)
        {
            return i+1;
        }

    }
    return -1;
}

int Booklist::Find_binary(int book)
{
    //binary algorithm
    //can't find return -1 or return middle
    int low=0;
    int high=numbers-1;
    int middle;

    while(low<=high)
    {
        middle=(low+high)/2;
        if(book==*(booklist+middle))
            return middle+1;
        else
        {
            if(book<*(booklist+middle))
            {
                high=middle-1;
            }
            else
            {
                low=middle+1;
            }
        }

    }
    cout<<"Can't find this book"<<endl;
    return -1;
}

void Booklist::Delete_pos(int position)
{
    numbers--;
    for(int i=position-1;i<numbers;i++)
    {
        *(booklist+i)=*(booklist+i+1);
    }
}

bool Booklist::Delete_num(int book)
{
    for(int i=0;i<numbers;i++)
    {
        if(*(booklist+i)==book)
        {
            numbers--;
            for(int j=i;j<numbers;j++)
            {
                *(booklist+j)=*(booklist+j+1);
            }
            cout<<"Delete successfully"<<endl;
            return true;
        }
    }
    return false;
}

void Booklist::Sort_Selection()
{
    int i;
    int min=0;
    int min_index=0;

    for( i=0;i<numbers-1;i++)
    {
        min=*(booklist+i);
        for(int j=i+1;j<numbers;j++)
        {
            if(*(booklist+j)<min)
            {
                min=*(booklist+j);
                min_index=j;
                Swap(min_index,i);
            }

        }

    }

}

void Booklist::Sort_Bubble()
{
    //bubble algorithm
    for(int i=0;i<numbers-1;i++)
    {
        for(int j=0;j<numbers-1-i;j++)
        {
            if(*(booklist+j)>*(booklist+j+1))
            {
                Swap(j,j+1);
            }

        }
    }
}

//do the swap operation
void Booklist::Swap(int a,int b)
{
    int temp;
    temp=*(booklist+a);
    *(booklist+a)=*(booklist+b);
    *(booklist+b)=temp;
}
