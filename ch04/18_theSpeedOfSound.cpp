/*
  The speed of sound varies depending on the medium through which it travels. In general, sound travels 
  fastest in rigid media, such as steel, slower in liquid media, such as water, and slowest of all in 
  gases, such as air. The following table shows the approximate speed of sound, measured in feet per 
  second, in air, water, and steel.

          Medium          Speed (feet per sec)
          Air             1,100
          Water           4,900
          Steel           16,400

  Write a program that displays a menu allowing the user to select air, water, or steel, and then has the 
  user enter the number of feet a sound wave will travel in the selected medium. The program should then 
  compute and display (with four decimal places) the number of seconds it will take.
*/

#include <iostream>
#include <iomanip>

using namespace std;

int main() {
    int choice;
    int feetTraveled;
    double seconds;

    cout << "Menu\n";
    cout << "1. Air\n";
    cout << "2. Water\n";
    cout << "3. Steel\n";

    cout << "Choice: ";
    cin >> choice;

    cout << "Please enter distance sound will travel (in feet): ";
    cin >> feetTraveled;

    switch(choice) {
        case 1:
            seconds = static_cast<double>(feetTraveled) / 1100; // Air
            break;
        case 2:
            seconds = static_cast<double>(feetTraveled) / 4900; // Water
            break;
        case 3:
            seconds = static_cast<double>(feetTraveled) / 16400; // Steel
            break;
        default:
            cout << "Invalid option!\n";
            return 0;
    }

    cout << fixed << setprecision(4);
    cout << "It will take " << seconds << " seconds for the sound to travel "
         << feetTraveled << " feet.\n";

    return 0;
}

