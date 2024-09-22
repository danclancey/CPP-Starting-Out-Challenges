/*
Write a program with a loop that lets the user enter a series of integers, followed by the end 
sentinel −99 to signal the end of the series. After all the numbers have been entered, the 
program should display the largest and smallest numbers entered.
*/

#include <iostream>
using namespace std;

int main() {
    int number, largest, smallest;

    // Prompt the user for the first number
    cout << "Enter a series of integers (enter -99 to stop): ";
    cin >> number;

    // Initialize largest and smallest with the first input number
    if (number != -99) {
        largest = smallest = number;

        // Loop to process the rest of the numbers
        while (number != -99) {
            // Check if the current number is larger or smaller than the stored values
            if (number > largest) {
                largest = number;
            }
            if (number < smallest) {
                smallest = number;
            }

            // Prompt for next number
            cin >> number;
        }

        // Display the results
        cout << "Largest number entered: " << largest << endl;
        cout << "Smallest number entered: " << smallest << endl;
    } else {
        cout << "No numbers were entered." << endl;
    }

    return 0;
}

