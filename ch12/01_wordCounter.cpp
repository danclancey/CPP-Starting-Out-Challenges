/*
Write a function that accepts a C-string as an argument and returns the number of words contained in the string. For instance, 
if the string argument is “Four score and seven years ago” the function should return the number 6. Demonstrate the function 
in a program that asks the user to input a string and then passes it to the function. The number of words in the string should 
be displayed on the screen.
*/

#include <iostream>
#include <cstring>

using namespace std;

int countWords(const char* str);

int main() {
    const int SIZE = 100;
    char userInput[SIZE];

    // Prompt user for string 
    cout << "Enter a string: ";
    cin.getline(userInput, SIZE);

    // Call the function to count words and display result 
    int wordCount = countWords(userInput);
    cout << "The number of words in the string is: " << wordCount << endl;

    return 0;
}

// Function to cound words in C-String 
int countWords(const char* str) {
    int wordCount = 0;
    bool inWord = false;

    // Loop through characters in string 
    while (*str != '\0') {
        if (*str != ' ' && !inWord) {
            // If we encounter a non-space character and are not in a word 
            // we have found the start of a new word 
            wordCount++;
            inWord = true;
        } else if (*str == ' ') {
            // If we encounter a space, we are no longer in a word 
            inWord = false;
        }

        str++;
    }

    return wordCount;

}
