/*
Write a program that displays a table of speeds in kilometers per hour (kph) with their 
values converted to miles per hour (mph). The table should display the speeds from 40 
kilometers per hour through 120 kilometers per hour, in increments of 10 kilometers per 
hour. In other words, it should display 40 kph, 50 kph, 60 kph and so forth, up through 
120 kph.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // Print column headers
    cout << "KPH" << setw(14) << right << "MPH\n";
    cout << "----------------\n";

    for (int k = 40; k <= 120; k+= 10) {
        // Calculate mph
        double mph  = k / 1.609344;
        
        // Display table of values
        cout << setw(11) << left << k << right << fixed 
             << setprecision(2) << mph << endl;
    }
}
