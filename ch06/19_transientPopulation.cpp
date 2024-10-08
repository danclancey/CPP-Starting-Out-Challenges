/*
Modify Programming Challenge 17 to also consider the effect on population caused by people moving into or 
out of a geographic area. Given as input a starting population size, the annual birth rate, the annual 
death rate, the number of individuals that typically move into the area each year, and the number of 
individuals that typically leave the area each year, the program should project what the population will 
be numYears from now. You can either prompt the user to input a value for numYears, or you can set it 
within the program.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
double calculateNewPopulation(double currentPopulation, double birthRate, double deathRate, int moveIn, int moveOut);

int main() {
    double startingPopulation, birthRate, deathRate;
    int years, moveIn, moveOut;

    // Get user input for the starting population
    do {
        cout << "Enter the starting size of the population (minimum 2): ";
        cin >> startingPopulation;
        if (startingPopulation < 2) {
            cout << "The population size must be at least 2. Please try again.\n";
        }
    } while (startingPopulation < 2);

    // Get user input for the birth rate
    do {
        cout << "Enter the annual birth rate (as a decimal, e.g., 0.032 for 3.2%): ";
        cin >> birthRate;
        if (birthRate < 0) {
            cout << "The birth rate cannot be negative. Please try again.\n";
        }
    } while (birthRate < 0);

    // Get user input for the death rate
    do {
        cout << "Enter the annual death rate (as a decimal, e.g., 0.026 for 2.6%): ";
        cin >> deathRate;
        if (deathRate < 0) {
            cout << "The death rate cannot be negative. Please try again.\n";
        }
    } while (deathRate < 0);

    // Get user input for the number of people moving in and out
    do {
        cout << "Enter the number of individuals moving into the area each year: ";
        cin >> moveIn;
        if (moveIn < 0) {
            cout << "The number of individuals moving in cannot be negative. Please try again.\n";
        }
    } while (moveIn < 0);

    do {
        cout << "Enter the number of individuals moving out of the area each year: ";
        cin >> moveOut;
        if (moveOut < 0) {
            cout << "The number of individuals moving out cannot be negative. Please try again.\n";
        }
    } while (moveOut < 0);

    // Get user input for the number of years
    do {
        cout << "Enter the number of years to display (minimum 1): ";
        cin >> years;
        if (years < 1) {
            cout << "The number of years must be at least 1. Please try again.\n";
        }
    } while (years < 1);

    // Display the starting population and projected population for each year
    double currentPopulation = startingPopulation;
    cout << fixed << setprecision(2);
    cout << "\nYear 0: " << currentPopulation << " (Starting Population)\n";

    for (int year = 1; year <= years; ++year) {
        currentPopulation = calculateNewPopulation(currentPopulation, birthRate, deathRate, moveIn, moveOut);
        cout << "Year " << year << ": " << currentPopulation << endl;
    }

    return 0;
}

// Function to calculate the new population size based on the formula
double calculateNewPopulation(double currentPopulation, double birthRate, double deathRate, int moveIn, int moveOut) {
    // Calculate the population after accounting for birth and death rates
    double newPopulation = currentPopulation * (1 + birthRate) * (1 - deathRate);

    // Adjust for people moving in and out
    newPopulation += moveIn - moveOut;

    return newPopulation;
}

