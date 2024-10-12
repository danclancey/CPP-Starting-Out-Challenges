/*
Write a program that displays the word UP on the bottom line of the screen a couple of 
inches to the left of center and displays the word DOWN on the top line of the screen 
a couple of inches to the right of center. Moving about once a second, move the word 
UP up a line and the word DOWN down a line until UP disappears at the top of the 
screen and DOWN disappears at the bottom of the screen.
*/

#include <iostream>
#include <windows.h>
#include <thread> // For sleep_for
#include <chrono> // For seconds

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
    int upRow = screenHeight - 1; // Bottom of the screen for "UP"
    int downRow = 0;              // Top of the screen for "DOWN"
    int upCol = screenWidth / 2 - 10;    // A couple of inches to the left of center for "UP"
    int downCol = screenWidth / 2 + 10;  // A couple of inches to the right of center for "DOWN"

    // Loop to move "UP" and "DOWN"
    while (upRow >= 0 && downRow < screenHeight) {
        // Clear the screen
        system("cls");

        // Display "UP" at its current position
        placeCursor(screen, upRow, upCol);
        cout << "UP";

        // Display "DOWN" at its current position
        placeCursor(screen, downRow, downCol);
        cout << "DOWN";

        // Move "UP" up a line and "DOWN" down a line
        upRow--;
        downRow++;

        // Sleep for 1 second before the next move
        this_thread::sleep_for(chrono::seconds(1));
    }

    // Clear the screen one last time
    system("cls");

    cout << "Words have moved off the screen. Press any key to exit...\n";
    cin.get(); // Wait for user input before closing the program

    return 0;
}
