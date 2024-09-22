/* 
Write a program that will predict the size of a population of organisms. The program should 
ask the user for the starting number of organisms, their average daily population increase 
(as a percentage of current population), and the number of days they will multiply. A loop 
should display the size of the population for each day.

Input Validation: The program should not accept a number less than 2 for the starting size 
of the population, a negative number for average daily population increase, or a number less 
than 1 for the number of days they will multiply.
*/ 

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int startingPopulation, numberOfDays;
    double dailyIncreaseRate;

    // Input validation for starting pop
    cout << "Enter the starting number of organisms (must be at least 2): ";
    cin >> startingPopulation;
    while (startingPopulation < 2) {
        cout << "Invalid input! The starting number of organisms must be at least 2: ";
        cin >> startingPopulation;
    }

    // Input validation for the daily pop increase (percentage)
    cout << "Enter the average daily population increase (as a percentage, must be positive): ";
    cin >> dailyIncreaseRate;
    while (dailyIncreaseRate < 0) {
        cout << "Invalid input! The daily population increase must be positive: ";
        cin >> dailyIncreaseRate;
    }

    // Input validation for the number of days
    cout << "Enter the number of days the population will multiply (must be at least 1): ";
    cin >> numberOfDays;
    while (numberOfDays < 1) {
        cout << "Invalid input! The number of days must be at least 1: ";
        cin >> numberOfDays;
    }

    // Convert daily increase rate to a multiplier (e.g., 10% becomes 0.1)
    dailyIncreaseRate = dailyIncreaseRate / 100;

    // Display headers
    cout << "\nDay\tPopulation Size\n";
    cout << "---------------------\n";

    // Loop to display pop size for each day
    for (int day = 1; day <= numberOfDays; day++) {
        // Display the pop size for the current day
        cout << day << "\t" << fixed << setprecision(2) << startingPopulation << endl;

        // Increase pop based on the daily growth rate
        startingPopulation += startingPopulation * dailyIncreaseRate;
    }

    return 0;
}

