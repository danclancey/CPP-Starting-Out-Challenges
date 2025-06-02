/*
A corporation has six divisions, each responsible for sales to different geographic locations. Design a DivSales class that keeps sales 
data for a division, with the following members:

    - An array with four elements for holding four quarters of sales figures for the division.
    - A private static variable for holding the total corporate sales for all divisions for the entire year.
    - A member function that takes four arguments, each assumed to be the sales for a quarter. The value of the arguments should be 
      copied into the array that holds the sales data. The total of the four arguments should be added to the static variable that 
      holds the total yearly corporate sales.
    - A function that takes an integer argument within the range of 0 to 3. The argument is to be used as a subscript into the division 
      quarterly sales array. The function should return the value of the array element with that subscript.

Write a program that creates an array of six DivSales objects. The program should ask the user to enter the sales for four quarters for 
each division. After the data is entered, the program should display a table showing the division sales for each quarter. The program 
should then display the total corporate sales for the year.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Class - DivSales 
class DivSales {
    private:
        double quarterlySales[4];       // Array to store sales for 4 quarters 
        static double totalCorpSales;   // Static variable for total corporate sales 

    public:
        void setQuarterlySales(double q1, double q2, double q3, double q4);

        double getQuarterlySales (int quarter) const;
        static double getTotalCorpSales() { return totalCorpSales; }
};

// Funtion - Set sales data for 4 quarters 
void DivSales::setQuarterlySales(double q1, double q2, double q3, double q4) {
    quarterlySales[0] = q1;
    quarterlySales[1] = q2;
    quarterlySales[2] = q3;
    quarterlySales[3] = q4;

    // Add quarterly sales to get total corporate sales 
    totalCorpSales += (q1 + q2 + q3 + q4);
}

double DivSales::getQuarterlySales(int quarter) const {
    if (quarter >= 0 && quarter < 4) {
        return quarterlySales[quarter];
    }

    return 0.0;
}

double DivSales::totalCorpSales = 0.0;

int main() {
    const int NUM_DIVISIONS = 6;
    DivSales divisions[NUM_DIVISIONS];  // Array of DivSales objects

    // Input sales data for each division
    for (int i = 0; i < NUM_DIVISIONS; i++) {
        double q1, q2, q3, q4;
        cout << "Enter sales for Division " << i + 1 << ":\n";
        cout << "Quarter 1: ";
        cin >> q1;
        cout << "Quarter 2: ";
        cin >> q2;
        cout << "Quarter 3: ";
        cin >> q3;
        cout << "Quarter 4: ";
        cin >> q4;

        // Set the sales for this division
        divisions[i].setQuarterlySales(q1, q2, q3, q4);
    }

    // Display the sales table for each division
    cout << "\nSales Data for Each Division\n";
    cout << setw(10) << "Division" << setw(10) << "Q1" << setw(10) << "Q2" << setw(10) << "Q3" << setw(10) << "Q4" << endl;
    cout << "---------------------------------------------------\n";

    for (int i = 0; i < NUM_DIVISIONS; i++) {
        cout << setw(10) << i + 1;
        for (int j = 0; j < 4; j++) {
            cout << setw(10) << divisions[i].getQuarterlySales(j);
        }
        cout << endl;
    }

    // Display the total corporate sales
    cout << "\nTotal corporate sales for the year: $" << fixed << setprecision(2) << DivSales::getTotalCorpSales() << endl;

    return 0;
}
