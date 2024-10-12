#include "TestGrader.h"
#include <sstream>

using namespace std;

// Function to set answer key
void TestGrader::setKey(const string& key) {
    for (int i = 0; i < 20; i++) {
        answers[i] = toupper(key[i]);   // Store answers in uppercase 
    }
}

// Function to grade student answers 
string TestGrader::grade(const char stuAnswers[]) {
    int correctCount = 0;
    int wrongCount = 0;
    stringstream result;

    // Check answers and track right/wrong answers 
    result << "Incorrectly answered questions: ";
    for (int i = 0; i < 20; i++) {
        if (toupper(stuAnswers[i]) == answers[i]) {
            correctCount++;
        } else {
            wrongCount++;
            result << (i + 1) << " ";
        }
    }

    // Prepare the results
    result << "\nNumber of correct answers: " << correctCount 
           << "\nNumber of wrong answers: " << wrongCount 
           << "\nResult: " << (correctCount >= 15 ? "Passed" : "Failed");

    return result.str();
}
