/* 
    Using Program 1-1 as an exmaple, write a program that calculates how 
    much a Little League baseball team spent last year to purchase new 
    baseballs. The program should prompt the user to enter the number of
    baseballs purchased and the cost of each baseball. It should then
    calculate and display the total amount spent to purchase the baseballs.
*/

#include <iostream>

using namespace std;

int main()
{
    // Declare variables
    int numPurchased;
    double costPerBall, totalCost;

    // Prompt user for amount of baseballs purchased
    cout << "How many baseballs did you purchase? ";
    cin >> numPurchased;

    // Prompt user for cost per baseball
    cout << "How much does each baseball cost? ";
    cin >> costPerBall;

    // Calculate total cost
    totalCost = numPurchased * costPerBall;

    // Display total money spent on baseballs
    cout << "You spent $" << totalCost << " on baseballs.";

    return 0;
}