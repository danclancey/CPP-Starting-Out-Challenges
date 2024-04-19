/*
  The area of a rectangle is the rectangle’s length times its width. Write a program that asks for the length 
  and width of two rectangles. The program should then tell the user which rectangle has the greater area or 
  if the areas are the same.
*/

#include <iostream>

using namespace std;

int main()
{
  // Declare variables
  double aRectWidth,
         aRectLength,
         bRectWidth,
         bRectLength,
         areaA,
         areaB;

  // Welcome message
  cout << "Weclome to Dan's rectangle analyzer!\n"
       << "------------------------------------\n";
  cout << "\nThis Program will calculate the area of two given rectcangles.\n"
       << "Then it will calculate which rectangle is larger.\n\n";

  // Prompt user for input
  cout << "Please enter Width of Rectangle A (in inches): ";
  cin >> aRectWidth;
  cout << "Please enter Length of Rectangle A (in inches): ";
  cin >> aRectLength;
  cout << "Please enter Width of Rectangle B (in inches): ";
  cin >> bRectWidth;
  cout << "Please enter Length of Rectangle B (in inches): ";
  cin >> bRectLength;

  // Validate input
  if (aRectWidth <= 0 || aRectLength <= 0 || bRectWidth <= 0 || bRectLength <= 0)
  {
    cout << "Invalid input! Values must be greater than 0! Exiting..\n";
    return 1;
  }

  // Calculare area of rectangles
  areaA = aRectWidth * aRectLength;
  areaB = bRectWidth * bRectLength;

  // Determine which rectangle is larger and inform user
  if ( areaA > areaB )
  {
    cout << "\nRectangle A, with an area of " << areaA << " square inches, "
         << "is larger than Rectangle B (" << areaB << " square inches).\n";
  } else if ( areaA < areaB )
  {
    cout << "\nRectangle B, with an area of " << areaB << " square inches, "
         << "is larger than Rectangle A (" << areaA << " square inches)\n";
  } else 
  {
    cout << "\nRectangle A and B are equal in size! They are both " << areaA << " square inches!\n";
  }

  return 0;
}
