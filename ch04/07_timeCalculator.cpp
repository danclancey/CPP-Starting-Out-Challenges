/*
Write a program that asks the user to enter a number of seconds.

    * There are 86400 seconds in a day. If the number of seconds entered by the user is greater 
      than or equal to 86400, the program should display the number of days in that many seconds.

    * There are 3600 seconds in an hour. If the number of seconds entered by the user is less 
      than 86400 but is greater than or equal to 3600, the program should display the number of 
      hours in that many seconds.

    * There are 60 seconds in a minute. If the number of seconds entered by the user is less than 
      3600 but is greater than or equal to 60, the program should display the number of minutes 
      in that many seconds.
*/

#include <iostream>
#include <iomanip>
using namespace std;

const int SECONDS_IN_DAY = 86400;
const int SECONDS_IN_HOUR = 3600;
const int SECONDS_IN_MINUTE = 60;
int main()
{
    double seconds;

    // Input the number of seconds
    cout << "This program will convert seconds to days, hours, or minutes.\n\n";
    cout << "Enter the number of seconds (60 or more): ";
    cin >> seconds;

    // set the output format
    cout << fixed << setprecision(2);

    // Determine and print the corresponding number of days, hours,
    // or minutes depending on the number of seconds entered
    if (seconds >= SECONDS_IN_DAY)
        cout << "This equals " << (seconds / SECONDS_IN_DAY) << " day(s)\n";
    else if (seconds >= SECONDS_IN_HOUR)
        cout << "This equals " << (seconds / SECONDS_IN_HOUR) << " hour(s)\n";
    else if(seconds >= SECONDS_IN_MINUTE)
        cout << seconds << " seconds is " << (seconds / SECONDS_IN_MINUTE) << " minute(s)\n";
    else
        cout << "This is less than one minute!";
}
