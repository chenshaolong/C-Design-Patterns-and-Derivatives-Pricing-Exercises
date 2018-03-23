// C++ Design Patterns and Derivatives Pricing---Exercise 3.1, page 55

/*
requires
    PowerOption.cpp
    PayOff2.cpp
    Random1.cpp
    SimpleMC2.cpp
*/
#include "SimpleMC2.h"
#include "PowerOption.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // double time = clock();

    double Expiry;
    double Strike;
    int Power;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter Strike: ";
    cin >> Strike;
    cout << "Enter Power: ";
    cin >> Power;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    PayOffPowerCall callPayOff(Strike, Power);

    double callResult = SimpleMonteCarlo2(callPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    cout <<"the power call option price is "  << callResult <<" \n"; 

    PayOffPowerPut putPayOff(Strike, Power);

    double putResult = SimpleMonteCarlo2(putPayOff,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    cout <<"the power put option price is "  << putResult <<" \n"; 

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}