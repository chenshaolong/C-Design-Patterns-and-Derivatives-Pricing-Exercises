// C++ Design Patterns and Derivatives Pricing---Listing 2.2, page 33

#include "PayOff1.h"
#include <algorithm>    // std::minmax

PayOff::PayOff(double Strike_, OptionType TheOptionsType_) : Strike(Strike_), TheOptionsType(TheOptionsType_) {}

double PayOff::operator()(double spot) const {
    switch (TheOptionsType) {
    case call :
        return std::max(spot-Strike,0.0);
    case put:
        return std::max(Strike-spot,0.0);
    default:
        throw("unknown option type found.");
    } 
}