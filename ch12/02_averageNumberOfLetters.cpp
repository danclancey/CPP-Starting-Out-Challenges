/*
Modify the program you wrote for Problem 1 (Word Counter), so that it also displays the average number of letters in each word.
*/

#include <iostream>
#include <cstring>

using namespace std;

int countWordsAndLetters(const char* str, int& totalLetters);

int main() {
    const int SIZE = 100;
    char userInput[SIZE];
    int totalLetters = 0;

    // Prompt user for string
    cout << "Enter a string: ";
    cin.getline(userInput, SIZE);

    // Call function to count words and letters 
    int wordCount = countWordsAndLetters(userInput, totalLetters);

    // Display number of words 
    cout << "The number of words in the string is: " << wordCount << endl;


    // Calc and display avg number of letters per word 
    if (wordCount > 0) {
        double avgLettersPerWord = static_cast<double>(totalLetters) / wordCount;
        cout << "The average number of letters per word is: " << avgLettersPerWord << endl;
    } else {
        cout << "There are no words in the input string.\n";
    }

    return 0;
}

// Function to count number of words and total letters in C-string
int countWordsAndLetters(const char* str, int& totalLetters) {
    int wordCount = 0;
    bool inWord = false;
    totalLetters = 0;

    // Loop through characters in the string 
    while (*str != '\0') {
        if (*str != ' ' && *str != '\t' && *str != '\n') {
            // If we encounter a non-space character, increase letter count 
            totalLetters++;
            if (!inWord) {
                // Found start of new word 
                wordCount++;
                inWord = true;
            }
        } else {
            // If we encounter a space tab or newline, we are not in a word 
            inWord = false;
        }

        str++;
    }

    return wordCount;
}
