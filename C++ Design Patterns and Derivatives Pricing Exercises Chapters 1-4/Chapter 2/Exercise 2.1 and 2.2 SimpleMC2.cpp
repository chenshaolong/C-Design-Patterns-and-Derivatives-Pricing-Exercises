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
    double Expiry;
    double Strike, Strike2;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;
    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter strike: ";
    cin >> Strike;
    cout << "Enter 2nd strike: ";
    cin >> Strike2;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

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

    cout << "Done.\n";
    return 0;
}