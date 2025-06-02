/*
Write a program that creates and displays a report of 12 Little League baseball players and their 
batting averages, listed in order of batting average from highest to lowest. The program should use 
an array of structures or class objects to store the data, where each structure or object holds the 
name of a player and their batting average. Make the program modular by having main call on different 
functions to input the data, sort the data, perform swaps, and display the report.
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <sstream>

using namespace std;

class PlayerStats {
    private:
        string playerName;
        double battingAvg;

    public:
        PlayerStats() { playerName = ""; battingAvg = 0.0; }

        void setPlayerName(string p) { playerName = p; }
        void setBattingAvg(double a) { battingAvg = a; }

        string getPlayerName() const { return playerName; }
        double getBattingAvg() const { return battingAvg; }

};

// Function prototypes
void sortPlayers(PlayerStats players[], int SIZE);
string formatBattingAvg (double avg);
void displayPlayers(const PlayerStats players[], int size);

// Const for array size
const int SIZE = 12;

int main() {
    PlayerStats players[SIZE];

    cout << "Welcome to Dan's Baseball Stat Report!\n";
    cout << "This program will sort players by batting average.\n";

    for (int i = 0; i < SIZE; i++) {
        string player;
        double battingAvg;
        
        cout << "Enter player " << (i + 1) << " name: ";
        getline(cin, player);
        
        // Input validation for batting average 
        do {
            cout << "Enter " << player << "'s batting average: ";
            cin >> battingAvg;
            
            // Check if non-numeric input 
            if (cin.fail()) {
                cout << "Invalid input! Please enter a number between 0.000 and 1.000\n";
                cin.clear();
                cin.ignore(numeric_limits<streamsize>::max(), '\n');
            }

            // check if bating avg is within valid range 
            if (battingAvg < 0.0 || battingAvg > 1.0) 
                cout << "Invalid batting average! Must be between 0.000 and 1.000.\n";

        } while (battingAvg < 0.0 || battingAvg > 1.0);

        players[i].setPlayerName(player);
        players[i].setBattingAvg(battingAvg);
        cin.ignore();
    }

    sortPlayers(players, SIZE);

    displayPlayers(players, SIZE);

    return 0;
}

// Function to sort player objects 
void sortPlayers(PlayerStats players[], int SIZE) {
    int i, j;
    bool swapped;

    for (i = 0; i < SIZE - 1; i++) {
        swapped = false;

        for (j = 0; j < SIZE - 1; j++) {
            if (players[j].getBattingAvg() <  players[j + 1].getBattingAvg()) {
                swap(players[j], players[j + 1]);
                swapped = true;
            }
        }

        if (swapped == false)
            break;
    }
}

// Function to remove 0. at beginning of batting avg 
string formatBattingAvg(double avg) {
    stringstream stream;
    stream << fixed << setprecision(3) << avg;

    string formattedAvg = stream.str();

    if (formattedAvg[0] == '0')         // If formatted avg starts with '0', remove it 
        formattedAvg.erase(0, 1);
    
    return formattedAvg;
}

// Function to display report
void displayPlayers(const PlayerStats players[], int size) {
    cout << left << setw(17) << "Player Name" << right << "Batting Avg" << endl;
    cout << "-----------------------------\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << players[i].getPlayerName()
             << formatBattingAvg(players[i].getBattingAvg()) << endl;
    }
}
