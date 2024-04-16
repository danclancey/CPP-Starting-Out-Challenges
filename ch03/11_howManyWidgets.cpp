/*
  The Yukon Widget Company manufactures widgets that weigh 12.5 pounds each. Write a program that calculates 
  how many widgets are stacked on a pallet, based on the total weight of the pallet. The program should ask 
  the user how much the pallet weighs by itself and with the widgets stacked on it. It should then calculate 
  and display the number of widgets stacked on the pallet.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constant for wiedget weight
const double WIDGET_WEIGHT = 12.5;

int main ()
{
  // Declare variables
  double palletWeight,      // Weight of pallet by itself
         grossPalletWeight; // Total weight of stacked pallet
  int totalWidgets;         // Number of widgets on pallet
  
  // Welcome Message
  cout << "Welcome to Dan's Pallet Calculator!\n\n"
       << "This program will calculate the number of widgets stacked on a pallet\n"
       << "given the gross pallet weight and empty pallet weight.\n\n";
  
  // Prompt user for input
  cout << "Please enter weight of empty pallet (in pounds): ";
  cin >> palletWeight;
  cout << "Please enter weight of stacked pallet (in pounds): ";
  cin >> grossPalletWeight;

  // Calculate number of widgets on pallet
  totalWidgets = (grossPalletWeight - palletWeight) / WIDGET_WEIGHT;

  // Display results
  cout << "\nThere are " << totalWidgets << " widgets on the pallet.\n";

  return 0;

}
