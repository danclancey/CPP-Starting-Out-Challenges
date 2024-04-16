/*
    Write a program to find a baseball player’s batting average. The program should ask the user 
    to enter the number of times the player was at bat and the number of hits earned. Display the 
    batting average as a decimal between .000 and 1.000. For example, if a player bats 40 times 
    and gets 10 hits, which is 25% of the time, their batting average would be .250.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    // Declare variables
    double timesAtBat,
        hitsEarned;
    double battingAverage;

    // Greeting screen
    cout << "Welcome to Dans Batting Average Calculator!\n";

    // Prompt user for times at bat and hits earned
    cout << "Please enter times at bat: ";
    cin >> timesAtBat;
    cout << "Please enter hits earned: ";
    cin >> hitsEarned;

    // Calculate batting average
    battingAverage = hitsEarned / timesAtBat;

    // Display results
    cout << " - Batting average: " << fixed << setprecision(3) << battingAverage;

    return 0;
    
}