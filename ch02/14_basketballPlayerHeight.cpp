/*
  The star player of a high school basketball team is 75 inches tall. Write a program
  to compute and display the height in feet/inches form.

  Hint: Try using the modulus and integer divide operations
*/

#include <iostream>

using namespace std;
// declare constant for player height
const int HEIGHT_IN_INCHES = 75;

int main()
{
  int heightInFeet = HEIGHT_IN_INCHES / 12;
  int inches = HEIGHT_IN_INCHES % 12;
  cout << "Player Height: " << heightInFeet << "' " << inches <<"\"";

  return 0;
}


