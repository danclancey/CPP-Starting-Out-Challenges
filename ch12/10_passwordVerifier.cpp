/*
Imagine you are developing a software package that requires users to enter their own passwords. Your software requires that user’s 
passwords meet the following criteria:

    - The password should be at least six characters long.
    - The password should contain at least one uppercase and at least one lowercase letter.
    - The password should have at least one digit.

Write a program that asks for a password and then verifies that it meets the stated criteria. If it doesn’t, the program should 
display a message telling the user why.
*/

#include <iostream>
#include <cctype>  
#include <cstring> 

using namespace std;

// Function prototypes
bool isValidPassword(const string& password);
bool containsUppercase(const string& password);
bool containsLowercase(const string& password);
bool containsDigit(const string& password);

int main() {
    string password;

    // Prompt user to enter a password
    cout << "Enter your password: ";
    cin >> password;

    // Check if the password is valid based on the given criteria
    if (isValidPassword(password)) {
        cout << "Password is valid." << endl;
    } else {
        cout << "Password is invalid. Please meet the following criteria:\n";

        if (password.length() < 6) {
            cout << "- The password should be at least six characters long.\n";
        }
        if (!containsUppercase(password)) {
            cout << "- The password should contain at least one uppercase letter.\n";
        }
        if (!containsLowercase(password)) {
            cout << "- The password should contain at least one lowercase letter.\n";
        }
        if (!containsDigit(password)) {
            cout << "- The password should have at least one digit.\n";
        }
    }

    return 0;
}

// Function to check if the password meets all the required criteria
bool isValidPassword(const string& password) {
    return password.length() >= 6 && containsUppercase(password) &&
           containsLowercase(password) && containsDigit(password);
}

// Function to check if the password contains at least one uppercase letter
bool containsUppercase(const string& password) {
    for (char ch : password) {
        if (isupper(ch)) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one lowercase letter
bool containsLowercase(const string& password) {
    for (char ch : password) {
        if (islower(ch)) {
            return true;
        }
    }
    return false;
}

// Function to check if the password contains at least one digit
bool containsDigit(const string& password) {
    for (char ch : password) {
        if (isdigit(ch)) {
            return true;
        }
    }
    return false;
}

