/*
Write a program that can be used by a ski resort to keep track of local snow conditions for one week. 
It should have a seven-element array of structures or class objects, where each structure or object 
holds a date and the number of inches of snow in the base on that date. The program should have the 
user input the name of the month, the starting and ending date of the seven-day period being measured, 
and then the seven base snow depths. The program should then sort the data in ascending order by base 
depth and display the results. Here is the beginning of a sample report.

            Snow Report December 12 − 18
                Date    Base
                13      42.3
                12      42.5
                14      42.8
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

// Structure to store date and snow depth for a day 
struct SnowReport {
    int date;
    double snowDepth;
};

// Function prototypes
void inputSnowData(string month, int startDate, SnowReport snowData[], int size);
void sortSnowData(SnowReport snowData[], int size);
void displayReport(const string& month, int startDate, int endDate, const SnowReport snowData[], int size);
int getValidDate(const string& prompt);
double getValidSnowDepth(const string& prompt);

const int SIZE = 7;

int main() {
    SnowReport snowData[SIZE];
    string month;
    int startDate, endDate;

    // Get input from user
    cout << "Enter the month: ";
    cin >> month;

    // Get valid start date
    startDate = getValidDate("Enter the start date (1-31): ");
    // Get valid end date, ensuring it's after start date
    do {
        endDate = getValidDate("Enter the end date (1-31): ");
        if (endDate < startDate) {
            cout << "End date must be after or equal to start date. Please try again.\n";
        }
    } while (endDate < startDate);

    // Call functions to input depth, sort data, and display report
    inputSnowData(month, startDate, snowData, SIZE);
    sortSnowData(snowData, SIZE);
    displayReport(month, startDate, endDate, snowData, SIZE);

    return 0;
}

// Function to input snow data 
void inputSnowData(string month, int startDate, SnowReport snowData[], int size) {
    for (int i = 0; i < size; i++) {
        snowData[i].date = i + 1;
        snowData[i].snowDepth = getValidSnowDepth("Enter the snow depth for " + month + " " + to_string(snowData[i].date) + " (in inches): ");
    }
}

// Function to sort snow data by snow depth (ascending order) 
void sortSnowData(SnowReport snowData[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (snowData[j].snowDepth > snowData[j + 1].snowDepth) {
                // Swap elements 
                SnowReport temp = snowData[j];
                snowData[j] = snowData[j + 1];
                snowData[j + 1] = temp;
            }
        }
    }
}

// Function to display report 
void displayReport(const string& month, int startDate, int endDate, const SnowReport snowData[], int size) {
    cout << "\nSnow Report for " << month << " " << startDate << " - " << endDate << endl;
    cout << left << setw(10) << "Date" << "Base" << endl;
    cout << "------------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(10) << snowData[i].date << fixed << setprecision(1) << snowData[i].snowDepth << " inches\n";
    }
}

int getValidDate(const string& prompt) {
    int date;
    cout << prompt;
    cin >> date;
    while (cin.fail() ||  date < 1 || date > 31) {
          cin.clear();
          cin.ignore(numeric_limits<streamsize>::max(), '\n');
          cout << "Invalid input. " << prompt;
          cin >> date;
        }

    return date;
}

// Function to get a valid snow depth (non-negative double)
double getValidSnowDepth(const string& prompt) {
    double snowDepth;
    cout << prompt;
    cin >> snowDepth;
    while (cin.fail() || snowDepth < 0) {
        cin.clear(); // clear the error flag
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // discard invalid input
        cout << "Invalid input. Please enter a non-negative snow depth.\n" << prompt;
        cin >> snowDepth;
    }
    return snowDepth;
}
