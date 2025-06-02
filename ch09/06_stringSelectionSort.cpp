/*
Modify the selectionSort function presented in this chapter so it sorts an array of strings instead of 
an array of ints. Test the function with a driver program. Use Program 9-9 as a skeleton to complete.

Program 9-9

// Include needed header files here.
int main()
{
const int SIZE = 20;
string name[SIZE] = 
{"Collins, Bill",  "Smith, Bart",  "Michalski, Joe", "Griffin, Jim",
"Sanchez, Manny",  "Rubin, Sarah", "Taylor, Tyrone", "Johnson, Jill", 
 "Allison, Jeff",  "Moreno, Juan", "Wolfe, Bill",    "Whitman, Jean",
 "Moretti, Bella", "Wu, Eric",     "Patel, Renee",   "Harrison, Rose",
 "Smith, Cathy",   "Conroy, Pat",  "Kelly, Sean",    "Holland, Beth"};
// Insert your code to complete this program.
}
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototype
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

    // Display the original array
    cout << "Original list of names:\n";
    displayArray(name, SIZE);

    // Sort the array
    selectionSort(name, SIZE);

    // Display the sorted array
    cout << "\nSorted list of names:\n";
    displayArray(name, SIZE);

    return 0;
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
        // Swap the found minimum value with the current start position
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

