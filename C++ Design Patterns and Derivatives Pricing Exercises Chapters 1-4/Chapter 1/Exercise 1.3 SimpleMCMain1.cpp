// C++ Design Patterns and Derivatives Pricing---Listing 1.1, page 20

#include "Random1.h"
#include <iostream>
#include <cmath>
#include <ctime>
#include <string>
#include <sstream>

using namespace std;

double SimpleMonteCarlo1(double Expiry, double Strike, double Strike2, double Spot, double Vol, double r, unsigned long NumberOfPaths, int type) {
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
            case double_digital:
                if ((thisSpot - Strike) * (thisSpot - Strike2) <= 0)
                    thisPayoff = 1;
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
    double Strike, Strike2;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    int type;
    char whitespace;
    string input;
    cout << "Enter expiry, strike, spot, vol, r, number of paths, type in form of a string separated by comma:\n";
    cin >> input;
    istringstream iss(input);
    iss >> Expiry >> whitespace
        >> Strike >> whitespace
        >> Spot >> whitespace 
        >> Vol >> whitespace 
        >> r >> whitespace 
        >> NumberOfPaths >> whitespace
        >> type;
    cout << "expiry = " << Expiry << endl;
    cout << "strike = " << Strike << endl;
    cout << "spot = " << Spot << endl;
    cout << "vol = " << Vol << endl;
    cout << "r = " << r << endl;
    cout << "number of paths = " << NumberOfPaths << endl;
    cout << "type = " << type << endl;
    if (type == 2) {
        cout << "Enter 2nd strike: ";
        cin >> Strike2;
    }
    double result = SimpleMonteCarlo1(Expiry, Strike, Strike2, Spot, Vol, r, NumberOfPaths, type);
    switch (type) {
        case call: 
            cout << "the call option price is: " << result << "\n";
            break;
        case put: 
            cout << "the put option price is: " << result << "\n";
            break;
        case double_digital:
            cout << "the double digital option price is: " << result << "\n";
    }
    
    cout << "Done.\n";
    return 0; 
}