/*
Write a program that uses two identical arrays of eight randomly ordered integers. It should display 
the contents of the first array, then call a function to sort it using an ascending order bubble sort, 
modified to print out the array contents after each pass of the sort. Next the program should display 
the contents of the second array, then call a function to sort it using an ascending order selection 
sort, modified to print out the array contents after each pass of the sort.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void displayArray(const int arr[], int size);

const int SIZE = 8;

int main() {
    // Two identical arrays
    int arr1[SIZE] = {8, 3, 7, 1, 9, 4, 2, 5};
    int arr2[SIZE];

    // Copy contents of arr1 to arr2
    for (int i = 0; i < SIZE; i++) {
        arr2[i] = arr1[i];
    }

    // Display initial contents of arr1
    cout << "Original array (arr1): ";
    displayArray(arr1, SIZE);

    // Sort arr1 using bubble sort and print each pass
    cout << "\nBubble Sort Passes:\n";
    bubbleSort(arr1, SIZE);

    // Display initial contents of arr2
    cout << "\nOriginal array (arr2): ";
    displayArray(arr2, SIZE);

    // Sort arr2 using selection sort and print each pass
    cout << "\nSelection Sort Passes:\n";
    selectionSort(arr2, SIZE);

    return 0;
}

// Function to sort array using bubble sort in ascending order
void bubbleSort(int arr[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
                swapped = true;
            }
        }

        // Display the array after each pass
        cout << "Pass " << i + 1 << ": ";
        displayArray(arr, size);

        if (!swapped) // If no elements were swapped, the array is sorted
            break;
    }
}

// Function to sort array using selection sort in ascending order
void selectionSort(int arr[], int size) {
    int minIndex;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            swap(arr[i], arr[minIndex]);
        }

        // Display the array after each pass
        cout << "Pass " << i + 1 << ": ";
        displayArray(arr, size);
    }
}

// Function to display the contents of an array
void displayArray(const int arr[], int size) {
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

