/*
Write a program that determines which of a company’s four divisions (Northeast, Southeast, Northwest, 
and Southwest) had the greatest sales for a quarter. It should include the following two functions, 
which are called by main.

    double getSales() is passed the name of a division. It asks the user for a division’s quarterly 
    sales figure, validates that the input is not less than 0, then returns it. It should be called 
    once for each division.

    void findHighest() is passed the four sales totals. It determines which is the largest and prints 
    the name of the high grossing division, along with its sales figure.
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
double getSales(const string& division);
void findHighest(double northeast, double southeast, double northwest, double southwest);

int main() {
    // Variables to hold sales figures for each division
    double northeastSales = getSales("Northeast");
    double southeastSales = getSales("Southeast");
    double northwestSales = getSales("Northwest");
    double southwestSales = getSales("Southwest");

    // Determine and display the highest sales
    findHighest(northeastSales, southeastSales, northwestSales, southwestSales);

    return 0;
}

// Function to get and validate sales input
double getSales(const string& division) {
    double sales;
    do {
        cout << "Enter the quarterly sales for the " << division << " division: $";
        cin >> sales;
        if (sales < 0) {
            cout << "Sales cannot be negative. Please enter a valid sales figure.\n";
        }
    } while (sales < 0); // Validate that sales are not negative

    return sales;
}

// Function to find and display the highest sales
void findHighest(double northeast, double southeast, double northwest, double southwest) {
    double highestSales = northeast;
    string highestDivision = "Northeast";

    // Compare and find the highest sales and corresponding division
    if (southeast > highestSales) {
        highestSales = southeast;
        highestDivision = "Southeast";
    }
    if (northwest > highestSales) {
        highestSales = northwest;
        highestDivision = "Northwest";
    }
    if (southwest > highestSales) {
        highestSales = southwest;
        highestDivision = "Southwest";
    }

    // Display the division with the highest sales
    cout << fixed << setprecision(2);
    cout << "\nThe division with the highest sales is the " << highestDivision 
         << " division with sales totaling $" << highestSales << ".\n";
}

