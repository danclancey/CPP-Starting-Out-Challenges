/* 
  Write a program that calculates the average monthly rainfall for three months. The program should ask the user 
  to enter the name of each month, such as June or July, and the amount of rain (in inches) that fell that month. 
  The program should display a message similar to the following:

    * The average monthly rainfall for June, July, and August was 6.72 inches.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

int main()
{
  // Declare variables
  string nameMonth1,
         nameMonth2,
         nameMonth3;
  double rainMonth1,
         rainMonth2,
         rainMonth3,
         averageRain;

  // Welcome Message
  cout << "Welcome to Dans rainfall calculator!\n";
  cout << "This program will prompt user for three months and the total rainfall for each month.\n" 
       << "It will then calculate the average rainfall and report it back to the user.\n\n";

  // Prompt user for input
  cout << "Please enter first month: ";
  cin >> nameMonth1;
  cout << "Enter how much rain fell(in inches) in " << nameMonth1 << ": ";
  cin >> rainMonth1;
  cout << "Please enter second month: ";
  cin >> nameMonth2;
  cout << "Enter how much rain fell(in inches) in " << nameMonth2 << ": ";
  cin >> rainMonth2;
  cout << "Please enter third month: ";
  cin >> nameMonth3;
  cout << "Enter how much rain fell(in inches) in " << nameMonth3 << ":";
  cin >> rainMonth3;

  // Calculate Average rainfall
  averageRain = (rainMonth1 + rainMonth2 + rainMonth3) / 3;

  // Display results
  cout << "The average monthly rainfall for " << nameMonth1 << ", " << nameMonth2 << ", and " << nameMonth3
       << " was " << fixed << setprecision(2) << averageRain << " inches.\n";


  return 0;


}
