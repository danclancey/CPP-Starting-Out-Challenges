/*
  When traveling through a gas, the speed of sound depends primarily on the density of the medium. The less 
  dense the medium, the faster the speed will be. The following table shows the approximate speed of sound 
  at 0 degrees Celsius, measured in meters per second, when traveling through carbon dioxide, air, helium, 
  and hydrogen.

        Medium	          Speed (meters per sec)
        Carbon dioxide	  258.0
        Air	              331.5
        Helium	          972.0
        Hydrogen	        1270.0

  Write a program that displays a menu allowing the user to select one of these four gases. After a valid 
  selection has been made, the program should ask the user to enter the number of seconds (0 to 30) it took 
  for the sound to travel in this medium from its source to the location at which it was detected. The 
  program should then report how far away (in meters) the source of the sound was from the detection location.

  Input Validation: If the use enters an invalid menu choice the program should display an error message instead of prompting for the number of seconds.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int choice;
    double seconds, distance;
    const double maxSeconds = 30.0;  // Maximum valid time for input

    // Display menu options
    cout << "Select a gas medium from the following:\n";
    cout << "1. Carbon dioxide\n";
    cout << "2. Air\n";
    cout << "3. Helium\n";
    cout << "4. Hydrogen\n";
    cout << "Enter your choice: ";
    cin >> choice;

    // Check if the user entered a valid choice
    if (choice < 1 || choice > 4) {
        cout << "Invalid choice! Please select a valid option from 1 to 4.\n";
        return 0; // Exit program
    }

    // Prompt the user to enter the time in seconds
    cout << "Enter the number of seconds (0 to 30): ";
    cin >> seconds;

    // Input validation for seconds
    if (seconds < 0 || seconds > maxSeconds) {
        cout << "Invalid time! Seconds must be between 0 and 30.\n";
        return 0;
    }

    // Calculate the distance based on the selected medium
    switch (choice) {
        case 1:
            distance = seconds * 258.0; // Carbon dioxide
            break;
        case 2:
            distance = seconds * 331.5; // Air
            break;
        case 3:
            distance = seconds * 972.0; // Helium
            break;
        case 4:
            distance = seconds * 1270.0; // Hydrogen
            break;
    }

    // Display the result
    cout << fixed << setprecision(2);
    cout << "The source of the sound was approximately " << distance << " meters away.\n";

    return 0;
}

