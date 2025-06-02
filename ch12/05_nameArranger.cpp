/*
Write a program that asks for the user’s first, middle, and last names. The names should be stored in three different character 
arrays. The program should then store in a fourth array the name arranged in the following manner: the last name followed by a 
comma and a space, followed by the first name and a space, followed by the middle name. For example, if the user entered “Carol 
Lynn Smith”, it should store “Smith, Carol Lynn” in the fourth array. Display the contents of the fourth array on the screen.
*/

#include <iostream>
#include <cstring>

using namespace std;

int main() {
    const int SIZE = 50;  // Max size for name parts
    char firstName[SIZE], middleName[SIZE], lastName[SIZE], fullName[SIZE * 3 + 3];

    // Get user input
    cout << "Enter your first name: ";
    cin.getline(firstName, SIZE);
    
    cout << "Enter your middle name: ";
    cin.getline(middleName, SIZE);
    
    cout << "Enter your last name: ";
    cin.getline(lastName, SIZE);

    // Create the full name in the format "Last name, First name Middle name"
    strcpy(fullName, lastName);       // Copy last name
    strcat(fullName, ", ");           // Add comma and space
    strcat(fullName, firstName);      // Add first name
    strcat(fullName, " ");            // Add space
    strcat(fullName, middleName);     // Add middle name

    // Display the result
    cout << "Formatted name: " << fullName << endl;

    return 0;
}

