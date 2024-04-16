/*  
  Write a program that converts Celsius temperatures to Fahrenheit temperatures. The formula is
  
      F = 9/5 * C + 32
  
  where F is the Fahrenheit temperature and C  is the Celsius temperature. The program should prompt the 
  user to input a Celsius temperature and should display the corresponding Farenheit temperature.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() 
{
    double celsius, fahrenheit;

    // Welcome message
    cout << "Welcome to Dan's Celsius converter!\n"
         << "------------------------------------\n\n"
         << "This program will convert Celsius to Farenheit\n\n";

    // Prompt user to enter Celsius temperature
    cout << "Enter the temperature in Celsius: ";
    cin >> celsius;

    // Convert Celsius to Fahrenheit
    fahrenheit = (9.0 / 5.0) * celsius + 32.0;

    // Display the resulti
    cout << "The temperature in Fahrenheit is: " << fixed << setprecision(1) << fahrenheit << " F" << endl;

    return 0;
}
