// payfactorymain.cpp

/*
PayOff3.cpp
PayOffBridge.cpp
PayOffFactory.cpp
PayOffRegistration.cpp
*/

#include <PayOff3.h>
#include <PayOffConstructible.h>
#include <PayOffBridge.h>
#include <PayOffFactory.h>
#include <string>
#include <iostream>
using namespace std;

int main()
{

    double Strike;
    std::string name;

    cout << "Enter strike (40)\n";
    cin >> Strike;
    
    cout << "\npay-off name (call)\n";
    cin >> name;

    PayOff* PayOffPtr = PayOffFactory::Instance().CreatePayOff(name,Strike); 

    if (PayOffPtr != NULL)
    {
        double Spot;

        cout << "\nspot (42)\n";
        cin >> Spot;

        cout << "\n" << PayOffPtr->operator ()(Spot) << "\n";    
        delete PayOffPtr;
    }
    
    double tmp;
    cin >> tmp;
    return 0;
}