/*
The Middletown Wholesale Copper Wire Company sells spools of copper wiring for $100 each and ships them 
for $10 apiece. Write a program that displays the status of an order. It should use two functions. The 
first function asks for the following data and stores the input values in reference parameters.

    - The number of spools ordered.
    - The number of spools in stock.
    - Any special shipping and handling charges (above the regular $10 rate).

The second function receives as arguments any values needed to compute and display the following 
information:
    
    - The number of ordered spools ready to ship from current stock.
    - The number of ordered spools on backorder (if the number ordered is greater than what is in stock).
    - Total selling price of the portion ready to ship (the number of spools ready to ship times $100).
    - Total shipping and handling charges on the portion ready to ship.
    - Total of the order ready to ship.

The shipping and handling parameter in the second function should have the default argument 10.00.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getOrderData(int& spoolsOrdered, int& spoolsInStock, double& specialShipping);
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, double specialShipping = 10.00);

int main() {
    int spoolsOrdered, spoolsInStock;
    double specialShipping;

    // Get the order data
    getOrderData(spoolsOrdered, spoolsInStock, specialShipping);

    // Display the order status
    displayOrderStatus(spoolsOrdered, spoolsInStock, specialShipping);

    return 0;
}

// Function to get input data for the order
void getOrderData(int& spoolsOrdered, int& spoolsInStock, double& specialShipping) {
    // Get the number of spools ordered
    do {
        cout << "Enter the number of spools ordered: ";
        cin >> spoolsOrdered;
        if (spoolsOrdered < 1) {
            cout << "Invalid input. Number of spools ordered must be at least 1.\n";
        }
    } while (spoolsOrdered < 1);

    // Get the number of spools in stock
    do {
        cout << "Enter the number of spools in stock: ";
        cin >> spoolsInStock;
        if (spoolsInStock < 0) {
            cout << "Invalid input. Number of spools in stock cannot be negative.\n";
        }
    } while (spoolsInStock < 0);

    // Get any special shipping and handling charges
    do {
        cout << "Enter any special shipping and handling charges (above $10.00 per spool): ";
        cin >> specialShipping;
        if (specialShipping < 0) {
            cout << "Invalid input. Special shipping charges cannot be negative.\n";
        }
    } while (specialShipping < 0);
}

// Function to display the order status
void displayOrderStatus(int spoolsOrdered, int spoolsInStock, double specialShipping) {
    // Calculate the number of spools ready to ship and on backorder
    int spoolsReadyToShip = min(spoolsOrdered, spoolsInStock);
    int spoolsBackordered = max(0, spoolsOrdered - spoolsInStock);

    // Calculate the total selling price for the spools ready to ship
    double totalSellingPrice = spoolsReadyToShip * 100.0;

    // Calculate the total shipping and handling charges for the spools ready to ship
    double shippingCharges = spoolsReadyToShip * (10.0 + specialShipping);

    // Calculate the total cost of the order ready to ship
    double totalOrderCost = totalSellingPrice + shippingCharges;

    // Display the order status
    cout << fixed << setprecision(2);
    cout << "\nOrder Status:\n";
    cout << "-------------------------------------\n";
    cout << "Spools ready to ship: " << spoolsReadyToShip << endl;
    cout << "Spools on backorder: " << spoolsBackordered << endl;
    cout << "Total selling price: $" << totalSellingPrice << endl;
    cout << "Shipping & handling charges: $" << shippingCharges << endl;
    cout << "Total cost of the order ready to ship: $" << totalOrderCost << endl;
}

