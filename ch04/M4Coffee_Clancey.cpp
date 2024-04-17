// Dan Clancey
// CIS 211
// M4Coffee_Clancey.cpp

// For this assignment, write a program that calculates a discount for buying certain quantities of coffee. Consider the following scenario:
// A coffee company sells a pound of coffee for $12.99. Quantity discounts are given according to the table below.
//      Quantity        Discount
//        1-4       No Discount given
//        5-9              2%
//       10-19            15%
//       20-29            20%
//    30 or more          30%


// Create an application named as M4Coffee_YourLastname
// Declare numeric constant variables for discounts and use in calculation.
// NOTE: All variables should be correctly named, using the naming standards indicated in the book.
 
// The number of pounds entered should be checked to make sure it is greater than 0. If not it is invalid, a error message should be displayed and the programs ends. NO calculations should be done!
// No calculations should be done within the IF or Case statements. The calculation for price should be done outside the IF structure.
// Make sure the output formatting is appropriate for the values provided. 
// Be sure to include comments throughout your code where appropriate.
// Make sure you test your program with all possible values.

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    const double COST_PER_POUND = 12.99; // Cost per pound
    const double TWO_PERCENT = .02; // Discount for 5-9 pounds 
    const double FIFTEEN_PERCENT = .15; // Discount for 10-19 pounds
    const double TWENTY_PERCENT = .20; // Discount for 20-29 pounds
    const double THIRTY_PERCENT = .30; // Discount for 30+ pounds

    // Declare variables
    double coffeePounds, discount, totalDiscount, totalCost;

    // Prompt user for number of pounds to purchase
    cout << "Please enter desired coffee in pounds: ";
    cin >> coffeePounds;

    cout << fixed << setprecision(2);

    // Determine discount based on user input 
    if (coffeePounds >= 30)
        discount = THIRTY_PERCENT;
    else if (coffeePounds >= 20)
        discount = TWENTY_PERCENT;
    else if (coffeePounds >=10)
        discount = FIFTEEN_PERCENT;
    else if (coffeePounds >= 5)
        discount = TWO_PERCENT;
    else if (coffeePounds > 0)
        discount = 0;
    else
    {
        cout << "You entered less than 0 pounds of coffee! Exiting..";
        return 0;
    }

    // Calculate discount based on pounds purchased
    totalDiscount = coffeePounds * COST_PER_POUND * discount;
    totalCost = coffeePounds * COST_PER_POUND - totalDiscount;

    // Output total savings and total cost.
    cout << "Your total savings for " << coffeePounds << " is $" << totalDiscount << "\n";
    cout << "Your total price after discount is $" << totalCost;

    return 0;
}