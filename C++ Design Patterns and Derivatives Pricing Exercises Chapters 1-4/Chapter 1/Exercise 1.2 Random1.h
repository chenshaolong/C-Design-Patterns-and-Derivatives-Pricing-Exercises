// C++ Design Patterns and Derivatives Pricing---Listing 1.2, page 22

#ifndef RANDOM1_H
#define RANDOM1_H

double GetOneGaussianBySummation();
double GetOneGaussianByBoxMuller();

// create named constants for option type: call = 0, put = 1, double digital = 2
enum option {call, put, double_digital};

#endif 