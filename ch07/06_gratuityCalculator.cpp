/*
Design a Tips class that calculates the gratuity on a restaurant meal. Its only class 
member variable, taxRate, should be set by a one-parameter constructor to whatever 
rate is passed to it when a Tips object is created. If no argument is passed, a default 
tax rate of .085 should be used. The class should have just one public function, 
computeTip. This function needs to accept two arguments, the total bill amount and the 
tip rate. It should use the total bill amount, along with the value stored in the taxRate 
member variable, to compute the cost of the meal before the tax was added. It should then 
apply the tip rate to just the meal cost portion of the bill to compute and return the 
tip amount. Demonstrate the class by creating a program that creates a single Tips object, 
and then has a sentinel-controlled loop to let the user retrieve the correct tip amount 
using various bill totals and desired tip rates.
*/

#include <iostream>
#include <iomanip>

using namespace std;

class Tips {
private:
    double taxRate;

public:
    // Constructor with validation for the tax rate (percentage)
    Tips(double rate) {
        if (rate < 0) {
            cout << "Invalid tax rate. Setting to default 8.5%." << endl;
            taxRate = 0.085;
        } else {
            taxRate = rate / 100.0; // Convert percentage to decimal
        }
    }

    Tips() { taxRate = 0.085; }

    // Function to compute the tip based on the meal cost before tax
    double computeTip(double totBill, double tipRate);
};

double Tips::computeTip(double totBill, double tipRate) {
    // Calculate the meal cost before tax
    double mealCost = totBill / (1 + taxRate);

    // Calculate and return the tip amount based on the meal cost
    return mealCost * (tipRate / 100.0);  // Convert tipRate to decimal for calculation
}

int main() {
    double taxRate, totBill, tipRate;

    // Prompt user for tax rate in percentage and validate it
    cout << "Enter tax rate (as a percentage, e.g., 6 for 6%): ";
    cin >> taxRate;
    while (taxRate < 0) {
        cout << "Invalid input. Tax rate must be a positive number. Please try again: ";
        cin >> taxRate;
    }

    // Create a Tips object with the specified tax rate
    Tips myTips(taxRate);

    cout << "\nEnter a total bill amount and tip rate to compute the tip, or -1 to exit.\n";
    while (true) {
        // Prompt user for the total bill amount and validate it
        cout << "\nEnter the total bill amount: ";
        cin >> totBill;
        if (totBill == -1) {
            break; // Exit loop if the user enters -1
        }
        while (totBill < 0) {
            cout << "Invalid input. Total bill amount must be a positive number. Please try again: ";
            cin >> totBill;
        }

        // Prompt user for the tip rate and validate it
        cout << "Enter the desired tip rate (as a percentage, e.g., 20 for 20%): ";
        cin >> tipRate;
        while (tipRate < 0) {
            cout << "Invalid input. Tip rate must be a positive number. Please try again: ";
            cin >> tipRate;
        }

        // Compute the tip using the Tips object
        double tip = myTips.computeTip(totBill, tipRate);

        // Display the tip amount with 2 decimal places
        cout << fixed << setprecision(2);
        cout << "The tip amount is: $" << tip << endl;
    }

    cout << "Thank you for using Dan's tip calculator. Goodbye...\n";

    return 0;
}

