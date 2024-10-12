/*
Design and write an object-oriented program for managing inventory bins 
in a warehouse. To do this you will use two classes: InvBin and BinManager. 
The InvBin class holds information about a single bin. The BinManager class 
will own and manage an array of InvBin objects. Here is a skeleton of what 
the InvBin and BinManager class declarations should look like:


class InvBin 
{
    private:
       string description;                     // Item name
       int qty;                                // Quantity of items
                                               // in this bin
    public:
      InvBin (string d = "empty", int q = 0)   // 2-parameter constructor
        {    description = d;  qty = q; }      // with default values

       // It will also have the following public member functions. They
       // will be used by the BinManager class, not the client program.
       void setDescription(string d)
       string getDescription()
       void setQty(int q)
       int getQty( )
};
class BinManager 
{
    private:
       InvBin bin[30];                           // Array of InvBin objects
       int numBins;                              // Number of bins
                                                 // currently in use
    public:
       BinManager()                              // Default constructor
       {   numBins = 0; }     
       BinManager(int size, string d[], int q[]) // 3-parameter constructor
       {   // Receives number of bins in use and parallel arrays of item names
           // and quantities. Uses this info. to store values in the elements
           // of the bin array. Remember, these elements are InvBin objects.
       }
       // The class will also have the following public member functions:
       string getDescription(int index)          // Returns name of one item
       int getQuantity(int index)                // Returns qty of one item
       bool addParts(int binIndex, int q)        // These return true if the
       bool removeParts(int binIndex, int q)     // action was done and false
                                                 // if it could not be done—
                                                 // see validation information
};
*/

#include <iostream>
#include <string>
#include <limits>
#include "BinManager.h"
#include "InvBin.h"

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
        while (cin.fail()) {
            cin.clear();                                                      // Clear the error flag on cin
            cin.ignore(numeric_limits<streamsize>::max(), '\n');              // Discard invalid input
            cout << "Invalid input. Please enter a number between 1 and 4: ";
            cin >> choice;
        }

        switch (choice) {
            case 1: {
                int index;
                cout << "Enter bin index (0-" << numBins - 1 << "): ";
                cin >> index;

                cout << "\n\t- Bin " << index << ": " << manager.getDescription(index)
                     << " - Quantity: " << manager.getQuantity(index) << "\n";
                break;
            }
            case 2: {
                int index, qty;
                cout << "Enter bin index (0-" << numBins - 1 << "): ";
                cin >> index;
                cout << "Enter quantity to add: ";
                cin >> qty;
                if (manager.addParts(index, qty)) {
                    cout << "\n\t- Added " << qty << " parts to bin " << index << ".\n";
                }
                break;
            }
            case 3: {
                int index, qty;
                cout << "Enter bin index (0-" << numBins - 1 << "): ";
                cin >> index;
                cout << "Enter quantity to remove: ";
                cin >> qty;
                if (manager.removeParts(index, qty)) {
                    cout << "\n\t- Removed " << qty << " parts from bin " << index << ".\n";
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

