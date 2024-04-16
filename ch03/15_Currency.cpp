/*
  Write a program that will convert U.S. dollar amounts to Japanese yen and to euros, storing the conversion 
  factors in the constant variables YEN_PER_DOLLAR and EUROS_PER_DOLLAR. To get the most up-to-date exchange 
  rates, search the Internet using the term “currency exchange rate” or “currency converter.” If you cannot 
  find the most recent exchange rates, use the following:
      1 Dollar = 111 Yen
      1 Dollar = .86 Euros
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants for currency conversion
const double YEN_PER_DOLLAR = 153.28;
const double EUROS_PER_DOLLAR = 0.94;

int main()
{
  // Declare variables
  double dollars, yen, euros;

  // Welcome Message
  cout << "Welcome to Dan's Currency Converter!\n";
  cout << "------------------------------------\n\n";
  cout << "This program will convert USD to Yen and Euros\n\n";

  // Prompt user for U.S. Dollars to convert
  cout << "Enter amount in U.S. Dollars $";
  cin >> dollars;

  // Calculate US dollar to YEN and euro converison
  yen = dollars * YEN_PER_DOLLAR;
  euros = dollars * EUROS_PER_DOLLAR;

  // Display conversion 
  cout << "Equivalent amount in Japanese Yen: \u00A5" << yen << endl;
  cout << "Equivalent amount in euros: \u20AC" << euros << endl;
}
