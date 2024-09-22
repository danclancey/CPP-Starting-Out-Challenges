/*
If moderately active persons cut their calorie intake by 500 calories a day, 
they can typically lose about 4 pounds a month. Write a program that has the 
users enter their starting weight and then creates and displays a table 
showing what their expected weight will be at the end of each month for the 
next 6 months if they stay on this diet.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    // const variable for weight loss at 500cal deficit
    const int WEIGHT_LOSS_PER_MONTH = 4;
    double userWeight;

    // Prompt user for weight
    cout << "Please enter your current weight (in pounds): ";
    cin >> userWeight;

    // Print column headers
    cout << setw(7) << left << "Month" << setw(9) << right << "Weight\n";
    cout << "-----------------\n";

    for (int i = 1; i <= 6; i++) {
        // Calculate weight at end of each month and display table
        userWeight -= WEIGHT_LOSS_PER_MONTH;
        cout << setw(7) << left << i << setw(6) << right 
             << fixed << setprecision(1) << userWeight << " lbs\n";
    }

    return 0;
}
