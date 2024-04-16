/* 
    A car holds 16 gallons of gasoline and can travel 312 miles before refueling.
    Write a program that calculates the number of miles per gallon the car gets.
    Display the results on the screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare variables
    double gasTankSize = 16, milesTraveled = 312;
    double milesPerGallon = milesTraveled / gasTankSize;

    // Display results
    cout << "A car that travels " << milesTraveled << " miles on " << gasTankSize
         << " gallons of gas gets " << fixed <<  setprecision(2) << milesPerGallon 
         << " miles per gallon.";

    return 0;
         
}