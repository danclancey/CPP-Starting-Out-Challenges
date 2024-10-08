/* 
Suppose you have a certain amount of money in a savings account that earns compound monthly interest, and 
you want to calculate the amount that you will have after a specific number of months. The formula, which 
is known as the future value formula, is:

F = P * (1 + i)^t

The variables in the formula are as follows:
    - F is the future value of the account after the specified time period.
    - P is the present value of the account.
    - i is the monthly interest rate.
    - t is the number of months.

Write a program that prompts the user to enter the account’s present value, monthly interest rate, and number 
of months that the money will be left in the account. The program should pass these values to a function named 
futureValue that computes and returns the future value of the account after the specified number of months. 
The program should display the account’s future value.
*/

#include <iostream>
#include <iomanip>
#include <cmath> // For the pow function

using namespace std;

// Function prototype
double futureValue(double presentValue, double monthlyRate, int months);

int main() {
    double presentValue, monthlyRate;
    int months;

    // Get user input for the present value, monthly interest rate, and number of months
    cout << "Enter the account's present value: $";
    cin >> presentValue;

    cout << "Enter the monthly interest rate (as a percentage, e.g., 0.5 for 0.5%): ";
    cin >> monthlyRate;

    cout << "Enter the number of months the money will be left in the account: ";
    cin >> months;

    // Convert the monthly interest rate from a percentage to a decimal
    double decimalRate = monthlyRate / 100;

    // Calculate the future value
    double accountFutureValue = futureValue(presentValue, decimalRate, months);

    // Display the result
    cout << fixed << setprecision(2);
    cout << "\nAfter " << months << " months, the account's future value will be: $" 
         << accountFutureValue << endl;

    return 0;
}

// Function to calculate the future value of the account
double futureValue(double presentValue, double monthlyRate, int months) {
    return presentValue * pow(1 + monthlyRate, months);
}

