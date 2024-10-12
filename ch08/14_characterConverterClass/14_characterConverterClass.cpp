/*
Create a CharConverter class that performs various operations on strings. 
It should have the following two public member functions to start with. 
Your instructor may ask you to add more functions to the class.

    - The uppercase member function accepts a string and returns a copy 
      of it with all lowercase letters converted to uppercase. If a 
      character is already uppercase or is not a letter, it should be 
      left alone.
    - The properWords member function accepts a string of words separated 
      by spaces and returns a copy of it with the first letter of each word 
      converted to uppercase.

Write a simple program that uses the class. It should prompt the user to 
input a string. Then it should call the properWords function and display the 
resulting string. Finally, it should call the uppercase function and display 
this resulting string. The program should loop to allow additional strings 
to be converted and displayed until the user chooses to quit.
*/

#include <iostream>
#include <limits>
#include <string>
#include "CharConverter.h"

using namespace std;

int main() {
    CharConverter converter;
    string input;
    char choice;

    cout << "Welcome to Dan's CharConverter Program!\n";

    do {
        // Get input from user 
        cout << "\nEnter a string: ";
        getline(cin, input);

        // Convert and display using properWords 
        string proper = converter.properWords(input);
        cout << "\nProper words: " << proper << endl;

        // Convert and display using uppercase 
        string upper = converter.uppercase(input);
        cout << "Uppercase: " << upper << endl;

        // Ask user if they want to enter another string 
        cout << "\nConvert another string? (y/n): ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

    } while (tolower(choice) == 'y');

    cout << "\nThank you for using Dan's CharConverter.\n Exiting . . .\n";

    return 0;
}
