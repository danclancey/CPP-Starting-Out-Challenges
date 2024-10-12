/*
A student has established the following monthly budget:

        Housing	                    1200.00
        Utilities, Internet & Phone 215.00
        Household expenses	        65.00
        Transportation	            50.00
        Food                        250.00
        Medical                     30.00
        Insurance                   100.00
        Entertainment               120.00
        Clothing                    75.00
        Miscellaneous               50.00

Write a modular program that declares a MonthlyBudget structure with member variables 
to hold each of these expense categories. The program should create two MonthlyBudget 
structure variables. The first will hold the budget figures given above. The second 
will hold the user-enter amounts actually spent during the past month. Using Program 
7-19 as a model, the program should create a screen form that displays each category 
name and its budgeted amount, then positions the cursor next to it for the user to 
enter the amount actually spent in that category. Once the user data has all been 
entered, the program should compute and display the amount over or under budget the 
student’s expenditures were in each category, as well as the amount over or under 
budget for the entire month.
*/

#include <iostream>
#include <iomanip>
#include <string>
#include <windows.h>

using namespace std;

struct MonthlyBudget {
    double housing;
    double utilities;
    double householdExpenses;
    double transportation;
    double food;
    double medical;
    double insurance;
    double entertainment;
    double clothing;
    double miscellaneous;
};

// Function prototypes
void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE, const MonthlyBudget&);
void getUserInput(HANDLE, MonthlyBudget&);
void displayDifferences(HANDLE, const MonthlyBudget&, const MonthlyBudget&);

int main() {
    // Initialize the budgeted amounts
    MonthlyBudget budget = { 1200.00, 215.00, 65.00, 50.00, 250.00, 30.00, 100.00, 120.00, 75.00, 50.00 };
    MonthlyBudget actual;

    // Get the handle to standard output device (the console)
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    // Display form prompts and get user input
    displayPrompts(screen, budget);
    getUserInput(screen, actual);

    // Display the results
    displayDifferences(screen, budget, actual);

    return 0;
}

/******************************************************
 *                    placeCursor                     *
 ******************************************************/
void placeCursor(HANDLE screen, int row, int col) {
    COORD position;
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);
}

/******************************************************
 *                   displayPrompts                   *
 ******************************************************/
void displayPrompts(HANDLE screen, const MonthlyBudget& budget) {
    placeCursor(screen, 2, 26);
    cout << "******* Monthly Budget Form *******" << endl;

    placeCursor(screen, 4, 26);
    cout << "Category                 Budgeted Amount        Spent" << endl;
    placeCursor(screen, 5, 26);
    cout << "-------------------------------------------------------" << endl;

    placeCursor(screen, 6, 26);
    cout << "Housing:\t\t\t$" << budget.housing << "    ";
    placeCursor(screen, 7, 26);
    cout << "Utils, Inet & Phone:\t\t$" << budget.utilities << "    ";
    placeCursor(screen, 8, 26);
    cout << "Household Expenses:\t\t$" << budget.householdExpenses << "    ";
    placeCursor(screen, 9, 26);
    cout << "Transportation:\t\t$" << budget.transportation << "    ";
    placeCursor(screen, 10, 26);
    cout << "Food:\t\t\t\t$" << budget.food << "    ";
    placeCursor(screen, 11, 26);
    cout << "Medical:\t\t\t$" << budget.medical << "    ";
    placeCursor(screen, 12, 26);
    cout << "Insurance:\t\t\t$" << budget.insurance << "    ";
    placeCursor(screen, 13, 26);
    cout << "Entertainment:\t\t$" << budget.entertainment << "    ";
    placeCursor(screen, 14, 26);
    cout << "Clothing:\t\t\t$" << budget.clothing << "    ";
    placeCursor(screen, 15, 26);
    cout << "Miscellaneous:\t\t$" << budget.miscellaneous << "    ";
}

/******************************************************
 *                    getUserInput                    *
 ******************************************************/
void getUserInput(HANDLE screen, MonthlyBudget& actual) {
    placeCursor(screen, 6, 74);
    cin >> actual.housing;
    placeCursor(screen, 7, 74);
    cin >> actual.utilities;
    placeCursor(screen, 8, 74);
    cin >> actual.householdExpenses;
    placeCursor(screen, 9, 74);
    cin >> actual.transportation;
    placeCursor(screen, 10, 74);
    cin >> actual.food;
    placeCursor(screen, 11, 74);
    cin >> actual.medical;
    placeCursor(screen, 12, 74);
    cin >> actual.insurance;
    placeCursor(screen, 13, 74);
    cin >> actual.entertainment;
    placeCursor(screen, 14, 74);
    cin >> actual.clothing;
    placeCursor(screen, 15, 74);
    cin >> actual.miscellaneous;
}

/******************************************************
 *                 displayDifferences                 *
 ******************************************************/
void displayDifferences(HANDLE screen, const MonthlyBudget& budget, const MonthlyBudget& actual) {
    placeCursor(screen, 17, 0);
    cout << "\nCategory                 Budgeted   Spent   Difference\n";
    cout << "-------------------------------------------------------\n";

    auto displayDiff = [](const string& category, double budgeted, double spent) {
        cout << left << setw(25) << category
             << "$" << setw(10) << budgeted
             << "$" << setw(10) << spent
             << "$" << setw(10) << (spent - budgeted) << endl;
    };

    displayDiff("Housing", budget.housing, actual.housing);
    displayDiff("Utils, Inet & Phone", budget.utilities, actual.utilities);
    displayDiff("Household Expenses", budget.householdExpenses, actual.householdExpenses);
    displayDiff("Transportation", budget.transportation, actual.transportation);
    displayDiff("Food", budget.food, actual.food);
    displayDiff("Medical", budget.medical, actual.medical);
    displayDiff("Insurance", budget.insurance, actual.insurance);
    displayDiff("Entertainment", budget.entertainment, actual.entertainment);
    displayDiff("Clothing", budget.clothing, actual.clothing);
    displayDiff("Miscellaneous", budget.miscellaneous, actual.miscellaneous);

    // Calculate the total difference
    double totalBudgeted = budget.housing + budget.utilities + budget.householdExpenses +
                           budget.transportation + budget.food + budget.medical + 
                           budget.insurance + budget.entertainment + budget.clothing + 
                           budget.miscellaneous;
    double totalSpent = actual.housing + actual.utilities + actual.householdExpenses +
                        actual.transportation + actual.food + actual.medical + 
                        actual.insurance + actual.entertainment + actual.clothing + 
                        actual.miscellaneous;
    double totalDifference = totalSpent - totalBudgeted;

    cout << "-------------------------------------------------------\n";
    cout << left << setw(25) << "Total"
         << "$" << setw(10) << totalBudgeted
         << "$" << setw(10) << totalSpent
         << "$" << setw(10) << totalDifference << endl;
}

