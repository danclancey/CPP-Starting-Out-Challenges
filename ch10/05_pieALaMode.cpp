/*
In statistics the mode of a set of values is the value that occurs most often. Write a program that determines how many pieces of pie 
most people eat in a year. Set up an integer array that can hold responses from 30 people. For each person, enter the number of pieces 
they say they eat in a year. Then write a function that finds the mode of these 30 values. This will be the number of pie slices eaten 
by the most people. The function that finds and returns the mode should accept two arguments, an array of integers, and a value 
indicating how many elements are in the array.
*/

#include <iostream>
using namespace std;

// Function prototype to find the mode
int findMode(int arr[], int size);

int main() {
    const int SIZE = 30;
    const int MAX_PIE_SLICES = 100; // Assume no one eats more than 100 slices a year
    int pieSlices[SIZE];

    // Get responses from 30 people
    cout << "Enter the number of pie slices each of 30 people eat in a year (0-" << MAX_PIE_SLICES << "):\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Person " << i + 1 << ": ";
        cin >> pieSlices[i];

        // Input validation to ensure non-negative values within reasonable range
        while (pieSlices[i] < 0 || pieSlices[i] > MAX_PIE_SLICES) {
            cout << "Invalid input. Please enter a number between 0 and " << MAX_PIE_SLICES << ": ";
            cin >> pieSlices[i];
        }
    }

    // Find the mode
    int mode = findMode(pieSlices, SIZE);

    // Display the result
    if (mode != -1) {
        cout << "\nThe mode (number of pie slices eaten by most people) is: " << mode << endl;
    } else {
        cout << "\nNo mode found (every value appears only once).\n";
    }

    return 0;
}

// Function to find the mode of the values in the array
int findMode(int arr[], int size) {
    const int MAX_PIE_SLICES = 101; // Include 0 to 100 slices
    int frequency[MAX_PIE_SLICES] = {0};  // Frequency array to count occurrences of each slice count

    // Count the occurrences of each value
    for (int i = 0; i < size; i++) {
        frequency[arr[i]]++;  // Increment the frequency for the corresponding number of pie slices
    }

    // Find the value with the highest frequency
    int mode = -1;
    int maxCount = 0;

    for (int i = 0; i < MAX_PIE_SLICES; i++) {
        if (frequency[i] > maxCount) {
            maxCount = frequency[i];
            mode = i;
        }
    }

    // Check if there is no mode (all values appear only once)
    if (maxCount == 1) {
        return -1;  // No mode
    }

    return mode;
}

