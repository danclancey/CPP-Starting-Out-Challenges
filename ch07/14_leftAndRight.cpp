/*
Modify the program you wrote for Programming Challenge 12 to display the words LEFT 
(starting at the right-hand side of the screen a row or two down from the middle) 
and RIGHT (starting at the left-hand side of the screen a row or two up from the 
middle). Moving about six moves per second, move LEFT to the left and RIGHT to the 
right until both words disappear off the screen.
*/

#include <iostream>
#include <windows.h>
#include <thread> // For sleep_for
#include <chrono> // For milliseconds

using namespace std;

// Function to set the cursor position on the console
void placeCursor(HANDLE screen, int row, int col) {
    COORD position;
    position.Y = row;
    position.X = col;
    SetConsoleCursorPosition(screen, position);
}

int main() {
    // Get the handle to the console screen
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the console screen size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(screen, &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;
    int screenHeight = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;

    // Set the starting positions
    int leftRow = screenHeight / 2 + 2;  // A row or two down from the center for "LEFT"
    int rightRow = screenHeight / 2 - 2; // A row or two up from the center for "RIGHT"
    int leftCol = screenWidth - 5;       // Start at the far right for "LEFT"
    int rightCol = 0;                    // Start at the far left for "RIGHT"

    // Loop to move "LEFT" left and "RIGHT" right until both disappear
    while (leftCol >= 0 && rightCol < screenWidth) {
        // Clear the screen
        system("cls");

        // Display "LEFT" at its current position
        placeCursor(screen, leftRow, leftCol);
        cout << "LEFT";

        // Display "RIGHT" at its current position
        placeCursor(screen, rightRow, rightCol);
        cout << "RIGHT";

        // Move "LEFT" left and "RIGHT" right
        leftCol--;
        rightCol++;

        // Sleep for about 0.17 seconds before the next move (approximately 6 moves per second)
        this_thread::sleep_for(chrono::milliseconds(170));
    }

    // Clear the screen one last time
    system("cls");

    cout << "Words have moved off the screen. Press any key to exit...\n";
    cin.get(); // Wait for user input before closing the program

    return 0;
}
