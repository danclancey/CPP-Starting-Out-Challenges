/*
Assuming that a year has 365 days, write a class named DayOfYear that takes an integer representing a day of the year and translates it to 
a string consisting of the month followed by day of the month. For example,

        Day 2 would be January 2.
        Day 32 would be February 1.
        Day 365 would be December 31.

The constructor for the class should take as parameter an integer representing the day of the year, and the class should have a member 
function print() that prints the day in the month-day format. The class should have an integer member variable to represent the day and should 
have static member variables of type string to assist in the translation from the integer format to the month–day format.

Test your class by inputting various integers representing days and printing out their representation in the month–day format.
*/

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

class DayOfYear {
private:
    int day;
    static const std::string months[12];
    static const int daysInMonth[12];
    
    int convertDate(const std::string& month, int day) const;

public:
    // Constructors
    DayOfYear();
    DayOfYear(int dayOfYear); 
    DayOfYear(const std::string& month, int day);

    DayOfYear getInput();
    void print() const;

};

const std::string DayOfYear::months[12] = {
            "January", "February", "March", "April",
            "May", "June", "July", "August",
            "September", "October", "November", "December"
            };

const int DayOfYear::daysInMonth[12] = {
            31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31
            };

DayOfYear::DayOfYear(int dayOfYear) {
    if (dayOfYear < 1 || dayOfYear > 365) {
        throw std::invalid_argument("Invalid day of year");
    }
    day = dayOfYear;
}

DayOfYear::DayOfYear(const std::string& month, int day) {
    this->day = convertDate(month,day);
}

void DayOfYear::print() const {
    int remainingDays = day;
    for (int i = 0; i < 12; ++i) {
        if (remainingDays <= daysInMonth[i]) {
            std::cout << months[i] << " " << remainingDays << endl;
            return;
        }
        remainingDays -=daysInMonth[i];
    }
}

int DayOfYear::convertDate(const std::string& month, int day) const {
    int dayOfYear = 0;
    for (int i = 0; i < 12; ++i) {
        if (months[i] == month) {
            if (day < 1 || day > daysInMonth[i]) {
                throw std::invalid_argument("Invalid day for the given month");
            }
            dayOfYear += day;
            return dayOfYear;
        }
        dayOfYear += daysInMonth[i];
    }
    throw std::invalid_argument("Invalid month");
}

int main() {
    int userDay;

    cout << "Enter a day of the year (1-365): ";
    cin >> userDay;

    // Create a DayOfYear object
    DayOfYear day(userDay);

    // Print the day in month-day format
    cout << "The corresponding date is: ";
    day.print();

    return 0;
}
