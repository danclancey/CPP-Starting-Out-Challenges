/*
Write a program that has an array of at least 10 string objects that hold people’s names and phone numbers. You may make up your 
own strings or use the following:

        "Hoshikawa Tanaka, 678–1223"
        "Joe Looney, 586–0097"
        "Geri Palmer, 223–8787"
        "Lynn Lopez, 887–1212"
        "Holly Gaddis, 223–8878"
        "Sam Wiggins, 486–0998"
        "Bob Kain, 586–8712"
        "Tim Haynes, 586–7676"
        "Warren Gaddis, 223–9037"
        "Jean James, 678–4939"
        "Ron Palmer, 486–2783"

The program should ask the user to enter a name or partial name to search for in the array. Any entries in the array that match the 
string entered should be displayed. For example, if the user enters “Palmer”, the program should display the following names from the 
list:

Geri Palmer, 223–8787
Ron Palmer, 486–2783
*/

#include <iostream>
#include <string>

using namespace std;

// Function prototype
void searchEntries(const string contacts[], int size, const string& searchString);

int main() {
    // Array of strings holding names and phone numbers
    const int SIZE = 11;
    string contacts[SIZE] = {
        "Hoshikawa Tanaka, 678–1223",
        "Joe Looney, 586–0097",
        "Geri Palmer, 223–8787",
        "Lynn Lopez, 887–1212",
        "Holly Gaddis, 223–8878",
        "Sam Wiggins, 486–0998",
        "Bob Kain, 586–8712",
        "Tim Haynes, 586–7676",
        "Warren Gaddis, 223–9037",
        "Jean James, 678–4939",
        "Ron Palmer, 486–2783"
    };

    string searchName;

    // Prompt user for the search string
    cout << "Enter a name or partial name to search for: ";
    getline(cin, searchName);

    // Call the function to search and display matching entries
    searchEntries(contacts, SIZE, searchName);

    return 0;
}

// Function to search for entries that match the given search string
void searchEntries(const string contacts[], int size, const string& searchString) {
    bool found = false;

    // Loop through each contact and check if the search string is found
    for (int i = 0; i < size; i++) {
        if (contacts[i].find(searchString) != string::npos) { // Check if searchString is in the contact
            cout << contacts[i] << endl;
            found = true;
        }
    }

    // If no matches are found, display a message
    if (!found) {
        cout << "No matches found for \"" << searchString << "\"." << endl;
    }
}

