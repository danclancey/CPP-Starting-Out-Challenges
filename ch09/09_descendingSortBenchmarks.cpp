/*
Write a program that uses two identical arrays of at least 20 integers stored in a random order. It 
should call a function that uses the bubble sort algorithm modified to sort one of the arrays in 
descending order. The function should count the number of exchanges it makes. The program should then 
call a function that uses the selection sort algorithm modified to sort the other array in descending 
order. It should also count the number of exchanges it makes. Display the sorted data along with these 
two clearly labeled counts on the screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void bubbleSortDescending(int arr[], int size, int& exchanges);
void selectionSortDescending(int arr[], int size, int& exchanges);
void displayArray(const int arr[], int size);

const int SIZE = 20;

int main()
{
    int arr1[SIZE] = {54, 23, 65, 2, 99, 12, 89, 43, 33, 72,
                      9, 1, 77, 86, 50, 91, 18, 7, 42, 30};
    int arr2[SIZE];

    // Copy contents of arr1 to arr2
    for (int i = 0; i < SIZE; i++)
        arr2[i] = arr1[i];

    int bubbleExchanges = 0, selectionExchanges = 0;

    // Sort arr1 using bubble sort and count exchanges
    bubbleSortDescending(arr1, SIZE, bubbleExchanges);

    // Sort arr2 using selection sort and count exchanges
    selectionSortDescending(arr2, SIZE, selectionExchanges);

    // Display results
    cout << "Sorted array using bubble sort (descending order):\n";
    displayArray(arr1, SIZE);
    cout << "Bubble sort exchanges: " << bubbleExchanges << endl << endl;

    cout << "Sorted array using selection sort (descending order):\n";
    displayArray(arr2, SIZE);
    cout << "Selection sort exchanges: " << selectionExchanges << endl;

    return 0;
}

// Function to sort array using bubble sort in descending order
void bubbleSortDescending(int arr[], int size, int& exchanges)
{
    bool swapped;
    for (int i = 0; i < size - 1; i++)
    {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++)
        {
            if (arr[j] < arr[j + 1])
            {
                // Swap elements
                swap(arr[j], arr[j + 1]);
                swapped = true;
                exchanges++;
            }
        }
        if (!swapped) // If no elements were swapped, the array is sorted
            break;
    }
}

// Function to sort array using selection sort in descending order
void selectionSortDescending(int arr[], int size, int& exchanges)
{
    int maxIndex;
    for (int i = 0; i < size - 1; i++)
    {
        maxIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] > arr[maxIndex])
                maxIndex = j;
        }
        if (maxIndex != i)
        {
            swap(arr[i], arr[maxIndex]);
            exchanges++;
        }
    }
}

// Function to display the contents of an array
void displayArray(const int arr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
}

