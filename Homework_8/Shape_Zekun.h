//
// Created by Zekun Zhang on 10/30/18.
//

#ifndef HOMEWORK_8_SHAPE_ZEKUN_H
#define HOMEWORK_8_SHAPE_ZEKUN_H


class Shape {
public:
    Shape();
    ~Shape();

    int getX() const;

    void setX(int x);

    int getY() const;

    void setY(int y);

    int getZ() const;

    void setZ(int z);

private:
    int x;
    int y;
    int z;

};


#endif //HOMEWORK_8_SHAPE_ZEKUN_H
