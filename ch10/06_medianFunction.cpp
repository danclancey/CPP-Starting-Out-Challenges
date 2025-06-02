/*
In statistics the median of a set of values is the value that lies in the middle when the values are arranged in sorted order. If the set 
has an even number of values, then the median is taken to be the average of the two middle values. Write a function that determines the 
median of a sorted array. The function should take an array of numbers and an integer indicating the size of the array and return the 
median of the values in the array. You may assume the array is already sorted. Use pointer notation whenever possible.
*/

#include <iostream>
using namespace std;

// Function prototype to find the median
double findMedian(const double* arr, int size);

int main() {
    // Example sorted array
    double values[] = {1.0, 2.0, 3.0, 4.0, 5.0};  // Odd number of elements
    int size = sizeof(values) / sizeof(values[0]);

    // Call the function and display the median
    cout << "Median of the array: " << findMedian(values, size) << endl;

    // Example with even number of elements
    double evenValues[] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0};  // Even number of elements
    size = sizeof(evenValues) / sizeof(evenValues[0]);

    // Call the function and display the median
    cout << "Median of the array: " << findMedian(evenValues, size) << endl;

    return 0;
}

// Function to find the median of a sorted array using pointer notation
double findMedian(const double* arr, int size) {
    if (size % 2 == 0) {
        // If even number of elements, return the average of the two middle elements
        return (*(arr + size / 2 - 1) + *(arr + size / 2)) / 2.0;
    } else {
        // If odd number of elements, return the middle element
        return *(arr + size / 2);
    }
}

