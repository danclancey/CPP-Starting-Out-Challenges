/*
  Write a program that asks for the number of calories and fat grams in a food and then displays what 
  percentage of the calories come from fat. If the calories from fat are less than 30 percent of the 
  total calories, it should also display a message indicating the food is low in fat.

  One gram of fat has 9 calories, so:

      Calories from fat = fat grams * 9

  The percentage of calories from fat can be calculated as:

      Calories from fat ÷ total calories

  Input Validation: The number of calories from fat cannot be greater than the total calories.
*/

#include <iostream>

using namespace std;

int main() {
    double totalCalories, fatGrams, percentCaloriesFat, caloriesFromFat;

    cout << "Please enter number of total calories: ";
    cin >> totalCalories;
    cout << "Please enter number of grams of fat: ";
    cin >> fatGrams;

    caloriesFromFat = fatGrams * 9;

    // Input validation: Calories from fat cannot exceed total calories
    if (caloriesFromFat > totalCalories) {
        cout << "Error: Calories from fat can't be greater than total calories\n";
        return 0;
    }

    // Calculate percentage of calories from fat
    percentCaloriesFat = (caloriesFromFat / totalCalories) * 100;

    // Display the percentage of calories from fat
    cout << "Percentage of Calories from Fat: " << percentCaloriesFat << "%\n";

    // Check if the food is low in fat (less than 30%)
    if (percentCaloriesFat < 30) {
        cout << "The food is low in fat!\n";
    }

    return 0;
}

