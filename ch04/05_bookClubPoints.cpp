/*
  An online book club awards points to its customers based on the number of books purchased each month. 
  Points are awarded as follows:

            Books Purchased	  Points Earned
            0                     0
            1                     5
            2                     15
            3                     30
            4 or more             50

  Write a program that asks the user to enter the number of books purchased this month and then displays 
  the number of points awarded.
*/

#include <iostream>

using namespace std;

int main()
{
  // Declare variables
  int booksPurchased,
      pointsEarned;

  // Welcome Message
  cout << "Welcome to Dan's Book Club Point Caclulator!\n"
       << "--------------------------------------------\n\n";
  cout << "This program will check how many points you earned this month based on the number of books purchased.\n\n";

  // Prompt user for amount of books purchased this month.
  cout << "Please enter how many books you purchased this Month: ";
  cin >> booksPurchased;

  // Validate input
  if (booksPurchased < 0)
  {
    cout << "Invalid Input! Please enter a number greater than or equal to 0. Exiting..\n";
    return 1;
  }

  // Calculate points 
  switch (booksPurchased) {
    case 0:
      pointsEarned = 0;
      break;
    case 1:
      pointsEarned = 5;
      break;
    case 2:
      pointsEarned = 15;
      break;
    case 3:
      pointsEarned = 30;
      break;
    default:
      pointsEarned = 50;
      break;
  }

  // Display points earned
  cout << "This month you have earned " << pointsEarned << " point(s).\n";

  return 0;
}
