/*
  During the past decade ocean levels have been rising faster than in the past, an average 
  of approximately 3.3 millimeters per year. Write a program that computes how much ocean 
  levels are expected to rise during the next 15 years if they continue rising at this rate. 
  Display the answer in both centimeters and inches.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const int FUTURE_YEARS = 15;
const double MILLIMETER_PER_YEAR = 3.3;
const double ONE_MM_IN_CM = 0.1;
const double ONE_CM_IN_INCHES = 0.3937;

int main() 
{
  // Calculate totals
  double riseInCentimeters = MILLIMETER_PER_YEAR * FUTURE_YEARS * ONE_MM_IN_CM;
  double riseInInches = riseInCentimeters * ONE_CM_IN_INCHES;

  // Format cout
  cout << fixed << setprecision(2);

  // Display Results
  cout << "Rise of Ocean levels in 15 years:\n"
       << "In Centimeters: " << riseInCentimeters << endl
       << "In Inches: " << riseInInches;

  return 0;

}
