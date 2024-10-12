/* 
Write a program that simulates a fishing game. In this game, a six-sided die is rolled 
to determine what the user has caught. Each possible item is worth a certain number of 
fishing points. The points will remain hidden until the user is finished fishing, and 
then a message is displayed congratulating the user depending on the number of fishing 
points gained.

Here are some suggestions for the game’s design:
    - Each round of the game is performed as an iteration of a loop that repeats as long 
      as the player wants to fish for more items.
    - At the end of each round, the program will ask the user whether or not he or she 
      wants to continue fishing.
    - The program simulates the rolling of a six-sided die
    - Each item that can be caught is represented by a number generated from the die—
      for example, 1 for “a huge fish”, 2 for “an old shoe”, 3 for “a little fish”, and so on.
    - Each item the user catches is worth a different number of points.
    - You, the program designer, get to decide what fish or object each number will represent 
      and how many points is associated with each “catch”.
    - The loop keeps a running total of the user’s fishing points.

When the loop is exited, the total number of fishing points is displayed, along with a message 
that varies depending on the number of points earned.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>

using namespace std;

class FishingGame {
    private:
        int totalPoints;

        int rollDie() const;
        string getCatch(int dieRoll, int &points);

    public:
        FishingGame();
        string fish(int &points);
        void addPoints(int pionts);
        void displayResult();
};

FishingGame::FishingGame() {
    totalPoints = 0;
    srand(static_cast<unsigned int>(time(0)));
}

int FishingGame::rollDie() const {
    return rand() % 6 + 1;
}

string FishingGame::getCatch(int dieRoll, int &points) {
    switch (dieRoll) {
        case 1:
            points = 10;
            return "a huge fish";
        case 2:
            points = 1;
            return "an old shoe";
        case 3:
            points = 5;
            return "a little fish";
        case 4:
            points = 15;
            return "a large treasure chest";
        case 5:
            points = 3;
            return "a crab";
        case 6:
            points = 0;
            return "a bunch of seaweed";
        default:
            points = 0;
            return "error: nothing";
    }
}

string FishingGame::fish(int &points) {
    int dieRoll = rollDie();
    return getCatch(dieRoll, points);
}

void FishingGame::addPoints(int points) {
    totalPoints += points;
}

void FishingGame::displayResult() {
    cout << "\nYou finished fishing with atotal of " << totalPoints << " points\n";

    if (totalPoints >= 30) {
        cout << "Congrats! You are a master angler!\n";
    } else if (totalPoints >= 20) {
        cout << "Good job! You caught quite a few items\n";
    } else if (totalPoints >= 10) {
        cout << "Not bad! You caught some decent items\n";
    } else {
        cout << "Better luck next time. Maybe stick with shopping!\n";
    }
}

int main() {
    // Create an instance of the FishingGame class
    FishingGame game;
    char choice;

    cout << "Welcome to the Fishing Game!\n";
    cout << "In this game, you'll roll a die to see what you catch.\n";
    cout << "Each catch is worth a different number of points. Try to catch as many points as you can!\n\n";
    
    cout << "Press [Enter] to start fishing!\n";
    cin.get();

    // Game loop
    do {
        int points = 0;
        string catchResult = game.fish(points);

        // Display the result of the catch
        cout << "You caught " << catchResult << " worth " << points << " points!\n";

        // Add points to the total
        game.addPoints(points);

        // Ask the user if they want to continue fishing
        cout << "Do you want to continue fishing? (y/n): ";
        cin >> choice;

    } while (choice == 'y' || choice == 'Y');

    // Display the final result
    game.displayResult();

    return 0;
}
