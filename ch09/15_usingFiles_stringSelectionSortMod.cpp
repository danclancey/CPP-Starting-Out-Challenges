/*
Modify the program you wrote for Programming Challenge 6 so it reads in the 20 strings from a file. The 
data can be found in the names.dat file located in the Chapter 9 programs folder on the book’s companion 
website.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Function prototype
void selectionSort(string array[], int size);
void displayArray(const string array[], int size);
void readNamesFromFile(string array[], int size, const string& filename);

int main()
{
    const int SIZE = 20;
    string name[SIZE];

    // Read names from the file
    readNamesFromFile(name, SIZE, "names.dat");

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

// Function to read names from file and store in the array
void readNamesFromFile(string array[], int size, const string& filename) {
    ifstream inputFile(filename);
    if (!inputFile) {
        cerr << "Error opening file: " << filename << endl;
        exit(1);  // Exit the program if file cannot be opened
    }

    // Read names from the file
    for (int i = 0; i < size; i++) {
        getline(inputFile, array[i]);
    }

    inputFile.close();  // Close the file after reading
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

