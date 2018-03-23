// C++ Design Patterns and Derivatives Pricing---Listing 3.7, page 53

/*
requires
    DoubleDigital.cpp
    PayOff2.cpp
    Random1.cpp
    SimpleMC2.cpp
*/
#include "SimpleMC2.h"
#include "DoubleDigital.h"
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

    double result = SimpleMonteCarlo2(thePayOff,
                                          Expiry,
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