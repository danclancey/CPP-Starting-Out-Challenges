/*
Write a function that accepts a C-string as an argument and capitalizes the first character of each sentence in the string. For instance, 
if the string argument is “hello. my name is Joe.  what is your name?” the function should manipulate the string so it contains “Hello. 
My name is Joe. What is your name?” Demonstrate the function in a program that asks the user to input a string and then passes it to the 
function. The modified string should be displayed on the screen.
*/

#include <iostream>
#include <cctype>    
#include <cstring>   

using namespace std;

// Function prototype
void capitalizeSentences(char* str);

int main() {
    const int SIZE = 200;  // Define the size of the input buffer
    char userInput[SIZE];

    // Ask the user to input a string
    cout << "Enter a string: ";
    cin.getline(userInput, SIZE);  // Get input from the user

    // Call the function to capitalize the first character of each sentence
    capitalizeSentences(userInput);

    // Display the modified string
    cout << "Modified string: " << userInput << endl;

    return 0;
}

// Function to capitalize the first character of each sentence in a C-string
void capitalizeSentences(char* str) {
    bool capitalizeNext = true;  // Flag to determine if the next character should be capitalized

    // Loop through each character in the string
    while (*str != '\0') {
        // Check if the character is a letter and we need to capitalize it
        if (isalpha(*str) && capitalizeNext) {
            *str = toupper(*str);  // Capitalize the letter
            capitalizeNext = false;  // Reset the flag
        }
        // If we encounter a sentence-ending punctuation ('.', '!', '?')
        if (*str == '.' || *str == '!' || *str == '?') {
            capitalizeNext = true;  // Set flag to capitalize the next letter after punctuation
        }

        // Move to the next character in the string
        str++;
    }
}

