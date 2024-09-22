/*
Write a program that calculates how much a person earns in a month if the salary is 
one penny the first day, two pennies the second day, four pennies the third day, and 
so on with the daily pay doubling each day the employee works. The program should ask 
the user for the number of days the employee worked during the month, validate that 
it is between 1 and 31, and then display a table showing how much the salary was for 
each day worked, as well as the total pay earned for the month. The output should be 
displayed in dollars with two decimal points, not in pennies.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int daysWorked;
    double totalPay = 0.0, dailyPay = 0.01; // dailyPay starts at 1 penny (0.01 dollars)

    // Prompt user for input
    cout << "Enter the number of days worked (between 1 and 31): ";
    cin >> daysWorked;

    // Validate input
    while (daysWorked < 1 || daysWorked > 31) {
        cout << "Invalid input! Please enter a number between 1 and 31: ";
        cin >> daysWorked;
    }

    // Display table headers
    cout << "Day\t\tSalary for the Day\n";
    cout << "-----------------------------------------\n";

    // Loop through each day and calculate the salary
    for (int day = 1; day <= daysWorked; day++) {
        // Display the salary for each day
        cout << setw(10) << left << day << fixed << setw(9) << right << "$" << setprecision(2) << dailyPay << endl;

        // Add the daily pay to the total pay
        totalPay += dailyPay;

        // Double the pay for the next day
        dailyPay *= 2;
    }

    // Display the total pay for the month
    cout << "\nTotal pay for " << daysWorked << " days is: $" << totalPay << endl;

    return 0;
}

