/*
  Write a program that calculates a car's gas mileage. The program should ask the user
  to enter the number of gallons of gas the car can hold and the number of miles it can
  be driven on a full tank. It should then calculate and display the number of miles
  per gallon the car gets.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
  // Declare variables
  double tankInGallons, distancePerTank, milesPerGallon;

  // Program Title
  cout << "Welcome to Dans Miles Per Gallon Calculator!\n";

  // Prompt user to enter size of gas tank
  cout << "Please enter the size of your gas tank in Gallons: ";
  cin >> tankInGallons;

  // Prompt user to enter miles driven per tank
  cout << "Please enter distance (in miles) you can drive on one tank: ";
  cin >> distancePerTank;

  // Calculate miles per gallon
  milesPerGallon = distancePerTank / tankInGallons;
  
  // Format output and display miles per gallon calculation 
  cout << fixed << setprecision(1);
  cout << "You get " << milesPerGallon << " miles per gallon!\n";
  cout << "Goodbye!";

  return 0;
}
