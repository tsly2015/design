// SimpleMCMain5.cpp

/*
DoubleDigital.cpp
PayOff2.cpp
Random1.cpp
SimpleMC2.cpp
*/

#include<SimpleMC2.h>
#include<DoubleDigital.h>
#include<iostream>
using namespace std;

int main()
{

	double Expiry;
	double Low,Up; 
	double Spot; 
	double Vol; 
	double r; 
	unsigned long NumberOfPaths;

	cout << "\nEnter expiry (0.5)\n";
	cin >> Expiry;
    
    cout << "\nEnter spot (42)\n";
    cin >> Spot;

	cout << "\nEnter low barrier\n";
	cin >> Low;

	cout << "\nEnter up barrier\n";
	cin >> Up;

	cout << "\nEnter vol (0.2)\n";
	cin >> Vol;

	cout << "\nr (0.1)\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low,Up);

	double result = SimpleMonteCarlo2(thePayOff,
                                      Expiry,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);
	
	cout <<"\nthe price is " << result << "\n";
    double tmp;
    cin >> tmp;

	return 0;

}