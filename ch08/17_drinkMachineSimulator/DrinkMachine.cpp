#include "DrinkMachine.h"
#include <iostream>
#include <iomanip>

// Constructor to init drink data
DrinkMachine::DrinkMachine() {
    drinks[0] = {"Cola", 1.00, 20};
    drinks[1] = {"Root Beer", 1.00, 20};
    drinks[2] = {"Orange Soda", 1.00, 20};
    drinks[3] = {"Grape Soda", 1.00, 20};
    drinks[4] = {"Bottled Water", 1.00, 20};
    totalMoneyCollected = 0.0;
}

// Destructor - Call daily report
DrinkMachine::~DrinkMachine() {
    dailyReport();
}

// Display available choices to customer 
void DrinkMachine::displayChoices() const {
    cout << "\nAvailable Drinks: \n";
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << ". " << setw(15) << left << drinks[i].name 
             << " $" << fixed << setprecision(2) << drinks[i].price
             << " (" << drinks[i].quantity << " available)\n"; 
    }
    cout << "6. Quit\n";
}

// Handle purchasing of drink 
void DrinkMachine::buyDrink(int choice) {
    if (choice < 1 || choice > 5) {
        cout << "\t- Invalid input. Please select drink from list.\n";
        return;
    }

    Drink& selectedDrink = drinks[choice - 1];

    // Check if drink is sold out 
    if (selectedDrink.quantity == 0) {
        cout << "\t- Sorry, " << selectedDrink.name << " is sold out. Select another drink\n";
        return;
    }

    // Call inputMoney to get payment 
    double moneyEntered = inputMoney(selectedDrink.price);
    if (moneyEntered < selectedDrink.price) {
        cout << "\t- Not enough money. Returning $" << fixed << setprecision(2) << moneyEntered << endl;
        return;
    }

    // Process sale
    selectedDrink.quantity--;
    totalMoneyCollected += selectedDrink.price;

    // Calc and return change if necessary 
    double change = moneyEntered - selectedDrink.price;
    if (change > 0) {
        cout << "\t- Returning change: $" << fixed << setprecision(2) << change << endl;
    }

    // dispense drink 
    cout << "Vending " << selectedDrink.name << ". Enjoy!\n";
}

// Accept and validate money from customer 
double DrinkMachine::inputMoney(double price) {
    double money;
    
    while (true) {
        cout << "Please enter $" << fixed << setprecision(2) << price << ": ";
        cin >> money;

        // Validate input 
        if (cin.fail() || money < 0) {
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << "Invalid input. Please enter a positive amount.\n";
        } else {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return money;
        }
    }
}

// Print daily report 
void DrinkMachine::dailyReport() const {
    cout << "\nDaily Report: \n";
    cout << "Total Money Collected: $" << fixed << setprecision(2) << totalMoneyCollected << endl;

    for (int  i = 0; i < 5; i++) {
        cout << drinks[i].name << ": " << drinks[i].quantity << " left\n";
    }
}

