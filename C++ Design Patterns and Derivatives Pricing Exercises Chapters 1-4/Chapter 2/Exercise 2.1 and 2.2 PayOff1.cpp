// C++ Design Patterns and Derivatives Pricing---Listing 2.2, page 33

#include "PayOff1.h"
#include <algorithm>    // std::minmax

PayOff::PayOff(double Strike_, double Strike2_, OptionType TheOptionsType_) : Strike(Strike_), Strike2(Strike2_), TheOptionsType(TheOptionsType_) {}

double PayOff::operator()(double spot) const {
    switch (TheOptionsType) {
    case call :
        return std::max(spot-Strike, 0.0);
    case put:
        return std::max(Strike-spot,0.0);
    case digital_call:
    	return spot >= Strike ? 1 : 0;
    case digital_put:
    	return spot <= Strike ? 1 : 0;
    case double_digital_call:
    	return (spot - Strike) * (spot - Strike2) <= 0 ? 1 : 0;
    case double_digital_put:
    	return (spot - Strike) * (spot - Strike2) <= 0 ? 1 : 0;
    default:
        throw("unknown option type found.");
    } 
}