/* 
  An electronics company makes 64 gigabyte USB flash drives that cost them
  $8.00 apiece to produce. Write a program to determine how much the company
  should sell them for if it wants to make a 35 percent profit. Display the
  results on the screen.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// initialize constant for flash drive price and markup
const double FLASH_DRIVE_COST = 8.00;
const double FLASH_DRIVE_MARKUP = 0.35;

int main()
{
  // declare and calculate sale price for flash drive
  double salePrice = (FLASH_DRIVE_COST * FLASH_DRIVE_MARKUP) + FLASH_DRIVE_COST;
  
  // Display Output
  cout << "Flash Drive Cost: $" << fixed << setprecision(2) << FLASH_DRIVE_COST  << endl;
  cout << "Suggested Markup Percentage: " << setprecision(0) << FLASH_DRIVE_MARKUP * 100 << "%\n";
  cout << "Suggested Sale Price: $" << setprecision(2) <<  salePrice;

  return 0;
}
