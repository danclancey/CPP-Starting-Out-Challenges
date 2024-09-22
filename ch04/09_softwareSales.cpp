/*
  A software company sells a package that retails for $199. Quantity discounts are given according 
  to the following table.

                          Quantity	    Discount
                          10–19	        20%
                          20–49	        30%
                          50–99	        40%
                          100 or more	  50%

  Write a program that asks for the number of units purchased and computes the total cost of the 
  purchase.

  Input Validation: Decide how the program should handle an input of less than 0.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const double UNIT_PRICE = 199.0;
const double DISCOUNT_10_19 = 0.20;
const double DISCOUNT_20_49 = 0.30;
const double DISCOUNT_50_99 = 0.40;
const double DISCOUNT_100_PLUS = 0.50;

int main()
{
  // Declare variables
  int unitsPurchased;
  double totalCost, discountRate, discountedPrice;

  // Display welcome message
  cout << "Welcome to Dan's Quantity Discount Calculator!" << endl;
  cout << "----------------------------------------------\n\n";
  cout << "This program will calculate your discount based on software packages purchased!\n\n";

  // Prompt user for input
  cout << "Enter number of software packages purchased: ";
  cin >> unitsPurchased;

  if (unitsPurchased < 0) {
    cout << "Invalid input! Number of packages must be greater than 0! Exiting..\n";
    return 1;
  }

  // Determine discount rate
  if (unitsPurchased >= 10 && unitsPurchased <= 19) {
    discountRate = DISCOUNT_10_19;
  } else if (unitsPurchased >= 20 && unitsPurchased <= 49) {
    discountRate = DISCOUNT_20_49;
  } else if (unitsPurchased >= 50 && unitsPurchased <= 99) {
    discountRate = DISCOUNT_50_99;
  } else if (unitsPurchased >= 100) {
    discountRate = DISCOUNT_100_PLUS;
  } else {
    discountRate = 0.0;
  }

  // Calculate discounted price and total cost
  discountedPrice = UNIT_PRICE * (1 - discountRate);
  totalCost = unitsPurchased * discountedPrice;

  // Display total cost and discount
  cout << fixed << setprecision(2);
  cout << "Total cost of purchase: $" << totalCost << endl;
  
  return 0;
}
