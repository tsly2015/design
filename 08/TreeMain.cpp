// TreeMain.cpp

/*
Arrays.cpp
BinomialTree.cpp
BlackScholesFormulas.cpp
Normals.cpp
Parameters.cpp
PayOff3.cpp
PayOffBridge.cpp
PayOffForward.cpp
TreeAmerican.cpp
TreeEuropean.cpp
TreeMain.cpp
TreeProducts.cpp
*/

#include <BinomialTree.h>
#include <TreeAmerican.h>
#include <TreeEuropean.h>
#include <BlackScholesFormulas.h>
#include <PayOffForward.h>
#include <iostream>
using namespace std;
#include <cmath>
int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r;
    double d;
	unsigned long Steps;

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

    cout << "\nd (0.05)\n";
    cin >> d;

    cout << "\nNumber of steps\n";
	cin >> Steps;

    PayOffCall thePayOff(Strike);

    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    TreeEuropean europeanOption(Expiry,thePayOff);
    TreeAmerican americanOption(Expiry,thePayOff);

    SimpleBinomialTree theTree(Spot,rParam,dParam,Vol,Steps,Expiry);
    double euroPrice = theTree.GetThePrice(europeanOption);
    double americanPrice = theTree.GetThePrice(americanOption);
    cout << "euro price " << euroPrice << " amer price " << americanPrice << "\n";

    double BSPrice = BlackScholesCall(Spot,Strike,r,d,Vol,Expiry);
    cout << "BS formula euro price " << BSPrice << "\n";
    
    PayOffForward forwardPayOff(Strike);
    TreeEuropean forward(Expiry,forwardPayOff);

    double forwardPrice = theTree.GetThePrice(forward);
    cout << "forward price by tree " << forwardPrice << "\n";

    double actualForwardPrice = exp(-r*Expiry)*(Spot*exp((r-d)*Expiry)-Strike);
    cout << "forward price " << actualForwardPrice << "\n";

    Steps++; // now redo the trees with one more step
    SimpleBinomialTree theNewTree(Spot,rParam,dParam,Vol,Steps,Expiry);

    double euroNewPrice = theNewTree.GetThePrice(europeanOption);
    double americanNewPrice = theNewTree.GetThePrice(americanOption);

    cout << "euro new price " << euroNewPrice << " amer new price " << americanNewPrice << "\n";

    double forwardNewPrice = theNewTree.GetThePrice(forward);

    cout << "forward price by new tree " << forwardNewPrice << "\n";

    double averageEuro = 0.5*(euroPrice + euroNewPrice);
    double averageAmer = 0.5*(americanPrice + americanNewPrice);
    double averageForward = 0.5*(forwardPrice + forwardNewPrice);

    cout << "euro av price " << averageEuro << " amer av price " << averageAmer << "\n";
    cout << "av forward " << averageForward << "\n";

    double tmp;
    cin >> tmp;

	return 0;
}