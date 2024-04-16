/*
 The average July high temperature is 85 degrees Fahrenheit in New York City, 88 degrees 
 in Denver, and 106 degrees in Pheonix. Write a program that calculates and reports what 
 the new average high July temperature would be for each of these cities if temperatures 
 to rise by 2 percent. 
*/

#include <iostream>
#include <iomanip>

// Declare constants
const int NYC_AVG_HIGH_JULY = 85;
const int DEN_AVG_HIGH_JULY = 88;
const int PHX_AVG_HIGH_JULY = 106;
const double TWO_PERCENT = 0.02;

using namespace std;

int main() 
{
  // Calculate new high if temps rise 2%
  double nycNewHigh = NYC_AVG_HIGH_JULY * TWO_PERCENT + NYC_AVG_HIGH_JULY;
  double denNewHigh = DEN_AVG_HIGH_JULY * TWO_PERCENT + DEN_AVG_HIGH_JULY;
  double phxNewHigh = PHX_AVG_HIGH_JULY * TWO_PERCENT + PHX_AVG_HIGH_JULY;
  
  // Format output
  cout << fixed << setprecision(1);

  // Display Results
  cout << "Average Temps in July by City if there is a 2% increase:\n"
       << "NYC: " << nycNewHigh << " Degrees Fahrenheit\n"
       << "DEN: " << denNewHigh << " Degrees Fahrenheit\n"
       << "PHX: " << phxNewHigh << " Degrees Fahrenheit";

  return 0;

}
