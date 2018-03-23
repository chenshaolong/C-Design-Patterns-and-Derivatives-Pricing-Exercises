// C++ Design Patterns and Derivatives Pricing---Listing 4.3, page 58

#ifndef SIMPLEMC3_H
#define SIMPLEMC3_H
#include "Vanilla1.h"

double SimpleMonteCarlo3(const VanillaOption& TheOption,
                         const double Spot,
                         const double Vol,
                         const double r,
                         const unsigned long NumberOfPaths);

#endif