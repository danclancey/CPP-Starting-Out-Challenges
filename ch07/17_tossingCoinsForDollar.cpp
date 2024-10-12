/*
Create a game program using the Coin class from Programming Challenge 16. The program 
should have three instances of the Coin class: one representing a quarter, one 
representing a dime, and one representing a nickel.

When the game begins, your starting balance is $0. During each round of the game, the 
program will toss each of the simulated coins. When a tossed coin lands heads-up, the 
value of the coin is added to your balance. For example, if the quarter lands heads-up, 
25 cents is added to your balance. Nothing is added to your balance for coins that land 
tails-up. The game is over when your balance reaches one dollar or more. If your balance 
is exactly one dollar, you win the game. If your balance exceeds one dollar, you lose.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

class Coin {
    private:
        string sideUp;

    public:
        Coin();
        void toss();
        string getSideUp() const;
};

// Default constructor
Coin::Coin() {
    // Seed randon number generator
    srand(time(0));
    // Randomly determine the side facing up 
    toss();
}


// Function to simulate tossing of coin
void Coin::toss() {
    int result = rand() % 2; // genrate random number 1 or 2
    if (result == 0) {
        sideUp = "heads";
    } else { 
        sideUp = "tails";
    }
}

// Function to get current side up 
string Coin::getSideUp() const {
    return sideUp;
}

int main() {
    // Create coin objects
    Coin quarter;
    Coin dime;
    Coin nickel;

    double balance = 0.0;

    cout << "Weclome to Dan's coin toss game! The goal is to get eactly $1.00!\n";
    cout << "You start with a balance of $0.00.\n\n";
    cout << "Press [Enter] to toss the coins!\n";
    cin.get();

    // game loop
    while (balance < 1.0) {
        // Toss each coin
        quarter.toss();
        dime.toss();
        nickel.toss();

        // Display result of each coin toss. Update balance if its lands on heads 
        cout << "Tossing coins. . . \n";

        if (quarter.getSideUp() == "heads") {
            balance += 0.25;
            cout << "Quarter landed heads. Added $0.25 to balance\n";
        } else {
            cout << "Quarter landed tails. No change to balance\n";
        }

        if (dime.getSideUp() == "heads") {
            balance += 0.10;
            cout << "Dime landed heads. Added $0.10 to balance\n";
        } else {
            cout << "Dime landed tails. No change to balance\n";
        }

        if (nickel.getSideUp() == "heads") {
            balance += 0.05;
            cout << "Nickel landed heads. Added $0.05 to balance\n";
        } else {
            cout << "Nickel landed tails. No change to balance\n";
        }

        // Display curr balance 
        cout << fixed << setprecision(2);
        cout << "Current balance: $" << balance << "\n\n";

        // Check if player won or lost 
        if (balance == 1.0) {
            cout << "Congrats! You reached exactly $1.00. You win!\n";
            break;
        } else if (balance > 1.0) {
            cout << "Your balance exceeds $1.00! You lose! Womp womp..\n";
            break;
        } else {
            cout << "Round over! Press [Enter] to toss again!\n";
            cin.get();
        }
    }

    return 0;
}
