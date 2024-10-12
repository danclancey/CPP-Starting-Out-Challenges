/*
Design a class called Date that has integer data members to store month, day, and year. 
The class should have a three-parameter default constructor that allows the date to be 
set at the time a new Date object is created. If the user creates a Date object without 
passing any arguments, or if any of the values passed are invalid, the default values of 
1, 1, 2001 (i.e., January 1, 2001) should be used. The class should have member functions 
to print the date in the following formats:

    3/15/20
    March 15, 2020
    15 March 2020

Demonstrate the class by writing a program that uses it. Be sure your program only accepts 
reasonable values for month and day. The month should be between 1 and 12. The day should be 
between 1 and the number of days in the selected month.
*/

#include <iostream>
#include <string>

using namespace std;

class Date {
    private:
      int month, day, year;

      int daysInMonth(int month, int year);
      string monthName(int month);

    public:
      Date();
      Date(int m, int d, int y);

      void print1();
      void print2();
      void print3();
};

// Default Constructor 
Date::Date() {
    month = 1;
    day = 1;
    year = 2001;
   
}
Date::Date(int m, int d, int y) {
    if (m < 1 || m > 12) {
        month = 1;
    } else {
        month = m;
    }

    if (d < 1 || d > daysInMonth(month, y)) {
        day = 1;
    } else {
        day = d;
    }

    if (y < 1900 || y > 2100) {
        year = 2001;
    } else {
        year = y;
    }
}

// Helper function to determine days in month
int Date::daysInMonth(int month, int year) {
    switch(month) {
        case 1: case 3: case 5: case 7: case 8: case 10: case 12:
            return 31;
        case 4: case 6: case 9: case 11:
            return 30;
        case 2:
            // check for leap year 
            if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
                return 29;
            } else {
                return 28;
            }
        default: 
            return 31; // Should not reach here
    }
}

// Helper function to convert a month number to name 
string Date::monthName(int month) {
    string months[] = {
        "January", "February", "March", "April", "May", "June",
        "July", "August", "September", "October", "November", "December"
    };
    if (month >= 1 && month <= 12) {
        return months[month - 1];
    }

    return "Invalid";
}

// Function to display in 3/15/20 format 
void Date::print1() {
    cout << month << "/" << day << "/" << (year % 100) << endl;
}

// Function to display in March, 15, 2020 format
void Date::print2() {
    cout << monthName(month) << " " << day << ", " << year << endl;
}

// Function to display in 15 March 2020 format 
void Date::print3() {
    cout << day << " " << monthName(month) << " " << year << endl;
}

int main() {
    int m, d, y;

    // Get input for month day and year 
    cout << "Enter month (1-12): ";
    cin >> m;
    cout << "Enter day: ";
    cin >> d;
    cout << "Enter year (1900-2100): ";
    cin >> y;

    // Create date object with user input 
    Date userDate(m, d, y);

    // Display in diff formats 
    cout << "\nDate in format 1 (MM/DD/YY): ";
    userDate.print1();
    cout << "Date in format 2 (Month DD, YYYY): ";
    userDate.print2();
    cout << "Date in format 3 (DD Month YYYY): ";
    userDate.print3();

    return 0;
}
