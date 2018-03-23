// C++ Design Patterns and Derivatives Pricing---Exercise 4.3, page 83
// Exercise 4.3 Implement a piecewise-constant parameters class.

#include <iostream>
#include "ParametersPWC.h"
#include "Arrays.h"
using namespace std;

int main()
{
	MJArray times(3);

	times[0] = 1.0;
	times[1] = 1.1;
	times[2] = 2.0;

	MJArray rates(3);

	rates[0] = 1.5;
	rates[1] = 2.1235;
	rates[2] = 3.15687;

	cout << "rates :" << endl;

	cout << "0, " << times[0] << ": " << rates[0] << endl;
	for (unsigned long i = 1; i < rates.size(); ++i)	
		cout << times[i - 1] << ", " << times[i] << ": " << rates[i] << endl;

	ParametersPWC my_param(times, rates);

	double time1 = 0.0;
	double time2 = 2.0;

	cout << "integral(" << time1 << ", " << time2 << ") : " <<
		my_param.Integral(time1, time2) << endl;

	cout << "integralSquare(" << time1 << ", " << time2 << ") : " <<
		my_param.IntegralSquare(time1, time2) << endl;

	cout << "Done.\n";
	return 0;
}