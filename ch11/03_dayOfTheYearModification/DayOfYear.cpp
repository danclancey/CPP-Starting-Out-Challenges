#include "DayOfYear.h"
#include <stdexcept>

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
            std::cout << months[i] << " " << remainingDays;
            return;
        }
        remainingDays -=daysInMonth[i];
    }
}

DayOfYear& DayOfYear::operator++() {
    day = (day == 365) ? 1 : day + 1;
    return *this;
}

DayOfYear DayOfYear::operator++(int) {
    DayOfYear temp = *this;
    ++(*this);
    return temp;
}

DayOfYear& DayOfYear::operator--() {
    day = (day == 1) ? 365 : day - 1;
    return *this;
}

DayOfYear DayOfYear::operator--(int) {
    DayOfYear temp = *this;
    --(*this);
    return temp;
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
