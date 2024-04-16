/*
  The monthly payment on a loan may be calculated by the following formula:

                   Rate * (1 + Rate)^N
        Payment = --------------------- * L
                    (1 + Rate)^N - 1


    * 'Rate' is the monthly interest rate, which is the annual interest rate divided by 12. 
      (A 12 percent annual interest would be 1 percent monthly interest.)
    * N is the number of payments
    * L is the amount of the loan.

  Write a program that asks for these values and displays a report similar to the following:

    Loan Amount:              $ 10000.00
    Monthly Interest Rate:            1%
    Number of Payments:               36
    Monthly Payment:          $   332.14
    Amount Paid Back:         $ 11957.15
    Interest Paid:            $  1957.15
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main() {
    // Display welcome message and description
    cout << "Welcome to the Loan Payment Calculator!" << endl;
    cout << "This program calculates the monthly payment on a loan and other related information." << endl;
    cout << "Let's get started!" << endl << endl;
    
    // Declare variables
    double loanAmount, rate, monthlyRate, monthlyPayment, amountPaidBack, interestPaid;
    int numPayments;
    
    // Get user input
    cout << "Enter the loan amount: $";
    cin >> loanAmount;
    cout << "Enter the annual interest rate (in percentage): ";
    cin >> rate;
    cout << "Enter the number of payments: ";
    cin >> numPayments;
    
    // Convert rate to monthly rate
    rate /= 100.0;
    monthlyRate = rate / 12.0;
    
    // Calculate monthly payment
    monthlyPayment = (monthlyRate * pow(1 + monthlyRate, numPayments)) / (pow(1 + monthlyRate, numPayments) - 1) * loanAmount;
    
    // Calculate amount paid back and interest paid
    amountPaidBack = monthlyPayment * numPayments;
    interestPaid = amountPaidBack - loanAmount;
    
    // Display the report
    cout << fixed << setprecision(2);
    cout << setw(20) << left << "Loan Amount: " << setw(10) << right << "$" << loanAmount << endl;
    cout << setw(20) << left << "Monthly Interest Rate: " << setw(10) << right << rate * 100 / 12 << "%" << endl;
    cout << setw(20) << left << "Number of Payments: " << setw(11) << right << numPayments << endl;
    cout << setw(20) << left << "Monthly Payment: " << setw(10) << right << "$" << monthlyPayment << endl;
    cout << setw(20) << left << "Amount Paid Back: " << setw(10) << right << "$" << amountPaidBack << endl;
    cout << setw(20) << left << "Interest Paid: " << setw(10) << right << "$" << interestPaid << endl;
    
    return 0;
}

