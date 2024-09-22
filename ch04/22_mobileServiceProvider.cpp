/*
  A mobile phone service has three different data plans for its customers:

      Plan A:	For $39.99 per month, 2 gigabytes are provided. Additional usage costs $8.00 per gigabyte.
      Plan B:	For $59.99 per month, 8 gigabytes are provided. Additional usage costs $8.00 per gigabyte.
      Plan C:	For $79.99 per month, unlimited data is provided.
  
  Write a program that calculates a customer’s monthly bill. It should input the customer name, which plan 
  was purchased, and how many gigabytes were used. It should then create a bill that includes the input 
  information and the total amount due. It should also display how much money plan A customers would save 
  if they purchased plan B or C, and how much money plan B customers would save if they purchased plan C. 
  If there would be no savings, no message should be printed. Wherever possible, use named constants 
  instead of numbers.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Constants for the pricing
    const double PLAN_A_COST = 39.99;
    const double PLAN_B_COST = 59.99;
    const double PLAN_C_COST = 79.99;
    const int PLAN_A_LIMIT = 2; // 2GB
    const int PLAN_B_LIMIT = 8; // 8GB
    const double ADDITIONAL_COST_PER_GB = 8.00;

    string customerName;
    char plan;
    double gigabytesUsed, totalBill;

    // Input customer information
    cout << "Enter the customer name: ";
    getline(cin, customerName);
    cout << "Enter the plan purchased (A, B, or C): ";
    cin >> plan;
    cout << "Enter the number of gigabytes used: ";
    cin >> gigabytesUsed;

    // Calculate total bill based on the plan and usage
    switch (plan) {
        case 'A':
        case 'a':
            if (gigabytesUsed > PLAN_A_LIMIT) {
                totalBill = PLAN_A_COST + (gigabytesUsed - PLAN_A_LIMIT) * ADDITIONAL_COST_PER_GB;
            } else {
                totalBill = PLAN_A_COST;
            }
            break;
        case 'B':
        case 'b':
            if (gigabytesUsed > PLAN_B_LIMIT) {
                totalBill = PLAN_B_COST + (gigabytesUsed - PLAN_B_LIMIT) * ADDITIONAL_COST_PER_GB;
            } else {
                totalBill = PLAN_B_COST;
            }
            break;
        case 'C':
        case 'c':
            totalBill = PLAN_C_COST; // Unlimited data
            break;
        default:
            cout << "Invalid plan selected!" << endl;
            return 0;
    }

    // Display the bill
    cout << fixed << setprecision(2);
    cout << "\nBill for " << customerName << ":\n";
    cout << "Plan: " << plan << endl;
    cout << "Data used: " << gigabytesUsed << " GB\n";
    cout << "Total amount due: $" << totalBill << "\n";

    // Savings calculation
    if (plan == 'A' || plan == 'a') {
        double planBTotal, planCTotal;
        if (gigabytesUsed > PLAN_B_LIMIT) {
            planBTotal = PLAN_B_COST + (gigabytesUsed - PLAN_B_LIMIT) * ADDITIONAL_COST_PER_GB;
        } else {
            planBTotal = PLAN_B_COST;
        }
        planCTotal = PLAN_C_COST;

        if (planBTotal < totalBill) {
            cout << "You would save $" << totalBill - planBTotal << " if you switched to Plan B.\n";
        }
        if (planCTotal < totalBill) {
            cout << "You would save $" << totalBill - planCTotal << " if you switched to Plan C.\n";
        }
    } else if (plan == 'B' || plan == 'b') {
        double planCTotal = PLAN_C_COST;
        if (planCTotal < totalBill) {
            cout << "You would save $" << totalBill - planCTotal << " if you switched to Plan C.\n";
        }
    }

    return 0;
}

