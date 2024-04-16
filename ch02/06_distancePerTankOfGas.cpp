/* 
    A car with a 20 gallon gas tank averages 23.5 miles per gallon when driven
    in a town and 28.9 miles per gallon when driven on the highway.

    Write a program that calculates and displays the distance the car can travel
    on one tank of gas when driven in town and when driven on the highway.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    // Decalre variables
    double tankSize = 20, mpgTown = 23.5, mpgHighway = 28.9;
    double townDistance, highwayDistance;

    // Calculate distance in town
    townDistance = tankSize * mpgTown;

    // Calculate distance on highway
    highwayDistance = tankSize * mpgHighway;

    // Display results
    cout << "Range of car in town: " << townDistance << " miles.\n";
    cout << "Range of car on highway: " << highwayDistance << " miles.\n";

    return 0;
}