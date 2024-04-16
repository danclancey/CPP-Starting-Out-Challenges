/* 
  There are three seating categories at a stadium. For a softball game, Class A seats
  cost $15, Class B seats cost $12, and Class C seats cost $9. Write a program that
  asks how many tickets for each class of seats were sold, then display the amount of
  income generated from ticket sales. Format your dollar amount in a fixed-point 
  notation wtih two decimal points and make sure the decimal point is always displayed.
*/

// This program calculates sales of Class A B and C tickets and outputs results to user

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const double CLASSA_PRICE = 15;
const double CLASSB_PRICE = 12;
const double CLASSC_PRICE = 9;

int main()
{
  // Declare variables
  double classASold, classBSold, classCSold;
  double classATotal, classBTotal, classCTotal;
  double totalSales;

  // Print Welcome screen
  cout << "Welcome to Dan's Ticket Sale Calculator!\n";

  // Prompt user to enter amount of tickets sold
  cout << "Please enter the amount of tickets sold for each class.\n";
  cout << " - Class A: ";
  cin >> classASold;

  cout << " - Class B: ";
  cin >> classBSold;

  cout << " - Class C: ";
  cin >> classCSold;

  // Calculate sales
  classATotal = CLASSA_PRICE * classASold;
  classBTotal = CLASSB_PRICE * classBSold;
  classCTotal = CLASSC_PRICE * classCSold;
  totalSales = classATotal + classBTotal + classCTotal;

  // Display results
  cout << fixed << setprecision(2);
  cout << "Class A Revenue: $" << classATotal << endl;
  cout << "Class B Revenue: $" << classBTotal << endl;
  cout << "Class C Revenue: $" << classCTotal << endl;
  cout << "------------------\n";
  cout << "Total Revenue: $" << totalSales << endl;

  return 0;
}
