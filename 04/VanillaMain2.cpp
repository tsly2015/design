// VanillaMain2.cpp

/*
PayOff3.cpp
Random1.cpp
SimpleMC4.cpp
Vanilla2.cpp
*/

#include<SimpleMC4.h>
#include<iostream>
using namespace std;
#include<Vanilla2.h>

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

	cout << "\nStrike (40)\n";
	cin >> Strike;

	cout << "\nEnter spot (42)\n";
	cin >> Spot;

	cout << "\nEnter vol (0.2)\n";
	cin >> Vol;

	cout << "\nr (0.1)\n";
	cin >> r;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);

	double result = SimpleMonteCarlo3(theOption,
                                      Spot, 
                                      Vol,
                                      r,
                                      NumberOfPaths);

	cout <<"\nthe call price (4.76) is " << result << "\n";
    
    VanillaOption secondOption(theOption);

    result = SimpleMonteCarlo3(secondOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

	cout <<"\nthe call price (4.76) is " << result << "\n";

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo3(theOption,
                               Spot, 
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"\nthe put price (0.81) is " << result << "\n";

    double tmp;
    cin >> tmp;

	return 0;
}
