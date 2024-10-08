/*
A particular talent competition has five judges, each of whom awards a score between 0 and 10 to each performer. 
Fractional scores, such as 8.3, are allowed. A performer’s final score is determined by dropping the highest and 
lowest score received, then averaging the three remaining scores. Write a program that uses these rules to 
calculate and display a contestant’s score. It should include the following functions:

    double getJudgeData() should ask the user for a judge’s score, validate it, and then return it. This function 
    should be called by main once for each of the five judges.

    double calcScore() should calculate and return the average of the three scores that remain after dropping the 
    highest and lowest scores the performer received. This function should be called just once by main and should 
    be passed the five scores.

Two additional functions, described below, should be called by calcScore, which uses the returned information to 
determine which scores to drop.

    int findLowest() should find and return the lowest of the five scores passed to it.

    int findHighest() should find and return the highest of the five scores passed to it.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Function prototypes
double getJudgeData();
double calcScore(double score1, double score2, double score3, double score4, double score5);
double findLowest(double score1, double score2, double score3, double score4, double score5);
double findHighest(double score1, double score2, double score3, double score4, double score5);

int main() {
    // Get scores from the judges
    double score1 = getJudgeData();
    double score2 = getJudgeData();
    double score3 = getJudgeData();
    double score4 = getJudgeData();
    double score5 = getJudgeData();

    // Calculate and display the final score
    double finalScore = calcScore(score1, score2, score3, score4, score5);
    cout << fixed << setprecision(2);
    cout << "The contestant's final score is: " << finalScore << endl;

    return 0;
}

// Function to get and validate a judge's score
double getJudgeData() {
    double score;
    do {
        cout << "Enter a judge's score (0-10): ";
        cin >> score;
        if (score < 0 || score > 10) {
            cout << "Invalid score. Please enter a value between 0 and 10.\n";
        }
    } while (score < 0 || score > 10);  // Input validation for score
    return score;
}

// Function to calculate the final score after dropping the highest and lowest scores
double calcScore(double score1, double score2, double score3, double score4, double score5) {
    double lowest = findLowest(score1, score2, score3, score4, score5);
    double highest = findHighest(score1, score2, score3, score4, score5);

    // Sum of all scores minus the highest and lowest
    double total = score1 + score2 + score3 + score4 + score5 - lowest - highest;

    // Return the average of the three remaining scores
    return total / 3.0;
}

// Function to find the lowest score
double findLowest(double score1, double score2, double score3, double score4, double score5) {
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

// Function to find the highest score
double findHighest(double score1, double score2, double score3, double score4, double score5) {
    double highest = score1;

    if (score2 > highest) {
        highest = score2;
    }
    if (score3 > highest) {
        highest = score3;
    }
    if (score4 > highest) {
        highest = score4;
    }
    if (score5 > highest) {
        highest = score5;
    }

    return highest;
}

