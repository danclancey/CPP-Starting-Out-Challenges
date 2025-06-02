/*
Modify the BinManager class you wrote for Programming Challenge 18 in Chapter 8 to overload its 
getQuantity, addParts, and removeParts functions as shown here:

        bool addParts(string itemDescription, int q);
        bool removeParts(string itemDescription, int q)
        int getQuantity(string itemDescription);

These new functions allow parts to be added, parts to be removed, and the quantity in stock for a 
particular item to be retrieved by using an item description, rather than a bin number, as an argument. 
In addition to writing the three overloaded functions, you will need to create a private BinManager 
class function that uses the item description as a search key to locate the index of the desired bin.

Test the new class functions with the same client program you wrote for Programming Challenge 15 in 
Chapter 8, modifying it to call the new functions. Be sure to use some descriptions that match bins 
in the array and some that do not.

As you did in the previous Bin Manager program, if an add or remove operation is successfully carried 
out, make the function return true. If it cannot be done—for example, because the string passed to it 
does not match any item description in the array—make the function return false. If the getQuantity 
function cannot locate any item whose description matches the one passed to it, make it return −1.
*/

#include <iostream>
#include <limits>
#include <string>
#include "BinManager.h" // Include your BinManager and InvBin class headers

using namespace std;

int main() {
    const int numBins = 5;
    string descriptions[numBins] = {"Screws", "Nails", "Bolts", "Washers", "Nuts"};
    int quantities[numBins] = {50, 30, 60, 80, 40};

    // Create a BinManager with initial data
    BinManager manager(numBins, descriptions, quantities);

    int choice;
    do {
        cout << "\nWarehouse Bin Management System\n";
        cout << "1. View bin information\n";
        cout << "2. Add parts to a bin\n";
        cout << "3. Remove parts from a bin\n";
        cout << "4. Quit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        // Check for non-integer input and clear the error state
        while (cin.fail() || choice < 1 || choice > 4) {
            cin.clear();                                                      // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');              // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                string itemDescription;
                cout << "Enter the item description (e.g., Screws, Nails, etc.): ";
                cin >> itemDescription;

                int quantity = manager.getQuantity(itemDescription);
                if (quantity != -1) {
                    cout << "\n\t- Item: " << itemDescription << " - Quantity: " << quantity << "\n";
                } else {
                    cout << "Item '" << itemDescription << "' not found.\n";
                }
                break;
            }
            case 2: {
                string itemDescription;
                int qty;
                cout << "Enter the item description (e.g., Screws, Nails, etc.): ";
                cin >> itemDescription;

                cout << "Enter quantity to add: ";
                cin >> qty;

                // Check for invalid quantity input
                while (cin.fail() || qty < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid positive integer quantity: ";
                    cin >> qty;
                }

                if (manager.addParts(itemDescription, qty)) {
                    cout << "\n\t- Added " << qty << " parts to " << itemDescription << ".\n";
                } else {
                    cout << "\n\t- Failed to add parts. Item not found or invalid quantity.\n";
                }
                break;
            }
            case 3: {
                string itemDescription;
                int qty;
                cout << "Enter the item description (e.g., Screws, Nails, etc.): ";
                cin >> itemDescription;

                cout << "Enter quantity to remove: ";
                cin >> qty;

                // Check for invalid quantity input
                while (cin.fail() || qty < 0) {
                    cin.clear();
                    cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    cout << "Invalid input. Please enter a valid positive integer quantity: ";
                    cin >> qty;
                }

                if (manager.removeParts(itemDescription, qty)) {
                    cout << "\n\t- Removed " << qty << " parts from " << itemDescription << ".\n";
                } else {
                    cout << "\n\t- Failed to remove parts. Item not found or invalid quantity.\n";
                }
                break;
            }
            case 4:
                cout << "Exiting program. Goodbye!\n";
                break;
            default:
                cout << "Invalid choice. Please enter a number between 1 and 4.\n";
        }

    } while (choice != 4);

    return 0;
}

