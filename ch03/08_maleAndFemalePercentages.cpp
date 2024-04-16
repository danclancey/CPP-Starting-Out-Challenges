/*
  Write a program that asks the user for the number of males and number of females registered in a class. 
  The program should then compute and report what percentage of the students are males and what percentage 
  are females. Convert the decimal result of each calculation to percent form and display it with two 
  decimal points. The two values should add up to 100.00 percent.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
  // Declare Variables
  int malesInClass,
      femalesInClass,
      totalInClass;

  double  pctMale,
          pctFemale;

  // Display Welcome Message
  cout << "Welcome to Dans Class Demographics Calculator!\n"
       << "----------------------------------------------\n"
       << "This program will calculate the percentage of males and females in your class.\n\n";

  // Prompt user for class demographics
  cout << "Please enter how many males are in your class: ";
  cin >> malesInClass;
  cout << "Please enter how many females are inyour class: ";
  cin >> femalesInClass;

  // Calculate percentage of each gender
  totalInClass = malesInClass + femalesInClass;
  pctMale = static_cast<double>(malesInClass) / totalInClass;
  pctFemale = static_cast<double>(femalesInClass) / totalInClass;
  
  // Display Results
  cout << "\nHere is the demographic breakdown of your class: \n"
       << " - Males make up " << fixed << setprecision(2) << pctMale * 100 << "% of the class.\n"
       << " - Females make up " << pctFemale * 100 << "% of the class.\n";

  // End program
  cout << "\n Exiting... Goodbye!\n";

  return 0;

}
