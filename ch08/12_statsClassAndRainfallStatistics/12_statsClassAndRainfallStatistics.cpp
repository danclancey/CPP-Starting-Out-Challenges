/*
Create a Stats class whose member data includes an array capable of 
storing 30 double data values, and whose member functions include 
total, average, lowest, and highest functions for returning information 
about the data to the client program. These are general versions of the 
same functions you created for Programming Challenge 8, but now they 
belong to the Stats class, not the application program. In addition to 
these functions, the Stats class should have a Boolean storeValue 
function that accepts a double value from the client program and stores 
it in the array. It is the job of this function to keep track of how many 
values are currently in the array, so it will know where to put the next 
value it receives and will know how many values there are to process when 
it is carrying out its other functions. It is also the job of this function 
to make sure that no more than 30 values are accepted. If the storeValue 
function is able to successfully store the value sent to it, it should 
return true to the client program. However, if the client program tries to 
store a thirty-first value, the function should not store the value and 
should return false to the client program.

The client program should create and use a Stats object to carry out the same 
rainfall analysis requested by Programming Challenge 8. Notice that the Stats 
object does no I/O. All input and output is done by the client program.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "Stats.h"

using namespace std;

// Constants 
const int MONTHS = 12;
const string monthNames[MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};


// Function prototypes
void getData(Stats& rainfallData);
void displayReport(const Stats& rainfallData);

int main() {
    Stats rainfallData;

    // Get data for each month 
    getData(rainfallData);

    // Display Report 
    displayReport(rainfallData);

    return 0;
}

// Function to get rainfall data from user
void getData(Stats& rainfallData) {
    cout << "Enter the total rainfall (in inches) for each month:\n";
    for (int i = 0; i < MONTHS; i++) {
        double rainfall;
        do {
            cout << monthNames[i] << ": ";
            cin >> rainfall;
            // Validate input to ensure non-negative values
            if (rainfall < 0) {
                cout << "Invalid input, please enter a non-negative value.\n";
            }
        } while (rainfall < 0);
        rainfallData.storeValue(rainfall);
    }
}

// Function to display the rainfall report
void displayReport(const Stats& rainfallData) {
    double total = rainfallData.total();
    double average = rainfallData.average();
    int driest = rainfallData.lowest();
    int wettest = rainfallData.highest();

    cout << "\nRain Report for the Year\n";
    cout << "--------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Rainfall:\t\t" << total << " inches\n";
    cout << "Avg monthly rainfall:\t" << average << " inches\n";
    cout << "\nThe least rain fell in " << monthNames[driest]
         << " with " << rainfallData.getValue(driest) << " inches.\n";
    cout << "The most rain fell in " << monthNames[wettest]
         << " with " << rainfallData.getValue(wettest) << " inches.\n";
}
