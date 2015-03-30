// SimpleMC2.h

#ifndef SIMPLEMC_H
#define SIMPLEMC_H

#include <PayOff2.h> //the only difference from SimpleMC.h

double SimpleMonteCarlo2(const PayOff& thePayOff, 
                         double Expiry, 
						 double Spot,
						 double Vol, 
						 double r, 
						 unsigned long NumberOfPaths);


#endif