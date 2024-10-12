/* 
Modify the program you wrote for Programming Challenge 12, so that after disappearing 
off of the screen, the word UP reappears at the bottom of the screen and the word DOWN 
reappears at the top of the screen. Have these words each traverse the screen three 
times before the program terminates.
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

    // Set the starting positions and counters
    int upCol = screenWidth / 2 - 10;    // A couple of inches to the left of center for "UP"
    int downCol = screenWidth / 2 + 10;  // A couple of inches to the right of center for "DOWN"
    int upRow, downRow;
    int iterations = 0;

    // Loop to make the words traverse the screen three times
    while (iterations < 3) {
        // Reset starting positions for "UP" at the bottom and "DOWN" at the top
        upRow = screenHeight - 1; // Bottom of the screen for "UP"
        downRow = 0;              // Top of the screen for "DOWN"

        // Loop to move "UP" and "DOWN" until they disappear
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

        // Increment the iteration counter after one full traversal
        iterations++;
    }

    // Clear the screen one last time
    system("cls");

    cout << "The words have traversed the screen three times. Press any key to exit...\n";
    cin.get(); // Wait for user input before closing the program

    return 0;
}
