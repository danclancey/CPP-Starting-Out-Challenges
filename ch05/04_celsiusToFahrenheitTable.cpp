/*
In one of the Chapter 3 Programming Challenges you were asked to write a program 
that converts a Celsius temperature to Fahrenheit. Modify that program so it uses 
a loop to display a table of the Celsius temperatures from 0 to 30 and their 
Fahrenheit equivalents.

F = 9/5C + 32 
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main () {
    // Print column headers
    cout << left << setw(15) << "Celsius" << right << " Fahrenheit\n";
    cout << "-------------------------\n";

    for (int c = 0; c <= 30; c++) {
        double fahrenheit;

        // Calculate fahrenheit 
        fahrenheit = 1.8 * c + 32;

        // Display table of Celcius and Fahrenheit
        cout << left << setw(15) << c << right << setw(10)
             << fixed << setprecision(1) << fahrenheit << endl;
    }

    return 0;
}
