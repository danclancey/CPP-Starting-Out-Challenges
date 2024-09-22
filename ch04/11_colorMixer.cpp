/*
  Red, blue, and yellow are known as the primary colors because they cannot be made by mixing other colors. 
  When you mix two primary colors, you get a secondary color. Red and blue create purple, red and yellow 
  create orange, and blue and yellow create green.

  Write a program that prompts the user to enter the names of two primary colors to mix. If the user enters 
  anything other than “red,” “blue,” or “yellow,” display an error message. Otherwise, display the name of 
  the secondary color produced.
*/

#include <iostream>
#include <string>
#include <algorithm>
#include <cctype>

using namespace std;

int main()
{
  string color1, color2;

  // Display Welcome
  cout << "Welcome to Dan's Primary Color Mixer.\n";
  cout << "-------------------------------------\n\n";
  cout << "This program will return the secondary color created by mixing two primary colors.\n\n";

  // Prompt user to enter colors
  cout << "Enter the names of two primary colors to mix (red, blue, or yellow): ";
  cin >> color1 >> color2;

  // convert to lowercase
  transform(color1.begin(), color1.end(), color1.begin(), [](unsigned char c) { return tolower(c); });
  transform(color2.begin(), color2.end(), color2.begin(), [](unsigned char c) { return tolower(c); });

  // Check colors
  if ((color1 == "red" && color2 == "blue") || (color1 == "blue" && color2 == "red" ))
  {
    cout << "Mixing " << color1 << " and " << color2 << " produces purple.\n";
  }
  else if ((color1 == "red" && color2 == "yellow") || (color1 == "yellow" && color2 == "red"))
  {
    cout << "Mixing " << color1 << " and " << color2 << " produces orange.\n";
  }
  else if ((color1 == "blue" && color2 == "yellow") || (color1 == "yellow" && color2 == "blue"))
  {
    cout << "Mixing " << color1 << " and " << color2 << " produces green.\n";
  }
  else 
  {
    cout << "Error: Invalid Input! Exiting...\n";
  }

  return 0;
}
