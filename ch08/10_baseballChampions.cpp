/* 
This challenge uses two files located in the Chapter 8 programs 
folder on the book’s companion website.

    - teams.dat contains an alphabetical list of a number of Major 
      League baseball teams that have won the World Series at least 
      once.
    - WorldSeriesWinners.dat contains a chronological list of World 
      Series’ winning teams from 1950 through 2014. The first line in 
      the file is the name of the team that won in 1950, and the last 
      line is the name of the team that won in 2014. (Note that the 
      World Series was not played in 1994.)

Write a program that reads the contents of each of these files into an 
array or vector. It should then display the contents of the teams.dat 
file on the screen and prompt the user to enter the name of one of the 
teams. When the user enters a team name, the program should display the 
number of times that team has won the World Series in the time period 
from 1950 through 2014.
*/

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

// Function prototypes
void loadTeams(const string& filename, vector<string>& teams);
void loadWinners(const string& filename, vector<string>& winners);
int countWins(const vector<string>& winners, const string& team);
void displayTeams(const vector<string>& teams);
string toLowerCase(const string& str);
string trim(const string& str);

int main() {
    // Vectors to store team names and World Series winners
    vector<string> teams;
    vector<string> winners;

    // Load data from the files into vectors
    loadTeams("teams.dat", teams);
    loadWinners("worldserieswinners.dat", winners);

    // Display the list of teams to user
    displayTeams(teams);

    // Prompt the user to enter team name
    string userTeam;
    cout << "\nEnter the name of a team to see how many times they have won the World Series: ";
    getline(cin, userTeam);

    // Count the number of wins for the team
    int wins = countWins(winners, userTeam);

    // Display result
    if (wins > 0) {
        cout << "\nThe " << userTeam << " have won the World Series " << wins << " times from 1950 to 2014.\n";
    } else {
        cout << "\nThe " << userTeam << " did not win the World Series between 1950 and 2014, or the team name was not found.\n";
    }

    return 0;
}

// Function to load teams from file into a vector
void loadTeams(const string& filename, vector<string>& teams) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file " << filename << endl;
        return;
    }
    string team;
    while (getline(file, team)) {
        team = trim(team); // Trim the string
        teams.push_back(team);
    }
    file.close();
}

// Function to load World Series winners from file into a vector
void loadWinners(const string& filename, vector<string>& winners) {
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file " << filename << endl;
        return;
    }
    string winner;
    while (getline(file, winner)) {
        winner = trim(winner); // Trim the string
        winners.push_back(winner);
    }
    file.close();
}

// Function to count the number of World Series wins for a specific team (case-insensitive)
int countWins(const vector<string>& winners, const string& team) {
    int count = 0;
    string lowerTeam = toLowerCase(team);
    for (const string& winner : winners) {
        if (toLowerCase(winner) == lowerTeam) {
            count++;
        }
    }
    return count;
}

// Function to display the list of teams
void displayTeams(const vector<string>& teams) {
    cout << "List of teams that have won the World Series at least once:\n";
    for (const string& team : teams) {
        cout << team << endl;
    }
}

// Function to convert a string to lowercase
string toLowerCase(const string& str) {
    string lowerStr = str;
    transform(lowerStr.begin(), lowerStr.end(), lowerStr.begin(), ::tolower);
    return lowerStr;
}

// Function to trim leading and trailing whitespace (including '\r' and '\n')
string trim(const string& str) {
    size_t first = str.find_first_not_of(" \t\r\n");
    if (first == string::npos) {
        return ""; // String is all whitespace
    }
    size_t last = str.find_last_not_of(" \t\r\n");
    return str.substr(first, (last - first + 1));
}

