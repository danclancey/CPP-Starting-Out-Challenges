/*
  The Earth's ocean levels have risen an average of 1.8 millimeters per year over
  the past century. Write a program that computes and displays the number of 
  centimeters and number of inches the oceans rose during that time. One millimeter
  is equivalent to 0.1 centimeters. One centimeter is equivalent to 0.3937 inches.
*/

#include <iostream>
#include <iomanip>

// Declare constants 
const int CENTURY_IN_YEARS = 100;
const double MILLIMETER_PER_YEAR = 1.8;
const double ONE_MM_IN_CM = 0.1;
const double ONE_CM_IN_INCHES = 0.3937;

using namespace std;

int main() 
{
  // Calculate totals
  double riseInCentimeters = MILLIMETER_PER_YEAR * CENTURY_IN_YEARS * ONE_MM_IN_CM;
  double riseInInches = riseInCentimeters * ONE_CM_IN_INCHES;

  // Format cout

  cout << fixed << setprecision(2);
  // Display Results
  cout << "Ocean level increase in past century:\n"
       << "In Centimeters: " << riseInCentimeters << endl
       << "In Inches: " << riseInInches;

  return 0;
}
