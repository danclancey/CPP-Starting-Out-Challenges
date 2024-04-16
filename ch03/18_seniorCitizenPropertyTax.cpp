/*
  Madison County provides a $5000 homeowner exemption for senior citizens. For example, if their house is 
  valued at $158,000 its assessed value would be $94,800, as explained above. However they would only pay 
  tax on $89,800. At last year’s tax rate of $2.64 for each $100 of assessed value, their property tax 
  would be $2370.72. In addition to the tax break, senior citizens are allowed to pay their property tax in 
  four equal payments. The quarterly payment due on this property would be $592.68. Write a program that 
  asks the user to input the actual value of a piece of property and the current tax rate for each $100 of 
  assessed value. The program should then calculate and report how much annual property tax a senior 
  homeowner will be charged for this property and what their quarterly tax bill will be.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const double ASSESSED_VALUE_PCT = 0.60;
const double SENIOR_EXEMPTION = 5000.00;
const int NUM_QUARTERS = 4;

int main()
{
  // Declare variables
  double actualValue, taxRate, assessedValue, taxableValue,
         propertyTax, quarterlyPayment;

  // Welcome Message
  cout << "Welcome to Dan's Senior Citizen property tax calculator!\n"
       << "--------------------------------------------------------\n\n"
       << "This program calculates the annual property tax and quarterly payments for senior citizens.";

  // Prompt user for input
  cout << "\nEnter the actual value of the property: $";
  cin >> actualValue;
  cout << "Enter the current tax rate (in dollars per $100 of assessed value): $";
  cin >> taxRate;

  // Calculate assessed value, senior exemption, property tax, and quarterly payments
  assessedValue = actualValue * ASSESSED_VALUE_PCT;
  taxableValue = assessedValue - SENIOR_EXEMPTION;
  propertyTax = taxableValue / 100 * taxRate;
  quarterlyPayment = propertyTax / NUM_QUARTERS;

  // Display results
  cout << fixed << setprecision(2);
  cout << "\nAssesedValue:      $" << setw(10) << assessedValue;
  cout << "\nTaxable Value:     $" << setw(10) << taxableValue;
  cout << "\nProperty Tax:      $" << setw(10) << propertyTax;
  cout << "\nQuarterly Payment: $" << setw(10) << quarterlyPayment << endl;

  return 0;
}
