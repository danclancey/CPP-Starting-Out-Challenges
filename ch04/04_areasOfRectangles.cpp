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
         bRectLength;

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
  if (aRectWidth < 0 || aRectLength < 0 || bRectWidth < 0 || bRectLength < 0)
  {
    cout << "Invalid input! Exiting..\n";
    return 1;
  }

  // Determine which rectangle is larger and inform user
  if ( (aRectWidth * aRectLength) > (bRectWidth * bRectLength) )
  {
    cout << "\nRectangle A, with an area of " << aRectWidth * aRectLength << " square inches, "
         << "is larger than Rectangle B (" << bRectWidth * bRectLength << " square inches).\n";
  } else if ( (aRectWidth * aRectLength) < (bRectWidth * bRectLength) )
  {
    cout << "\nRectangle B, with an area of " << bRectWidth * bRectLength << " square inches, "
         << "is larger than Rectangle A (" << aRectWidth * aRectLength << " square inches)\n";
  } else 
  {
    cout << "\nRectangle A and B are equal in size! They are both " << aRectWidth * aRectLength << " square inches!\n";
  }

  return 0;
}
