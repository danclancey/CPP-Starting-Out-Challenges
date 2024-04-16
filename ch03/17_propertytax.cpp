/*
  Madison County collects property taxes on the assessed value of property, which is 60 percent of its actual value. 
  For example, if a house is valued at $158,000, its assessed value is $94,800. This is the amount the homeowner 
  pays tax on. At last year’s tax rate of $2.64 for each $100 of assessed value, the annual property tax for this 
  house would be $2502.72. Write a program that asks the user to input the actual value of a piece of property and 
  the current tax rate for each $100 of assessed value. The program should then calculate and report how much annual 
  property tax the homeowner will be charged for this property.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constant for assessed value percentage
const double ASSESSED_VALUE_PCT = 0.60;

int main()
{
  // Declare variables
  double actualValue, taxRate, assessedValue, propertyTax;
  
  // Welcome message
  cout << "Welcome to Dan's Property Tax calculator!\n"
       << "-----------------------------------------\n\n"
       << "This program will prompt you for a property value and its tax rate.\n"
       << "It will then calculate the Assessed Value and the amount of property tax owed for the year.\n\n";
  // Prompt user for input
  cout << "Enter the actual value of the property: $";
  cin >> actualValue;
  cout << "Enter the current tax rate (in dollars per $100 of assessed value): $";
  cin >> taxRate;

  // Calculate assessed value and property tax

  assessedValue = actualValue * ASSESSED_VALUE_PCT;
  propertyTax = assessedValue / 100 * taxRate;

  // Display Results
  cout << fixed << setprecision(2);
  cout << "\nAssessed Value: $" << setw(10) << assessedValue
       << "\nPropertyTax:    $" << setw(10) << propertyTax << endl;

  return 0;
}
