/*
This program started as a Chapter 3 Programming Challenge and was modified in a Chapter 4 
Programming Challenge. Starting with the version described in Chapter 4, modify the 
program again so that it displays a menu allowing the user to select an addition, 
subtraction, or multiplication problem. The final selection on the menu should let the user 
quit the program. After the user has finished the math problem, the program should display 
the menu again. This process must repeat until the user chooses to quit the program. If the 
user selects an item not on the menu, the program should print an error message and then 
display the menu again.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    int choice;
    
    // Display welcome message
    cout << "Welcome to the Math Tutor Program!" << endl;

    do {
        // Display the menu
        cout << "\nMath Tutor Menu\n";
        cout << "1. Addition Problem\n";
        cout << "2. Subtraction Problem\n";
        cout << "3. Multiplication Problem\n";
        cout << "4. Quit\n";
        cout << "Enter your choice (1-4): ";
        cin >> choice;

        // Validate menu choice
        while (choice < 1 || choice > 4) {
            cout << "Error: Invalid choice. Please select a valid option (1-4): ";
            cin >> choice;
        }

        if (choice == 4) {
            cout << "Thank you for using the Math Tutor Program. Goodbye!" << endl;
            break;
        }

        // Generate two random numbers between 1 and 9
        int num1 = rand() % 9 + 1;
        int num2 = rand() % 9 + 1;
        int studentAnswer, correctAnswer;

        if (choice == 1) {
            // Addition problem
            cout << "  " << num1 << endl;
            cout << "+ " << num2 << endl;
            cout << "-----" << endl;

            // Get the student's answer
            cout << "Enter your answer: ";
            cin >> studentAnswer;

            // Calculate the correct answer
            correctAnswer = num1 + num2;

        } else if (choice == 2) {
            // Subtraction problem
            cout << "  " << num1 << endl;
            cout << "- " << num2 << endl;
            cout << "-----" << endl;

            // Get the student's answer
            cout << "Enter your answer: ";
            cin >> studentAnswer;

            // Calculate the correct answer
            correctAnswer = num1 - num2;

        } else if (choice == 3) {
            // Multiplication problem
            cout << "  " << num1 << endl;
            cout << "* " << num2 << endl;
            cout << "-----" << endl;

            // Get the student's answer
            cout << "Enter your answer: ";
            cin >> studentAnswer;

            // Calculate the correct answer
            correctAnswer = num1 * num2;
        }

        // Display the correct answer
        cout << "Correct answer: " << correctAnswer << endl;

    } while (choice != 4);  // Repeat until the user chooses to quit

    return 0;
}

