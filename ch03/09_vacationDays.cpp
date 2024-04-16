/*
  Write a program that prompts the users to enter the number of days they plan to spend on their next vacation.
  Then compute and report how long that is in hours, in minute, and in seconds.
*/

#include <iostream>
using namespace std;

const int SECONDS_IN_MINUTE = 60;
const int MINUTES_IN_HOUR = 60;
const int HOURS_IN_DAY = 24;

int main()
{
  // Declare variables
  int vacationDays;

  // Display Welcome Message
  cout << "Welcome to Dans Class Vacation Calculator!\n"
       << "----------------------------------------------\n"
       << "This program will calculate the length of your vacation in Hours, Minutes, and Seconds.\n\n";

  // Prompt user for vacation days
  cout << "Enter the amount of days you'll be on vacation: ";
  cin >> vacationDays;

  // Display Results
  cout << "\nYou will be on vacation for " << vacationDays << " which translates to: \n"
       << " - " << vacationDays * HOURS_IN_DAY << " hours\n"
       << " - " << vacationDays * HOURS_IN_DAY * MINUTES_IN_HOUR << " minutes\n"
       << " - " << vacationDays * HOURS_IN_DAY * MINUTES_IN_HOUR * SECONDS_IN_MINUTE << " seconds\n\n";

  // Exit program
  cout << "Exiting... Goodbye!";

  return 0;
}
