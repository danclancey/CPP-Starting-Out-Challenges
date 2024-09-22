/*
Write a program that asks the user for two positive integers between 2 and 10 to use 
for the length and width of a rectangle. If the numbers are different, the larger of 
the two numbers should be used for the length and the smaller for the width. The 
program should then display a rectangle of this size on the screen using the character 
‘X’. For example, if the user enters either 3 5 or 5 3, the program should display the 
following:

        XXXXX
        XXXXX
        XXXXX
*/

#include <iostream>

using namespace std;

int main() {
    int num1, num2, length, width;

    // Prompt for two positive integers between 2 and 10
    cout << "Enter two positive integers between 2 and 10:\n";
    cin >> num1 >> num2;

    // Input validation: both numbers must be between 2 and 10
    while (num1 < 2 || num1 > 10 || num2 < 2 || num2 > 10) {
        cout << "Invalid input! Please enter two numbers between 2 and 10: ";
        cin >> num1 >> num2;
    }

    // Determine which number is the length and which is the width
    if (num1 > num2) {
        length = num1;
        width = num2;
    } else {
        length = num2;
        width = num1;
    }

    // Display the rectangle
    for (int i = 0; i < width; i++) {
        for (int j = 0; j < length; j++) {
            cout << "X";
        }
        cout << endl;  // Move to the next line after printing a row
    }

    return 0;
}

