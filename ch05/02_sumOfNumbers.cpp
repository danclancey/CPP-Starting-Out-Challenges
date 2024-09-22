/*
Write a program that asks the user for a positive integer value and that uses a loop to validate the input. 
The program should then use a second loop to compute the sum of all the integers from 1 up to the number 
entered. For example, if the user enters 20, the loop will find the sum of Write a program that asks the user 
for a positive integer value and that uses a loop to validate the input. The program should then use a second 
loop to compute the sum of all the integers from 1 up to the number entered. For example, if the user enters 
20, the loop will find the sum of: 1 + 2 + 3 + 4 + . . . + 20 
*/

#include <iostream>

using namespace std;

int main() {
    int userInput;
    int total = 0;

    // Initial prompt
    cout << "Please enter a positive integer: ";
    cin >> userInput;

    // Validate input for positive integer
    while (userInput < 1) {
        cout << "Error: Please enter a positive Integer!\n";
        cout << "Please enter a positive integer: ";
        cin >> userInput;
    };
    
    // Sum all integers from 1 to userInput
    for (int i = 1; i <= userInput; i++) {
        total += i;
    }

    // Output result
    cout << "Sum of integers 1 through " << userInput << ": " << total << endl;

    return 0;
}
