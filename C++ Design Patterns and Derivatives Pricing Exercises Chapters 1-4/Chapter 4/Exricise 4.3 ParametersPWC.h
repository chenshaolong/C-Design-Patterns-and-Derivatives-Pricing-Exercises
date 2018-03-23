// C++ Design Patterns and Derivatives Pricing---Exercise 4.3, page 83
// Exercise 4.3 Implement a piecewise-constant parameters class.

#include "Parameters.h"
#include "Arrays.h"
using namespace std;

#ifndef PARAMETERS_PWC_H
#define PARAMETERS_PWC_H

class ParametersPWC : public ParametersInner
{
public:
  	ParametersPWC(const MJArray& times_, const MJArray& constant_);

  	virtual ParametersInner* clone() const;
  	virtual double Integral(double time1, double time2) const;
  	virtual double IntegralSquare(double time1, double time2) const;
private:
	MJArray Times;
  	MJArray Constant;
  	MJArray K1;
  	MJArray K2;
};

#endif
