// C++ Design Patterns and Derivatives Pricing---Exercise 4.12, page 67

/*
requires
    PayOff3.cpp
    PayOffBridge.cpp
    Random1.cpp
    SimpleMC5.cpp
    Vanilla3.cpp
*/
#include "SimpleMC5.h"
#include "Vanilla3.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // double time = clock();

    double Expiry;
    double Strike;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter Strike: ";
    cin >> Strike;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    PayOffCall thePayOff(Strike);

    VanillaOption theOption(thePayOff, Expiry);
    // VanillaOption(const PayOffBridge& ThePayOff_, double Expiry_);
    // PayOffBridge(const PayOff& innerPayOff);
    // PayOff& PayOffCall::thePayOff -> PayOffBridge

    double result = SimpleMonteCarlo3(theOption,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    cout <<"the call price is "  << result <<" \n"; 

    VanillaOption secondOption(theOption);

    result = SimpleMonteCarlo3(secondOption,
                               Spot,
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"the call price is "  << result <<" \n"; 

    PayOffPut otherPayOff(Strike);
    VanillaOption thirdOption(otherPayOff, Expiry);
    theOption = thirdOption;

    result = SimpleMonteCarlo3(theOption,
                               Spot,
                               Vol,
                               r,
                               NumberOfPaths);

    cout <<"the put price is "  << result <<" \n"; 

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}