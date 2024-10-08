/*
Write a program that asks the user to enter an item’s wholesale cost and its markup percentage. 
It should then display the item’s retail price. For example:

    - If an item’s wholesale cost is $5.00 and its markup percentage is 100 percent, then the 
      item’s retail price is $10.00.
    - If an item’s wholesale cost is $5.00 and its markup percentage is 50 percent, then the 
      item’s retail price is $7.50.

The program should have a function named calculateRetail that receives the wholesale cost and the 
markup percentage as arguments and returns the retail price of the item.
*/

#include <iostream>
#include <iomanip>

using namespace std;

double calculateRetail(double, double); // Function Prototype

int main() {
    
    double wsCost, markupPct, retailPrice;

    // Prompt user for wholesale cost with input validation
    do {
        cout << "Please enter wholesale cost of item: $";
        cin >> wsCost;
        if (wsCost < 0) {
            cout << "Error: Wholesale cost cannot be negative.\n";
        }
    } while (wsCost < 0);

    // Prompt user for markup percentage with input validation
    do {
        cout << "Please enter markup percentage: ";
        cin >> markupPct;
        if (markupPct < 0) {
            cout << "Error: Markup percentage cannot be negative.\n";
        }
    } while (markupPct < 0);

    // Call calculateRetail and return retail cost to retailPrice 
    retailPrice = calculateRetail(wsCost, markupPct);
    
    // Display results
    cout << "\nThe retail cost of the item is: $" 
         << fixed << setprecision(2) << retailPrice << endl;

    return 0;
}

double calculateRetail(double wsCost, double markupPct) {
    return wsCost * (1 + ( markupPct / 100));
}
