/* 
  Write a program that uses a loop to display the characters for each ASCII code 32 
  through 127. Display 16 characters on each line with one space between characters.
*/

#include <iostream>

using namespace std;

int main()
{
    char asciiCode;
    int counter = 0;
    
    // Loop through ascii codes 32 - 127
    for (int i = 32; i <= 127; i++) {
        asciiCode = i;
        cout << asciiCode << " ";
        counter++;

        // Print newline after 16 characters
        if (counter == 16) {
            cout << endl;
            counter = 0;
        }
    }
    cout << endl;

    return 0;
}
