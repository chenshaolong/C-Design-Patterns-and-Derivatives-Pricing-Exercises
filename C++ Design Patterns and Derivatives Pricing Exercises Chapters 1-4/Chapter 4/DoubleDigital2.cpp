// C++ Design Patterns and Derivatives Pricing---Listing 3.6, page 53

#include "DoubleDigital2.h"

PayOffDoubleDigital::PayOffDoubleDigital(double LowerLevel_, double UpperLevel_) : LowerLevel(LowerLevel_), UpperLevel(UpperLevel_) {}

double PayOffDoubleDigital::operator()(double Spot) const
{
	if (Spot <= LowerLevel || Spot >= UpperLevel)
		return 0;
	else
		return 1;
}

PayOff* PayOffDoubleDigital::clone() const
{
	return new PayOffDoubleDigital(*this);
}