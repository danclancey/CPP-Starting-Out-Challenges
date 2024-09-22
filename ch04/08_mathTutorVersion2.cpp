/*
  Write a program that can be used as a math tutor for a young student. The program should display two 
  random numbers between 10 and 50 that are to be added, such as:

            24
           +12
          -----
 
  The program should then wait for the student to enter the answer. If the answer is correct, a message 
  of congratulations should be printed. If the answer is incorrect, a message should be printed showing 
  the correct answer.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    // Display welcome message
    cout << "Welcome to the Math Tutor Program!" << endl;
    cout << "This program will generate two random numbers between 10 and 50," << endl;
    cout << "and you'll have to add them together." << endl;
    cout << "Let's get started!" << endl << endl;

    // Seed the random number generator
    srand(time(0));

    // Generate two random numbers between 1 and 9
    int num1 = rand() % 40 + 10;
    int num2 = rand() % 40 + 10;

    // Display the addition problem
    cout << "  " << num1 << endl;
    cout << "+ " << num2 << endl;
    cout << "-----" << endl;

    // Get the student's answer
    int studentAnswer;
    cout << "Enter your answer: ";
    cin >> studentAnswer;

    // Calculate the correct answer
    int correctAnswer = num1 + num2;
    
    // Display response
    if (correctAnswer == studentAnswer) {
      cout << "Congrats! You got it right!\n";
    } else {
      cout << "Whoops! You got it wrong. The correct answer is: " << correctAnswer << endl;
    }
    return 0;
}
