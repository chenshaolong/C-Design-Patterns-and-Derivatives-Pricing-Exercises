// C++ Design Patterns and Derivatives Pricing---Listing 2.3, page 34

#ifndef SIMPLEMC_H
#define SIMPLEMC_H
#include "PayOff1.h"

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         double Expiry,
                         double Spot,
                         double Vol,
                         double r,
                         unsigned long NumberOfPaths);

#endif