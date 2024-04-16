/*
  A particular brand of paint covers 340 square feet per gallon. Write a program to determine 
  and report approximately how many gallons of paint will be needed to paint two coats on each 
  side of a wooden fence that is 6 feet high and 100 feet long. 
*/

#include <iostream>
#include <iomanip>

// Declare constants
const int COVERAGE_PER_GALLON = 340; // Square feet
const int FENCE_HEIGHT = 6; // feet
const int FENCE_LENGTH = 100; // feet
const int COATS_OF_PAINT = 2;

using namespace std;

int main() 
{
  // Calculate paint requirements
  double totalArea = (FENCE_HEIGHT * FENCE_LENGTH);
  double gallonsNeeded = double(totalArea) / COVERAGE_PER_GALLON * COATS_OF_PAINT;
  
  // Format output
  cout << fixed << setprecision(2);

  // Display Results
  cout << "For a fence " << FENCE_HEIGHT << " feet tall and "
       << FENCE_LENGTH << " feet long, " << endl;
  cout << "you'll need approximately " << gallonsNeeded
       << " gallons of paint for " << COATS_OF_PAINT << " coats." << endl;
  return 0;
}
