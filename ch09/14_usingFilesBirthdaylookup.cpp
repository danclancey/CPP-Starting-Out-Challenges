/*
Modify the program you wrote for Programming Challenge 13 so that after reading in the data from the 
birthdays.dat file it sorts the array elements alphabetically by the name field and then prints the names, 
prompting the user to enter the name of the person whose birthday they want to find. It should then locate 
and display that person’s birthday.
*/

#include <iostream>
#include <fstream>
#include <iomanip>
#include <string>
#include <algorithm>

using namespace std;

// Structure to hold name and birthday
struct Birthday {
    string name;
    string birthday;  // In the format mm/dd
};

// Function prototypes
void readData(Birthday people[], int size);
void sortByName(Birthday people[], int size);
void swap(Birthday &a, Birthday &b);
void displayList(const Birthday people[], int size);
string trim(const string &str);
int searchByName(const Birthday people[], int size, const string &name);

const int SIZE = 10;

int main() {
    Birthday people[SIZE];

    // Read data from the file
    readData(people, SIZE);

    // Sort the data alphabetically by name
    sortByName(people, SIZE);

    // Display the sorted list
    displayList(people, SIZE);

    // Prompt the user to search for a birthday
    string name;
    cout << "\nEnter the name of the person whose birthday you want to find: ";
    getline(cin, name);

    // Search for the name and display the birthday
    int index = searchByName(people, SIZE, name);
    if (index != -1) {
        cout << name << "'s birthday is " << people[index].birthday << ".\n";
    } else {
        cout << "Sorry, " << name << " was not found in the list.\n";
    }

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

// Function to sort the birthdays by name (alphabetically)
void sortByName(Birthday people[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (people[j].name > people[j + 1].name) {
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

// Function to search for a person's name and return the index
int searchByName(const Birthday people[], int size, const string &name) {
    for (int i = 0; i < size; i++) {
        if (people[i].name == name) {
            return i;  // Return the index if found
        }
    }
    return -1;  // Return -1 if not found
}

