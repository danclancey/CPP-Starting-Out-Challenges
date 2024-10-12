/*
Create a program with a function that accepts three arguments: an 
integer array, an integer size that indicates how many elements are
in the array, and an integer n. The function should display all of 
the numbers in the array that are greater than the number n.
*/

#include <iostream>

using namespace std;

// Function Prototype
void displayGreater(int arr[], int size, int n);

int main() {

    const int SIZE = 5;
    int nums[SIZE];
    int n;

    // Prompt user for 5 integers 
    cout << "Enter 5 integers\n";
    for (int i = 0; i < SIZE; i++) {
        cout << "Integer " << i + 1 << ": ";
        cin >> nums[i];
    }
    
    // Ask for number to compare against
    cout << "Enter integer to compare array against: ";
    cin >> n;

    // Call displayGreater function
    cout << "\nValues great than " << n << " are: \n";
    displayGreater(nums,SIZE, n);

    return 0;
}


// Function to display elements greater than n
void displayGreater(int arr[], int size, int n) {
    int count = 0;
    
    // loop through array and display elements greater than 'n'
    for (int i = 0; i < size; i++) {
        if (arr[i] > n) {
            cout << arr[i] << " ";
            count++;
        }
    }
    
    // Check if no values were greater than 'n'
    if (count == 0) {
        cout << "No values are greater than " << n << ".";
    }

    cout << endl;
}
