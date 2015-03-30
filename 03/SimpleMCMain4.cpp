// SimpleMCMain4.cpp

/*
PayOff2.cpp
Random1.cpp
SimpleMC2.cpp
*/

#include<SimpleMC2.h>
#include<iostream>
using namespace std;

int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry (0.5)\n";
	cin >> Expiry;

	cout << "\nEnter strike (40)\n";
	cin >> Strike;

	cout << "\nEnter spot (42)\n";
	cin >> Spot;

	cout << "\nEnter vol (0.2)\n";
	cin >> Vol;

	cout << "\nr (0.1)\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;


    unsigned long optionType;

    cout << "\nenter 0 for call, otherwise put ";
    cin >> optionType;


    PayOff* thePayOffPtr; 

    if (optionType== 0)
        thePayOffPtr = new PayOffCall(Strike);
    else
        thePayOffPtr = new PayOffPut(Strike);

	double result = SimpleMonteCarlo2(*thePayOffPtr,
                                      Expiry,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);
	
	cout <<"\nthe price (call 4.76, put 0.81) is " << result << "\n";
    double tmp;
    cin >> tmp;

    delete thePayOffPtr;

	return 0;

}