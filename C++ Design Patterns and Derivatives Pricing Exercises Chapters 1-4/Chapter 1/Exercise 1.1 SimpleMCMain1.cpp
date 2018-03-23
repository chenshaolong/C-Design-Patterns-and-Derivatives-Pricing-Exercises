// C++ Design Patterns and Derivatives Pricing---Listing 1.1, page 20

#include "Random1.h"
#include <iostream>
#include <cmath>
#include <ctime>
using namespace std;

double SimpleMonteCarlo1(double Expiry, double Strike, double Spot, double Vol, double r, unsigned long NumberOfPaths, int type = call) {
    /* initialize random seed: */
    srand (time(NULL));

    double variance = Vol*Vol*Expiry;
    double rootVariance = sqrt(variance);
    double itoCorrection = -0.5*variance;
    double movedSpot = Spot*exp(r*Expiry +itoCorrection);
    double thisSpot;
    double runningSum=0;
    for (unsigned long i=0; i < NumberOfPaths; i++) {
        double thisGaussian = GetOneGaussianByBoxMuller();
        thisSpot = movedSpot*exp( rootVariance*thisGaussian);
        double thisPayoff = 0;
        switch (type) {
            case call: 
                thisPayoff = thisSpot - Strike;
                break;
            case put: 
                thisPayoff = Strike - thisSpot;
                break;
        }
        thisPayoff = thisPayoff > 0 ? thisPayoff : 0;
        runningSum += thisPayoff;
    }
    double mean = runningSum / NumberOfPaths;
    mean *= exp(-r*Expiry);
    return mean;
}

int main() {
    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    int type;
    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;
    cout << "option type call = 0, put = 1: ";
    cin >> type;
    double result = SimpleMonteCarlo1(Expiry, Strike, Spot, Vol, r, NumberOfPaths, type);
    switch (type) {
        case call: 
            cout << "the call option price is: " << result << "\n";
            break;
        case put: 
            cout << "the put option price is: " << result << "\n";
            break;
    }
    
    cout << "Done.\n";
    return 0; 
}