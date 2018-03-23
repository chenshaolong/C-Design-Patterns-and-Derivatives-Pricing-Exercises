// C++ Design Patterns and Derivatives Pricing---Listing 3.5, page 52

#ifndef DOUBLEDIGITAL2_H
#define DOUBLEDIGITAL2_H
#include "PayOff3.h"

class PayOffDoubleDigital : public PayOff
{
public:
    PayOffDoubleDigital(double LowerLevel_, double UpperLevel_);
    virtual double operator()(double Spot) const;
    virtual ~PayOffDoubleDigital() {}
    virtual PayOff* clone() const;
private:
	double LowerLevel;
	double UpperLevel;
};

#endif