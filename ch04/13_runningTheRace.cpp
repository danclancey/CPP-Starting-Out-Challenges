/*
  Write a program that asks for the names of three runners and the time it took each of them to finish a race. 
  The program should display who came in first, second, and third place. Think about how many test cases are 
  needed to verify that your problem works correctly. (That is, how many different finish orders are possible?)

  Input Validation: Only allow the program to accept positive numbers for the times.
*/

#include <iostream>
#include <string>

using namespace std;

int main() {
    string runnerName1, runnerName2, runnerName3;
    int runnerTime1, runnerTime2, runnerTime3;

    cout << "Please enter name of runner 1: ";
    cin >> runnerName1;
    cout << "Please enter time of runner 1 (positive number): ";
    cin >> runnerTime1;
    if (runnerTime1 <= 0) {
        cout << "Invalid input! Time must be positive." << endl;
        return 1; // Exit the program with an error code
    }

    cout << "Please enter name of runner 2: ";
    cin >> runnerName2;
    cout << "Please enter time of runner 2 (positive number): ";
    cin >> runnerTime2;
    if (runnerTime2 <= 0) {
        cout << "Invalid input! Time must be positive." << endl;
        return 1;
    }

    cout << "Please enter name of runner 3: ";
    cin >> runnerName3;
    cout << "Please enter time of runner 3 (positive number): ";
    cin >> runnerTime3;
    if (runnerTime3 <= 0) {
        cout << "Invalid input! Time must be positive." << endl;
        return 1;
    }

    if (runnerTime1 < runnerTime2 && runnerTime1 < runnerTime3) {
        cout << "First place: " << runnerName1 << endl;
        if (runnerTime2 < runnerTime3) {
            cout << "Second place: " << runnerName2 << endl;
            cout << "Third place: " << runnerName3 << endl;
        } else {
            cout << "Second place: " << runnerName3 << endl;
            cout << "Third place: " << runnerName2 << endl;
        }
    } else if (runnerTime2 < runnerTime1 && runnerTime2 < runnerTime3) {
        cout << "First place: " << runnerName2 << endl;
        if (runnerTime1 < runnerTime3) {
            cout << "Second place: " << runnerName1 << endl;
            cout << "Third place: " << runnerName3 << endl;
        } else {
            cout << "Second place: " << runnerName3 << endl;
            cout << "Third place: " << runnerName1 << endl;
        }
    } else if (runnerTime3 < runnerTime1 && runnerTime3 < runnerTime2) {
        cout << "First place: " << runnerName3 << endl;
        if (runnerTime1 < runnerTime2) {
            cout << "Second place: " << runnerName1 << endl;
            cout << "Third place: " << runnerName2 << endl;
        } else {
            cout << "Second place: " << runnerName2 << endl;
            cout << "Third place: " << runnerName1 << endl;
        }
    } else {
        cout << "There is a tie!" << endl;
    }

    return 0;
}

