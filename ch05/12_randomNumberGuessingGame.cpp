/*
Write a program that generates a random number between 1 and 100 and asks the user 
to guess what the number is. If the user’s guess is higher than the random number, 
the program should display “Too high. Try again.” If the user’s guess is lower than 
the random number, the program should display “Too low. Try again.” The program 
should use a loop that repeats until the user correctly guesses the random number. 
Then the program should display “Congratulations. You figured out my number.”
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

int main() {
    int randomNumber, userGuess;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    // Loop until the user guesses the correct number
    do {
        // Prompt user for their guess
        cout << "Guess a number between 1 and 100: ";
        cin >> userGuess;

        // Check if the guess is too high or too low
        if (userGuess > randomNumber) {
            cout << "Too high. Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low. Try again." << endl;
        }

    } while (userGuess != randomNumber);  // Repeat until the guess is correct

    // Announce win 
    cout << "Congratulations. You figured out my number." << endl;

    return 0;
}

