//
// Created by Zekun Zhang on 10/13/18.
//

#ifndef BOOKLIST_ZEKUN
#define BOOKLIST_ZEKUN

class Booklist{

public:
    Booklist();
    bool Sorted;
    void Print();
    bool Judge_Empty();
    bool Judge_Full();
    int Input_Position_Insert();
    int Input_Position_Delete();
    void Insert(int);
    void Insert_pos(int,int);
    int Find_linear(int);
    int Find_binary(int);
    void Delete_pos(int);
    bool Delete_num(int);
    void Sort_Selection();
    void Sort_Bubble();

private:

    int numbers;
    int position;
    int booklist[20];
    void Swap(int,int);

};

#endif //BOOKLIST_ZEKUN