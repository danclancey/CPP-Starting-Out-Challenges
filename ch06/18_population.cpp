/*
In a population, the birth rate is the percentage increase of the population due to births, and the death 
rate is the percentage decrease of the population due to deaths. Write a program that asks for the 
following:

    - The starting size of a population (minimum 2)
    - The annual birth rate
    - The annual death rate
    - The number of years to display (minimum 1)

The program should then display the starting population and the projected population at the end of each 
year. It should use a function that calculates and returns the projected new size of the population after 
a year. The formula is

                N = P(1 + B)(1 - D)

where
    - N is the new population size,
    - P is the previous population size,
    - B is the birth rate,
    - and D is the death rate.

Annual birth rate and death rate are the typical number of births and deaths in a year per 1,000 people, 
expressed as a decimal. So, for example, if there are normally about 32 births and 26 deaths per 1,000 
people in a given population, the birth rate would be .032 and the death rate would be .026.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototype
double calculateNewPopulation(double currentPopulation, double birthRate, double deathRate);

int main() {
    double startingPopulation, birthRate, deathRate;
    int years;

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
        currentPopulation = calculateNewPopulation(currentPopulation, birthRate, deathRate);
        cout << "Year " << year << ": " << currentPopulation << endl;
    }

    return 0;
}

// Function to calculate the new population size based on the formula
double calculateNewPopulation(double currentPopulation, double birthRate, double deathRate) {
    return currentPopulation * (1 + birthRate) * (1 - deathRate);
}

