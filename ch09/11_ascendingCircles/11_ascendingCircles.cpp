/*
Program 8-31 from Chapter 8 creates an array of four Circle objects, then displays the area of each 
object. Using a copy of that program as a starting point, modify it to create an array of seven Circle 
objects initialized with the following radii: 2.5, 4.0, 1.0, 3.0, 6.0, 5.5, 2.0. Then use a bubble sort 
to arrange the objects in ascending order of radius size before displaying the radius and area of each 
object.
*/

#include <iostream>
#include <iomanip>
#include "Circle.h"  // Circle class declaration file

using namespace std;

const int NUM_CIRCLES = 7;

// Function prototypes
void bubbleSort(Circle circleArray[], int size);
void displayCircles(const Circle circleArray[], int size);

int main() {
    // Initialize an array of Circle objects with given radii
    Circle circles[NUM_CIRCLES] = {
        Circle(2.5), Circle(4.0), Circle(1.0),
        Circle(3.0), Circle(6.0), Circle(5.5),
        Circle(2.0)
    };

    // Sort the circles in ascending order by radius
    bubbleSort(circles, NUM_CIRCLES);

    // Display the circles' radius and area
    displayCircles(circles, NUM_CIRCLES);

    return 0;
}

// Bubble sort to sort circles by radius in ascending order
void bubbleSort(Circle circleArray[], int size) {
    bool swapped;
    for (int i = 0; i < size - 1; i++) {
        swapped = false;
        for (int j = 0; j < size - i - 1; j++) {
            // Compare the radius of adjacent circles
            if (circleArray[j].getRadius() > circleArray[j + 1].getRadius()) {
                // Swap if the first radius is greater than the second
                swap(circleArray[j], circleArray[j + 1]);
                swapped = true;
            }
        }
        if (!swapped)
            break;  // No swaps means array is sorted
    }
}

// Function to display the circles' radius and area
void displayCircles(const Circle circleArray[], int size) {
    cout << fixed << showpoint << setprecision(2);
    cout << "\nCircles sorted by radius (ascending order):\n";
    cout << left << setw(10) << "Radius" << "Area\n";
    cout << "-----------------\n";

    for (int i = 0; i < size; i++) {
        cout << left << setw(10) << circleArray[i].getRadius()
             << circleArray[i].findArea() << " sq.units\n";
    }
}

