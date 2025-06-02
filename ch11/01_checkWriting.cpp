/*
Design a class Numbers that can be used to translate whole dollar amounts in the range 0 through 9999 into an English description of 
the number. For example, the number 713 would be translated into the string seven hundred thirteen, and 8203 would be translated into 
eight thousand two hundred three.

The class should have a single integer member variable

        int number;

and a collection of static string members that specify how to translate key dollar amounts into the desired format. For example, you 
might use static strings such as

        string lessThan20[ ] =
            {"zero", "one", …, "eighteen", "nineteen" };
        string hundred = "hundred";
        string thousand = "thousand";

The class should have a constructor that accepts a non-negative integer and uses it to initialize the Numbers object. It should have a 
member function print() that prints the English description of the Numbers object. Demonstrate the class by writing a main program that 
asks the user to enter a number in the proper range and then prints out its English description.
*/

#include <iostream>
#include <string>

using namespace std;

class Numbers {
    private: 
        int number;                     // Number to be translates

        // Static arrays for translating number into word 
        static string lessThan20[20];
        static string tens[10];
        static string hundred;
        static string thousand;

    public:
        Numbers(int n);                 // Constructor for non-negative number 
        
        void print() const;             // Function to print number as words 


};

// Param Constructor for non-neg word 
Numbers::Numbers(int n) {
    if (n >= 0 && n <= 9999) {
        number = n;
    } else {
        cout << "Number out of range. Defaulting to 0.\n";
        number = 0;
    }
}

// Function to print number in words 
void Numbers::print() const {
    if (number == 0) {
        cout << lessThan20[0] << endl;
        return;
    }

    int num = number;

    if (num >= 1000) {
        cout << lessThan20[num /1000] << " " << thousand; 
        num %= 1000;
        if (num > 0)
            cout << " ";
    }

    if (num >= 100) {
        cout << lessThan20[num / 100] << " " << hundred;
        num %= 100;
        if (num > 0)
            cout << " ";
    }
    
    if (num >= 20) {
        cout << tens[num / 10];
        num %= 10;
        if (num > 0)
            cout << " ";
    }

    if (num > 0 && num < 20) {
        cout << lessThan20[num];
    }

    cout << endl;

}

// Static member init 
string Numbers::lessThan20[20] = {
    "zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine", 
    "ten", "eleven", "twelve", "thirteen", "fourteen", "fifteen", "sixteen", 
    "seventeen", "eighteen", "nineteen"
};

string Numbers::tens[10] = {
    "", "", "twenty", "thirty", "forty", "fifty", "sixty", "seventy", "eighty", "ninety"
};

string Numbers::hundred = "hundred";
string Numbers::thousand = "thousand";

// Main program 
int main() {
    int userNum;

    cout << "Enter a number between 0 and 9999: ";
    cin >> userNum;

    // Create a numbers object 
    Numbers number(userNum);

    // Print number in words 
    cout << "The number in words is: ";
    number.print();

    return 0;
}
