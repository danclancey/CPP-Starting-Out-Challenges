/*
The formula for converting a temperature from Fahrenheit to Celsius is

 C = 5/9(F - 32)

where  is the Fahrenheit temperature and  is the Celsius temperature. 
Write a function named celsius that accepts a Fahrenheit temperature as an argument and returns the 
temperature converted to Celsius. Demonstrate the function by calling it in a loop that displays 
a table of every fifth Fahrenheit temperature from 0 through 100 and its Celsius equivalent.
*/

#include <iostream>
#include <iomanip>

using namespace std;

double celsius(double);

int main() {
    // Print column headers    
    cout << "Fahrenheit\tCelsius\n";
    cout << "----------------------------\n";

    // Loop through 0F - 100F in 5 degree increments
    // Calling celsius to convert i to celsius
    for (int i = 0; i <=100; i+=5) {
        cout << i << " F\t\t" << fixed << setprecision(1) << celsius(i) << " C" << endl;
    }
}

double celsius (double fTemp) {
    // Return Fahrenheit temp
    return (5.0/9.0) * (fTemp  - 32);
}
