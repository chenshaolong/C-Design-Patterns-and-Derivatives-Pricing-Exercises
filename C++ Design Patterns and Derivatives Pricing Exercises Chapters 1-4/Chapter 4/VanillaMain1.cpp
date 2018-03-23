// C++ Design Patterns and Derivatives Pricing---Exercise 4.5, page 59

/*
requires
    DoubleDigital.cpp
    PayOff2.cpp
    Random1.cpp
    SimpleMC3.cpp
    Vanilla1.cpp
*/
#include "SimpleMC3.h"
#include "DoubleDigital.h"
#include "Vanilla1.h"
#include <iostream>
#include <ctime>
using namespace std;

int main() {
    srand(time(0));
    // double time = clock();

    double Expiry;
    double Low, Up;
    double Spot;
    double Vol;
    double r;
    unsigned long NumberOfPaths;

    cout << "Enter expiry: ";
    cin >> Expiry;
    cout << "Enter low barrier: ";
    cin >> Low;
    cout << "Enter up barrier: ";
    cin >> Up;
    cout << "Enter spot: ";
    cin >> Spot;
    cout << "Enter vol: ";
    cin >> Vol;
    cout << "r: ";
    cin >> r;
    cout << "Number of paths: ";
    cin >> NumberOfPaths;

    PayOffDoubleDigital thePayOff(Low, Up);

    VanillaOption theOption(thePayOff, Expiry);

    double result = SimpleMonteCarlo3(theOption,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    cout <<"the price is "  << result <<" \n"; 

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;
}