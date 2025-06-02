/*
Write a program that has at least 20 integers stored in an array in ascending order. It should call a 
function that uses the linear search algorithm to locate one of the values. The function should keep a 
count of the number of comparisons it makes until it finds the value. The program then should call a 
function that uses the binary search algorithm to locate the same value. It should also keep count of 
the number of comparisons it makes. Display these two counts on the screen.
*/

#include <iostream>
using namespace std;

// Function prototypes
int linearSearch(const int array[], int size, int value, int& comparisons);
int binarySearch(const int array[], int size, int value, int& comparisons);

int main()
{
    const int SIZE = 20;
    int array[SIZE] = {5, 12, 23, 28, 35, 42, 47, 53, 59, 62, 
                       68, 71, 77, 83, 88, 93, 98, 104, 110, 120};

    int value;
    cout << "Enter a value to search for: ";
    cin >> value;

    // Linear search
    int comparisonsLinear = 0;
    int indexLinear = linearSearch(array, SIZE, value, comparisonsLinear);

    // Binary search
    int comparisonsBinary = 0;
    int indexBinary = binarySearch(array, SIZE, value, comparisonsBinary);

    // Display results
    if (indexLinear != -1)
        cout << "Linear search found the value at index " << indexLinear << " after " << comparisonsLinear << " comparisons.\n";
    else
        cout << "Linear search did not find the value. Total comparisons made: " << comparisonsLinear << ".\n";

    if (indexBinary != -1)
        cout << "Binary search found the value at index " << indexBinary << " after " << comparisonsBinary << " comparisons.\n";
    else
        cout << "Binary search did not find the value. Total comparisons made: " << comparisonsBinary << ".\n";

    return 0;
}

// Linear search function
int linearSearch(const int array[], int size, int value, int& comparisons)
{
    for (int i = 0; i < size; i++)
    {
        comparisons++;  // Increment comparison counter
        if (array[i] == value)
            return i;  // Return index where the value is found
    }
    return -1;  // Value not found
}

// Binary search function
int binarySearch(const int array[], int size, int value, int& comparisons)
{
    int first = 0, last = size - 1, middle;

    while (first <= last)
    {
        comparisons++;  // Increment comparison counter
        middle = (first + last) / 2;

        if (array[middle] == value)
            return middle;  // Return index where the value is found
        else if (array[middle] > value)
            last = middle - 1;  // Search in the left half
        else
            first = middle + 1;  // Search in the right half
    }

    return -1;  // Value not found
}

