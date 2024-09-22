/*
Enhance the program that you wrote for Programming Challenge 12 so it keeps a count of the 
number of guesses the user makes. When the user correctly guesses the random number, the 
program should display the number of guesses along with the message of congratulations.
*/

#include <iostream>
#include <cstdlib>  
#include <ctime>   

using namespace std;

int main() {
    int randomNumber, userGuess, guessCount = 0;

    // Seed the random number generator
    srand(static_cast<unsigned int>(time(0)));

    // Generate a random number between 1 and 100
    randomNumber = rand() % 100 + 1;

    // Loop until the user guesses the correct number
    do {
        // Prompt the user for their guess
        cout << "Guess a number between 1 and 100: ";
        cin >> userGuess;

        // Increment the guess count
        guessCount++;

        // Check if the guess is too high or too low
        if (userGuess > randomNumber) {
            cout << "Too high. Try again." << endl;
        } else if (userGuess < randomNumber) {
            cout << "Too low. Try again." << endl;
        }

    } while (userGuess != randomNumber);  // Repeat until the guess is correct

    // Display you won and number of attempts
    cout << "Congratulations. You figured out my number!" << endl;
    cout << "It took you " << guessCount << " guesses." << endl;

    return 0;
}

