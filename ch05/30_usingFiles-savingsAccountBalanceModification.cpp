/*
Modify the Savings Account Balance program described in Programming Challenge 25 so that it writes 
the report to a file. After the program runs, print the file to hand in to your instructor.
*/

#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

int main() {
    double startingBalance, annualInterestRate, totalDeposits = 0, totalWithdrawals = 0, totalInterest = 0;

    // Prompt the user for the starting balance and annual interest rate
    cout << "Enter the starting balance: $";
    cin >> startingBalance;

    cout << "Enter the annual interest rate (as a percentage): ";
    cin >> annualInterestRate;

    // Convert annual interest rate to a decimal and calculate monthly interest rate
    double monthlyInterestRate = (annualInterestRate / 100) / 12;

    double balance = startingBalance;

    // Create an output file to write the report
    ofstream outFile("savings_report.txt");
    if (!outFile) {
        cout << "Error: Could not create report file." << endl;
        return 1;
    }

    // Write the header to the file
    outFile << fixed << setprecision(2);
    outFile << "SAVINGS ACCOUNT REPORT\n";
    outFile << "-----------------------\n";

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

    // Write the summary report to the file
    outFile << "Starting balance:    $" << startingBalance << endl;
    outFile << "Total deposits:      $" << totalDeposits << endl;
    outFile << "Total withdrawals:   $" << totalWithdrawals << endl;
    outFile << "Total interest:      $" << totalInterest << endl;
    outFile << "Final balance:       $" << balance << endl;

    // Close the file
    outFile.close();

    // Notify the user that the report has been written to the file
    cout << "Savings account report has been written to 'savings_report.txt'." << endl;

    return 0;
}

