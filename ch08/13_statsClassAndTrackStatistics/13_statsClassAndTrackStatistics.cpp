/*
Write a client program that uses the Stats class you created for 
Programming Challenge 12 to store and analyze “best” 100-yard dash 
times for each of the 15 runners on a track team. All I/O should 
be done by the client program. In addition to main, it should have 
two other functions: a getData function to accept input from the 
user and send it to the Stats object and a createReport function 
that creates and displays a report similar to the one shown here,

         Tulsa Tigers Track Team

Average 100 yard-dash time: 11.16 seconds
Slowest runner: Jack        13.09 seconds
Fastest runner: Will        10.82 seconds
*/

#include <iostream>
#include <iomanip>
#include <limits>
#include <string>
#include "Stats.h"

using namespace std;

// Function prototypes
void getData(Stats& stats, string names[]);
void createReport(const Stats& stats, const string names[]);

int main() {
    Stats teamStats;
    string runnerNames[15];

    // Get data for each runner
    getData(teamStats, runnerNames);

    // Create and display the report
    createReport(teamStats, runnerNames);

    return 0;
}

// Function to get data from the user for each runner
void getData(Stats& stats, string names[]) {
    cout << "Enter the names and 100-yard dash times for each runner:\n";
    for (int i = 0; i < 15; i++) {
        string name;
        double time;

        cout << "Runner " << (i + 1) << " Name: ";
        cin >> ws; // To ignore leading whitespace
        getline(cin, name);

        while (true) {
            cout << "Runner " << (i + 1) << " Time (in seconds): ";
            cin >> time;

            // Validate input: ensure it's a number and greater than 0
            if (cin.fail() || time <= 0) {
                cout << "Invalid input. Please enter a positive numeric time.\n";
                cin.clear(); // Clear the error state
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); 
            } else {
                break; // Valid input received, break out of the loop
            }
        }

        names[i] = name;
        stats.storeValue(time);
    }
}


// Function to create and display the report
void createReport(const Stats& stats, const string names[]) {
    double avgTime = stats.average();
    int fastestIndex = stats.lowest();  // The lowest time indicates the fastest runner
    int slowestIndex = stats.highest(); // The highest time indicates the slowest runner

    cout << "\n         Tulsa Tigers Track Team\n\n";
    cout << fixed << setprecision(2);
    cout << "Average 100 yard-dash time: " << avgTime << " seconds\n";
    cout << "Fastest runner: " << setw(10) << left << names[fastestIndex]
         << " " << setw(6) << right << stats.getValue(fastestIndex) << " seconds\n";
    cout << "Slowest runner: " << setw(10) << left << names[slowestIndex]
         << " " << setw(6) << right << stats.getValue(slowestIndex) << " seconds\n";
}

