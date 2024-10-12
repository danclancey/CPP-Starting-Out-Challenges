/*
Create a class that simulates and manages a soft drink machine. Information 
on each drink type should be stored in a structure that has data members to 
hold the drink name, the drink price, and the number of drinks of that type 
currently in the machine.

The class should have an array of five of these structures, initialized 
with the following data:

Drink Name	    Cost    Number in Machine
Cola	        1.00	20
Root beer	    1.00	20
Orange soda	    1.00	20
Grape soda	    1.00	20
Bottled water	1.50	20

The class should have two public member functions, displayChoices (which 
displays a menu of drink names and prices) and buyDrink (which handles a sale). 
The class should also have at least two private member functions, inputMoney, 
which is called by buyDrink to accept, validate, and return (to buyDrink) the 
amount of money input, and dailyReport, which is called by the destructor to 
report how many of each drink type remain in the machine at the end of the day 
and how much money was collected. You may want to use additional functions to 
make the program more modular.

The client program that uses the class should have a main processing loop that 
calls the displayChoices class member function and allows the patron to either 
pick a drink or quit the program. If the patron selects a drink, the buyDrink 
class member function is called to handle the actual sale. This function should 
be passed the patron’s drink choice. Here is what the buyDrink function should 
do:
    - Call the inputMoney function, passing it the patron’s drink choice.
    - If the patron no longer wishes to make the purchase, return all input money.
    - If the machine is out of the requested soda, display an appropriate “sold 
      out” message and return all input money.
    - If the machine has the soda and enough money was entered, complete the sale 
      by updating the quantity on hand and money collected information, calculating 
      any change due to be returned to the patron, and delivering the soda. This 
      last action can be simulated by printing an appropriate “here is your beverage” 
      message.
*/

#include "DrinkMachine.h"
#include <iostream>

using namespace std;

// Function prototype for valid menu choice 
int getValidMenuChoice();

int main() {
    DrinkMachine machine;
    int choice;

    cout << "Welcome to Dan's Drink Machine!\n";

    do {
        machine.displayChoices();
        
        choice = getValidMenuChoice();

        if (choice >= 1 && choice <= 5) {
            machine.buyDrink(choice);
        }
    } while (choice != 6);

    cout << "Thank you for using Dan's Drink Machine!\nExiting. . .\n";

    return 0;
}

int getValidMenuChoice() {
    int choice;

    while (true) {
        cout << "Please make a selection (1-6): ";
        cin >> choice;

        // Check if input is an integer and within the valid range
        if (cin.fail() || choice < 1 || choice > 6) {
            cin.clear(); 
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            cout << "Invalid input. Please enter a number between 1 and 6.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return choice;
        }
    }
}

