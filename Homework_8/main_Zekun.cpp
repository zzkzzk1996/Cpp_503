//Zekun Zhang          Oct.30.2018

#include <iostream>

#include "Circle_Zekun.h"
#include "Triangle_Zekun.h"
#include "Sphere_Zekun.h"
#include "RegularTetrahedron_Zekun.h"

using std::cout;
using std::cin;
using std::endl;

void ShowMenu();

int main() {
    Circle circle;
    Triangle triangle;
    Sphere sphere;
    RegularTetrahedron regularTetrahedron;

    int x = 0;
    int y = 0;
    int z = 0;
    int choice = 0;

    ShowMenu();
    cin >> choice;

    while(choice != 0)
    {
        double radius = 0.0;
        double edge = 0.0;

        switch(choice)
        {
            case 1:
                cout << "You have chosen the circle." << endl;
                cout << "\nPlease enter the center of the circle (x-coordinate and then y-coordinate):" << endl;
                cin >> x >> y;
                circle.setX(x);
                circle.setY(y);
                cout << "\nPlease enter the radius of the circle:" << endl;
                cin >> radius;
                circle.setRadius(radius);
                circle.print();
                break;

            case 2:
                cout << "You have chosen the triangle." << endl;
                cout << "\nPlease enter the center of the triangle (x-coordinate and then y-coordinate):" << endl;
                cin >> x >> y;
                triangle.setX(x);
                triangle.setY(y);
                cout << "\nPlease enter the edge length of the triangle:" << endl;
                cin >> edge;
                triangle.setEdge(edge);
                triangle.print();
                break;

            case 3:
                cout << "You have chosen the sphere." << endl;
                cout << "\nPlease enter the center of the sphere (x-coordinate, y-coordinate, then z-coordinate):" << endl;
                cin >> x >> y >> z;
                sphere.setX(x);
                sphere.setY(y);
                sphere.setZ(z);
                cout << "\nPlease enter the radius of the sphere:" << endl;
                cin >> radius;
                sphere.setRadius(radius);
                sphere.print();
                break;

            case 4:
                cout << "You have chosen the regular tetrahedron." << endl;
                cout << "\nPlease enter the center of the regular tetrahedron (x-coordinate, y-coordinate, then z-coordinate):" << endl;
                cin >> x >> y >> z;
                regularTetrahedron.setX(x);
                regularTetrahedron.setY(y);
                regularTetrahedron.setZ(z);
                cout << "\nPlease enter the edge length of the regular tetrahedron" << endl;
                cin >> edge;
                regularTetrahedron.setEdge(edge);
                regularTetrahedron.print();
                break;

            default:
                cout<<"Wrong Input."<<endl;
        }
        ShowMenu();
        cin >> choice;
    }

    cout<<"It's over, bye-bye!"<<endl;
    return 0;
}

void ShowMenu()
{
    cout<<"\nMenu"<<endl;
    cout<<"Please choose a shape or 0 to exit:"<<endl;
    cout<<" Choice 1: Circle"<<endl;
    cout<<" Choice 2: Triangle"<<endl;
    cout<<" Choice 3: Sphere"<<endl;
    cout<<" Choice 4: Regular Tetrahedron"<<endl;
    cout<<" Choice 0: Exit"<<endl;
    cout<<" Choice : ";

}
