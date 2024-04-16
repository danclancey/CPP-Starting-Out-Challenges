/*
    Write a program that computes the taxa nd tip on a restaurant bill for a patron 
    with a $44.50 meal charge. The tax should be 6.75 percent of the meal cost. The
    tip should be 15 percent of the total after adding the tax. 
    Display the meal cost, tax amount, tip amount, and total bill on the screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare variables
    double mealCost = 44.50, taxAmt = 0.0675, tipAmt = 0.15;
    double totalTip, totalTax, totalBill;

    // Calculate Total Tax
    totalTax = mealCost * taxAmt;

    // Calculate Total Tip
    totalTip = (mealCost + totalTax) * tipAmt;

    // Calculate Total Bill
    totalBill = mealCost + totalTax + totalTip;

    // Display Results
    cout << fixed << setprecision(2);
    cout << "Meal Cost: $" << mealCost
         << "\nTax Amount: $" << totalTax
         << "\nTip Amount: $" << totalTip
         << "\nTotal Bill: $" << totalBill;

    return 0;
}