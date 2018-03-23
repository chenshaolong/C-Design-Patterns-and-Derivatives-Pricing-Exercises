// C++ Design Patterns and Derivatives Pricing---Listing 3.1, page 42

#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
public:
    PayOff() {};
    virtual double operator()(double Spot) const = 0; // pure virtual method
    virtual ~PayOff() {} // the the destructor has to be virtual if a pure virtual method is declared
private:
};

class PayOffCall : public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffCall() {}
private:
	double Strike; 
};

class PayOffPut : public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	virtual ~PayOffPut() {}
private:
	double Strike;
};

#endif