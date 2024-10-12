/*
Write a program that displays an inchworm on the left-hand side of the screen, facing 
right. Then slowly move him across the screen, until he disappears off the right-hand 
side. You may wish to do this in a loop so that after disappearing to the right, the 
worm appears again on the left. The diagram below shows how he may look at various 
points on the screen.

-----
                  \/             \/                  \/             \/                 \/
                  00           0 00             000  00          0  00                 00
~000000000~0000 0000      ~000 000      ~0000      0000     ~0000 0000         ~000000000
-----
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

// Function to draw the inchworm at a given position
void drawWorm(HANDLE screen, int col, int frame) {
    // Clear the screen
    system("cls");

    // Draw the worm's head and body at different frames
    switch (frame) {
        case 0:
            placeCursor(screen, 2, col);
            cout << "  \\/";
            placeCursor(screen, 3, col);
            cout << "  00";
            placeCursor(screen, 4, col);
            cout << "~000000000~";
            break;
        case 1:
            placeCursor(screen, 2, col);
            cout << "   0 00";
            placeCursor(screen, 3, col);
            cout << " 0000";
            placeCursor(screen, 4, col);
            cout << "~000000000~";
            break;
        case 2:
            placeCursor(screen, 2, col);
            cout << "    \\/";
            placeCursor(screen, 3, col);
            cout << " 000 00";
            placeCursor(screen, 4, col);
            cout << "~000000000~";
            break;
    }
}

int main() {
    // Get the handle to the console screen
    HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);

    // Get the console screen size
    CONSOLE_SCREEN_BUFFER_INFO csbi;
    GetConsoleScreenBufferInfo(screen, &csbi);
    int screenWidth = csbi.srWindow.Right - csbi.srWindow.Left + 1;

    // Loop to move the worm across the screen indefinitely
    while (true) {
        // Move the worm from left to right
        for (int col = 0; col < screenWidth; col++) {
            // Display each frame for animation effect
            for (int frame = 0; frame < 3; frame++) {
                drawWorm(screen, col, frame);
                this_thread::sleep_for(chrono::milliseconds(100));
            }
        }
    }

    return 0;
}
