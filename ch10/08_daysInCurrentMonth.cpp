/*
Write a program that can determine the number of days in a month for a specified month and year. The program should allow a user to 
enter two integers representing a month and a year, and it should determine how many days are in the specified month. The integers 1 
through 12 will be used to identify the months of January through December. The user indicates the end of input by entering 0 0 for 
the month and year. At that point, the program prints the number of days in the current month and terminates.

Use the following criteria to identify leap years:

    1. A year Y is divisible by 100. Then Y is a leap year if and only if it is divisible by 400. For example, 2000 is a leap year but 
       2100 is not.

    2. A year Y is not divisible by 100. Then Y is a leap year if and only if it is divisible by 4. For example, 2008 is a leap year 
       but 2009 is not.

Here is sample run of the program:

        Enter month and year: 2 2008[Enter]
        29 days
        Enter month and year: 0 0[Enter] 

        The current month, September 2009, has 30 days.
*/

#include <iostream>
#include <ctime>  
using namespace std;

// Function prototypes
bool isLeapYear(int year);
int daysInMonth(int month, int year);
void displayCurrentMonthDays();

int main() {
    int month, year;

    while (true) {
        // Get user input for month and year
        cout << "Enter month and year (0 0 to print current month/year and quit): ";
        cin >> month >> year;

        // Exit condition (month and year == 0)
        if (month == 0 && year == 0) {
            displayCurrentMonthDays();
            break;
        }

        // Validate month input
        if (month < 1 || month > 12) {
            cout << "Invalid month. Please enter a number between 1 and 12.\n";
            continue;
        }

        // Display the number of days in the given month and year
        cout << daysInMonth(month, year) << " days\n";
    }

    return 0;
}

// Function to check if a year is a leap year
bool isLeapYear(int year) {
    if (year % 100 == 0) {
        return (year % 400 == 0);  // Divisible by 400, it's a leap year
    } else {
        return (year % 4 == 0);    // Divisible by 4 and not 100, it's a leap year
    }
}

// Function to return the number of days in a given month and year
int daysInMonth(int month, int year) {
    // Array to store the number of days in each month
    int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    // February has 29 days in a leap year
    if (month == 2 && isLeapYear(year)) {
        return 29;
    } else {
        return days[month - 1];
    }
}

// Function to display the number of days in the current month
void displayCurrentMonthDays() {
    // Get current system time
    time_t t = time(0);
    tm* now = localtime(&t);

    int currentYear = now->tm_year + 1900;  // tm_year is years since 1900
    int currentMonth = now->tm_mon + 1;     // tm_mon is 0-based, so add 1

    // Display the current month and number of days
    int days = daysInMonth(currentMonth, currentYear);

    // Month names array for display purposes
    string monthNames[] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

    cout << "\nThe current month, " << monthNames[currentMonth - 1] << " " << currentYear << ", has " << days << " days.\n";
}

