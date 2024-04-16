/*
  Assuming there are no deposits other than the original investment, the balance in a savings 
  account after one year may be calculated as

      Final Balance = Principal ( 1 + Rate / T)^T

    * where 'Principal' is the starting balance in the account
    * 'Rate' is the annual interest rate,
    * 'T' is the number of times the interest is compounded during a year (e.g., T is 4 if the 
      interest is compounded quarterly and 12 if it is compounded monthly).

  Write a program that asks for the principal, the annual interest rate, and the number of times 
  the interest is compounded. It should display a report similar to the following:

    Interest Rate:              4.25%
    Times Compounded:            12
    Principal:             $ 1000.00
    Interest:              $   43.33
    Final balance:         $ 1043.33
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Display welcome message and description
    cout << "Welcome to the Savings Account Calculator!" << endl;
    cout << "This program calculates the final balance in a savings account after one year." << endl;
    cout << "Let's get started!" << endl << endl;
    
    // Declare variables
    double principal, rate, finalBalance;
    int timesCompounded;
    
    // Get user input
    cout << "Enter the principal amount: $";
    cin >> principal;
    cout << "Enter the annual interest rate (in percentage): ";
    cin >> rate;
    cout << "Enter the number of times the interest is compounded: ";
    cin >> timesCompounded;
    
    // Convert rate to decimal and calculate final balance
    rate /= 100.0;
    finalBalance = principal * pow(1 + rate / timesCompounded, timesCompounded);
    
    // Calculate interest
    double interest = finalBalance - principal;
    
    // Display the report
    cout << fixed << setprecision(2);
    cout << "Interest Rate:     " << setw(10) << rate * 100 << "%" << endl;
    cout << "Times Compounded:  " << setw(10) << timesCompounded << endl;
    cout << "Principal:        $" << setw(10) << principal << endl;
    cout << "Interest:         $" << setw(10) << interest << endl;
    cout << "Final balance:    $" << setw(10) << finalBalance << endl;
    
    return 0;
}

