/*
Write a program that uses nested loops to display the triangle pattern shown below.

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
    // Upper part of the triangle
    for (int i = 1; i <= 7; i += 2) {
        for (int j = 0; j < i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    // Lower part of the triangle
    for (int i = 5; i >= 1; i -= 2) {
        for (int j = 0; j < i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}

