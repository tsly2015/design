// RandomMain2.cpp

/*
AntiThetic.cpp
Arrays.cpp
ConvergenceTable.cpp
MCStatistics.cpp
Normals.cpp
Parameters.cpp
PayOff3.cpp
PayOffBridge.cpp
Random2.cpp
Random3.cpp
SimpleMC8.cpp
Vanilla3.cpp
*/

#include<SimpleMC8.h>
#include<Random3.h>
#include<iostream>
using namespace std;
#include<Vanilla3.h>
#include<MCStatistics.h>
#include<ConvergenceTable.h>
#include<AntiThetic.h>

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

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

   
    RandomRand generator(1);

    MJArray variates(1);
    
    AntiThetic GenTwo(generator);

	SimpleMonteCarlo6(theOption,
                                      Spot, 
                                      VolParam,
                                      rParam,
                                      NumberOfPaths,
                                      gathererTwo,
                                      GenTwo);

    vector<vector<double> > results =gathererTwo.GetResultsSoFar();


	cout <<"\nFor the call price (4.76) the results are \n";
  
    {
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }}

    ConvergenceTable gathererThree(gatherer);

	SimpleMonteCarlo6(theOption,
                                      Spot, 
                                      VolParam,
                                      rParam,
                                      NumberOfPaths,
                                      gathererTwo,
                                      GenTwo);

    vector<vector<double> > resultsExtra =gathererTwo.GetResultsSoFar();
	cout <<"\nFor the call price (4.76) the results are \n";

    for (unsigned long i=0; i < resultsExtra.size(); i++)
    {
        for (unsigned long j=0; j < resultsExtra[i].size(); j++)
            cout << resultsExtra[i][j] << " ";

        cout << "\n";
    }
    
    double tmp;
    cin >> tmp;

	return 0;

}