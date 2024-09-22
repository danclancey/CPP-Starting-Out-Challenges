/*
  Write a program that displays the following menu:


        Geometry Calculator
            1. Calculate the Area of a Circle
            2. Calculate the Area of a Rectangle
            3. Calculate the Area of a Triangle
            4. Quit
        Enter your choice (1–4):
  
  * If the user enters 1, the program should ask for the radius of the circle and then display 
    its area. Use 3.14159 for Pi.

  * If the user enters 2, the program should ask for the length and width of the rectangle, 
    and then display the rectangle’s area.

  * If the user enters 3, the program should ask for the length of the triangle’s base and 
    height, and then display its area.

  * If the user enters 4, the program should end.

  Input Validation: Decide how the program should handle any illegal inputs.
*/

#include <iostream>
#include <iomanip>

using namespace std;

// Constant for PI
const double PI = 3.14159;

int main()
{
  // Declare variables
  int menuOption;
  double radius, length, width, 
         height, base, area;

  // Print Menu
  cout << "Geometry Calculator\n";
  cout << "   1. Calculate the Area of a Circle\n";
  cout << "   2. Calculate the Area of a Rectangle\n";
  cout << "   3. Calculate the Area of a Triangle\n";
  cout << "   4. Quit\n";
  cout << " Enter your choice (1-4): ";
  cin >> menuOption;

  switch(menuOption) 
  {
    case 1: // Circle 
      {
        cout << "Enter the radius of the Circle: ";
        cin >> radius;

        if (radius <= 0) 
        {
          cout << "Invalid radius. Radius must be positive." << endl;
          break;
        }

        area = PI * radius * radius;
        cout << "Area of the Circle: " << area << endl;
        break;
      }
    case 2: // Rectangle
      {
        cout << "Enter the length of the rectangle: ";
        cin >> length;
        cout << "Enter the width of the rectangle: ";
        cin >> width;

        if (length <= 0 || width <= 0)
        {
          cout << "Invalid dimensions. Length and Width must be positive." << endl;
          break;
        }

        area = length * width;
        cout << "Area of the rectangle: " << area << endl;
        break;
      }
    case 3: // Triangle
      {
        cout << "Enter the length of the triangle's base: ";
        cin >> base;
        cout << "Enter the height of the triangle: ";
        cin >> height;

        if (base <= 0 || height <= 0)
        {
          cout << "Invalid dimensions. Base and height must be positive." << endl;
          break;
        }

        area = (base * height) / 2;
        cout << "Area of the triangle: " << area << endl;
        break;
      }
    case 4: // Exit Program
      {
        cout << "Exiting..." << endl;
        break;
      }
    default: // Invalid Menu Option 
      {
        cout << "Invalid choice. Exiting..." << endl;
        break;
      }
  }

  return 0;
}
