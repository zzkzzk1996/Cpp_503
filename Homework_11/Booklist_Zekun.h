//
// Created by Zekun Zhang on 11/21/18.
//

#ifndef HOMEWORK_11_BOOKLIST_ZEKUN_H
#define HOMEWORK_11_BOOKLIST_ZEKUN_H

#include <iostream>
using std::cout;
using std::endl;
using std::cin;

template <class T>
class Booklist{

public:
    bool Sorted;
    Booklist()
    {
        memset(booklist,0, sizeof(booklist));
        numbers = position = 0;
        Sorted = false;
    }

    virtual ~Booklist() {

    }

    T Input()
    {
        T book;
        cout << "Please type in the element" << endl;
        cin >> book;
        return book;
    }

    void Print()
    {
        cout<<"Your list is now:"<<endl;
        for(int i=0;i<numbers;i++)
        {
            cout<<i+1<<". "<<booklist[i]<<endl;
        }
    }

    bool Judge_Full()
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

    bool Judge_Empty()
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
    int Input_Position_Insert()
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
    int Input_Position_Delete()
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

    void Insert(T& new_book)
    {
        numbers++;
        *(booklist+numbers-1)=new_book;
    }

    void Insert_pos(T& new_book,int position)
    {
        numbers++;
        for(int i=numbers-1;i>=position;i--)
        {
            booklist[i]=*(booklist+i-1);
        }
        *(booklist+position-1)=new_book;
    }

    int Find_linear(T& book)
    {
        //can't find return -1 or return i
        for(int i=0;i<numbers;i++)
        {
            if(booklist[i]==book)
            {
                return i+1;
            }

        }
        return -1;
    }

    int Find_binary(T& book)
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

    void Delete_pos(int position)
    {
        numbers--;
        for(int i=position-1;i<numbers;i++)
        {
            booklist[i]=booklist[i+1];
        }
    }

    bool Delete_item(T& book)
    {
        for(int i=0;i<numbers;i++)
        {
            if(booklist[i]==book)
            {
                numbers--;
                for(int j=i;j<numbers;j++)
                {
                    *(booklist+j)=booklist[j+1];
                }
                cout<<"Delete successfully"<<endl;
                return true;
            }
        }
        return false;
    }

    void Sort_Selection()
    {
        int i;
        T min;
        int min_index=0;

        for( i=0;i<numbers-1;i++)
        {
            min=booklist[i];
            for(int j=i+1;j<numbers;j++)
            {
                if(booklist[j]<min)
                {
                    min=booklist[j];
                    min_index=j;
                    Swap(min_index,i);
                }

            }

        }

    }

    void Sort_Bubble()
    {
        //bubble algorithm
        for(int i=0;i<numbers-1;i++)
        {
            for(int j=0;j<numbers-1-i;j++)
            {
                if(booklist[j]>booklist[j+1])
                {
                    Swap(j,j+1);
                }

            }
        }
    }

private:

    int numbers;
    int position;
    T booklist[20];

    //do the swap operation
    void Swap(int a,int b)
    {
        T temp;
        temp=*(booklist+a);
        *(booklist+a)=*(booklist+b);
        *(booklist+b)=temp;
    }

};

#endif //HOMEWORK_11_BOOKLIST_ZEKUN_H
