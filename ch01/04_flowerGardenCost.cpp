/*
    Write a program that calcualtes how much the nature center spent to make
    the flower garden display described in the previous problem. The program
    should prompt the user to enter the cost of the soil, the flower seeds,
    and the fence. It should then calculate and display the total amount spent.
*/

#include <iostream>

using namespace std;

int main()
{
    // Declare variables
    double soilCost, seedCost, fenceCost, totalCost;

    // Prompt user for costs
    cout << "Enter cost of the soil: ";
    cin >> soilCost;

    cout << "Enter cost of the flower seeds: ";
    cin >> seedCost;

    cout << "Enter cost of the fence: ";
    cin >> fenceCost;

    // Calculate the cost of materials
    totalCost = soilCost + seedCost + fenceCost;

    // Display total cost
    cout << "The total cost of the flower garden is: $" << totalCost;

    return 0;

}