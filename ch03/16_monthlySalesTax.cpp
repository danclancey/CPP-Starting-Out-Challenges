/*
  A retail company must file a monthly sales tax report listing the sales for the month and the amount of sales 
  tax collected. Write a program that asks for the month, the year, and the total amount collected at the cash 
  register (that is, sales plus sales tax). Assume the state sales tax is 4 percent and the county sales tax is 
  2 percent.

  If the total amount collected is known and the total sales tax is 6 percent, the amount of product sales may be 
  calculated as:
        
          S = T / 1.06

  Where S is the prodcut sales and T is the total income (product sales plus sales tax). The program shoud
  display a report similar to the following:

      Month: August 2016
      --------------------
      Total Collected:      $ 26572.89
      Sales:                $ 25068.76
      County Sales Tax:     $   501.38
      State Sales Tax:      $  1002.75
      Total Sales Tax:      $  1504.13
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Declare constants
const double STATE_TAX_RATE = 0.04;
const double COUNTY_TAX_RATE = 0.02;
const double TOTAL_TAX_RATE = STATE_TAX_RATE + COUNTY_TAX_RATE;

int main() 
{
  // Declare variables
  string month;
  int year;
  double totalCollected, sales, countyTax, stateTax, totalTax;
  
  // Weclome Message
  cout << "Welcome to Dan's Sales Calculator!\n";
  cout << "----------------------------------\n\n";
  cout << "This program will calculate amount of tax that must be filed\n"
       << "based on a months sales.\n\n";

  // Input
  cout << "Enter the month: ";
  getline(cin, month);
  cout << "Enter the year: ";
  cin >> year;
  cout << "Enter the total amount collected: $";
  cin >> totalCollected;

  // Calculate sales and taxes
  sales = totalCollected / (1 + TOTAL_TAX_RATE);
  stateTax = sales * STATE_TAX_RATE;
  countyTax = sales * COUNTY_TAX_RATE;
  totalTax = stateTax + countyTax;

  // Output report
  cout << "\nMonth: " << month << " " << year << endl;
  cout << "--------------------" << endl;
  cout << fixed << setprecision(2);
  cout << "Total Collected:      $" << setw(10) << totalCollected << endl;
  cout << "Sales:                $" << setw(10) << sales << endl;
  cout << "County Sales Tax:     $" << setw(10) << countyTax << endl;
  cout << "State Sales Tax:      $" << setw(10) << stateTax << endl;
  cout << "Total Sales Tax:      $" << setw(10) << totalTax << endl;

    return 0;
}

