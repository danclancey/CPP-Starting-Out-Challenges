/*
Write a program that simulates a lottery. The program should have an 
array of five integers named winningDigits, with a randomly generated 
number in the range of 0 through 9 for each element in the array. The 
program should ask the user to enter five digits and should store them 
in a second integer array named player. The program must compare the 
corresponding elements in the two arrays and count how many digits 
match. For example, the following shows the winningDigits array and the 
Player array with sample numbers stored in each. There are two matching 
digits, elements 2 and 4.

        WinningDigits	7	4	9	1	3
        player	        4	2	9	7	3

Once the user has entered a set of numbers, the program should display 
the winning digits and the player’s digits and tell how many digits matched.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// constant for lottery array size
const int SIZE = 5;

// Function Prototypes
void generateWinningNums(int winningNums[], int size);
void getPlayerNums(int player[], int size);
int countMatches(const int winningNums[], const int player[], int size);
void displayResults(const int winningNums[], const int player[], int size, int matches);

int main() {
    int winningNums[SIZE];
    int player[SIZE];

    // seed RNG and gen winning numbers 
    srand(static_cast<unsigned int>(time(0)));
    generateWinningNums(winningNums, SIZE);

    // Get player numbers 
    getPlayerNums(player, SIZE);

    // Count matches between player and lotto
    int matches = countMatches(winningNums, player, SIZE);

    // Display results 
    displayResults(winningNums, player, SIZE, matches);

    return 0;
}

// Function to generate winning numbers 
void generateWinningNums(int winningNums[], int size) {
    for (int i = 0; i < size; i++) {
        winningNums[i] = rand() % 10;
    }
}

// Function to get player numbers 
void getPlayerNums(int player[], int size) {
    cout << "Enter your 5 digit lotto picks (0-9): \n";
    for (int i = 0; i < size; i++) {
        do {
            cout << "Pick " << (i + 1) << ": ";
            cin >> player[i];

            // validate input 
            if (player[i] < 0 || player[i] > 9) {
                cout << "Invalid input. Enter a number between 0 and 9.\n";
            }
        } while (player[i] < 0 || player[i] > 9);
    } 
}

// Function to count matching between player and lotto nums 
int countMatches(const int winningNums[], const int player[], int size) {
    int matchCount = 0;
    for (int i = 0; i < size; i++) {
        if (winningNums[i] == player[i]) {
            matchCount++;
        }
    }

    return matchCount;
}

// Function to display winning numbers, player numbers, and number of matches 
void displayResults(const int winningNums[], const int player[], int size, int matches) {
    cout << "\nWinning Numbers:\t";
    for (int i = 0; i < size; i++) {
        cout << winningNums[i] << " ";
    }

    cout << "\nPlayer picks:\t\t";
    for (int i = 0; i < size; i++) {
        cout << player[i] << " ";
    }

    cout << "\n\nNumber of matching numbers: " << matches  << endl;
}
