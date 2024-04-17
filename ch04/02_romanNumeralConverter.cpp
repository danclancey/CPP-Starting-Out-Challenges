/*
  Write a program that asks the user to enter a number within the range of 1 through 10. Use a switch statement 
  to display the Roman numeral version of that number.

  Input Validation: Decide how the program should handle an input that is less than 1 or greater than 10.
*/

#include <iostream>

using namespace std;

int main()
{
  int number;
  
  // Welcome Message
  cout << "Welcome to the Roman Numeral Converter!\n";
  cout << "---------------------------------------\n\n";
  cout << "This program converts a number within the range of 1-10 to a Roman Numeral\n\n";

  cout << "Please enter a number between 1 and 10: ";
  cin >> number;
  
  // Input validation
  if (number < 1 || number > 10) 
  {
    cout << "Invalid input! Exiting..\n";
    return 1;
  }

  // Display Roman Numeral equivalent of input
  cout << " - Roman numeral equivalent: ";
  switch(number)
  {
    case 1:
      cout << "I";
      break;
    case 2:
      cout << "II";
      break;
    case 3:
      cout << "III";
      break;
    case 4:
      cout << "IV";
      break;
    case 5:
      cout << "V";
      break;
    case 6:
      cout << "VI";
      break;
    case 7:
      cout << "VII";
      break;
    case 8:
      cout << "VIII";
      break;
    case 9:
      cout << "IX";
      break;
    case 10:
      cout << "X";
      break;
    default: 
      cout << "Invalid Input..";
  }
  
  cout << endl;

  return 0;

}
