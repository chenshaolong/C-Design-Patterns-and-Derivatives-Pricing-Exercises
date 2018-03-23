// C++ Design Patterns and Derivatives Pricing---Listing 4.10, page 66

#ifndef SIMPLEMC5_H
#define SIMPLEMC5_H
#include "Vanilla3.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         const double Spot,
                         const double Vol,
                         const double r,
                         const unsigned long NumberOfPaths);

#endif