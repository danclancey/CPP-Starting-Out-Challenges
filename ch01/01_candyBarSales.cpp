/*  
    Using program 1-1 as an example, write a program that calculates how much a student organization earns during its fund raising candy sale. 
    The program should prompt the user to enter the number of candy pars sold and the amount the organization earns for each bar sold. 
    It should then calculate and display the total amount earned.

    Input: numSold, earningsPerBar
    Calculate: totalEarnings
    Display: totalEarnings
*/

#include <iostream>
using namespace std;

int main()
{
    double numSold, earningsPerBar, totalEarnings;

    // Get the number of of candy bars sold

    cout << "How many bars did you sell? ";
    cin >> numSold;

    // Get the earnings per bar sold

    cout << "How much is earned for each bar sold? ";
    cin >> earningsPerBar;

    // Calculate total earnings

    totalEarnings = numSold * earningsPerBar;

    cout << "You have earned $" << totalEarnings;
    return 0;
}