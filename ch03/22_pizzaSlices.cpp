/*  
  Joe’s Pizza Palace needs a program to calculate the number of slices a pizza of any size can be divided into. 
  The program should perform the following steps:

    * Ask the user for the diameter of the pizza in inches.
    * Divide the diameter by 2 to get the radius.
    * Calculate the number of slices that may be taken from a pizza of that size if each slice has an area 
      of 14.125 square inches.
    * Display a message telling the number of slices.

  The number of square inches in the total pizza can be calculated with this formula:

        Area = πr^2

  where variable 'r' is the radius of the pizza and π is the Greek letter PI. In your program make PI a named 
  constant with the value 3.14. Display the number of slices as a whole number (i.e., with no decimals).
*/

#include <iostream>
using namespace std;

const double PI = 3.14;
const double sliceArea = 14.125;

int main() 
{
    double diameter, radius, area;
    int numSlices;

    // Welcome message and program description
    cout << "Welcome to Joe's Pizza Palace!" << endl;
    cout << "This program calculates the number of slices a pizza can be divided into based on its diameter." << endl << endl;

    // Get the diameter of the pizza from the user
    cout << "Enter the diameter of the pizza in inches: ";
    cin >> diameter;

    // Calculate the radius, area, and number of slices
    radius = diameter / 2.0;
    area = PI * radius * radius;
    numSlices = area / sliceArea;

    // Display the number of slices
    cout << "The number of slices for a pizza with diameter " << diameter << " inches is: " << numSlices << endl;

    return 0;
}

