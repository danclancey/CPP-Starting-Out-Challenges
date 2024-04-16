/*
  A cookie recipe calls for the following ingredients:
    1.5 cups of sugar
    1 cup of butter
    2.75 cups of flour

  The recipe produces 48 cookies with these amounts of the ingredients. Write a program that asks the user how many 
  cookies he or she wants to make and then displays the number of cups of each ingredient needed for the specified 
  number of cookies.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Declare constants
const double SUGAR_PER_COOKIE = 1.5 / 48; // cups
const double BUTTER_PER_COOKIE = 1.0 / 48; // cups
const double FLOUR_PER_COOKIE = 2.75/ 48; // cups

int main()
{
  // Variables to store user input and calculated ingredient amounts
    int numCookies;
    double sugarNeeded, butterNeeded, flourNeeded;
    // Welcome Message
    cout << "Welcome to Dan's Cookie Calculator!\n"
         << "-----------------------------------\n"
         << "This will calculate the ingredients needed\n"
         << "for a given amount of cookies\n\n";

    // Get the number of cookies from the user
    cout << "Enter the number of cookies you want to make: ";
    cin >> numCookies;

    // Calculate the amount of each ingredient needed
    sugarNeeded = SUGAR_PER_COOKIE * numCookies;
    butterNeeded = BUTTER_PER_COOKIE * numCookies;
    flourNeeded = FLOUR_PER_COOKIE * numCookies;

    // Display the resultas
    cout << fixed << setprecision(2);
    cout << "For " << numCookies << " cookies, you will need:" << endl;
    cout << "Sugar: " << sugarNeeded << " cups" << endl;
    cout << "Butter: " << butterNeeded << " cups" << endl;
    cout << "Flour: " << flourNeeded << " cups" << endl;
}
