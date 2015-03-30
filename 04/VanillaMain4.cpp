// VanillaMain4.cpp

/*
Parameters.cpp
PayOff3.cpp
PayOffBridge.cpp
Random1.cpp
SimpleMC6.cpp
Vanilla3.cpp
*/

#include<SimpleMC6.h>
#include<iostream>
using namespace std;
#include<Vanilla3.h>

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

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);

	double result = SimpleMonteCarlo4(theOption,
                                      Spot, 
                                      VolParam,
                                      rParam,
                                      NumberOfPaths);

	cout <<"\nthe call price (4.76) is " << result << "\n";
    
    VanillaOption secondOption(theOption);

    result = SimpleMonteCarlo4(secondOption,
                               Spot, 
                               VolParam,
                               rParam,
                               NumberOfPaths);

	cout <<"\nthe call price (4.76) is " << result << "\n";


    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo4(theOption,
                               Spot, 
                               VolParam,
                               rParam,
                               NumberOfPaths);


    cout <<"\nthe put price (0.81) is " << result << "\n";

    double tmp;
    cin >> tmp;

	return 0;
}