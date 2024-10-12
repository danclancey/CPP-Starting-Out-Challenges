/*
The State Department of Motor Vehicles (DMV) has asked you to write a program 
that grades the written portion of the driver’s license exam, which has 20 
multiple-choice questions. Here are the correct answers:

    1. B    5. C    9. C    13. D   17. C
    2. D    6. A    10. D   14. A   18. B
    3. A    7. B    11. B   15. D   19. D
    4. A    8. A    12. C   16. C   20. A        
 
To do this, you should create a TestGrader class. The class will have an answers 
array of 20 characters, which holds the correct test answers. It will have two 
public member functions that enable user programs to interact with the class: 
setKey and grade. The setKey function receives a 20-character string holding the 
correct answers and copies this information into its answers array. The grade 
function receives a 20-character array holding the test taker’s answers and 
compares each of their answers to the correct one. An applicant must correctly 
answer 15 or more questions to pass the exam. After “grading” the exam, the grade 
function should create and return to the user a string that includes the following 
information:

    - A message indicating whether the applicant passed or failed the exam
    - The number of right answers and the number of wrong answers
    - A list of the question numbers for all incorrectly answered questions

The client program that creates and uses a TestGrader object should first make a 
single call to setKey, passing it a string containing the 20 correct answers. Once 
this is done, it should allow a test taker’s 20 answers to be entered, making sure 
only answers of A–D are accepted, and store them in a 20-character array. Then it 
should call the grade function to grade the exam and should display the string the 
function returns. The program should loop to allow additional tests to be entered 
and graded until the user indicates a desire to quit.
*/

#include <iostream>
#include <string>
#include <limits>
#include "TestGrader.h"

using namespace std;

bool isValidAnswer(char answer);
void getStudentAnswers(char answers[]);

int main() {
    TestGrader grader;
    string key = "BDACCADBBCDACDDBCCAA";                          // Provided answer key 
    grader.setKey(key);

    char studentAnswers[20];
    char choice;

    cout << "Welcome to the DMV Test Grader Program!\n";

    do {
        // Get answers from student 
        getStudentAnswers(studentAnswers);

        // Grade answers and display result 
        string result = grader.grade(studentAnswers);
        cout << "\n" << result << "\n";

        // Ask user if they want to grade another 
        cout << "\nWould you like to grade another test? (y/n): ";
        cin >> choice;
        while (cin.fail() || (tolower(choice) != 'y' && tolower(choice) != 'n')) {
            cin.clear();                                          // Clear error flag
            cin.ignore(numeric_limits<streamsize>::max(), '\n');  // Discard invalid input
            cout << "Invalid input. Please enter 'y' for yes or 'n' for no: ";
            cin >> choice;
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');      // Clear leftover input 

    } while (tolower(choice) == 'y');

    cout << "Thanks for using DMV Test Grader.\nExiting . . .";

    return 0;
}

// Function to validate if answer is A B C or D 
bool isValidAnswer (char answer) {
    return answer == 'A' || answer == 'B' || answer == 'C' || answer == 'D';
}

// Function to get the student answers with input validation 
void getStudentAnswers(char answers[]) {
    cout << "\nEnter student answers (A-D): \n";
    for (int i = 0; i < 20; i++) {
        char answer;
        bool validInput = false;

        // Loop for validation 
        while (!validInput) {
            cout << "Question " << (i + 1) << ": ";
            cin >> answer;
            answer = toupper(answer);                              // Normalize to uppercase
            
            if (cin.fail() || !isValidAnswer(answer)) {
                cin.clear();                                       // Clear error flag 
                cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Discard invalid input 
                cout << "Invalid input! Please enter A, B, C, or D.\n";
            } else {
                validInput = true;
                answers[i] = answer;
            }
        }
    }
}
