/*
A teacher has asked all her students to line up according to their first name. 

For example, in one class Amy will be at the front of the line and Yolanda will be at the end. 
Write a program that prompts the user to enter a number between 1 and 20 for the number of 
students in the class and then loops to read in that many names. Once all the names have been 
read in, it should report which student would be at the front of the line and which one would 
be at the end of the line. You may assume that no two students have the same name.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    int numStudents;
    string name, firstStudent, lastStudent;

    // Prompt for number of students
    cout << "Enter the number of students (between 1 and 20): ";
    cin >> numStudents;

    // Input validation for number of students
    while (numStudents < 1 || numStudents > 20) {
        cout << "Invalid input! Please enter a number between 1 and 20: ";
        cin >> numStudents;
    }

    // Read the names and determine the alphabetical order
    cout << "Enter the names of the students:\n";

    for (int i = 0; i < numStudents; i++) {
        cout << "Enter name of student " << (i + 1) << ": ";
        cin >> name;

        // For the first student, initialize both firstStudent and lastStudent
        if (i == 0) {
            firstStudent = name;
            lastStudent = name;
        } else {
            // Update firstStudent if the current name is alphabetically earlier
            if (name < firstStudent) {
                firstStudent = name;
            }
            // Update lastStudent if the current name is alphabetically later
            if (name > lastStudent) {
                lastStudent = name;
            }
        }
    }

    // Display the results
    cout << "The student at the front of the line is: " << firstStudent << endl;
    cout << "The student at the end of the line is: " << lastStudent << endl;

    return 0;
}

