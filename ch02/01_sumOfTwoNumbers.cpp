/*
    Write a program that stores the integers 50 and 100 in variables
    and stores the sum of these two in a variable named total.
    Display the total on the screen
*/

#include <iostream>

using namespace std;

int main() 
{
    // Declare variables
    int num1 = 50, num2 = 100, total;

    // Calculate sum of two integers
    total = num1 + num2;

    // Display total
    cout << num1 << " + " << num2 << " = " << total;

    return 0;

}