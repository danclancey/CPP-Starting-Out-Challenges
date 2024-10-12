/*
A local zoo wants to keep track of how many pounds of food each of 
its three monkeys eats each day during a typical week. Write a 
program that stores this information in a two-dimensional 3x7 array, 
where each row represents a different monkey and each column 
represents a different day of the week. The program should first 
have the user input the data for each monkey. Then it should create 
a report that includes the following information:

    - Average amount of food eaten per day by the whole family 
      of monkeys
    - The least amount of food eaten during the week by any one 
      monkey
    - The greatest amount of food eaten during the week by any one 
      monkey
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const int MONKEYS = 3;
    const int DAYS = 7;
    double foodIntake[MONKEYS][DAYS];
    double totalFood = 0.0;
    double averageFood;
    double leastFood;
    double greatestFood;

    // Input food intake data for each monkey
    cout << "Enter the pounds of food eaten each day by each monkey:\n";
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            do {
                cout << "Monkey " << (i + 1) << ", Day " << (j + 1) << ": ";
                cin >> foodIntake[i][j];
                // Input validation to ensure non-negative values
                if (foodIntake[i][j] < 0) {
                    cout << "Invalid input. Please enter a non-negative number.\n";
                }
            } while (foodIntake[i][j] < 0);
            totalFood += foodIntake[i][j];
        }
    }

    // Calculate the average amount of food eaten per day by the whole family
    averageFood = totalFood / (MONKEYS * DAYS);

    // Find the least and greatest amount of food eaten by any one monkey during the week
    leastFood = foodIntake[0][0];
    greatestFood = foodIntake[0][0];
    for (int i = 0; i < MONKEYS; i++) {
        for (int j = 0; j < DAYS; j++) {
            if (foodIntake[i][j] < leastFood) {
                leastFood = foodIntake[i][j];
            }
            if (foodIntake[i][j] > greatestFood) {
                greatestFood = foodIntake[i][j];
            }
        }
    }

    // Display the report
    cout << "\nFood Intake Report:\n";
    cout << "---------------------------\n";
    cout << "Average amount of food eaten per day by the whole family: " << fixed << setprecision(2) << averageFood << " lbs\n";
    cout << "Least amount of food eaten during the week by any one monkey: " << fixed << setprecision(2) << leastFood << " lbs\n";
    cout << "Greatest amount of food eaten during the week by any one monkey: " << fixed << setprecision(2) << greatestFood << " lbs\n";

    return 0;
}

