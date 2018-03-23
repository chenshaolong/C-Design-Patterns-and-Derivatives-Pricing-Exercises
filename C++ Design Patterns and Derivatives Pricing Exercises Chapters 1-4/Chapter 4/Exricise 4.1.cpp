// C++ Design Patterns and Derivatives Pricing---Exercise 4.1, page 83

/*
Exercise 4.1 Test how fast new is on your computer and compiler. 
Do this by using it to allocate an array of doubles, ten thousand times. 
See how the speed varies with array size. 
If you have more than one compiler see how they compare. 
Note that you can time things using the clock() function.
*/

// elapsed time with using new = 2.81269 seconds
// elapsed time without using new = 0.002399 seconds

#include <iostream>
#include <cstdio>
#include <ctime>
using namespace std;

int main(){
    int n = 1000000;
    int size = 1000;

    double time = clock();
    double * pointer;
    while (n-- > 0) {
        pointer = new double[size];

        for (int i = 0; i < size; i++)
            pointer[i] = i;

        delete[] pointer;
    }

    double time1 = clock() - time;

    while (n-- > 0) {
        double pointer[size];

        for (int i = 0; i < size; i++)
            pointer[i] = i;
    }

    double time2 = clock() - time1;

    // cout << "elapsed time with using new = " << time1 << " ticks\n";
    cout << "elapsed time with using new = " << time1/CLOCKS_PER_SEC << " seconds\n";

    // cout << "elapsed time without using new = " << time2 << " ticks\n";
    cout << "elapsed time without using new = " << time2/CLOCKS_PER_SEC << " seconds\n";

    cout << "Done.\n";
    return 0;

}
