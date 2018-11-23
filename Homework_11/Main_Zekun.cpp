
// Created by Zekun Zhang on 11/21/18.

#include <iostream>
#include <string>
#include "Booklist_Zekun.h"

using std::cout;
using std::endl;
using std::cin;
using std::string;

//prototypes for the menu system and input module, which shouldn't be include in the class
void ShowMenu();

int main()
{
    //define variables and create an object
    int pos=0;
    //for implementation data type 'string'
    string book;
    Booklist< string > booklist;

    //for implementation data type 'int'
//    int book;
//    Booklist< int > booklist;

    cout<<"Welcome to the Book list program"<<endl;
    ShowMenu();

    int choice;
    cout<<"(And you first choice should be 1)"<<endl;
    cin>>choice;

    //use while loop to do a circular menu
    while(choice!=0) {
        switch (choice) {

            //add an element to end of list
            case 1:

                //if the list is full can't do insertion
                if(booklist.Judge_Full())
                {
                    break;
                }

                book = booklist.Input();

                //If there is more than one occurrence of an name, just delete the first one
                if(booklist.Find_linear(book)!=-1)
                {
                    booklist.Delete_item(book);
                    cout<<"Already has the book."<<endl;
                }

                booklist.Insert(book);
                //insertion will make the list unsorted
                booklist.Sorted= false;
                booklist.Print();

                break;

                //add an element at a location
            case 2:

                //if the list is full can't do insertion
                if(booklist.Judge_Full())
                {
                    break;
                }

                book = booklist.Input();

                //If there is more than one occurrence of an name, just delete the first one
                if(booklist.Find_linear(book)!=-1)
                {
                    booklist.Delete_item(book);
                    cout<<"Already has the book."<<endl;
                }

                //input position
                pos=booklist.Input_Position_Insert();

                booklist.Insert_pos(book,pos);
                //insertion will make the list unsorted
                booklist.Sorted= false;
                booklist.Print();
                break;

                //find an element by name number (linear search)
            case 3:

                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }


                book=booklist.Input();

                //judge whether the book can be found or not
                if(booklist.Find_linear(book)!=-1)
                {
                    cout << "This book is at position " << booklist.Find_linear(book) << endl;
                    break;
                }
                else {
                    cout << "Can't find this book" << endl;
                    break;
                }

                //find an element by name number (binary search)
            case 4:

                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }

                //judge whether it is sorted or not
                //judge whether the book can be found or not
                if(booklist.Sorted)
                {
                    book=booklist.Input();

                    if(booklist.Find_binary(book)!=-1)
                    {
                        cout << "This book is at position " << booklist.Find_binary(book) << endl;
                        break;
                    }
                    else
                        break;
                }
                else{
                    cout<<"The list isn't sorted and please do the sort operation first"<<endl;
                    break;
                }

                //delete an element at position
            case 5:

                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }

                //input position
                pos=booklist.Input_Position_Delete();

                booklist.Delete_pos(pos);
                booklist.Print();
                break;

                //delete an element by name number
            case 6:

                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }

                book=booklist.Input();
                if(booklist.Delete_item(book))
                {
                    booklist.Print();
                    break;
                }
                else {
                    cout << "Can't find the book you want to delete and delete failed" << endl;
                    break;
                }

                //sort the list (using selection sort)
            case 7:
                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }

                booklist.Sort_Selection();
                //make the list sorted
                booklist.Sorted= true;
                booklist.Print();
                break;

                //sort the list (using bubble sort)
            case 8:

                //if the list is empty can't do this operation
                if(booklist.Judge_Empty())
                {
                    break;
                }

                booklist.Sort_Bubble();
                //make the list sorted
                booklist.Sorted= true;
                booklist.Print();
                break;

            case 9:
                booklist.Print();
                break;

            default:
                cout << "Wrong Input" << endl;

        }

        ShowMenu();
        cin >> choice;
    }

    cout<<"It's over, Bye-bye!"<<endl;

    return 0;
}

void ShowMenu()
{
    cout<<"What would you like to do?"<<endl;
    cout<<"        1. add an element to end of list"<<endl;
    cout<<"        2. add an element at a location"<<endl;
    cout<<"        3. find an element by book name (linear search)"<<endl;
    cout<<"        4. find an element by book name (binary search)"<<endl;
    cout<<"        5. delete an element at position"<<endl;
    cout<<"        6. delete an element by book name"<<endl;
    cout<<"        7. sort the list (using selection sort)"<<endl;
    cout<<"        8. sort the list (using bubble sort)"<<endl;
    cout<<"        9. print the list"<<endl;
    cout<<"        0. exit"<<endl;
    cout<<"your choice is: "<<endl;
}

