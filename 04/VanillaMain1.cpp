// VanillaMain1.cpp

/*
DoubleDigital.cpp
PayOff2.cpp
Random1.cpp
SimpleMC3.cpp
Vanilla1.cpp
*/

#include<SimpleMC3.h>
#include<DoubleDigital.h>
#include<iostream>
using namespace std;
#include<Vanilla1.h>

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

    VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);
	
	cout <<"\nthe price is " << result << "\n";
    double tmp;
    cin >> tmp;

	return 0;

}