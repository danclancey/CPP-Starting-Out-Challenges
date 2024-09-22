/*
Write a program that uses a loop to display Pattern A below, followed by
another loop that displays Pattern B.


      Pattern A         Pattern B
      +                 ++++++++++
      ++                +++++++++
      +++               ++++++++
      ++++              +++++++
      +++++             ++++++
      ++++++            +++++
      +++++++           ++++
      ++++++++          +++
      +++++++++         ++
      ++++++++++        +
*/

#include <iostream>

using namespace std;

int main() {
    const int SIZE = 10;

    // Display Pattern A
    cout << "Pattern A" << endl;
    for (int i = 1; i <= SIZE; i++) {
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    // Display Pattern B
    cout << "\nPattern B" << endl;
    for (int i = SIZE; i >= 1; i--) {
        for (int j = 1; j <= i; j++) {
            cout << "+";
        }
        cout << endl;
    }

    return 0;
}

