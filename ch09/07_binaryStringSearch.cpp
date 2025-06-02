/*
Modify the binarySearch function presented in this chapter so it searches an array of strings instead of 
an array of ints. Test the function with a driver program. Use Program 9-9 as a skeleton to complete. 
(The array must be sorted before the binary search will work.)
*/

#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

// Function prototypes
int binarySearch(const string array[], int size, const string& value);
void selectionSort(string array[], int size);
void displayArray(const string array[], int size);

int main()
{
    const int SIZE = 20;
    string name[SIZE] = 
    {"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
     "Sanchez, Manny",  "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
     "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
     "Moretti, Bella", "Wu, Eric",     "Patel, Renee",   "Harrison, Rose",
     "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};

    // Sort the array
    selectionSort(name, SIZE);

    // Display the sorted array
    cout << "Sorted list of names:\n";
    displayArray(name, SIZE);

    // Ask the user to search for a name
    string searchName;
    cout << "\nEnter a name to search for: ";
    getline(cin, searchName);

    // Perform binary search
    int result = binarySearch(name, SIZE, searchName);

    // Display the result of the search
    if (result != -1)
        cout << searchName << " was found at index " << result << ".\n";
    else
        cout << searchName << " was not found.\n";

    return 0;
}

// Binary search function for string array
int binarySearch(const string array[], int size, const string& value)
{
    int first = 0;
    int last = size - 1;
    int middle;
    bool found = false;

    while (first <= last && !found)
    {
        middle = (first + last) / 2;

        if (array[middle] == value)   // If value is found
            return middle;
        else if (array[middle] > value)  // If value is in the lower half
            last = middle - 1;
        else                            // If value is in the upper half
            first = middle + 1;
    }

    return -1;  // Not found
}

// Selection sort function for string array
void selectionSort(string array[], int size)
{
    int minIndex;
    string minValue;

    for (int start = 0; start < (size - 1); start++)
    {
        minIndex = start;
        minValue = array[start];
        for (int index = start + 1; index < size; index++)
        {
            if (array[index] < minValue) // Compare strings
            {
                minValue = array[index];
                minIndex = index;
            }
        }
        swap(array[minIndex], array[start]);
    }
}

// Function to display the array
void displayArray(const string array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << endl;
    }
}

