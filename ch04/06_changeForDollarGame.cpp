/*
  Create a change-counting game that asks the user to enter what coins to use to make exactly one dollar. 
  The program should ask the user to enter the number of pennies, nickels, dimes, and quarters. If the 
  total value of the coins entered is equal to one dollar, the program should congratulate the user for 
  winning the game. Otherwise, the program should display a message indicating whether the amount entered 
  was more or less than one dollar. Use constant variables to hold the coin values.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants for coin values
const double PENNY_VALUE = 0.01;
const double NICKEL_VALUE = 0.05;
const double DIME_VALUE = 0.10;
const double QUARTER_VALUE = 0.25;

int main ()
{
  // Declare variables
  int totPenny,
      totNickel,
      totDime,
      totQuarter;
  double changeTotal;

  // Welcome message
  cout << "Welcome to Dan's Change-Counting Game!\n";
  cout << "--------------------------------------\n\n";
  cout << "This game will ask you to input the number of pennies, nickels, dimes, and quarters\n"
       << "that will equal one dollar. If you calculate correctly, you win!\n\n";
  
  // Prompt user for input
  cout << "Enter number of pennies: ";
  cin >> totPenny;
  cout << "Enter number of nickels: ";
  cin >> totNickel;
  cout << "Enter number of dimes: ";
  cin >> totDime;
  cout << "Enter number of quarters: ";
  cin >> totQuarter;

  // Calculate change total
  changeTotal = (totPenny * PENNY_VALUE) + (totNickel * NICKEL_VALUE) + 
                (totDime * DIME_VALUE) + (totQuarter * QUARTER_VALUE);

  // Output results based on change total
  if (changeTotal == 1.0)
  {
    cout << "Congratulations! Your change adds up to 1 dollar!\n";
  } else if (changeTotal < 1.0) 
  {
    cout << "Your change is less than 1 dollar!\n";
  } else 
  {
    cout << "Your change is more than 1 dollar!\n";
  }
  cout << fixed << setprecision(2);
  cout << "Your change adds up to: $" << changeTotal << endl;

  return 0;
}
