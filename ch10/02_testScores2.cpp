/*
Modify the program of Programming Challenge 1 to allow the user to enter name–score pairs. For each student taking a test, the user types
a string representing the name of the student, followed by an integer representing the student’s score. Modify both the sorting and 
average-calculating functions so they take arrays of structures, with each structure containing the name and score of a single student. 
In traversing the arrays, use pointers rather than array indices.
*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

// Structure to hold name-score pairs
struct Student {
    string name;
    double score;
};

// Function prototypes
void sortScores(Student *students, int size);
double calculateAverage(const Student *students, int size);

int main() {
    int totalScores;

    // Get the number of test scores from the user
    cout << "Enter the number of students: ";
    cin >> totalScores;

    // Validate input
    while (totalScores <= 0) {
        cout << "Number of students must be positive. Please enter again: ";
        cin >> totalScores;
    }

    // Dynamically allocate an array of Student structures
    Student *students = new Student[totalScores];

    // Input the student names and test scores
    cout << "Enter the name and test scores for each student:\n";
    for (int i = 0; i < totalScores; i++) {
        cout << "Student " << (i + 1) << " Name: ";
        cin.ignore();  // Ignore leftover newline character
        getline(cin, (students + i)->name);
        cout << "Student " << (i + 1) << " Score: ";
        cin >> (students + i)->score;

        // Validate input for score
        while ((students + i)->score < 0) {
            cout << "Score cannot be negative. Please enter again: ";
            cin >> (students + i)->score;
        }
    }

    // Sort the students by score
    sortScores(students, totalScores);

    // Calculate the average score
    double average = calculateAverage(students, totalScores);

    // Display sorted list of students with scores
    cout << "\nSorted list of students by score:\n";
    cout << left << setw(20) << "Name" << "Score\n";
    cout << string(30, '_') << "\n\n";
    for (int i = 0; i < totalScores; ++i) {
        cout << left << setw(20) << (students + i)->name << (students + i)->score << endl;
    }

    // Display the average score
    cout << "\nAverage test score: " << average << endl;

    // Free dynamically allocated memory
    delete[] students;

    return 0;
}

// Function to sort the students by their scores in ascending order
void sortScores(Student *students, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if ((students + j)->score > (students + j + 1)->score) {
                // Swap the student records
                Student temp = *(students + j);
                *(students + j) = *(students + j + 1);
                *(students + j + 1) = temp;
            }
        }
    }
}

// Function to calculate the average score
double calculateAverage(const Student *students, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += (students + i)->score;
    }
    if (size == 0)
        return 0;
    else
        return (sum / size);
}

