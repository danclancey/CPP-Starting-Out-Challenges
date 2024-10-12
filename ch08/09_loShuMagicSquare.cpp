/*
The Lo Shu Magic Square is a grid with three rows and three columns 
that has the following properties:

    - The grid contains the numbers 1 through 9 exactly.
    - The sum of each row, each column, and each diagonal all add up 
      to the same number. This is shown in Figure 8-18.

Figure 8-18 Lo Shu Magic Square

Write a program that simulates a magic square using a two-dimensional  
3 x 3 array. It should have a Boolean function isMagicSquare that 
accepts the array as an argument and returns true if it determines it 
is a Lo Shu Magic Square and false if it is not. Test the program with 
one array, such as the one shown in Figure 8-18, that is a magic square 
and one that is not.
*/

#include <iostream>

using namespace std;

// Constants for the size of the grid and the target sum for a magic square.
const int SIZE = 3;
const int MAGIC_SUM = 15;

// Function prototypes
bool isMagicSquare(int square[SIZE][SIZE]);
void printSquare(int square[SIZE][SIZE]);

int main() {
    // Example 3x3 arrays.
    int magicSquare[SIZE][SIZE] = {
        {4, 9, 2},
        {3, 5, 7},
        {8, 1, 6}
    };

    int nonMagicSquare[SIZE][SIZE] = {
        {4, 2, 9},
        {3, 5, 7},
        {8, 1, 6}
    };

    // Test with a valid magic square.
    cout << "Testing with a magic square:\n";
    printSquare(magicSquare);
    if (isMagicSquare(magicSquare)) {
        cout << "This is a Lo Shu Magic Square.\n";
    } else {
        cout << "This is NOT a Lo Shu Magic Square.\n";
    }

    // Test with a non-magic square.
    cout << "\nTesting with a non-magic square:\n";
    printSquare(nonMagicSquare);
    if (isMagicSquare(nonMagicSquare)) {
        cout << "This is a Lo Shu Magic Square.\n";
    } else {
        cout << "This is NOT a Lo Shu Magic Square.\n";
    }

    return 0;
}

// Function to print a 3x3 square.
void printSquare(int square[SIZE][SIZE]) {
    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            cout << square[row][col] << " ";
        }
        cout << endl;
    }
    cout << endl;  // Add a blank line for readability.
}

// Function to check if a 3x3 array is a Lo Shu Magic Square.
bool isMagicSquare(int square[SIZE][SIZE]) {
    // Check if each number from 1 to 9 is used exactly once.
    int frequency[10] = {0}; // Index 0 is unused.

    for (int row = 0; row < SIZE; ++row) {
        for (int col = 0; col < SIZE; ++col) {
            int num = square[row][col];
            if (num < 1 || num > 9 || frequency[num] != 0) {
                return false; // Number out of range or already seen.
            }
            frequency[num] = 1; // Mark the number as seen.
        }
    }

    // Check the sums of rows, columns, and diagonals.
    for (int i = 0; i < SIZE; ++i) {
        int rowSum = 0, colSum = 0;
        for (int j = 0; j < SIZE; ++j) {
            rowSum += square[i][j];      // Sum of the ith row.
            colSum += square[j][i];      // Sum of the ith column.
        }
        if (rowSum != MAGIC_SUM || colSum != MAGIC_SUM) {
            return false;
        }
    }

    // Check diagonals.
    int diag1Sum = square[0][0] + square[1][1] + square[2][2];
    int diag2Sum = square[0][2] + square[1][1] + square[2][0];

    if (diag1Sum != MAGIC_SUM || diag2Sum != MAGIC_SUM) {
        return false;
    }

    // If all checks pass, it is a magic square.
    return true;
}

