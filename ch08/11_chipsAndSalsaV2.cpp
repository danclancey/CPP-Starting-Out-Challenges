/*
Revise Programming Challenge 4 to use an array of Product objects 
instead of two parallel arrays. The Product class will need member 
variables to hold a product name and a quantity.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Product class definition
class Product {
private:
    string name;
    int jarsSold;

public:
    // Constructor to initialize product name and jars sold
    Product(string n, int jars = 0) {
        name = n;
        jarsSold = jars;
    }

    // Getters and setters
    string getName() const {
        return name;
    }

    int getJarsSold() const {
        return jarsSold;
    }

    void setJarsSold(int jars) {
        jarsSold = jars;
    }
};

int main() {
    // Array to store Product objects for each type of salsa
    const int NUM_TYPES = 5;
    Product products[NUM_TYPES] = {
        Product("mild"),
        Product("medium"),
        Product("sweet"),
        Product("hot"),
        Product("zesty")
    };

    // Input the number of jars sold for each type
    cout << "Enter the number of jars sold for each salsa type:\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        int jars;
        do {
            cout << products[i].getName() << ": ";
            cin >> jars;
            // Validate input to ensure non-negative values
            if (jars < 0) {
                cout << "Invalid input. Please enter a non-negative number.\n";
            } else {
                products[i].setJarsSold(jars);
            }
        } while (jars < 0);
    }

    // Calculate total sales, and find the highest and lowest selling products
    int totalSales = 0;
    int highestSales = products[0].getJarsSold();
    int lowestSales = products[0].getJarsSold();
    int highestIndex = 0;
    int lowestIndex = 0;

    for (int i = 0; i < NUM_TYPES; i++) {
        int jarsSold = products[i].getJarsSold();
        totalSales += jarsSold;
        if (jarsSold > highestSales) {
            highestSales = jarsSold;
            highestIndex = i;
        }
        if (jarsSold < lowestSales) {
            lowestSales = jarsSold;
            lowestIndex = i;
        }
    }

    // Display the sales report with formatted output
    cout << "\nSalsa Sales Report:\n";
    cout << "--------------------------------\n";
    cout << left << setw(21) << "Salsa" << setw(15) << "Jars Sold" << endl;
    cout << "--------------------------------\n";
    for (int i = 0; i < NUM_TYPES; i++) {
        cout << left << setw(10) << products[i].getName()
             << right << setw(15) << products[i].getJarsSold() << " jars" << endl;
    }

    cout << left << setw(27) << "\nTotal Sales: " << totalSales << " jars\n";
    cout << left << setw(26) << "Highest Selling Product: " << products[highestIndex].getName()
         << " (" << highestSales << " jars)\n";
    cout << left << setw(26) << "Lowest Selling Product: " << products[lowestIndex].getName()
         << " (" << lowestSales << " jars)\n";

    return 0;
}

