/*
Modify the program you wrote for Programming Challenge 2 (Lottery Winners) so it performs a binary 
search instead of a linear search.
*/

#include <iostream>

using namespace std;

// function prototype;
bool isWinner(int playerNums[], int SIZE, int winningNum);

const int SIZE = 10;

int main() {
    int inputNum;
    int playerNums[SIZE] = {
        13579, 26791, 26792, 33445, 55555,
        62483, 77777, 79422, 85647, 93121
    };

    cout << "Enter this weeks winning number: ";
    cin >> inputNum;

    if (isWinner(playerNums, SIZE, inputNum) == true) {
        cout << "Congrats! You won! The winning number is: " << inputNum << endl;
    } else {
        cout << "You did not select the winning number.\n";
    }

}

// Binary search
bool isWinner(int playerNums[], int SIZE, int winningNum)
{
    int low = 0;
    int high = SIZE - 1;
    int middle;

    while (low <= high) {
        middle = (low + high) / 2;                // Find mid point of array
        
        if (playerNums[middle] == winningNum)
            return true;                          // Return true if value matches winningNum  
        else if (playerNums[middle] < winningNum)
            low = middle + 1;                     // adjust the search to the upper half 
        else 
            high = middle - 1;                    // adjust the search to the bottom half
    }

    return false;
}

