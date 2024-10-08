/*
A prime number is an integer greater than 1 that is evenly divisible by only 1 and itself. For example, the 
number 5 is prime because it can only be evenly divided by 1 and 5. The number 6, however, is not prime 
because it can be divided by 1, 2, 3, and 6.

Write a Boolean function named isPrime, which takes an integer as an argument and returns true if the 
argument is a prime number, and false otherwise. Demonstrate the function in a complete program.

Tip
Recall that the % operator divides one number by another and returns the remainder of the division. In an 
expression such as num1 % num2, the % operator will return 0 if num1 is evenly divisible by num2.
*/

#include <iostream>
using namespace std;

// Function prototype
bool isPrime(int num);

int main() {
    int number;

    // Get input from the user
    cout << "Enter an integer greater than 1 to check if it is prime: ";
    cin >> number;

    // Validate input
    while (number <= 1) {
        cout << "Number must be greater than 1. Please enter a valid number: ";
        cin >> number;
    }

    // Check if the number is prime and display the result
    if (isPrime(number)) {
        cout << number << " is a prime number." << endl;
    } else {
        cout << number << " is not a prime number." << endl;
    }

    return 0;
}

// Function to determine if a number is prime
bool isPrime(int num) {
    if (num <= 1) {
        return false; // Numbers less than or equal to 1 are not prime
    }

    // Check for factors from 2 up to the square root of num
    for (int i = 2; i * i <= num; i++) {
        if (num % i == 0) {
            return false; // If divisible by any number, it is not prime
        }
    }

    return true; // If no factors were found, the number is prime
}

