/*
Design a class called NumDays. The class’s purpose is to store a value that represents a number of work hours and convert it to a number 
of days. For example, 8 hours would be converted to 1 day, 12 hours would be converted to 1.5 days, and 18 hours would be converted to 
2.25 days. The class should have a constructor that accepts a number of hours, as well as member functions for storing and retrieving the 
hours and days. The class should also have the following overloaded operators:

        - The addition operator +. The number of hours in the sum of two objects is the sum of the number of hours in the individual objects.
        - The subtraction operator −. The number of hours in the difference of two objects X and Y is the number of hours in X minus the 
          number of hours in Y.
        - Prefix and postfix increment operators ++. The number of hours in an object is incremented by 1.
        - Prefix and postfix decrement operators −−. The number of hours in an object is decremented by 1.
*/

#include <iostream>

using namespace std;

class NumDays {
    private:
        double hours;   // Number of hours worked

    public:
        // Constructor 
        NumDays(int h) : hours(h) {}

        // Mutator functions
        void setHours(double hours) { this->hours = hours; }
        
        // Accessor Functions 
        double getHours() { return hours; }
        double getDays() { return hours / 8.0; }

        // Overloaded operators 
        NumDays operator-(const NumDays &rhs) const { return NumDays(this->hours - rhs.hours); }
        NumDays operator+(const NumDays &rhs) const { return NumDays(this->hours + rhs.hours); }
        NumDays& operator++();
        NumDays operator++(int);
        NumDays& operator--();
        NumDays operator--(int);

};

// Prefix increment operator (++Object)
NumDays& NumDays::operator++() {
    ++this->hours;
    return *this;
}

// Postfix increment operator (Object++)
NumDays NumDays::operator++(int) {
    NumDays temp = *this;
    this->hours++;
    return temp;
}

// Prefix decrement operator (--Object)
NumDays& NumDays::operator--() {
    --this->hours;
    return *this;
}

// Postfix decrement operator (Object++)
NumDays NumDays::operator--(int) {
    NumDays temp = *this;
    this->hours--;
    return temp;
}

int main() {
    NumDays day1(8);  // Create object with 8 hours worked
    NumDays day2(10); // Create object with 10 hours worked 

    // Display init hours and days 
    cout << "Day 1: " << day1.getHours() << " hours (" << day1.getDays() << " days)\n";
    cout << "Day 2: " << day2.getHours() << " hours (" << day2.getDays() << " days)\n";

    // Add  
    NumDays total = day1 + day2;
    cout << "\nTotal after addition: " << total.getHours() << " hours (" << total.getDays() << " days)\n";

    // Subract 
    NumDays diff = day2 - day1;
    cout << "Total after subraction: " << diff.getHours() << " hours (" << diff.getDays() << " days)\n";

    // Increment 
    ++day1;
    cout << "\nDay1 after prefix increment: " << day1.getHours() << " hours (" << day1.getDays() << " days)\n";

    day2++;
    cout << "Day2 after postfix increment: " << day2.getHours() << " hours (" << day2.getDays() << " days)\n";

    // Decrement
    --day1;
    cout << "\nDay1 after prefix decrement: " << day1.getHours() << " hours (" << day1.getDays() << " days)\n";

    day2--;
    cout << "Day2 after postfix decrement: " << day2.getHours() << " hours (" << day2.getDays() << " days)\n";

    return 0;
}
