// C++ Design Patterns and Derivatives Pricing---Listing 3.2, page 43

#include "PayOff2.h"
#include <algorithm>    // std::minmax

PayOffCall::PayOffCall(double Strike_) : Strike(Strike_) {}
PayOffPut::PayOffPut(double Strike_) : Strike(Strike_) {}

double PayOffCall::operator()(double Spot) const
{
    return std::max(Spot - Strike, 0.0);
}

double PayOffPut::operator()(double Spot) const
{
    return std::max(Strike - Spot, 0.0);
}