/*
  Write a program that asks for five test scores. The program should calculate the average test score and display it. 
  The number displayed should be formatted in fixed-point notation, with one decimal point of precision.
*/

#include <iostream>
#include <iomanip>

using namespace std;

const int TOTAL_TEST = 5;

int main()
{
  // Declare variables
  int test1, test2, test3, test4, test5;
  double testAverage;

  // Display welcome
  cout << "Welcome to Dans test average calculator!\n";
  cout << "This program will ask for 5 test scores and then calculate the average of the 5 test\n";
  
  // Prompt user for test scores
  cout << "\nPlease enter Test score 1: ";
  cin >> test1;
  cout << "Please enter Test score 2: ";
  cin >> test2;
  cout << "Please enter Test score 3: ";
  cin >> test3;
  cout << "Please enter Test score 4: ";
  cin >> test4;
  cout << "Please enter Test score 5: ";
  cin >> test5;

  // Calculate average of 5 tests
  testAverage = static_cast<double>(test1 + test2 + test3 + test4 + test5) / TOTAL_TEST;

  // Display results
  cout << "\nThe average score for the 5 input tests is " << fixed << setprecision(1) << testAverage << endl;
  cout << "Goodbye!";

  return 0;

}
