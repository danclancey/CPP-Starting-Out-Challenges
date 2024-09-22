/*
The distance a vehicle travels can be calculated as follows:

    distance = speed * time

For example, if a train travels 40 miles per hour for 3 hours, 
the distance traveled is 120 miles.

Write a program that asks the user for the speed of a vehicle 
(in miles per hour) and how many hours it has traveled. It 
should then use a loop to display the total distance traveled 
at the end of each hour of that time period. 

Here is an example of the output:

What is the speed of the vehicle in mph? 40
How many hours has it traveled? 3

Hour         Miles Traveled
----------------------------
 1                40
 2                80
 3               120
 */

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int milesPerHour,
        hours,
        milesTraveled;
    
    // Prompt user for input
    cout << "Please enter speed of vehicle (In MPH): ";
    cin >> milesPerHour;
    cout << "Please enter time traveled (In hours): ";
    cin >> hours;

    // Display columns
    cout << std::left << std::setw(12) << "Hour" << std::right << "Miles Traveled\n";
    cout << "--------------------------\n";

    // Calculate and display miles traveled for every hour traveled
    for (int i = 1; i <= hours; i++) {
        milesTraveled = milesPerHour * i;
        cout << std::left << std::setw(12) << i << std::right << std::setw(14) 
             << milesTraveled << endl;
    } 
    
    return 0;
}
