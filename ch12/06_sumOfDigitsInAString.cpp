/*
Write a program that asks the user to enter a series of single-digit numbers with nothing separating them. Read the input as a 
C-string or a string object. The program should display the sum of all the single-digit numbers in the string. For example, if 
the user enters 2514, the program should display 12, which is the sum of 2, 5, 1, and 4. The program should also display the 
highest and lowest digits in the string.
*/

#include <iostream>
#include <cstring>
#include <cctype>  

using namespace std;

int main() {
    const int SIZE = 100;  // Maximum size for the input string
    char numberString[SIZE];
    int sum = 0;
    int highest = -1;
    int lowest = 10;

    // Get the input from the user
    cout << "Enter a series of single-digit numbers with no spaces: ";
    cin.getline(numberString, SIZE);

    // Process each character in the input string
    for (int i = 0; i < strlen(numberString); i++) {
        if (isdigit(numberString[i])) {         // Ensure that the character is a digit
            int digit = numberString[i] - '0';  // Convert character to its integer value
            sum += digit;

            if (digit > highest) {
                highest = digit;
            }

            if (digit < lowest) {
                lowest = digit;
            }
        } else {
            cout << "Invalid input. Only single-digit numbers are allowed.\n";
            return 1;                           // Exit the program if invalid input is found
        }
    }

    // Display the sum, highest, and lowest digits
    cout << "Sum of digits: " << sum << endl;
    cout << "Highest digit: " << highest << endl;
    cout << "Lowest digit: " << lowest << endl;

    return 0;
}

