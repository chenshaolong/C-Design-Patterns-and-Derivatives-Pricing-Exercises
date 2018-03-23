// C++ Design Patterns and Derivatives Pricing---Listing 3.6, page 53

#include "PowerOption.h"
#include <cmath>
#include <algorithm>

PayOffPowerCall::PayOffPowerCall(double Strike_, double Power_) : Strike(Strike_), Power(Power_) {}

double PayOffPowerCall::operator()(double Spot) const
{
	return std::max(pow(Spot, Power) - Strike, 0.0);
}

PayOffPowerPut::PayOffPowerPut(double Strike_, double Power_) : Strike(Strike_), Power(Power_) {}

double PayOffPowerPut::operator()(double Spot) const
{
	return std::max(Strike - pow(Spot, Power), 0.0);
}