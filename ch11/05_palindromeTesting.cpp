/*
A palindrome is a string that reads the same backward as forward. For example, the words mom, dad, madam, and radar are all palindromes. 
Write a class Pstring that is derived from the STL string class. The Pstring class adds a member function

        bool isPalindrome( )

that determines whether the string is a palindrome. Include a constructor that takes an STL string object as parameter and passes it to 
the string base class constructor. Test your class by having a main program that asks the user to enter a string. The program uses the 
string to initialize a Pstring object and then calls isPalindrome() to determine whether the string entered is a palindrome.

You may find it useful to use the subscript operator [] of the string class: If str is a string object and k is an integer, then str[k] 
returns the character at position k in the string.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

class Pstring : public string {
    public:
        // Constructor - taking a string object 
        Pstring (const string& str) : string(str) {}

        // Member Function - check for palindrome 
        bool isPalindrome();
};

bool Pstring::isPalindrome() {
    int length = this->length();
    string cleanedStr = "";

    // Remove spaced and punctuation
    for (int i = 0; i < length; i++) {
        if(isalnum((*this)[i])) {
            cleanedStr += tolower((*this)[i]);
        }
    }

    // Update length after cleaning string 
    length = cleanedStr.length();

    // Check if palindrome 
    for (int i = 0; i < length / 2; i++) {
        if (cleanedStr[i] != cleanedStr[length - 1 - i]) {
            return false; // Characters don't match, return not palindrome 
        }
    }

    return true;    // All characters match, return is palindrome 
}

int main() {
    string inputStr;
    cout << "Dan's Palindrome Checker\n\n";
    cout << "Enter a string (word or phrase): ";
    getline(cin, inputStr);

    Pstring pstr(inputStr);
    if (pstr.isPalindrome()) {
        cout << " - \"" << inputStr << "\" is a palindrome.\n";
    } else {
        cout << " - \"" << inputStr << "\" is not a palindrome.\n";
    }

    return 0;
}
