/*
  Write a program that asks the user for an angle, entered in radians. The program should then display 
  the sine, cosine, and tangent of the angle. (Use the sin, cos, and tan library functions to determine 
  these values.) The output should be displayed in fixed-point notation, rounded to four decimal places 
  of precision.
*/

#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

int main() 
{
    double angleInRadians, sine, cosine, tangent;

    // Welcome message and program description
    cout << "Welcome to the Angle Calculator!" << endl;
    cout << "This program calculates the sine, cosine, and tangent of an angle entered in radians." << endl << endl;

    // Get the angle in radians from the user
    cout << "Enter the angle in radians: ";
    cin >> angleInRadians;

    // Calculate sine, cosine, and tangent
    sine = sin(angleInRadians);
    cosine = cos(angleInRadians);
    tangent = tan(angleInRadians);

    // Display the results rounded to four decimal places
    cout << fixed << setprecision(4);
    cout << setw(10) << left << "Sine: " << setw(10) << right <<  sine << endl;
    cout << setw(10) << left << "Cosine: " << setw(10) << right <<  cosine << endl;
    cout << setw(10) << left << "Tangent: " << setw(10) << right << tangent << endl;

    return 0;
}

