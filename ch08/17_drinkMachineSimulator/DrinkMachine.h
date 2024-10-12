#ifndef DRINKMACHINE_H
#define DRINKMACHINE_H 

#include <limits>
#include <string>

using namespace std;

struct Drink {
    string name;
    double price;
    int quantity;
};

class DrinkMachine {
    private:
        Drink drinks[5];
        double totalMoneyCollected;

        // Helper functions 
        double inputMoney(double price);
        void dailyReport() const;

    public:
        // Constructor 
        DrinkMachine();

        // Destructor
        ~DrinkMachine();

        // Member Functions 
        void displayChoices() const;
        void buyDrink(int choice);
};

#endif
