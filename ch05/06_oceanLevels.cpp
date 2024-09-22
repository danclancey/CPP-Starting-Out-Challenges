/*
Assuming the level of the Earth’s oceans continues rising at about 3.1 millimeters per year, 
write a program that displays a table showing the cumulative (i.e., total) number of 
millimeters the oceans will have risen each year for the next 25 years.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main() {

    double totalRise = 0.0;
    const double RISE_PER_YEAR = 3.1;

    // Display table heading
    cout << "  Year    Cumulative Ocean Rise (mm)\n";
    cout << "------------------------------------\n";
    cout << fixed << setprecision(1);

    for (int year = 1; year <= 25; year++)
        {
            // Calculate and display ocean rise
            totalRise += RISE_PER_YEAR;
            cout << setw(4) << year
                 << setw(20) << totalRise << " mm \n";
        }
    return 0;
}
