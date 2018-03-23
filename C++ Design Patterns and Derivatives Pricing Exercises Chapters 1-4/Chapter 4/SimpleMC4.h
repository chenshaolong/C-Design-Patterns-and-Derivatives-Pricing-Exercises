// C++ Design Patterns and Derivatives Pricing---Listing 4.10, page 66

#ifndef SIMPLEMC4_H
#define SIMPLEMC4_H
#include "Vanilla2.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         const double Spot,
                         const double Vol,
                         const double r,
                         const unsigned long NumberOfPaths);

#endif