/*
Write a program that calculates the average of a group of test scores, where the lowest score in the group
is dropped. It should use the following functions:

    void getScore() should ask the user for a test score, store it in a reference parameter variable, and 
    validate that it is not lower than 0 or higher than 100. This function should be called by main once 
    for each of the five scores to be entered.

    void calcAverage() should calculate and display the average of the four highest scores. This function 
    should be called just once by main and should be passed the five scores.

    int findLowest() should find and return the lowest of the five scores passed to it. It should be called 
    by calcAverage, which uses the function to determine which one of the five scores to drop.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
void getScore(double& score);
void calcAverage(double score1, double score2, double score3, double score4, double score5);
int findLowest(double score1, double score2, double score3, double score4, double score5);

int main() {
    double score1, score2, score3, score4, score5;

    // Get the scores using the getScore function
    getScore(score1);
    getScore(score2);
    getScore(score3);
    getScore(score4);
    getScore(score5);

    // Calculate and display the average of the highest scores
    calcAverage(score1, score2, score3, score4, score5);

    return 0;
}

// Function to get a test score and validate it
void getScore(double& score) {
    do {
        cout << "Enter a test score (0-100): ";
        cin >> score;
        if (score < 0 || score > 100) {
            cout << "Invalid score. Please enter a value between 0 and 100.\n";
        }
    } while (score < 0 || score > 100);
}

// Function to calculate and display the average of the four highest scores
void calcAverage(double score1, double score2, double score3, double score4, double score5) {
    int lowest = findLowest(score1, score2, score3, score4, score5);
    double total = score1 + score2 + score3 + score4 + score5 - lowest;
    double average = total / 4.0;

    cout << fixed << setprecision(2);
    cout << "The average of the four highest scores is: " << average << endl;
}

// Function to find the lowest score
int findLowest(double score1, double score2, double score3, double score4, double score5) {
    double lowest = score1;

    if (score2 < lowest) {
        lowest = score2;
    }
    if (score3 < lowest) {
        lowest = score3;
    }
    if (score4 < lowest) {
        lowest = score4;
    }
    if (score5 < lowest) {
        lowest = score5;
    }

    return lowest;
}

