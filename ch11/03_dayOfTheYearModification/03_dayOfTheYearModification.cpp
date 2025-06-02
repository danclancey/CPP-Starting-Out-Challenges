/*
Modify the DayOfYear class, written in an earlier Programming Challenge, to add a constructor that takes two parameters: a string representing
a month and an integer in the range 0 through 31 representing the day of the month. The constructor should then initialize the integer member
of the class to represent the day specified by the month and day of month parameters. The constructor should terminate the program with an
appropriate error message if the number entered for a day is outside the range of days for the month given.

Add the following overloaded operators:
        - ++ prefix and postfix increment operators. These operators should modify the DayOfYear object so that it represents the next day. If
          the day is already the end of the year, the new value of the object will represent the first day of the year.

        - -- prefix and postfix decrement operators. These operators should modify the DayOfYear object so that it represents the previous day.
          If the day is already the first day of the year, the new value of the object will represent the last day of the year.
*/

#include <iostream>
#include <iomanip>
#include "DayOfYear.h"

int main() {
    try {
        // Test 180th day of year
        DayOfYear date1(180);
        std::cout << std::left << std::setw(10) << "date1" << ": ";
        date1.print();
        ++date1;
        std::cout << std::endl << std::left << std::setw(10) << "++date1" << ": ";
        date1.print();
        date1--;
        std::cout << std::endl << std::left << std::setw(10) << "date1--" << ": ";
        date1.print();
        
        // Test 1st day of year
        DayOfYear date2(1);
        std::cout << std::endl << std::endl << std::left << std::setw(10) << "date2" << ": ";
        date2.print();
        --date2;
        std::cout << std::endl << std::left << std::setw(10) << "--date2" << ": ";
        date2.print();
        date2++; 
        std::cout << std::endl << std::left << std::setw(10) << "date2++" << ": ";
        date2.print();

        // Test December 31th
        DayOfYear date3("December", 31);
        std::cout << std::endl << std::endl << std::left << std::setw(10) << "date3" << ": ";
        date3.print();
        date3++;
        std::cout << std::endl << std::left << std::setw(10) << "++date3" << ": ";
        date3.print();
        date3--;
        std::cout << std::endl << std::left << std::setw(10) << "date3--" << ": ";
        date3.print();

        // Test Invalid Date
        std::cout << std::endl << std::endl << std::left << std::setw(10) << "date4" << ": ";
        DayOfYear date4("January", 44);

        // Exit Program
        std::cout << "\n\nGoodbye . . .\n\n";

    } catch (const std::invalid_argument &e) {
        std::cerr << "Error: " << e.what() << std::endl;
    }

    return 0;
}
