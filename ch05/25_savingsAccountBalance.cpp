/*
Write a program that calculates the balance of a savings account at the end of a three-month period. 
It should ask the user for the starting balance and the annual interest rate. A loop should then 
iterate once for every month in the period, performing the following steps:

        A. Ask the user for the total amount deposited into the account during that month and add 
           it to the balance. Do not accept negative numbers.

        B. Ask the user for the total amount withdrawn from the account during that month and 
           subtract it from the balance. Do not accept negative numbers or numbers greater than the 
           balance after the deposits for the month have been added in.

        C. Calculate the interest for that month. The monthly interest rate is the annual interest 
           rate divided by 12. Multiply the monthly interest rate by the average of that month’s 
           starting and ending balance to get the interest amount for the month. This amount should 
           be added to the balance.

After the last iteration, the program should display a nicely formatted report that includes the 
starting balance, total deposits, total withdrawals, total interest, and final balance.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    double startingBalance, annualInterestRate, totalDeposits = 0, totalWithdrawals = 0, totalInterest = 0;

    // Prompt for the starting balance and annual interest rate
    cout << "Enter the starting balance: $";
    cin >> startingBalance;

    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annualInterestRate;

    // Convert annual interest rate to decimal and calcu monthly interest rate
    double monthlyInterestRate = (annualInterestRate / 100) / 12;
    
    double balance = startingBalance;

    // Loop for 3 months
    for (int month = 1; month <= 3; month++) {
        double deposit, withdrawal, startingMonthBalance = balance;

        // Ask for deposits and validate input
        do {
            cout << "Enter total deposits for month " << month << ": $";
            cin >> deposit;
            if (deposit < 0) {
                cout << "Deposits cannot be negative. Please enter again.\n";
            }
        } while (deposit < 0);

        balance += deposit;
        totalDeposits += deposit;

        // Ask for withdrawals and validate input
        do {
            cout << "Enter total withdrawals for month " << month << ": $";
            cin >> withdrawal;
            if (withdrawal < 0) {
                cout << "Withdrawals cannot be negative. Please enter again.\n";
            } else if (withdrawal > balance) {
                cout << "Withdrawals cannot be greater than the current balance. Please enter again.\n";
            }
        } while (withdrawal < 0 || withdrawal > balance);

        balance -= withdrawal;
        totalWithdrawals += withdrawal;

        // Calculate interest for the month
        double averageBalance = (startingMonthBalance + balance) / 2;
        double monthlyInterest = averageBalance * monthlyInterestRate;
        balance += monthlyInterest;
        totalInterest += monthlyInterest;
    }

    // Display the report
    cout << fixed << setprecision(2);
    cout << "\nSAVINGS ACCOUNT SUMMARY\n";
    cout << "-----------------------\n";
    cout << "Starting balance:    $" << startingBalance << endl;
    cout << "Total deposits:      $" << totalDeposits << endl;
    cout << "Total withdrawals:   $" << totalWithdrawals << endl;
    cout << "Total interest:      $" << totalInterest << endl;
    cout << "Final balance:       $" << balance << endl;

    return 0;
}

