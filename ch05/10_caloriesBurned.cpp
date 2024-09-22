/*
Running on a particular treadmill, you burn 3.9 calories per minute. 
Write a program that uses a loop to display the number of calories 
burned after 5, 10, 15, 20, 25, and 30 minutes.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    const double CAL_PER_MIN = 3.9;
    double totalCalBurn;
    
    // Print column headers
    cout << setw(10) << left << "Minutes" << setw(15) << right 
         << "Calories Burned\n";
    cout << "-------------------------\n";
    for (int i = 5; i <= 30; i+=5) {
        // Calculate calories burned
        totalCalBurn = CAL_PER_MIN * i;
        cout << setw(10) << left << i << setw(15) << right
             << fixed << setprecision(2) << totalCalBurn << endl;

    }

    return 0;
}
