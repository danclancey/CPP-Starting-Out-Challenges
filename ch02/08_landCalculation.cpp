/*
  In the United States, land is often measured in square feet. In many other countries,
  it is measured in square meters. One acre of land is equivalent to 43,560 square feet.
  A square meter is equivalent to 10.7639 square feet. Write a program that computes and
  displays the number of square feet and the number of square meters in .5 acre of land.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// initialize conversion constants
const double feetInAcres = 43560;
const double feetInMeters = 10.7639;

// Function prototypes
double convertAcreToFeet(double);
double convertAcreToMeter(double);

int main()
{
  // initialize acres to calculate
  double acres = 0.5;

  // Display output
  cout << "Acre Converter\n";
  cout << "There are " << convertAcreToFeet(acres) << " square feet in " << acres << " acres\n";
  cout << "There are " << convertAcreToMeter(acres) << " square meters in " << acres << "acres\n";

  return 0;
}

// Function to calculate how many square feet are in given acres
double convertAcreToFeet(double acres) {
  return acres * feetInAcres;
}

// Function to calculate how many square meters are in given acres
double convertAcreToMeter(double acres) {
  return (acres * feetInAcres) / feetInMeters;
}
