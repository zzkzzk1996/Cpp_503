
//Zekun Zhang       Nov.5.2018

#include <iostream>
#include <vector>

using std::cout;
using std::cin;
using std::endl;
using std::vector;

#include "package_Zekun.h"
#include "TwoDayPackage_Zekun.h"
#include "OvernightPackage_Zekun.h"

double VirtualViaPointer(const package*, int);

int main() {

    double total = 0.0;

//    package Package("John Smith", "1 Davidson Road", "Piscataway", "NJ 08854", "Tom Smith", "2 Davidson Road", "Piscataway", "NJ 08854", 10.0, 0.5);
//    TwoDayPackage twoDayPackage("Mary Smith", "3 Davidson Road", "Piscataway", "NJ 08854", "Jennifer Smith", "4 Davidson Road", "Piscataway", "NJ 08854", 5.0, 0.5, 2.0);
//    OvernightPackage overnightPackage("John Smith", "1 Davidson Road", "Piscataway", "NJ 08854", "Mary Smith", "3 Davidson Road", "Piscataway", "NJ 08854", 2.0, 0.5, 5.0);

    package Package("John Zhang 1", "1 Orchard St", "Piscataway", "NJ 08854", "Tom Zhang", "2 Orchard St", "Piscataway", "NJ 08854", 10.0, 1.0);
    TwoDayPackage twoDayPackage("Mary Zhang", "3 Orchard St", "Piscataway", "NJ 08854", "Jennifer Zhang", "4 Orchard St", "Piscataway", "NJ 08854", 7.0, 1.0, 2.0);
    OvernightPackage overnightPackage("John Zhang", "1 Orchard St", "Piscataway", "NJ 08854", "Mary Zhang", "3 Orchard St", "Piscataway", "NJ 08854", 5.0, 1.0, 3.0);

    vector < package * > packptr;

    packptr.push_back(& Package);
    packptr.push_back(& twoDayPackage);
    packptr.push_back(& overnightPackage);

    cout << "Cost per ounce for a package: $" << Package.getCostpo() <<"/ounce" << endl;
    cout << "Additional cost for two-day delivery: $" << twoDayPackage.getFlatpo1() <<"/ounce" << endl;
    cout << "Additional cost for overnight delivery: $" << overnightPackage.getFlatpo2() <<"/ounce" << endl;

    for(int i = 0; i < packptr.size(); i++)
    {
        total += VirtualViaPointer(packptr[i], i);
    }

    cout << "\nTotal cost of all the packages : $" << total << endl;

    return 0;
}

double VirtualViaPointer(const package* Ptr, int i)
{
    cout << "\nPackage " << i + 1 << " :" <<endl;
    Ptr->print();
    Ptr->print_cost();
    return Ptr->calculateCost();
}
