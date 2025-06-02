/*
Modify Program 12-16 by adding a function

        string dollarFormat(double amount)

that takes a dollar amount in numeric form and returns a string formatted in currency notation, with a $ sign and commas inserted at the 
appropriate locations. Test your function using suitable inputs.
*/

// This program demonstrates the use of the string find
// and insert member functions.
#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <cmath>
#include <limits>

using namespace std;

string dollarFormat(string);  // Prototype
string dollarFormat(double);

int main() {
    // --- Test the original dollarFormat(string function) ---
    cout << "--- Testing the original dollarFormat(string function) ---" << endl;
    string inputS;
    cout << "Enter a dollar amount in the form nnnnn.nn (e.g., 12345.67): ";
    cin >> inputS;
    
    cout << "Formatted amount (from string input '" << inputS << "'): " << dollarFormat(inputS) << endl;
    cout << endl;

    // --- Test the new dollarFormat(double amount) function ---
    cout << "--- Testing the new dollarFormat(double amount) function ---" << endl;
    double amountD;

    cin.clear(); 
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
    cout << "Enter a dollar amount as a number (e.g., -67890.123 or 12345): ";
    cin >> amountD;
    cout << "Formatted amount (from double input " << amountD << "): " << dollarFormat(amountD) << endl;
    cout << endl;

    cout << "Additional hardcoded test cases for dollarFormat(double amount):" << endl;
    double test_values[] = {
        0.0, 0.5, 0.99, 0.999, 1.0, 123.45, 1234.56, 12345.67, 
        1234567.89, 9999999.99, -0.01, -0.75, -123.45, -1234567.89, 
        12345.0, 
        1234567890.12, -1234567890.123, 0.001, -0.001, 
        1000.0, 200.0, -0.0 
    };

    // Set formatting for printing the input double values clearly during tests
    cout << fixed << setprecision(3); // Show 3 decimal places for input double to see rounding

    for (double val : test_values) {
        cout << "Input: " << setw(20) << left << val 
             << "  Formatted: " << dollarFormat(val) << endl;
    }
    
    cout.unsetf(ios_base::fixed); 
    cout << setprecision(6);      

    return 0;
}

//******************************************************
// Returns a $-formatted version of the input string.  *
//******************************************************
string dollarFormat(string original) {
    string formatted = original;
    int dp = formatted.find('.');  // Position of decimal point
    int pos = dp;                  // Search for comma position
    while (pos > 3) {
        pos = pos - 3;
        formatted.insert(pos, ",");
    }

    formatted.insert(0, "$");
    return formatted;
}

//*******************************************************
// Returns a $-formatted version of input double        *
//*******************************************************
string dollarFormat(double amount) {
    ostringstream ss;
    ss << fixed << setprecision(2) << abs(amount);
    
    string numStr = ss.str();

    string integerPart;
    string fractionalPart;
    
    size_t decimalPos = numStr.find('.');

    if (decimalPos != string::npos) {
        integerPart = numStr.substr(0, decimalPos);
        fractionalPart = numStr.substr(decimalPos + 1);
    } else {
        integerPart = numStr;
        fractionalPart = "00";
    }

    int insertPosition = integerPart.length() - 3;
    while (insertPosition > 0) {
        integerPart.insert(insertPosition, ",");
        insertPosition -= 3;
    }

    string coreFormattedNumber = integerPart + "." + fractionalPart;

    if (signbit(amount)) {
        return "-$" + coreFormattedNumber;
    } else {
        return "$" + coreFormattedNumber;
    }
}
