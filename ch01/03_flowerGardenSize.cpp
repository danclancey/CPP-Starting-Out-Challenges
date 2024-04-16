/*
    Write a program that caluclates the size of a rectangular flower
    garden in a nature center. The program should prompt the user to
    enter the length and width of the garden in feet. It should then
    calculate and display the number of square feet in the garden.
*/

#include <iostream>

using namespace std;

int main()
{
    // Declare variables
    double length, width, totalSize;

    // Prompt user for length and width
    cout << "What is the length of the flower garden in feet? ";
    cin >> length;

    cout << "What is the width of the flower garden in feet? ";
    cin >> width;

    // Calculate the size of the garden

    totalSize = length * width;

    cout <<"The total size of the flower garden is: " << totalSize << " feet";

    return 0;
}