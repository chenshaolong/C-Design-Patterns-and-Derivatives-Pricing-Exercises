// C++ Design Patterns and Derivatives Pricing---Listing 1.1, page 20

/*
requires
    PayOff1.cpp
    Random1.cpp,
    SimpleMC.cpp,
*/
#include "SimpleMC.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    double time = clock();

    const double Expiry = 1.0;
    const double Strike = 100.0;
    const double Strike2 = 110.0;
    const double Spot = 100.0;
    const double Vol = 0.3;
    const double r = 0.06;
    const unsigned long NumberOfPaths = 100000000;
    cout << "Processing...\n";
    // cout << "Enter expiry: ";
    // cin >> Expiry;
    // cout << "Enter strike: ";
    // cin >> Strike;
    // cout << "Enter 2nd strike: ";
    // cin >> Strike2;
    // cout << "Enter spot: ";
    // cin >> Spot;
    // cout << "Enter vol: ";
    // cin >> Vol;
    // cout << "r: ";
    // cin >> r;
    // cout << "Number of paths: ";
    // cin >> NumberOfPaths;

    PayOff digitalCallPayOff(Strike, Strike2, PayOff::digital_call);
    PayOff digitalPutPayOff(Strike, Strike2, PayOff::digital_put);
    PayOff doubleDigitalCallPayOff(Strike, Strike2, PayOff::double_digital_call);
    PayOff doubleDigitalPutPayOff(Strike, Strike2, PayOff::double_digital_put);
    double digitalCall = SimpleMonteCarlo2(digitalCallPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double digitalPut = SimpleMonteCarlo2(digitalPutPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);

    double doubleDigitalCall = SimpleMonteCarlo2(doubleDigitalCallPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    double doubleDigitalPut = SimpleMonteCarlo2(doubleDigitalPutPayOff,
                                         Expiry,
                                         Spot,
                                         Vol,
                                         r,
                                         NumberOfPaths);


    cout <<"the prices are " 
        << digitalCall <<" for the digital call, and " 
        << digitalPut << " for the digital put, and "
        << doubleDigitalCall <<" for the double digital call, and " 
        << doubleDigitalPut << " for the double digital put.\n";

    time = clock() - time;
    cout << "elapsed time = " << time << " ticks\n";
    cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";
    cout << "Using const speeds code up a little bit.\n";
    cout << "Done.\n";
    return 0;
}