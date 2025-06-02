/*
Write a program that asks for the user’s name and year of birth, greets the user by name, and declares the user’s age in years. Users are 
assumed to be born between the years 1800 and 2099, and should enter the year of birth in one of the three formats 18XX, 19XX, or 20XX. A 
typical output should be “Hello Caroline, you are 23 years old.”
*/

#include <iostream>
#include <string>
#include <ctime>  // for getting the current year

using namespace std;

// Function to get the current year
int getCurrentYear() {
    time_t t = time(0);
    tm* now = localtime(&t);
    return (now->tm_year + 1900);  // tm_year gives the years since 1900
}

int main() {
    string name;
    int birthYear;
    int currentYear = getCurrentYear();

    // Ask for user's name
    cout << "Please enter your name: ";
    getline(cin, name);

    // Ask for user's year of birth
    cout << "Please enter your year of birth (1800 - 2099): ";
    cin >> birthYear;

    // Validate birth year input
    while (birthYear < 1800 || birthYear > 2099) {
        cout << "Invalid input. Please enter a year between 1800 and 2099: ";
        cin >> birthYear;
    }

    // Calculate the user's age
    int age = currentYear - birthYear;

    // Greet the user and display their age
    cout << "Hello " << name << ", you are " << age << " years old." << endl;

    return 0;
}

