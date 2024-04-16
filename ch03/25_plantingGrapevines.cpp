/*
  A vineyard owner is planting several new rows of grapevines, and needs to know how many grapevines to plant 
  in each row. She has determined that after measuring the length of a future row, she can use the following 
  formula to calculate the number of vines that will fit in the row, along with the trellis end-post assemblies 
  that will need to be constructed at each end of the row:

                 R - 2E
          V =  ----------
                   S

  The terms in the formula are:
    * V is the number of grapevines that willf it in the row.
    * R is the length of the row, in feet.
    * E is the amount of space used by an end-post assembly.
    * S is the space between vinecs, in feet.
  
  Write a program taht makes the calculation for the vineyard owner. The program should ask the user t input
  the following:

    * The length of the row, in feet.
    * The amount of space used by an end-post assembly, in feet.
    * The amount of space between the vines, in feet.

  Once the input data has been entered, the program should calculate and display the number of grapevines that
  will fit in the row.
*/

#include <iostream>
#include <cmath>

using namespace std;

int main() 
{
    double rowLength, endPostSpace, vineSpace;
    int numVines;

    // Welcome message and program description
    cout << "Welcome to the Vineyard Calculator!" << endl;
    cout << "This program calculates the number of grapevines that will fit in a row." << endl << endl;

    // Get input from the user
    cout << "Enter the length of the row (in feet): ";
    cin >> rowLength;
    cout << "Enter the amount of space used by an end-post assembly (in feet): ";
    cin >> endPostSpace;
    cout << "Enter the amount of space between the vines (in feet): ";
    cin >> vineSpace;

    // Calculate the number of grapevines
    numVines = (rowLength - 2 * endPostSpace) / vineSpace;

    // Display the result
    cout << "The number of grapevines that will fit in the row: " << numVines << endl;

    return 0;
}

