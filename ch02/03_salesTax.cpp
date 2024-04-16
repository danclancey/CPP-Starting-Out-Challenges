/*
    Write a program that computes the sales tax and total price on a $95 purchase.
    Assume the state sales tax is 6.5 percent and the county sales tax is 2 percent.
    Display the purhcase price, total tax, and total price on the screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    // Declare variables
    double stateTax = 0.065, countyTax = 0.02, purchase = 95;
    double totalTax, totalPrice;

    // Calculate Total Tax and total Price
    totalTax = (purchase * stateTax) + (purchase * countyTax);
    totalPrice = purchase + totalTax;

    // Display Purchase Price, Total Tax, and Total Price
    cout << fixed << setprecision(2);
    cout << "Purchase Price: $" << purchase
         << "\nTotal Tax: $" << totalTax
         << "\nTotal Price: $" << totalPrice;

    return 0;
}