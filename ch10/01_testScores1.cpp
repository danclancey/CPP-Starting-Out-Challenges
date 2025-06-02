/*
Write a program that dynamically allocates an array large enough to hold a user-defined number of test scores. Once all the scores are entered, 
the array should be passed to a function that sorts them in ascending order. Another function should be called that calculates the average 
score. The program should display the sorted list of scores and averages with appropriate headings. Use pointer notation rather than array 
notation whenever possible.

Input Validation: Do not accept negative numbers for test scores.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void sortScores(double *scores, int size);
double calculateAverage(double *scores, int size);

int main() {
    int totalScores;

    // Get the number of test scores from the user
    cout << "Enter the number of test scores: ";
    cin >> totalScores;

    // Validate input
    while (totalScores <= 0) {
        cout << "Number of test scores must be positive. Please enter again: ";
        cin >> totalScores;
    }

    // Dynamically allocate an array to hold the test scores
    double *scores = new double[totalScores];

    // Input the test scores
    cout << "Enter the test scores:\n";
    for (int i = 0; i < totalScores; i++) {
        cout << "Test score " << (i + 1) << ": ";
        cin >> *(scores + i);

        // Validate input
        while (*(scores + i) < 0) {
            cout << "Score cannot be negative. Please enter again: ";
            cin >> *(scores + i);
        }
    }

    // Sort the scores
    sortScores(scores, totalScores);

    // Calculate the average score
    double average = calculateAverage(scores, totalScores);

    // Display sorted list of scores
    cout << "\nSorted list of scores:\n";
    cout << string(totalScores + 10, '_' ) << "\n\n";
    for (int i = 0; i < totalScores; ++i) {
        cout << left << setw(12) << "Test" << (i + 1) << ": " << *(scores + i) << endl;
    }

    // Display the average score
    cout << "\nAverage test score: " << average << endl;

    // Free dynamically allocated memory
    delete[] scores;

    return 0;
}

// Function to sort the scores in ascending order using bubble sort algorithm
void sortScores(double *scores, int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (*(scores + j) > *(scores + j + 1)) {
                // Swap the scores
                double temp = *(scores + j);
                *(scores + j) = *(scores + j + 1);
                *(scores + j + 1) = temp;
            }
        }
    }
}

// Function to calculate the average score
double calculateAverage(double *scores, int size) {
    double sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(scores + i);
    }
    if (size == 0)
        return 0;
    else
        return (sum / size);
}
