// C++ Design Patterns and Derivatives Pricing---Listing 4.19, page 81

#ifndef SIMPLEMC6_H
#define SIMPLEMC6_H
#include "Vanilla3.h"
#include "Parameters.h"

double SimpleMonteCarlo4(const VanillaOption& TheOption,
                         const double Spot,
                         const Parameters& Vol,
                         const Parameters& r,
                         const unsigned long NumberOfPaths);

#endif