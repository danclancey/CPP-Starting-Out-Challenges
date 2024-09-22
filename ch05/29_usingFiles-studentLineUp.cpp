/*
Modify the Student Line Up program described in Programming Challenge 15 so that it gets the 
names from a data file. Names should be read in until there is no more data to read. Data to 
test your program can be found in the lineUp.txt file located in the Chapter 5 programs 
folder on the book’s companion website.
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile("lineUp.txt");
    string name, firstStudent, lastStudent;

    // Check if file opened successfully
    if (!inputFile) {
        cout << "Error: Unable to open file!" << endl;
        return 1;
    }

    // Read the first name from the file to initialize first and last
    if (inputFile >> name) {
        firstStudent = name;
        lastStudent = name;
    } else {
        cout << "Error: No data in the file!" << endl;
        return 1;
    }

    // Read the remaining names and update the first and last student
    while (inputFile >> name) {
        if (name < firstStudent) {
            firstStudent = name;
        }
        if (name > lastStudent) {
            lastStudent = name;
        }
    }

    // Close the input file
    inputFile.close();

    // Display the first and last student alphabetically
    cout << "First student alphabetically: " << firstStudent << endl;
    cout << "Last student alphabetically: " << lastStudent << endl;

    return 0;
}

