/*
  The date June 10, 1960, is special because when we write it in the following format, the month times the 
  day equals the year.

        6/10/60

  Write a program that asks the user to enter a month (in numeric form), a day, and a two-digit year. The program 
  should then determine whether the month times the day is equal to the year. If so, it should display a message 
  saying the date is magic. Otherwise, it should display a message saying the date is not magic. Test your program 
  with some dates that are magic and some that are not.

  Input Validation: Think about what legal values the program should accept for month and day.
*/

#include <iostream>

using namespace std;

int main() 
{
  // Declare variables
  int month, day,  year;

  // Welcome message
  cout << "Welcome to the Magic Date Checker!\n";
  cout << "----------------------------------\n\n";
  cout << "This program determines whether a date is a magic date based on the\n"
       << "month, day, and year entered.\n\n";

  // Prompt user for month, day and year.
  cout << "Enter a month (1-12): ";
  cin >> month;
  cout << "Enter a day (1-31): ";
  cin >> day;
  cout << "Enter a 2 digit year: ";
  cin >> year;

  // Check if input is Valid 
  if (month < 1 || month > 12 || day < 1 || day > 31 || year < 0)
  {
    cout << "Invalid Input! Exiting..\n";
  }

  if (month * day == year)
  {
    cout << "The date " << month << "/" << day << "/" << year << " is a magic date!\n";
  }
  else 
  {
    cout << "The date " << month << "/" << day << "/" << year << " is not a magic date\n";
  }

  return 0;
}
