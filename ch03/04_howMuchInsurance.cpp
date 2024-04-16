/* 
  Many financial experts advise property owners to insure their homes
  or buildings for at least 80 percent of thea mount it would cost to
  replace the structure. Write a program that asks the user to enter
  the replacement cost of a building and then displays the minimum
  amount of insurance that should be purchased for the property.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constant for minimum suggested insurance percentage
const double MIN_INSURANCE_PCT = .8;

int main()
{
  // Declare variables
  double replacementCost,
         minimumInsurance;

  // Welcome Message
  cout << "Welcome to Dans Minimum Insurance Calculator!\n";
  cout << "Please enter the replacement cost of your building: $";
  cin >> replacementCost;

  // Calculate minimum suggested insurance amount
  minimumInsurance = replacementCost * MIN_INSURANCE_PCT;

  // Display results
  cout << "It is recommended that you insurce you building for at least $"
       << fixed << setprecision(2) <<  minimumInsurance << " (80%)\n";

  return 0;  
}

