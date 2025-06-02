/*
Consider a company that needs to sort an array Person data[10] of structures of type Person by name.

struct Person
{
   string name;
   int age;
}

In real life the Person structures may have many members and occupy a large area of memory, making it computationally expensive to move Person 
objects around while sorting. You can define an auxiliary array Person *pData[10], setting each entry of pData[k] to point to the corresponding 
entry of data[k]. Write a program that sorts the array of pointers so that when you go through pData in increasing order of index k, the entries 
pData[k] point to Person objects in ascending alphabetic order of names.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

struct Person {
    string name;
    int age;
};

// Function prototypes
void sortPointers(Person* pData[], int size);
void displayPersons(Person* pData[], int size);

int main() {
    // Original array of Person structures
    Person data[10] = {
        {"Alice", 30}, {"Bob", 25}, {"Charlie", 35}, {"Diana", 28}, {"Eve", 22},
        {"Frank", 33}, {"Grace", 31}, {"Hank", 29}, {"Ivy", 26}, {"John", 34}
    };

    // Array of pointers to Person objects
    Person* pData[10];

    // Initialize pData to point to each corresponding entry in the data array
    for (int i = 0; i < 10; i++) {
        pData[i] = &data[i];
    }

    // Sort the array of pointers by name
    sortPointers(pData, 10);

    // Display the sorted persons
    displayPersons(pData, 10);

    return 0;
}

// Function to sort the array of pointers by name
void sortPointers(Person* pData[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = i + 1; j < size; j++) {
            // Compare the names via pointers
            if (pData[i]->name > pData[j]->name) {
                // Swap pointers if out of order
                Person* temp = pData[i];
                pData[i] = pData[j];
                pData[j] = temp;
            }
        }
    }
}

// Function to display the sorted Person data via pointers
void displayPersons(Person* pData[], int size) {
    cout << "Sorted Persons by Name:\n\n";
    cout << left << setw(15) << "Name" << "Age\n";
    cout << "_______________________\n";
    for (int i = 0; i < size; i++) {
        cout << left << setw(15) << pData[i]->name << pData[i]->age << endl;
    }
}

