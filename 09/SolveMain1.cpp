// SolveMain1.cpp

/*
BlackScholesFormulas.cpp
BSCallClass.cpp
Normals.cpp
*/

#include <Bisection.h>
#include <cmath>
#include <iostream>
#include <BSCallClass.h>
#include <BlackScholesFormulas.h>

using namespace std;

int main()
{
  	double Expiry;
	double Strike; 
	double Spot; 
	double r;
    double d;
    double Price;

	cout << "\nEnter expiry (0.5)\n";
	cin >> Expiry;

	cout << "\nStrike (40)\n";
	cin >> Strike;

	cout << "\nEnter spot (42)\n";
	cin >> Spot;

	cout << "\nEnter price (4.76)\n";
	cin >> Price;

	cout << "\nr (0.1)\n";
	cin >> r;

    cout << "\nd (0)\n";
    cin >> d;

    double low,high;

    cout << "\nlower guess (0.1)\n";
    cin >> low;

    cout << "\nhigh guess (0.3)\n";
    cin >> high;

    double tolerance;

    cout << "\nTolerance (0.00001)\n";
    cin >> tolerance;

    BSCall theCall(r,d,Expiry,Spot,Strike);

    double vol=Bisection(Price,low,high,tolerance,theCall);
    double PriceTwo = BlackScholesCall(Spot,Strike,r,d,vol,Expiry);

    cout << "\n vol " << vol << " pricetwo " << PriceTwo << "\n";

    double tmp;
    cin >> tmp;

	return 0;
}