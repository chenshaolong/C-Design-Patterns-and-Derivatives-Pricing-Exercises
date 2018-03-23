// C++ Design Patterns and Derivatives Pricing---Listing 3.4, page 48

/*
requires
    PayOff2.cpp
    Random1.cpp,
    SimpleMC2.cpp,
*/
#include "SimpleMC2.h"
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

    unsigned long optionType;
    cout << "Enter 0 for call, otherwise put: ";
    cin >> optionType;

    PayOff* thePayOffPtr;

    if (optionType == 0)
        thePayOffPtr = new PayOffCall(Strike);
    else
        thePayOffPtr = new PayOffPut(Strike);

    double result = SimpleMonteCarlo2(*thePayOffPtr,
                                          Expiry,
                                          Spot,
                                          Vol,
                                          r,
                                          NumberOfPaths);

    cout <<"the price is "  << result <<" \n"; 

    // time = clock() - time;
    // cout << "elapsed time = " << time << " ticks\n";
    // cout << "elapsed time = " << time/CLOCKS_PER_SEC << " seconds\n";

    delete thePayOffPtr;
    cout << "Done.\n";
    return 0;
}