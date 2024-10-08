/*
You know that the == operator can be used to test if two string objects are equal. However, you will recall 
that they are not considered equal, even when they hold the exact same letters, if the cases of any letters 
are different. So, for example, if name1 = "Jack" and name2 = "JACK", they are not considered the same. 
Write a program that asks the user to enter two names and stores them in string objects. It should then 
report whether or not, ignoring case, they are the same.

To help the program accomplish its task, it should use two functions in addition to main, upperCaseIt() and 
sameString(). Here are their function headers.

    string upperCaseIt(string s)
    Boolean sameString (string s1, string s2)

The sameString function, which receives the two strings to be compared, will need to call upperCaseIt for each 
of them before testing if they are the same. The upperCaseIt function should use a loop so that it can call the 
toupper function for every character in the string it receives before returning it to the sameString function.
*/

#include <iostream>
#include <string>
#include <cctype>

using namespace std;

// Function prototypes
string upperCaseIt(string s);
bool sameString(string s1, string s2);

int main() {
    string name1, name2;

    // Get the two names from the user
    cout << "Enter the first name: ";
    getline(cin, name1);
    cout << "Enter the second name: ";
    getline(cin, name2);

    // Check if the names are the same, ignoring case
    if (sameString(name1, name2)) {
        cout << "The names are the same, ignoring case.\n";
    } else {
        cout << "The names are not the same.\n";
    }

    return 0;
}

// Function to convert a string to uppercase
string upperCaseIt(string s) {
    for (int i = 0; i < s.length(); i++) {
        s[i] = toupper(s[i]);
    }
    return s;
}

// Function to compare two strings, ignoring case
bool sameString(string s1, string s2) {
    // Convert both strings to uppercase
    s1 = upperCaseIt(s1);
    s2 = upperCaseIt(s2);

    // Compare the uppercase versions of the strings
    return s1 == s2;
}

