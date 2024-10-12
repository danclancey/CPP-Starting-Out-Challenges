/*
Write a modular program that analyzes a year’s worth of rainfall data. 
In addition to main, the program should have a getData function that 
accepts the total rainfall for each of 12 months from the user and 
stores it in an array holding double numbers. It should also have four 
value-returning functions that compute and return to main the 
totalRainfall, averageRainfall, driestMonth, and wettestMonth. These 
last two functions return the number of the month with the lowest and 
highest rainfall amounts, not the amount of rain that fell those months. 
Notice that this month number can be used to obtain the amount of rain 
that fell those months. This information should be used either by main 
or by a displayReport function called by main to print a summary rainfall 
report similar to the following:

   2019 Rain Report for Springdale County

Total rainfall: 23.19 inches
Average monthly rainfall: 1.93 inches
The least rain fell in January with 0.24 inches.
The most rain fell in April with 4.29 inches.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Constants
const int MONTHS = 12;
const string monthNames[MONTHS] = {
    "January", "February", "March", "April", "May", "June",
    "July", "August", "September", "October", "November", "December"
};

// Function prototypes
void getData(double rainfall[], int size);
double totalRainfall(const double rainfall[], int size);
double averageRainfall(const double rainfall[], int size);
int driestMonth(const double rainfall[], int size);
int wettestMonth(const double rainfall[], int size);
void displayReport(const double rainfall[], int size);

int main() {
    double rainfall[MONTHS];

    // Get rainfall data for each month 
    getData(rainfall, MONTHS);

    // Display report
    displayReport(rainfall, MONTHS);

    return 0;
}

// Function to get rainfall data from user 
void getData(double rainfall[], int size) {
    cout << "Enter the total rainfall (in inches) for each month:\n";
    for (int i = 0; i < size; i++) {
        do {
            cout << monthNames[i] << ": ";
            cin >> rainfall[i];
            // validate input 
            if (rainfall[i] < 0) {
                cout << "Invalid input, Please enter a non-negative value\n";
            }
        } while (rainfall[i] < 0);
    }
}

// Function to calculate total rainfall for year
double totalRainfall(const double rainfall[], int size) {
    double total = 0.0;
    for (int i = 0; i < size; i++) {
        total += rainfall[i];
    }

    return total;
}

// Function to find the average rainfall for year 
double averageRainfall(const double rainfall[], int size) {
    double total = totalRainfall(rainfall, size);
    return total / size;
}

// Function to find month with least rainfall 
int driestMonth(const double rainfall[], int size) {
    int driest = 0;
    for (int i = 1; i < size; i++) {
        if (rainfall[i] > rainfall[driest]) {
            driest = i;
        }
    }

    return driest;
}

// Function to find month with most rainfall 
int wettestMonth(const double rainfall[], int size) {
    int wettest = 0;
    for (int i = 1; i < size; i++) {
        if (rainfall[i] < rainfall[wettest]) {
            wettest = i;
        }
    }

    return wettest;
}

// Function to display report 
void displayReport(const double rainfall[], int size) {
    double total = totalRainfall(rainfall, size);
    double average = averageRainfall(rainfall, size);
    int driest = driestMonth(rainfall, size);
    int wettest = wettestMonth(rainfall, size);

    cout << "\nRain Report for the Year\n";
    cout << "--------------------------\n";
    cout << fixed << setprecision(2);
    cout << "Total Rainfall:\t\t" << total << " inches\n";
    cout << "Avg monthly rainfall:\t" << average << " inches\n";
    cout << "\nThe least rain fell in " << monthNames[driest] 
         << " with " << rainfall[driest] << " inches\n";
    cout << "The most rain fell in " << monthNames[wettest]
         << " with " << rainfall[wettest] << " inches\n";
}
