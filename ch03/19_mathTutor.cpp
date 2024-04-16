/*
  Write a program that can be used as a math tutor for a young student. 
  The program should display two random numbers between 1 and 9 to be added, such as
      2
     +1
    -----

  After the student has entered an answer and pressed the [Enter] key, the program should 
  display the correct answer so the student can see if his or her answer is correct.
*/

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() 
{
    // Display welcome message
    cout << "Welcome to the Math Tutor Program!" << endl;
    cout << "This program will generate two random numbers between 1 and 9," << endl;
    cout << "and you'll have to add them together." << endl;
    cout << "Let's get started!" << endl << endl;
    
    // Seed the random number generator
    srand(time(0));
    
    // Generate two random numbers between 1 and 9
    int num1 = rand() % 9 + 1;
    int num2 = rand() % 9 + 1;
    
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
    
    // Display the correct answer
    cout << "Correct answer: " << correctAnswer << endl;
    
    return 0;
}

