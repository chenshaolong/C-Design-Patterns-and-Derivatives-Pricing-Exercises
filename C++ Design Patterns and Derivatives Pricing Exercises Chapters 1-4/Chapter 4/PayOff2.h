// C++ Design Patterns and Derivatives Pricing---Listing 3.1, page 42

#ifndef PAYOFF2_H
#define PAYOFF2_H

class PayOff
{
public:
    PayOff() {};
    virtual double operator()(double Spot) const = 0;
    virtual ~PayOff() {}
private:
};

class PayOffCall : public PayOff
{
public:
	PayOffCall(double Strike_);
	virtual double operator()(double Spot) const;
	~PayOffCall() {}
private:
	double Strike; 
};

class PayOffPut : public PayOff
{
public:
	PayOffPut(double Strike_);
	virtual double operator()(double Spot) const;
	~PayOffPut() {}
private:
	double Strike;
};

#endif