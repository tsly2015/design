// EquityFXMain.cpp

/*
AntiThetic.cpp
Arrays.cpp
ConvergenceTable.cpp
ExoticBSEngine.cpp
ExoticEngine
MCStatistics.cpp
Normals.cpp
Parameters.cpp
ParkMiller.cpp
PathDependent.cpp
PathDependentAsian.cpp
PayOff3.cpp
PayOffBridge.cpp
Random2.cpp
*/

#include<ParkMiller.h>
#include<iostream>
using namespace std;
#include<MCStatistics.h>
#include<ConvergenceTable.h>
#include<AntiThetic.h>
#include<PathDependentAsian.h>
#include<ExoticBSEngine.h>
int main()
{

	double Expiry;
	double Strike; 
	double Spot; 
	double Vol; 
	double r;
    double d;
	unsigned long NumberOfPaths;
    unsigned NumberOfDates;

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

    cout << "Number of dates (480)\n";
    cin >> NumberOfDates;

	cout << "\nNumber of paths\n";
	cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);


    MJArray times(NumberOfDates);

    for (unsigned long i=0; i < NumberOfDates; i++)
        times[i] = (i+1.0)*Expiry/NumberOfDates;

    ParametersConstant VolParam(Vol);
    ParametersConstant rParam(r);
    ParametersConstant dParam(d);

    PathDependentAsian theOption(times, Expiry, thePayOff);

    StatisticsMean gatherer;
    ConvergenceTable gathererTwo(gatherer);

   
    RandomParkMiller generator(NumberOfDates);
    
    AntiThetic GenTwo(generator);

    ExoticBSEngine theEngine(theOption, rParam, dParam, VolParam, GenTwo, Spot);

    theEngine.DoSimulation(gathererTwo, NumberOfPaths);

    vector<vector<double> > results =gathererTwo.GetResultsSoFar();


	cout <<"\nFor the Asian call price the results are \n";
  
    {
    for (unsigned long i=0; i < results.size(); i++)
    {
        for (unsigned long j=0; j < results[i].size(); j++)
            cout << results[i][j] << " ";

        cout << "\n";
    }}

    double tmp;
    cin >> tmp;

	return 0;

}
