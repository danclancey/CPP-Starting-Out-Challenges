/*
Write a modular program that accepts up to 20 integer test scores 
in the range of 0 to 100 from the user and stores them in an array. 
Then main should report how many perfect scores were entered 
(i.e., scores of 100), using a value-returning countPerfect function 
to help it. Hint: Have the program count the scores as they are 
entered. Your program may need this information later.
*/

#include <iostream>

using namespace std;

// Function prototype with array and size
int countPerfect(double arr[], int size);

int main() {
    const int SIZE = 20;
    int perfectScores = 0;
    double scores[SIZE];

    cout << "This program will count how many perfect scores are in an array.\n";
    cout << "The scoring range is 0-100\n";
    cout <<"Please enter valid scores.\n";

    for (int i = 0; i < 20; i++) {
        cout << "Score " << i + 1 << ": ";
        cin >> scores[i];
        // Input validation for scores between 0 and 100 
        while (scores[i] < 0 || scores[i] > 100 ) {
            cout << "Invalid score. Please enter a score from 0-100: ";
            cin >> scores[i];
        }
    }

    // call countPerfect function
    perfectScores = countPerfect(scores, SIZE);

    // Display the result
    cout << "There are " << perfectScores << " perfect scores!\n";

    return 0;
}

// Function to count perfect scores 
int countPerfect(double arr[], int size) {
    int perfectScores = 0;

    // Loop through array to count perfect scores 
    for (int i = 0; i < size; i++) {
        if (arr[i] == 100) {
            perfectScores += 1;
        }    
    }

    return perfectScores;
}
