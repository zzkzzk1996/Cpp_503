//Zekun Zhang       Oct.8.2018
//Book List

#include <iostream>

using std::cout;
using std::endl;
using std::cin;


//prototypes
void ShowMenu();
int Input();
void Print(int [],int);
int Insert(int [],int,int);
int Insert_pos(int[],int,int,int);
int Find_linear(int[],int,int);
int Find_binary(int[],int,int,int,int);
int Delete_pos(int[],int,int);
int Delete_num(int[],int,int);
void Sort_Selection(int[],int);
void Sort_Bubble(int[],int);
void Swap(int[],int,int);

//the maximum number of books should be 20
const int MAXBOOKS=20;

int main()
{
    //define variables and array for booklist
    //Sorted is for judging if the list is sorted
    int isbn;
    int pos;
    int numbers=0;
    bool Sorted= false;
    int booklist[MAXBOOKS];

    cout<<"Welcome to the Book list program"<<endl;
    ShowMenu();

    int choice;
    cout<<"(And you first choice should be 1)"<<endl;
    cin>>choice;

    //use while loop to do a circular menu
    while(choice!=0)
    {
        switch(choice)
        {
            //add an element to end of list
            case 1:

                //if the list is full can't do insertion
                if(numbers==20)
                {
                    cout<<"The booklist is full"<<endl;
                    break;
                }

                isbn=Input();

                //If there is more than one occurrence of an ISBN, just delete the first one
                if(Find_linear(booklist,numbers,isbn)!=-1)
                {
                    numbers=Delete_num(booklist,numbers,isbn);
                    cout<<"Already has the book."<<endl;
                }

                numbers= Insert(booklist,numbers,isbn);
                //insertion will make the list unsorted
                Sorted= false;
                Print(booklist,numbers);
                break;

                //add an element at a location
            case 2:
                //if the list is full can't do insertion
                if(numbers==20)
                {
                    cout<<"The booklist is full"<<endl;
                    break;
                }

                isbn=Input();

                //If there is more than one occurrence of an ISBN, just delete the first one
                if(Find_linear(booklist,numbers,isbn)!=-1)
                {
                    numbers=Delete_num(booklist,numbers,isbn);
                    cout<<"Already has the book."<<endl;
                }

                //make sure the position is in the range of the list
                cout<<"the position range is: "<<"1~"<<numbers+1<<endl;
                cout<<"At what position:"<<endl;
                cin>>pos;
                while(pos<=0||pos>numbers+1)
                {
                    cout<<"Not in the range"<<endl;
                    cin>>pos;
                }

                numbers = Insert_pos(booklist,numbers,isbn,pos);
                //insertion will make the list unsorted
                Sorted= false;
                Print(booklist,numbers);
                break;

                //find an element by ISBN number (linear search)
            case 3:

                //if the list is empty can't do this operation
                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                isbn=Input();

                pos=Find_linear(booklist,numbers,isbn);

                //judge whether the book can be found or not
                if(pos!=-1)
                {
                    cout << "This book is at position " << pos << endl;
                    break;
                }
                else
                {
                    cout<<"Can't find this book"<<endl;
                    break;
                }

                //find an element by ISBN number (binary search)
            case 4:

                //if the list is empty can't do this operation
                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                //judge whether it is sorted or not
                //judge whether the book can be found or not
                if(Sorted)
                {
                    isbn=Input();
                    pos=Find_binary(booklist,numbers,isbn,0,numbers-1);

                    if(pos!=-1)
                    {
                        cout << "This book is at position " << pos << endl;
                        break;
                    }
                    else
                    {
                        cout<<"Can't find this book"<<endl;
                        break;
                    }

                }
                else{
                    cout<<"The list isn't sorted and please do the sort operation first"<<endl;
                    break;
                }


                //delete an element at position
            case 5:

                //if the list is empty can't do this operation

                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                //make sure the position is in the range of the list
                cout<<"the position range is: "<<"1~"<<numbers<<endl;
                cout<<"At what position:"<<endl;
                cin>>pos;
                while(pos<=0||pos>numbers)
                {
                    cout<<"Not in the range"<<endl;
                    cin>>pos;
                }

                numbers = Delete_pos(booklist,numbers,pos);
                Print(booklist,numbers);
                break;


                //delete an element by ISBN number
            case 6:

                //if the list is empty can't do this operation
                int new_number;
                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                isbn=Input();
                new_number= Delete_num(booklist,numbers,isbn);

                //judge whether do the deletion or not
                if(new_number!=numbers)
                {
                    numbers=new_number;
                    Print(booklist, numbers);
                    break;
                }
                else
                {
                    cout<<"Can't find the book you want to delete and delete failed"<<endl;
                    break;
                }

                //sort the list (using selection sort)
            case 7:

                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                Sort_Selection(booklist,numbers);
                //make the list sorted
                Sorted= true;
                Print(booklist,numbers);
                break;

                //sort the list (using bubble sort)
            case 8:

                //if the list is empty can't do this operation
                if(numbers==0)
                {
                    cout<<"The booklist is empty"<<endl;
                    break;
                }

                Sort_Bubble(booklist,numbers);
                //make the list sorted
                Sorted= true;
                Print(booklist,numbers);
                break;

            case 9:
                Print(booklist,numbers);
                break;

            default:
                cout<<"Wrong Input"<<endl;
        }

        ShowMenu();
        cin>>choice;
    }

    cout<<"It's over, Bye-bye!"<<endl;

    return 0;
}

void ShowMenu()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"        1. add an element to end of list"<<endl;
    cout<<"        2. add an element at a location"<<endl;
    cout<<"        3. find an element by ISBN number (linear search)"<<endl;
    cout<<"        4. find an element by ISBN number (binary search)"<<endl;
    cout<<"        5. delete an element at position"<<endl;
    cout<<"        6. delete an element by ISBN number"<<endl;
    cout<<"        7. sort the list (using selection sort)"<<endl;
    cout<<"        8. sort the list (using bubble sort)"<<endl;
    cout<<"        9. print the list"<<endl;
    cout<<"        0. exit"<<endl;
    cout<<"your choice is: "<<endl;
}

int Input()
{
    int num;
    cout<<"Please input your ISBN and there should be only 9 digits"<<endl;
    cout<<"And the first number shouldn't be 0"<<endl;
    cin>>num;
    return num;
}

void Print(int Booklist[],int num)
{
    cout<<"Your list is now:"<<endl;
    for(int i=0;i<num;i++)
    {
        cout<<i+1<<". "<<Booklist[i]<<endl;
    }
}

int Insert(int Booklist[],int num,int new_book)
{
    num++;
    Booklist[num-1]=new_book;
    return num;
}

int Insert_pos(int Booklist[],int num,int new_book,int position)
{
    num++;
    for(int i=num-1;i>=position;i--)
    {
        Booklist[i]=Booklist[i-1];
    }
    Booklist[position-1]=new_book;
    return num;
}

int Find_linear(int Booklist[],int num,int book)
{
    //can't find return -1 or return i
    for(int i=0;i<num;i++)
    {
        if(Booklist[i]==book)
        {
            return i+1;
        }
    }
    return -1;
}

int Find_binary(int Booklist[],int num,int book,int low,int high)
{
    //binary algorithm
    //can't find return -1 or return middle
    int middle;
    while(low<=high)
    {
        middle=(low+high)/2;
        if(book==Booklist[middle])
            return middle+1;
        else
        {
            if(book<Booklist[middle])
            {
                high=middle-1;
            }
            else
            {
                low=middle+1;
            }
        }

    }
    return -1;
}

int Delete_pos(int Booklist[],int num,int position)
{
    num--;
    for(int i=position-1;i<num;i++)
    {
        Booklist[i]=Booklist[i+1];
    }
    return num;
}

int Delete_num(int Booklist[],int num,int book)
{
    for(int i=0;i<num;i++)
    {
        if(Booklist[i]==book)
        {
            num--;
            for(int j=i;j<num;j++)
            {
                Booklist[j]=Booklist[j+1];
            }
            return num;
        }
    }
    return num;
}

void Sort_Selection(int Booklist[],int num)
{
    int i;
    int smallest=0;
    int smPtr=0;

    for( i=0;i<num-1;i++)
    {
        smallest=*(Booklist+i);
        for(int j=i+1;j<num;j++)
        {
            if(*(Booklist+j)<smallest)
            {
                smallest=*(Booklist+j);
                smPtr=j;
                Swap(Booklist,smPtr,i);
            }

        }

    }

}

void Sort_Bubble(int Booklist[],int num)
{
    //bubble algorithm
    for(int i=0;i<num-1;i++)
    {
        for(int j=0;j<num-1-i;j++)
        {
            if(*(Booklist+j)>*(Booklist+j+1))
            {
                Swap(Booklist,j,j+1);
            }

        }
    }
}

//do the swap operation
void Swap(int Booklist[],int a,int b)
{
    int temp;
    temp=*(Booklist+a);
    *(Booklist+a)=*(Booklist+b);
    *(Booklist+b)=temp;
}
