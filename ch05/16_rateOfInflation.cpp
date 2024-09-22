/*
The annual rate of inflation is the rate at which money loses its value. 

For example, if the annual rate of inflation is 3.0 percent, then in one year it will cost $1,030 
to buy the goods that could have been purchased for $1,000 today. Put another way, a year from now 
$1,000 will only buy 1/1.03 * $1,000, or $970.87, worth of goods. Two years from now, $1,000 will 
only buy only 1/1.03 of $970.87, or $942.59 worth of goods. Write a program that allows the user to 
enter an annual rate of inflation between 1 percent and 10 percent, and which then displays a table 
showing how much $1,000 today will be worth each year for the next 10 years.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double inflationRate, currentValue = 1000.0;

    // Prompt for annual rate of inflation (between 1% and 10%)
    cout << "Enter the annual rate of inflation (between 1% and 10%): ";
    cin >> inflationRate;

    // Validate input
    while (inflationRate < 1.0 || inflationRate > 10.0) {
        cout << "Invalid input! Please enter a rate between 1% and 10%: ";
        cin >> inflationRate;
    }

    // Convert inflation rate from percentage to a multiplier (e.g., 3% becomes 1.03)
    inflationRate = 1 + (inflationRate / 100);

    // Display table headers
    cout << "\nYear   Value of $1,000\n";
    cout << "---------------------\n";

    // Loop through 10 years to display the decreasing value of $1,000
    for (int year = 1; year <= 10; year++) {
        // Calculate the value after the current year
        currentValue /= inflationRate;

        // Display the year and current value of $1,000
        cout << setw(4) << year << "     $" << fixed << setprecision(2) << currentValue << endl;
    }

    return 0;
}

