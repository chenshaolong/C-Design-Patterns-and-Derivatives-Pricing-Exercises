// C++ Design Patterns and Derivatives Pricing---Listing 2.4, page 34

#include "SimpleMC.h"
#include "Random1.h"
#include <cmath>
// the basic math functions should be in
// namespace std but aren’t in VCPP6
#if !defined(_MSC_VER)
using namespace std;
#endif

double SimpleMonteCarlo2(const PayOff& thePayOff,
                         const double Expiry,
                         const double Spot,
                         const double Vol,
                         const double r,
                         const unsigned long NumberOfPaths) {
    const double variance = Vol*Vol*Expiry;
    const double rootVariance = sqrt(variance);
    const double itoCorrection = -0.5*variance;
    const double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum=0;
    for (unsigned long i=0; i < NumberOfPaths; i++)
    {
      double thisGaussian = GetOneGaussianByBoxMuller();
      thisSpot = movedSpot*exp( rootVariance*thisGaussian);
      double thisPayOff = thePayOff(thisSpot);
      runningSum += thisPayOff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}
