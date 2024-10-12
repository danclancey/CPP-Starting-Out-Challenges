/*
Write a program that displays the Roman numeral equivalent of any 
decimal number between 1 and 20 that the user enters. The Roman 
numerals should be stored in an array of strings, and the decimal 
number that the user enters should be used to locate the array 
element holding the Roman numeral equivalent. The program should 
have a loop that allows the user to continue entering numbers 
until an end sentinel of 0 is entered.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    // Array to store roman numerals (1-20)
    string romanNums[20] = {
        "I", "II", "III", "IV", "V",
        "VI", "VII", "VIII", "IX", "X",
        "XI", "XII", "XIII", "XIV", "XV",
        "XVI", "XVII", "XVIII", "XIX" , "XX"
    };

    int num;

    // Main loop 
    do {
        cout << "Enter a number between 1 and 20 (0 to quit): ";
        cin >> num;

        // Input validation
        if (num < 0 || num > 20) {
            cout << "Invalid input!\n";
        } else if (num > 0) {
            // Display roman numeral for user number 
            cout << "Roman numeral equivalent of " << num << " is: " << romanNums[num - 1] << endl << endl;
        }
    } while (num != 0);

    cout << "Exiting . . .\n";

    return 0;
}
