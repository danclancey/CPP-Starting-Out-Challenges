/*
Write a program that uses nested loops to display the diamond pattern shown below. 
The outer loop should iterate once for each line. Inner loops should be used to 
handle the number of space and + characters on each line.

     +
    +++
   +++++
  +++++++
   +++++
    +++
     +
*/

#include <iostream>

using namespace std;

int main() {
    const int MAX_WIDTH = 7;

    // Upper part of the triangle (increasing part)
    for (int i = 1; i <= MAX_WIDTH; i += 2) {
        for (int j = 0; j < (MAX_WIDTH - i) / 2; j++) {
            cout << " ";  // Print spaces to center the pattern
        }
        for (int k = 0; k < i; k++) {
            cout << "+";
        }
        cout << endl;
    }

    // Lower part of the triangle (decreasing part)
    for (int i = MAX_WIDTH - 2; i >= 1; i -= 2) {
        for (int j = 0; j < (MAX_WIDTH - i) / 2; j++) {
            cout << " ";  // Print spaces to center the pattern
        }
        for (int k = 0; k < i; k++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}

