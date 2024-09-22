/*
  Write a program that asks the user to enter a year and then reports when the next leap year will be. 
  Here are program outputs from two sample runs.

        Enter a year: 2019[Enter] 
        The next leap year is 2020.
        Enter a year:  2024[Enter]
        2024 is a leap year.
*/

#include <iostream>

using namespace std;

int main() {
    int year;
    int nextLeapYear;

    cout << "Enter a year: ";
    cin >> year;

    // Check if the entered year is a leap year
    bool isLeapYear = (year % 400 == 0) || (year % 100 != 0 && year % 4 == 0);

    if (isLeapYear) {
        // If the current year is a leap year, display that
        cout << year << " is a leap year." << endl;
    } else {
        // Find the next leap year by incrementing the year
        nextLeapYear = year + 1;
        while (!((nextLeapYear % 400 == 0) || (nextLeapYear % 100 != 0 && nextLeapYear % 4 == 0))) {
            nextLeapYear++;
        }
        cout << "The next leap year is " << nextLeapYear << endl;
    }

    return 0;
}

