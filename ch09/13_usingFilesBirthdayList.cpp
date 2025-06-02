/*
Write a program that produces a list of stored names and birthdays in date order. It should use a 
10-element array of structures or class objects that each holds two string variables, name and birthday. 
The program should fill the array elements by reading in the data from the birthdays.dat file located 
in the Chapter 9 programs folder on the book’s companion website. The file contains 20 lines with a 
person’s name on one line, followed by his or her birthday on the next line in the form mm/dd. Once the 
data has been read in and stored, the program should sort the elements in ascending order of date and 
display the birthday list. Make the program modular with main calling different functions to read in the 
file data, perform the sort, swap two elements, and display the list.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>  // For the trimming functions

using namespace std;

// Structure to hold name and birthday
struct Birthday {
    string name;
    string birthday;  // In the format mm/dd
};

// Function prototypes
void readData(Birthday people[], int size);
void sortBirthdays(Birthday people[], int size);
void swap(Birthday &a, Birthday &b);
void displayList(const Birthday people[], int size);
string trim(const string &str);

const int SIZE = 10;

int main() {
    Birthday people[SIZE];

    // Read data from the file
    readData(people, SIZE);

    // Sort the data by birthday
    sortBirthdays(people, SIZE);

    // Display the sorted list
    displayList(people, SIZE);

    return 0;
}

// Function to read names and birthdays from a file
void readData(Birthday people[], int size) {
    ifstream inputFile("birthdays.dat");

    if (!inputFile) {
        cerr << "Error: Could not open the file." << endl;
        exit(1);
    }

    for (int i = 0; i < size; i++) {
        getline(inputFile, people[i].name);       // Read name
        getline(inputFile, people[i].birthday);   // Read birthday in mm/dd format
        
        // Trim leading and trailing whitespace from the name and birthday
        people[i].name = trim(people[i].name);
        people[i].birthday = trim(people[i].birthday);
    }

    inputFile.close();
}

// Function to sort the birthdays in ascending order of date
void sortBirthdays(Birthday people[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (people[j].birthday > people[j + 1].birthday) {
                swap(people[j], people[j + 1]);
            }
        }
    }
}

// Function to swap two Birthday structures
void swap(Birthday &a, Birthday &b) {
    Birthday temp = a;
    a = b;
    b = temp;
}

// Function to display the sorted list of birthdays
void displayList(const Birthday people[], int size) {
    cout << left << setw(20) << "Name" << "Birthday" << endl;
    cout << "---------------------------" << endl;
    for (int i = 0; i < size; i++) {
        cout << left << setw(20) << people[i].name << people[i].birthday << endl;
    }
}

// Function to trim leading and trailing whitespace
string trim(const string &str) {
    size_t first = str.find_first_not_of(" \t\n\r");
    size_t last = str.find_last_not_of(" \t\n\r");
    
    if (first == string::npos || last == string::npos)
        return "";  // The string is empty or only whitespace
    
    return str.substr(first, last - first + 1);
}

