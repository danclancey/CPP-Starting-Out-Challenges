/*
Write a class named Coin. The Coin class should have the following member variable:

    - A string named sideUp. The sideUp member variable will hold either “heads” or 
      “tails” indicating the side of the coin that is facing up.

The Coin class should have the following member functions:

    - A default constructor that randomly determines the side of the coin that is 
      facing up (“heads” or “tails”) and initializes the sideUp member variable 
      accordingly.
    - A void member function named toss that simulates the tossing of the coin. When 
      the toss member function is called, it randomly determines the side of the coin 
      that is facing up (“heads” or “tails”) and sets the sideUp member variable 
      accordingly.
    - A member function named getSideUp that returns the value of the sideUp member 
      variable.

Write a program that demonstrates the Coin class. The program should create an instance 
of the class and display the side that is initially facing up. Then, use a loop to toss 
the coin 20 times. Each time the coin is tossed, display the side that is facing up. The 
program should keep count of the number of times heads is facing up and the number of 
times tails is facing up, and display those values after the loop finishes.
*/

#include <iostream>
#include <string>
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
    // Create coin object
    Coin myCoin;

    cout << "Initial side up: " << myCoin.getSideUp() << endl;

    // Counters for heads and tails 
    int headsCount = 0;
    int tailsCount = 0;

    // Toss coin 20 times 
    for (int i = 0; i < 20; i++) {
        myCoin.toss();
        string result = myCoin.getSideUp();
        cout << "Toss: " << (i + 1) << ": " << result << endl;

        // Update counters 
        if (result == "heads") {
            headsCount++;
        } else {
            tailsCount++;
        }
    }

    // Display Results
    cout << "\nNumber of heads: " << headsCount << endl;
    cout << "\nNumber of tails: " << tailsCount << endl;

    return 0;
}
