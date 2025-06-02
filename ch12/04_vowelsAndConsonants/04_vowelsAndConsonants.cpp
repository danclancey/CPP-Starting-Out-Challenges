/*
Write a function that accepts a C-string as its argument. The function should count the number of vowels appearing in the string 
and return that number.

Write another function that accepts a C-string as its argument. This function should count the number of consonants appearing in 
the string and return that number.

Demonstrate the two functions in a program that performs the following steps:
    - The user is asked to enter a string.
    - The program displays the following menu:
        - Count the number of vowels in the string
        - Count the number of consonants in the string
        - Count both the vowels and consonants in the string
        - Enter another string
        - Exit the program

The program performs the operation selected by the user and repeats until the user selects E, to exit the program.
*/
#include <iostream>
#include <limits>
#include <iomanip>
#include "StringChecker.h"

using namespace std;

void displayMenu();
char getMenuChoice();

int main() {
    StringChecker checker;
    char choice;

    cout << "Dan's Vowel and Consonant Counter\n\n";

    while (true) {
        checker.setInputString();

        while (true) {
            displayMenu();
            choice = getMenuChoice();

            if (choice == 'E') {
                cout << "Exiting . . .\n\n";
                return 0; // Exit the program
            } else if (choice == '4') {
                break; // Go back to getInputString
            }

            // Process the input based on the menu choice
            switch (choice) {
                case '1':
                    cout << "- Number of vowels: " << StringChecker::countVowels(checker.getInputString().c_str()) << endl;
                    break;
                case '2':
                    cout << "- Number of consonants: " << StringChecker::countConsonants(checker.getInputString().c_str()) << endl;
                    break;
                case '3':
                    cout << "- " << left << setw(20) << "Number of vowels" << ": " 
                              << StringChecker::countVowels(checker.getInputString().c_str()) << endl;
                    cout << "- " << left << setw(20) << "Number of consonants" << ": " 
                              << StringChecker::countConsonants(checker.getInputString().c_str()) << endl;
                    break;
            }

            cout << "\nPress [Enter] to return to Menu . . .";
            cin.get();
        }
    }
}

void displayMenu() {
    cout << "\nMenu:\n";
    cout << "1. Count vowels\n";
    cout << "2. Count consonants\n";
    cout << "3. Count both\n";
    cout << "4. Enter another string\n";
    cout << "E. Exit\n";
}

char getMenuChoice() {
    char choice;
    do {
        cout << "\nChoice: ";
        cin >> choice;
        cin.ignore(numeric_limits<streamsize>::max(),'\n');

        choice = toupper(choice);
        if ((choice < '1' || choice > '4') && choice != 'E') {
            cout << "Invalid input. Please enter 1-4 or 'E' to exit.\n";
        }
    } while ((choice < '1' || choice > '4') && choice != 'E'); // Loop until valid choice selected

    return choice;
}

