/*
Write a program that lets a maker of chips and salsa keep track of 
their sales for five different types of salsa they produce: mild, 
medium, sweet, hot, and zesty. It should use two parallel five-
element arrays: an array of strings that holds the five salsa names 
and an array of integers that holds the number of jars sold during 
the past month for each salsa type. The salsa names should be stored 
using an initialization list at the time the name array is created. 
The program should prompt the user to enter the number of jars sold 
for each type. Once this sales data has been entered, the program 
should produce a report that displays sales for each salsa type, 
total sales, and the names of the highest selling and lowest selling 
products.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main() {
    // Array to store salsa names
    const int NUM_TYPES = 5;
    string salsaNames[NUM_TYPES] = {"mild", "medium", "sweet", "hot", "zesty"};

    // Array to store jars sold for each type of salsa
    int jarsSold[NUM_TYPES];

    // Input the number of jars sold for each type
    cout << "Enter the number of jars sold for each salsa type:\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        do {
            cout << salsaNames[i] << ": ";
            cin >> jarsSold[i];
            // Validate input to ensure non-negative values
            if (jarsSold[i] < 0) {
                cout << "Invalid input. Please enter a non-negative number.\n";
            }
        } while (jarsSold[i] < 0);
    }

    // Calculate total sales, and find the highest and lowest selling products
    int totalSales = 0;
    int highestSales = jarsSold[0];
    int lowestSales = jarsSold[0];
    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 0; i < NUM_TYPES; i++) {
        totalSales += jarsSold[i];
        if (jarsSold[i] > highestSales) {
            highestSales = jarsSold[i];
            highestIndex = i;
        }
        if (jarsSold[i] < lowestSales) {
            lowestSales = jarsSold[i];
            lowestIndex = i;
        }
    }

    // Display the sales report with formatted output
    cout << "\nSalsa Sales Report:\n";
    cout << "--------------------------------\n";
    cout << left << setw(21) << "Salsa" << setw(15) << "Jars Sold" << endl;
    cout << "--------------------------------\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        cout << left << setw(10) << salsaNames[i] << right << setw(15) << jarsSold[i] << " jars" << endl;
    }

    cout << left << setw(27) << "\nTotal Sales: " << totalSales << " jars\n";
    cout << left << setw(26) << "Highest Selling Product: " << salsaNames[highestIndex] << " (" << highestSales << " jars)\n";
    cout << left << setw(26) << "Lowest Selling Product: " << salsaNames[lowestIndex] << " (" << lowestSales << " jars)\n";

    return 0;
}

