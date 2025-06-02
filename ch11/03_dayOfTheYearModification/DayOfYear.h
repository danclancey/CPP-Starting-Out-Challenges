#ifndef DAYCHECKER_H
#define DAYCHECKER_H

#include <iostream>
#include <string>

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

    // Overloaded operators
    DayOfYear& operator++();
    DayOfYear operator++(int);
    DayOfYear& operator--();
    DayOfYear operator--(int);

};

#endif
