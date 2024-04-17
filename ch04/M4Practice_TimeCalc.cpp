// Time Calculator
// This program converts days to seconds, hours, or minutes,
// whichever is most appropriate.


#include <iostream>
#include <iomanip>
using namespace std;

int main() 
{
    int const SECONDS_IN_DAY = 86400;
    int const SECONDS_IN_HOUR = 3600;
    int const SECONDS_IN_MINUTE = 60;

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