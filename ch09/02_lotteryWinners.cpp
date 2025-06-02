/*
A lottery ticket buyer purchases 10 tickets a week, always playing the same 10 five-digit “lucky” 
combinations. Write a program that initializes an array with these numbers and then lets the player 
enter this week’s winning five-digit number. The program should perform a linear search through the 
list of the player’s numbers and report whether or not one of the tickets is a winner this week. 
Here are the numbers:

        13579	26791	26792	33445	55555	62483	77777	79422	85647	93121
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

// linearsearch 
bool isWinner(int playerNums[], int SIZE, int winningNum)
{
    for (int count = 0; count < SIZE; count++)
    {
        if (playerNums[count] == winningNum)
            return true;
    }
    return false;
}

