// SolveMain2.cpp

/*
BlackScholesFormulas.cpp
BSCallTwo.cpp
Normals.cpp
*/

#include <NewtonRaphson.h>
#include <cmath>
#include <iostream>
#include <BSCallTwo.h>
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
   
    double start;

    cout << "\nstart guess (0.1)\n";
    cin >> start;

    double tolerance;

    cout << "\nTolerance (0.00001)\n";
    cin >> tolerance;

    BSCallTwo theCall(r,d,Expiry,Spot,Strike);

    double vol=NewtonRaphson<BSCallTwo, &BSCallTwo::Price, &BSCallTwo::Vega>(Price,
                                                                           start,
                                                                           tolerance,
                                                                           theCall);

    double PriceTwo = BlackScholesCall(Spot,Strike,r,d,vol,Expiry);

    cout << "\n vol " << vol << " \nprice two:" << PriceTwo << "\n";

    double tmp;
    cin >> tmp;

	return 0;
}
