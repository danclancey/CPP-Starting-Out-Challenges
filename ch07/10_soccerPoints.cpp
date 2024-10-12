/* 
Youth soccer teams earn 3 points for each win, 1 point for each tie, and 0 points for 
each loss. Create a teamScore class that has variables to hold the teamName, and to 
count the number of wins, ties, and losses. The constructor should accept the team 
name and initialize the three counters to 0. The class should have member functions 
updateWins, updateTies, and updateLosses that each add 1 to the appropriate counter. 
It should also have a displayRecord function that produces a nicely formatted display 
containing the team name, number of wins, ties, and losses so far, and the computed 
points. Demonstrate the class by creating a menu-driven program that creates a 
teamScore object and then includes a loop to display a menu and call the appropriate 
class function depending on the user-entered menu choice.
*/

#include <iostream>
#include <string>

using namespace std;

class teamScore {
    private:
        string teamName;
        int wins;
        int ties;
        int losses;

    public:
        // Constructor
        teamScore(string t);

        void updateWins() { wins++; }
        void updateTies() { ties++; }
        void updateLosses() {losses++; }
        
        void displayRecord();
};

teamScore::teamScore(string t) {
    teamName = t;
    wins = 0;
    ties = 0;
    losses = 0;
}

void teamScore::displayRecord() {
    int points = (wins * 3) + (ties * 3);
    cout << "\nTeam:\t" << teamName << endl;
    cout << "Wins:\t" << wins << endl;
    cout << "Ties:\t" << ties << endl;
    cout << "Losses:\t" << losses << endl;
    cout << "------------------------\n";
}
int main() {
    string teamName;
    int choice;

    // Get team name from user 
    cout << "Please enter team name: ";
    getline(cin, teamName);

    // Create teamScore object 
    teamScore myTeam(teamName);

    // Menu driven loop 
    do {
        // Display menu 
        cout << "\nMenu:\n";
        cout << "1. Record a win\n";
        cout << "2. Record a tie\n";
        cout << "3. Record a loss\n";
        cout << "4. Display team record\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        // Switch case for menu choice 
        switch (choice) {
            case 1:
                myTeam.updateWins();
                cout << "Successfully added win.\n";
                break;
            case 2:
                myTeam.updateTies();
                cout << "Successsfully added tie.\n";
                break;
            case 3:
                myTeam.updateLosses();
                cout << "Successfully added loss.\n";
                break;
            case 4:
                myTeam.displayRecord();
                break;
            case 5:
                cout << "Exiting . . .\n";
                break;
            default:
                cout << "Invalid choice. Please try again.\n";
        }
    } while (choice != 5);

    return 0;
}
