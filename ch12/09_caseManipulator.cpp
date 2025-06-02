/*
Write a program with three functions: upper, lower, and flip. The upper function should accept a C-string as an argument. It should 
step through all the characters in the string, converting each to uppercase. The lower function, too, should accept a pointer to a 
C-string as an argument. It should step through all the characters in the string, converting each to lowercase. Like upper and lower, 
flip should also accept a C-string. As it steps through the string, it should test each character to determine whether it is upper- 
or lowercase. If a character is uppercase, it should be converted to lowercase. If a character is lowercase, it should be converted to 
uppercase.

Test the functions by asking for a string in function main, then passing it to them in the following order: flip, lower, and upper.
*/

#include <iostream>
#include <cstring>  
#include <cctype>  

using namespace std;

// Function prototypes
void upper(char *str);
void lower(char *str);
void flip(char *str);

int main() {
    const int SIZE = 100;
    char input[SIZE];

    // Prompt user for string  
    cout << "Enter a string: ";
    cin.getline(input, SIZE);

    // Apply flip, lower, and upper functions sequentially
    cout << "\nOriginal string: " << input << endl;

    flip(input);
    cout << "\nAfter flip: " << input << endl;

    lower(input);
    cout << "\nAfter lower: " << input << endl;

    upper(input);
    cout << "\nAfter upper: " << input << endl;

    return 0;
}

// Function to convert all characters in the C-string to uppercase
void upper(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = toupper(str[i]);  // Convert each character to uppercase
    }
}

// Function to convert all characters in the C-string to lowercase
void lower(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        str[i] = tolower(str[i]);  // Convert each character to lowercase
    }
}

// Function to flip the case of each character in the C-string
void flip(char *str) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (isupper(str[i])) {
            str[i] = tolower(str[i]);  // If uppercase, convert to lowercase
        } else if (islower(str[i])) {
            str[i] = toupper(str[i]);  // If lowercase, convert to uppercase
        }
    }
}

