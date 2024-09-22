/*
  Write a program that asks the user to enter two different integers. The program should use the conditional operator 
  to determine which number is the smaller and which is the larger.
*/

#include <iostream>

using namespace std;

int main() 
{
  int num1, num2;

  // Prompt user for two integers.
  cout << "Enter the first integer: ";
  cin >> num1;
  cout << "Enter the second integer: ";
  cin >> num2;

  // Determine which number is smaller/larger
  int smaller = (num1 < num2) ? num1 : num2;
  int larger = (num1 > num2) ? num1 : num2;

  // Display results
  cout << "The smaller number is: " << smaller << endl;
  cout << "The larger number is: " << larger << endl;

  return 0;
}
