/*
  A bag of cookies holds 30 cookies. The calorie information on the bag claims that there are 10 “servings” 
  in the bag and that a serving equals 240 calories. Write a program that asks the user to input how many 
  cookies they actually ate and then reports how many total calories were consumed.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const int COOKIES_IN_BAG = 30,
          SERVINGS_PER_BAG = 10,
          CALORIES_PER_SERVING = 240;

int main()
{
  // Declare variables
  int caloriesPerCookie = CALORIES_PER_SERVING / (COOKIES_IN_BAG / SERVINGS_PER_BAG),
      cookiesEaten;

  // Welcome Message
  cout << "Welcome to Dan's Cookie Calorie Counter!\n\n"
       << "This program will prompt you for how many cookies you ate\n"
       << "and will return the amount of calories you consumed.\n\n";

  // Prompt user for input
  cout << "Please enter how many cookies you ate: ";
  cin >> cookiesEaten;

  // calculate and display  calories consumed
  cout << "\nEach cookie is approximately " << caloriesPerCookie << " calories.\n"
       << "Therefore you consumed approximately " << cookiesEaten * caloriesPerCookie << " calories.\n";
  
  return 0;
}
