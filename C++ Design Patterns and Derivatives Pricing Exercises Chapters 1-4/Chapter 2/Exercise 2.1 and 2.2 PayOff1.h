// C++ Design Patterns and Derivatives Pricing---Listing 2.1, page 31

#ifndef PAYOFF_H
#define PAYOFF_H

class PayOff
{
public:
    enum  OptionType {call, put, digital_call, digital_put, double_digital_call, double_digital_put};
    PayOff(double Strike_, double Strike2_, OptionType TheOptionsType_);
    double operator()(double Spot) const;
private:
    double Strike;
    double Strike2;
    OptionType TheOptionsType;
};

#endif